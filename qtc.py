# Copyright (C) 2021 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only WITH Qt-GPL-exception-1.0s

import sys
if sys.version_info < (3,5):
	sys.exit("______\nqtc.py: Python 3.5 or later is required (on some systems, use the command\n"+
	" \"python3\" instead of \"python\" since the latter is reserved for python 2).\n_____");


import glob # for searching files
import os
import re # regular expression, for removing comments
import random # for debbugging
import time
from contextlib import suppress as ignoreException

inputDir = "src/"
outputDir = "c_src/out/"
overlayDir = "c_src/overlay/"

# 1 = params, 2 = wrapperParams, 12 = both
typeMap = {
	"PointerToMemberFunction": ["void*", 2],
	"std::chrono::milliseconds": ["unsigned long long", 12],
	"std::filesystem::path": ["char*", 12],
	"uint": ["unsigned int", 12]
}


# for verbose output, puts "message" at the end of a line beginning with "started [filename]..."
# to prevent overflowing the normal terminal width of 80 chars, "message" must have 5 chars or less
def sayResult(filename, message):
	print(' ' * max(67 - len(filename), 1) + message)

testingMode = True # Python errors do not appear with multithreading in use, so this disables it
testingFile = inputDir+"corlib/kernel/qobject.h" # can be used when "testingMode = True" to step through a file

# the overlay system adds or replaces elements in [$inputDir]/header.h
# with elements from [$overlayDir]/header.h.

def applyOverlay(target, overlay):
	for elm in overlay:
		if type(elm) == Variable:
			if elm.type == "DELETE":
				for elm2 in target:
					if type(elm2) in (Variable, Function, Enum, Class):
						if elm2.name == elm.name:
							target.remove(elm2)
			elif elm.type == "OVERWRITE":
				if elm.name == "ALL":
					return overlay
			else:
				_continue = False
				for elm2 in target:
					if type(elm2) != Macro:
						if elm2.name == elm.name:
							elm2.type = elm.type
							_continue = True
							break
				if _continue:
					continue
				target.append(elm)
		elif type(elm) == Function:
			if elm.returnType in ("DELETE", "RENAME"):
				for elm2 in target:
					if type(elm2) in (Variable, Function, Enum, Class):
						elm2NewName = ""
						for p in elm2.params:
							if p.type == "TO":
								elm2NewName = p.name
								elm2.params.remove(p)

						# for functions, only work if the parameters match or the only parameter is "ANY" (eg. "DELETE func(ANY);")
						if type(elm2) == Function:
							# exec is used to prevent an index out-of-range exception if the function has zero parameters
							if elm.params == elm2.params or exec("elm.params[0].type == 'ANY'"):
								if elm.returnType == "DELETE":
									target.remove(elm2)
								else:
									if elm2NewName == "":
										exit("qtc.py: ERROR: \"RENAME "+elm.name+"\" in overlay file has no \"TO\" parameter.")
									elm2.name = elm2NewName
						else:
							if elm.returnType == "DELETE":
								target.remove(elm2)
							else:
								elm2.name = elm.name
			else:
				_continue = False
				for elm2 in target:
					if elm2.name == elm.name:
						elm2.returnType = elm.returnType
						elm2.params = elm.params
						_continue = True
						break
				if _continue:
					continue
				target.append(elm)
		elif type(elm) == Macro:
			if len(elm.contents) > 9:
				if elm.contents[:8] == "#define ":
					for elm2 in target:
						if type(elm2) == Macro:
							if elm2.contents[:7] == "#define ":
								# if same macro name
								if elm.contents.split(' ')[1].split('(')[0] == elm2.contents.split(' ')[1].split('(')[0]:
									elm2.contents = elm.contents
				elif elm.contents[:7] == "#undef ":
					for elm2 in target:
						if type(elm2) == Macro:
							if elm2.contents[:7] == "#define ":
								if elm.contents.split(' ')[1].split('(')[0] == elm2.contents.split(' ')[1].split('(')[0]:
									target.remove(elm2)
		elif type(elm) == Class:
			for elm2 in target:
				if type(elm2) == Class:
					if elm2.name == elm.name:
						elm2.funcs = applyOverlay(elm2.funcs, elm.funcs + elm.enums + elm.variables)
						elm2.variables = applyOverlay(elm2.variables, elm.funcs + elm.enums + elm.variables)
						elm2.enums = applyOverlay(elm2.enums, elm.funcs + elm.enums + elm.variables)

	return target

# file-specific post-processing functions. They are applied after overlay files.
# (there aren't any yet, but you can make them like this: "def corelib_kernel_qobject_h(parsedFile):")

def polishTemplateType(t):
	if '<' in t and '>' in t:
		bracketPart = t[t.find('<') : t.find('>')]
		if '*' in bracketPart or '&' in bracketPart:
			return re.sub('<.*?>', '_ptr_', t)
		else:
			return t.replace('<', '_').replace('>', '_')
	return t

def parseTypedef(file, index):
	index += 8
	while file[index].isspace():
		index += 1
	newType = ""
	while not file[index].isspace():
		newType += file[index]
		index += 1
	while file[index].isspace():
		index += 1
	newName = ""
	while True:
		while not (file[index].isspace() or file[index] == ';'):
			newName += file[index]
			index += 1
		while file[index].isspace():
			index += 1
		if file[index] == ';':
			return index+1, Typedef(newType, newName)
		else:
			newType += ' '+newName
			newName = ""


# converts a string "file" starting form "index" into a tree of classes
# "filename" is used for debugging purposes
def parseFile(filename, file, index = 0):
	file += ' ' * 99 # to prevent index errors while comparing substrings near the end of a file

	# removes templates. TODO: probably create a template class for storing data about them
	oldIndex = int(index)
	try: # Just keep parsing untill index goes out of range. Yeah I know it sucks.
		thisFileLen = len(file)
		while index < thisFileLen:
			if file[index:index+8] == "template":
				templateStartIndex = int(index)
				index += 8
				while file[index].isspace():
					index += 1
				if file[index] == '<':
					openBracketCount = 1
					openBracketIndex = int(index)
					index += 1
					while openBracketCount > 0:
						if file[index] == '<':
							openBracketCount += 1
						elif file[index] == '>':
							openBracketCount -= 1
						index += 1
					file = file[0:templateStartIndex] + file[index:]
			else:
				index += 1
	except Exception:
		pass

	index = oldIndex
	# templates are gone by now

	classes = []
	try:
		while True:
			if index == len(file):
				break
			while file[index].isspace() or file[index] == ';':
				index += 1

			if file[index:index+8] == "typedef ":
				index, newTypeDef = parseTypedef(file, index)
				classes.append(newTypeDef)
				continue
			elif file[index:index+6] == "class ":
				index += 5
				while file[index].isspace():
					index += 1

				# usually C++ attributes
				while file[index] == '#':
					while file[index:index+6] != "#endif":
						index += 1
					index += 6
					while file[index].isspace():
						index += 1

				newClassName = ""
				while (not file[index].isspace()) and (file[index] not in (':', ';', '{')):
					newClassName += file[index]
					index += 1

				while "_EXPORT" in newClassName: # make sure it wasn't Q_bla_EXPORT
					newClassName = ""

					while file[index].isspace():
						index += 1

					while (not file[index].isspace()) and (file[index] not in (':', ';', '{')):
						newClassName += file[index]
						index += 1

				while file[index].isspace():
					index += 1

				if file[index] == ';':
					index += 1
					continue

				derivatives = []
				if file[index] == ":":
					index += 1
					while file[index].isspace():
						index += 1
					while file[index] != '{':
						nextWord = ""
						while (not file[index].isspace()) and file[index] not in ('{', ','):
							nextWord += file[index]
							index += 1
						if nextWord not in ("public", "private", "protected"):
							derivatives.append(nextWord)
						while file[index].isspace() or file[index] == ',':
							index += 1

				classes.append(Class(newClassName))
				for d in derivatives:
					classes[-1].variables.append(Variable(d, "*"+d+"_derivative", True))
				while file[index].isspace():
					index += 1
				if file[index] == '{':
					index += 1
					while file[index].isspace():
						index += 1
				public = False
				signal = False
				# loop through class

				newPropertyIsStatic = False
				newPropertyIsConstepr = False
				macrosBeforeNewProperty = []
				while True:
					if filename == testingFile and testingMode == True:
						print("\n\n\n"+file[index-9:index]+"\033[93m["+file[index]+"]\033[0m"+file[index+1:index+9])
						time.sleep(1)

					while file[index].isspace() or file[index] == ';':
						index += 1

					newPropertyType = ""
					newPropertyName = ""
					newFunc = None

					if (file[index:index+8] == "signals:"
					or file[index:index+10] == "Q_SIGNALS:"
					or file[index:index+17] == "public Q_SIGNALS:"):
						signal = True
						while file[index] != '\n':
							index += 1
						continue

					if file[index:index+4] == "enum":
						index += 4
						while file[index].isspace():
							index += 1

						if file[index] == '#': # TODO
							while file[index] != '\n':
								index += 1
							continue

						newEnumName = ""
						if file[index] != '{':
							while not file[index].isspace():
								newEnumName += file[index]
								index += 1

						newEnum = Enum(newEnumName)
						while file[index].isspace():
							index += 1

						if file[index] == ';':
							index += 1
							continue
						elif file[index] == '{':
							index += 1
							while True:
								while file[index].isspace() or file[index] == ',':
									index += 1
								if file[index] == '}':
									index += 1
									break
								newMemberName = ""
								while not file[index].isspace() and file[index] not in [',', '=']:
									newMemberName += file[index]
									index += 1
								newEnum.memberNames.append(newMemberName)

								while file[index].isspace():
									index += 1
								if file[index] == '=':
									while file[index].isspace():
										index += 1
									newMemberValue = ""
									while not file[index].isspace() and file[index] != ',':
										newMemberValue += file[index]
										index += 1
									newEnum.memberValues.append(newMemberValue)
									index += 1
									continue
								else:
									newEnum.memberValues.append("")
								continue
					elif file[index:index+19+len(newClassName)] == "Q_DECLARE_PRIVATE("+newClassName+")":
						classes[-1].isPrivate = True
						index += 19+len(newClassName)
						continue
					elif file[index:index+2] == "Q_":
						while(file[index] != '\n'):
							index += 1
						continue
					elif file[index] == '#':
						newMacroContents = ''
						while file[index] != '\n':
							newMacroContents += file[index]
							if file[index] == '\\':
								while file[index] != '\n':
									index += 1
							index += 1
						classes[-1].funcs.append(Macro(newMacroContents))
						continue
					elif file[index] == '}':
						index += 3
						break
					elif file[index:index+6] == "public":
						public = True
						index += 7
						continue
					elif file[index:index+7] == "private" or file[index:index+9] == "protected":
						public = False
						while not file[index].isspace():
							index += 1
						continue
					elif (file[index:index+8] == "explicit"
					or file[index:index+7] == "virtual"
					or file[index:index+8] in ("Q_OBJECT", "Q_GADGET")
					or file[index:index+10] == "Q_PROPERTY"
					or file[index:index+6] in ("static", "inline")): # it's going to be inline anyways
						while not file[index].isspace():
							index += 1
						continue
					elif file[index:index+6] == "friend" or file[index:index+8] == "override":
						while file[index] != '\n':
							index += 1
						continue
					elif file[index:index+7] == "mutable":
						index += 7
						continue
					elif file[index:index+8] == "typename":
						while file[index] != ';':
							if file[index] == '{':
								index += 1
								openCurlyBraces = 1
								while openCurlyBraces != 0:
									if file[index] == '{':
										openCurlyBraces += 1
									elif file[index] == '}':
										openCurlyBraces -= 1
									index += 1
								break
							index += 1
						continue
					elif file[index:index+9] == "constexpr":
						newPropertyIsConstexpr = True
						index += 9
						continue
					elif file[index:index+15] == "QT_DEPRECATED_X":
						thisLine = ""
						while file[index] != '\n':
							thisLine += file[index]
							index += 1
						macrosBeforeNewProperty.append(Macro(thisLine))
						continue
					elif file[index:index + len(newClassName)] == newClassName:
						newFunc = Function(newClassName+'*', "new")
						newFunc.isConstructor = True
						index += len(newClassName)
					elif file[index:index + len(newClassName)+1] == '~'+newClassName:
						newFunc = Function("void", "destroy")
						newFunc.isDestructor = True
						classes[-1].funcs.append(newFunc)
						index += len(newClassName)
						while file[index] != '\n':
							index += 1
						continue
					elif file[index] == '{':
						openCurlyBraces = 1
						while openCurlyBraces != 0:
							if file[index] == '{':
								openCurlyBraces += 1
							elif file[index] == '}':
								openCurlyBraces -= 1
							index += 1
					else: # nothing special, so just store a type and name
						while True:
							while not file[index].isspace():
								newPropertyType += file[index]
								index += 1
							if newPropertyType == "static":
								newPropertyIsStatic = True
								index += 1
							elif newPropertyType == "const":
								index += 1
							else:
								break
						while file[index].isspace():
							index += 1
						while not (file[index].isspace() or file[index] in (';', '(')):
							newPropertyName += file[index]
							index += 1
					while file[index].isspace():
						index += 1
					if file[index] == '(': # if this type and name is for a function
						index += 1
						# if the function hasn't been already declared as a (con/de)structor, declare it as an ordinary function
						if newFunc is None:
							newFunc = Function(newPropertyType, newPropertyName)
						newFunc.isSignal = bool(signal)
						newFunc.isStatic = bool(newPropertyIsStatic)
						newFunc.isConstexpr = bool(newPropertyIsConstepr);

						newPropertyIsConstexpr = False
						newPropertyIsStatic = False

						openingBracketIndex = int(index)
						openBracketCount = 1
						while openBracketCount > 0:
							if file[index] == '(':
								openBracketCount += 1
							elif file[index] == ')':
								openBracketCount -= 1
							index += 1
						closingBracketIndex = index - 1

						if openingBracketIndex + 1 != closingBracketIndex:
							params = []
							for param in file[openingBracketIndex:closingBracketIndex].split(","):
								paramParts = [p.strip() for p in param.split(' ')]
								newParamIsConst = False
								if paramParts[0] == "const":
									newParamIsConst = True
								try:
									paramParts.remove('')
								except:
									pass
								try:
									paramParts.remove('const')
								except:
									pass
								if paramParts == []:
									continue
								if len(paramParts) == 1:
									if paramParts[0] != '':
										params.append(Variable(paramParts[0], "", public))
									else:
										break
								elif len(paramParts) > 1:
									params.append(Variable(paramParts[0], paramParts[1], public))
								params[-1].isConst = newParamIsConst

							newFunc.params = params
						if public:
							classes[-1].funcs += macrosBeforeNewProperty
							classes[-1].funcs.append(newFunc)
						macrosBeforeNewProperty = []
						newPropertyName = ""
						newPropertyType = ""
					while file[index].isspace():
						index += 1
					while file[index:index+5] == "const" or file[index:index+8] == "noexcept":
						while not file[index].isspace():
							index += 1
						while file[index].isspace():
							index += 1
					if file[index] == ';':
						index += 1
						continue
					elif file[index] == ':':
						while file[index] != '\n':
							index += 1
						while file[index].isspace():
							index += 1
					# skip "{ ... }" to prepare for next loop
					if file[index] == '{':
						index += 1
						# this algorithm makes sure that curly braces
						# within other curly braces don't break the parser
						openCurlyBraces = 1
						while openCurlyBraces != 0:
							if file[index] == '{':
								openCurlyBraces += 1
							elif file[index] == '}':
								openCurlyBraces -= 1
							index += 1
						while file[index].isspace():
							index += 1
					elif file[index] == '=':
						while file[index] not in (',', ')', ';'):
							index += 1
						index += 1
						continue

					if not newPropertyName == newPropertyType == '':
						classes[-1].variables += macrosBeforeNewProperty
						classes[-1].variables.append(Variable(newPropertyType, newPropertyName, public))
						macrosBeforeNewProperty = []
						if "newVarIsConst" in globals():
							classes[-1].variables[-1].isConst = True
							del newVarIsConst
			elif file[index] == '#':
				newMacroContents = ""
				while index < len(file) and file[index] != '\n':
					newMacroContents += file[index]
					if file[index] == '\\':
						while file[index] != '\n':
							index += 1
						newMacroContents += '\n'
					index += 1
				classes.append(Macro(newMacroContents))
			elif file[index:index+7] == "DELETE ": # for overlay file
				index += 7
				newVarName = ""
				while file[index].isspace():
					index += 1
				while not (file[index].isspace() or file[index] == ';'):
					newVarName += file[index]
					index += 1
				classes.append(Variable("DELETE", newVarName, True))
			else:
				index += 1

	except IndexError as e:
		pass
	except KeyboardInterrupt as e:
		# debug, since the program probably froze in an infinite loop in this case
		print(file[:index]+"\033[93m["+file[index]+"]\033[0m"+file[index+1:]+"\n___________________\n")
		raise e
		exit()
	except Exception as e:
		raise e

	return classes

class Macro:
	def __init__(self, contents):
		self.contents = contents
		self.isDefine = False
		self.isVariable = False
		self.isFunction = False
		while self.contents[1] == ' ':
			self.contents = self.contents[0] + self.contents[2:] # remove spaces in things like "#   define", to make parsing easier
		conentsSplit = self.contents.split(' ')
		if "define" in self.contents:
			self.isDefine = True
		if len(conentsSplit) > 3:
			if conentsSplit[0] == "#define":
				if '(' in conentsSplit[1]:
					self.isFunction = True
					secondBracketIndex = contents.find(")")
					if secondBracketIndex != -1:
						self.params = []
						paramsSubStr = contents[contents.find('('): secondBracketIndex]
						for p in paramsSubStr.split(','):
							self.params.append(p.strip())
				else:
					self.isVariable = True

	def polishList(a):
		aOriginalLen = len(a)
		i = 1
		j = int(aOriginalLen)
		while i < j:
			if type(a[i]) == type(a[i-1]) == Macro:
				if a[i].contents[:6] == "#endif" and a[i-1].contents[:3] == "#if":
					a.pop(i)
					a.pop(i-1)
					j -= 2
					i -= 1
			i += 1
		if j != aOriginalLen:
			Macro.polishList(a)
	def polish(self):
		pass

class Variable:
	def __init__(self, type, name, isPublic):
		self.type = type
		self.wrapperType = None
		self.name = name
		self.isPublic = isPublic
		self.isConst = False
		self.funcPtr = False
	def __str__(self):
		if self.funcPtr:
			return self.type
		else:
			return self.type +' '+ self.name
	def polish(self):
		if typeMap.get(self.type) != None:
			if typeMap.get(self.type)[1] in (1, 12):
				if typeMap.get(self.type)[1] == 12:
					self.type = typeMap.get(self.type)[0]
					self.wrapperType = self.type
				else:
					self.type = typeMap.get(self.type)[0]
			elif typeMap.get(self.type)[1] == 2:
				self.wrapperType = typeMap.get(self.type)[0]
		self.type = self.type.replace('::', '_')
		self.type = self.type.replace('&', '*')
		self.name = self.name.replace('&', '*')
		self.type = polishTemplateType(self.type)
		if self.wrapperType == None:
			self.wrapperType = self.type

class Function:
	def __init__(self, returnType, name):
		self.name = name
		self.wrapperName = self.name
		self.returnType = returnType
		self.wrapperReturnType = None
		self.params = []
		self.isConstructor = False
		self.isDestructor = False
		self.isConst = False
		self.isSignal = False
		self.isStatic = False # C++ member function static, not C "single-file" static
	def polish(self):
		self.returnType = self.returnType.replace('::', '_')
		self.returnType = self.returnType.replace('&', '*')
		self.name = self.name.replace('&', '*')
		for p in self.params:
			p.polish()
			Macro.polishList(self.params)
		if typeMap.get(self.returnType) != None:
			if typeMap.get(self.returnType)[1] in (1, 12):
				if typeMap.get(self.returnType)[1] == 12:
					self.returnType = typeMap.get(self.returnType)[0]
					self.wrapperReturnType = self.returnType
				else:
					self.returnType = typeMap.get(self.returnType)[0]
			elif typeMap.get(self.returnType)[1] == 2:
				self.wrapperReturnType = typeMap.get(self.returnType)[1]
		self.returnType = polishTemplateType(self.returnType)
		if self.wrapperReturnType == None:
			self.wrapperReturnType == self.returnType

class Enum:
	def __init__(self, name):
		self.name = name
		self.memberNames = []
		self.memberValues = []
	def polish(self):
		self.memberValues = self.memberValues.replace('::', '_')

class Typedef:
	def __init__(self, type = "", name = ""):
		self.type = type
		self.name = name
		self.isPrivate = False
	def polish(self):
		if typeMap.get(self.type) != None:
			if typeMap.get(self.type)[1] in (1, 12):
				if typeMap.get(self.type)[1] == 12:
					self.type = typeMap.get(self.type)[0]
					self.wrapperType = self.type
				else:
					self.type = typeMap.get(self.type)[0]
			elif typeMap.get(self.type)[1] == 2:
				self.wrapperType = typeMap.get(self.type)[0]
		self.type = polishTemplateType(self.type)

class Class:
	def __init__(self, name = ""):
		self.enums = []
		self.name = name
		self.funcs = [] # private variables not added
		self.variables = []
		self.isPrivate = False
	def polish(self):
		Macro.polishList(self.variables)
		Macro.polishList(self.funcs)
		for v in self.variables:
			v.polish()
		for f in self.funcs:
			f.polish()

# untangles overloaded functions
class Mixer:
	# takes a list of overloaded functions with the same parameter count
	def mixParamTypes(self, targets):
		for i in range(len(targets[0].params)):
			wantedType = targets[0].params[i].type
			foundDifference = False
			for t in targets:
				if t.params[i].type != wantedType:
					foundDifference = True
					break

			if foundDifference:
				sortedFuncs = {}
				for t in targets:
					if t.params[i].type not in sortedFuncs.keys():
						sortedFuncs[t.params[i].type] = []
					sortedFuncs[t.params[i].type].append(t)

				macroFuncParams = (', '.join([j.type.replace(' ', '_').replace("*", "_PTR_").replace("&", "_REF_")+"_param" for j in targets[0].params]))[:-2]
				self.contents += "#define "+targets[0].name+'('+macroFuncParams+')'
				self.contents += "_Generic(("+targets[0].params[i].type.replace(' ', '_').replace("*", "_PTR_").replace("&", "_REF_")+"), \\\n"
				for flist in sortedFuncs.values():
					self.contents += flist[0].params[i].type + ": " + flist[0].name+"_"+flist[0].params[i].type + ", \\\n"
				self.contents += ")("+macroFuncParams+')\n'

				for j in range(len(sortedFuncs.values())):
					for func in sortedFuncs[list(sortedFuncs.keys())[j]]:
						func.wrapperName += '_'+chr(ord('a') + j)
				for j in sortedFuncs.values():
					Mixer.mixParamTypes(self, j)

	# takes a list of overloaded functions
	def __init__(self, targets):
		self.contents = ""

		functionsByParamCounts = {}
		for t in targets:
			if len(t.params) not in functionsByParamCounts.keys():
				functionsByParamCounts[len(t.params)] = []
			functionsByParamCounts[len(t.params)].append(t)

		if len(functionsByParamCounts) == 1:
			Mixer.mixParamTypes(self, targets)
		else:
			for k in functionsByParamCounts.keys():
				for f in functionsByParamCounts[k]:
					f.wrapperName += str(k)
				Mixer.mixParamTypes(self, functionsByParamCounts[k])
			self.contents += "#define "+targets[0].name+"(...) QTC_COUNT_VA_ARGS("+targets[0].name+", __VA_ARGS__)\n"


def bindFile(filename):
	if filename[-4:] == "_p.h":
		return
	infile = open(filename, "r")

	outHeaderName = filename.replace(inputDir, outputDir)
	os.makedirs(os.path.dirname(outHeaderName), exist_ok=True)
	outheader = open(outHeaderName, "w")
	outsource = open(outHeaderName.replace(".h", ".cpp"), "w")

	### PARSE INPUT ###
	if testingMode:
		print("started "+filename+"... ", end='')

	file = infile.read();

	if "This file is not part of the Qt API" in file:
		sayResult(filename, " Skipped (1)")
		return

	# remove comments (https://stackoverflow.com/a/241329/13721385)
	file = re.sub('//.*?\n|/\*.*?\*/', '\n', file, flags=re.S)

	file = re.sub('\[\[.*?\]\]|noexcept|Q_DISABLE_COPY\(.*?\)' +
	'|Q_PROPERTY\(.*?\)|QDOC_PROPERTY\(.*?\)|override|Q_INVOKABLE' +
	"|QT_MOVE_ASSIGNMENT_OPERATOR_IMPL_VIA_MOVE_AND_SWAP\(.*?\)" +
	"|QT_MOVE_ASSIGNMENT_OPERATOR_IMPL_VIA_PURE_SWAP\(.*?\)", '', file, flags=re.S)

	file = re.sub('QT_HAS_CPP_ATTRIBUTE\(.*?\)|__cplusplus', '0', file, flags=re.S)

	file = re.sub('\) const', '\)', file, flags=re.S)

	# get input from inputDir, add overlay from overlayDir
	fileParsed = parseFile(filename, file)

	overlayFile = None
	try:
		overlayFile = open(filename.replace(inputDir, overlayDir))
	except:
		pass
	else:
		fileParsed = applyOverlay(fileParsed, parseFile(filename.replace(inputDir, overlayDir), overlayFile.read()))

	postProcessFunctionName = filename[len(inputDir):-2].replace('\\', '_').replace('/', '_').replace(' ', '_') + "_h"
	if postProcessFunctionName in globals():
		exec(postProcessFunctionName + "(fileParsed)")


	# write output to outputDir

	outsource.write("#include <"+outHeaderName+">\n")

	for c in fileParsed:
		c.polish()
		if type(c) is Macro:
			outheader.write(c.contents+'\n')
			outsource.write(c.contents+'\n')
			continue
		elif type(c) is Variable:
			continue
		elif type(c) is Typedef:
			outheader.write("\ntypedef "+c.type+" "+c.name+';\n')
			continue

		# class (typedef struct) declarations
		if c.isPrivate:
			outheader.write("\nstruct {void *ptr;} "+c.name+";\ntypedef void* "+c.name+";\n#define sizeof_"+c.name+" PRIVATE\n")
		else:
			outheader.write("\ntypedef struct "+c.name+' '+c.name+";\n")
			if c.variables != []:
				outheader.write("\nstruct "+c.name+" {\n")
				for var in c.variables:
					outheader.write("\t" + str(var) + ";\n")
				outheader.write("};\n")

		memberFuncsByName = {}
		for f in c.funcs:
			if type(f) == Class:
				if f.name not in memberFuncsByName.keys():
					memberFuncsByName[f.name] = []
				memberFuncsByName[f.name].append(f)
		for flist in memberFuncsByName.values():
			print(flist)
			outheader.write(Mixer(flist).contents+'\n')
		# functions
		for f in c.funcs:
			if type(f) == Macro:
				outheader.write(f.contents+'\n')
				outsource.write(f.contents+'\n')
				continue

			elif f.isSignal:
				outheader.write("void *"+c.name+'_'+f.name+'_signal;\n')
				outsource.write("extern \"C\" const auto "+c.name+'_'+f.name+"_signal = &"+c.name+'::'+f.name+';\n')
			else:
				if not (f.isConstructor or f.isDestructor):
					outheader.write("\nvoid *"+c.name+'_'+f.name+'_addr;\n')
					outsource.write("extern \"C\" const auto "+c.name+'_'+f.name+"_addr = &"+c.name+'::'+f.name+';\n')
				else:
					outheader.write('\n')

				f.params.insert(0, Variable(c.name, "*THIS", True))

				newDeclaration = f"inline {f.returnType} {c.name}_{f.name}({', '.join([str(v) for v in f.params]).strip()})"
				if f.isConst:
					newDeclaration = "const " + newDeclaration
				for p in f.params:
					i = 0
					if p.name == '':
						p.name = "unnamed"+str(i)
						i += 1
				newDeclarationWithParamNames = f"{f.returnType} {c.name}_{f.name}({', '.join([str(v) for v in f.params]).strip()})"

				functionCall = ""
				if f.isConstructor:
					functionCall = "*THIS = " + c.name
				elif f.isDestructor:
					functionCall = "delete THIS"
				else:
					if f.returnType != "void":
						functionCall = "return "
					if f.isStatic:
						functionCall += c.name+"::"+f.name
					else:
						functionCall += "THIS->"+f.name


				# turn array to string but replace "[]" with "()", leave out "THIS" unless static, and don't include param types. Used in the body of wrapper functions.
				paramsWithoutTypes = ""
				if not f.isDestructor:
					paramsWithoutTypes = '(' + ', '.join([v.name.replace('&', '').replace('*', '') for v in f.params[1:]]).strip() + ')'

				outsource.write('extern "C" '+newDeclarationWithParamNames + "{\n\t" + functionCall + paramsWithoutTypes + ";\n}\n")
				outheader.write(newDeclaration + ";\n")

				if f.isConstructor:
					outheader.write("inline "+c.name+" *new_"+c.name+', '.join([str(v) for v in f.params]).strip()+'{'+c.name)

	if testingMode:
		sayResult(filename, "        done!")
	else:
		print("finished "+filename)

try:
	from multiprocessing.pool import ThreadPool
except ModuleNotFoundError:
	print("WARNING: Python multiprocessing.pool module not found. Parsing will be done on one thread.")
	testingMode = True


global inputDirLength
inputDirLength = len(inputDir)

blacklist = ("corelib/text/qbytearrayalgorithms", "corelib/text/qanystringview", "corelib/text/qstringbuilder")

if testingMode:
	for filename in glob.iglob(inputDir+"**/*.h", recursive=True):
		if inputDir+'3rdparty' not in filename and inputDir+'tools' not in filename and filename[len(inputDir):-2] not in blacklist:
			bindFile(filename)

else:
	binders = ThreadPool()

	for filename in glob.iglob(inputDir+"**/*.h", recursive=True):
		if inputDir+'3rdparty' not in filename and inputDir+'tools' not in filename and filename[len(inputDir):-2] not in blacklist:
			binders.apply_async(bindFile, [filename])

	binders.close()
	binders.join()
