# Introduction

Contributing is usually quite easy. First, you need to find a class on the Qt
online docs or source code, and create *classname*.cpp in ./src and
*classname*.h in ./header. You will first want to create the header file,
because then you can copy its contents to the cpp file with minor modifications,
and add code after the function declarations to turn them into definitions.

For this example, we'll use the QCheckBox class. Remember to look at classes
that are already implemented for reference if you ever get confused. If you go
to to [the QCheckbox reference](https://doc.qt.io/qt-6/qcheckbox.html), you will
see that the class has 2 constructors, (0 enums,) 7 functions, and 1 Qt signal.

# Header

The first step is to add ```#pragma once``` and define the type (if one exists).

	#pragma once
	
	#ifndef __cplusplus
	typedef void* QCheckBox;
	#endif

Most types will be a ```void*``` pointer, but the exception is for types such as
QMargins, QSize, and QPoint. This is because allocating these kinds of types
outside of scope will lead to either memory leaks or having to free them one by
one. 

Next we add the "includes". The most common ones are QString and QWidget.

	#include <qtc/qstring.h>
	#include <qtc/qwidget.h>
	...
	
The reason the headers come after the typedef is because it prevents an error
from occuring in case of header loops. The way the error works is that:
 1. header A includes header B so that it can use typedef B in it's functions.
 2. header B happens to include header A again so the compiler circles back.
 3. header B finds undefined use of typedef B in header A, so we get a compile 
 error.

Defining the type before including other headers prevents this error from
happening.

After the headers are included, we add the constructors. QCheckBox has 4
possible constructors:
	
	new QCheckBox();
	new QCheckBox(QWidget *parent);
	new QCheckBox(QString *text);
	new QCheckBox(QString *text, QWidget *parent);

We can simulate the C++ optional parameters/multiple definitions feature by
using a macro called QTC_OPTARG_REGISTER (which I know I could have named a bit
better). The function is defined in ```<qtc/private_optargs.h>```. It works by
separating the function based on the amount of arguments passed to it. For
our checkbox example, we would do:

	#include <qtc/private_optargs.h>
	#define QCheckBox_new(...) QTC_OPTARG_REGISTER(QCheckBox_new, __VA_ARGS__)
	
The and we can use it like this:

	QCheckBox_new();         // this becomes QCheckBox_new0();
	QCheckBox_new(frame);    // this becomes QCheckBox_new1(frame);

At this point, we could declare the functions ```QCheckbox_new0()``` and
```QCheckBox_new2(QString text, QWidget parent);```, but we run into the problem
that our 2 other declarations both have 1 parameter each. This can be solved by
defining ```QCheckBox_new1``` as another macro, this time with a constant number
of parameters. This macro will use the _Generic keyword to call a function based
on the parameter type of the first parameter (in other scenarios, it will not
allways be the first parameter).

	// NOTE: multiple lines are added to make example readable.
	
	#define QCheckBox_new1(A) _Generic((A), \
	QString: QCheckBox_new_text,
	QWidget: QCheckBox_new_parent)(A)

With these 2 macros, we can now declare our 4 initializers, which can all be
accessed seamlessly by using ```QCheckBox_new(...)```.

	QCheckBox QCheckBox_new0();
	QCheckBox QCheckBox_new_text(QString text);
	QCheckBox QCheckBox_new_parent(QWidget parent);
	QCheckBox QCheckBox_new2(QString text, QWidget parent);

Now we can move on to the functions. This step is pretty simple, so we will skip
it in this example. You may want to view the source code for qcheckbox.h if you
would still like a quick summary of how functions would be declared.

( *This example had no enums to demonstrate, but if there were any, they would
be defined above the constructors and their values would be identical to those
of the C++ enums that they mirror. A QFlags would be created using ```typedef
[enumname] enumFlags```. Take a look at the ```<qtc/qt.h>``` for an example of
enums and QFlags* )

Now that we have finished our header, we can save a copy of it in ./src with the
file extention set to .cpp to use as a template for our code. After saving the
copy, go back to the header and add "```inline```" at the start of each function
declaration. (this was only not done earlier so that you wouldn't have to undo
it in the C++ copy).

# C++ 

Now you should be in a file called src/qcheckbox.cpp. Delete the ```pragma```
and ```typedef``` at the start of the file, as well as any enums or ```optarg```
or ```_Generic``` macros. Then, add ```#include <QCheckBox>``` at the top of
the file, and enclose the functions with ```extern "C" {FUNCTIONS}```. Finally,
change the parameters and return types of the functions to pointers/references
where necessary. If you are unsure weather a specific class should be a pointer
or not, use other files in the /src directory to help you or add an issue on
github.

The last step of making a widget is defining the functions. The constructors are
defined like this:

	QCheckBox *QCheckBox_new0(){return new QCheckBox();}
	QCheckBox *QCheckBox_new0(QWidget *parent){return new QCheckBox(parent);}

I forgot to mention this in the header section, but any class with a constructor
also has a destructor:

	void QCheckBox_destroy(QCheckBox *checkbox){delete checkbox;}

Finnally, functions are defined like this:

	bool QCheckBox_isTristate(QCheckBox *checkbox){return checkbox->isTristate();}
	void QCheckBox_setTristate(QCheckBox *checkbox, bool tristate){checkbox->setTristate(tristate);}
	
# Submitting changes

Now run the install.sh script as root, and create a small test program in the
/examples folder to test your new class.

	#include <qtc/qcheckbox.h>
	#include <qtc/qapplication.h>
	#include <qtc/qwidget.h>
	
	int main(int argc, char** argv){
		QApplication app = QApplication_new(argc, argv);
		QWidget_show(QCheckBox_new());
		QApplication_exec(app);
	}

Then compile and run your example, and if it works, you can add your name to the
CREDITS file and submit your pull request. (To be clear, don't submit your own
copy of the checkbox class. Make a class that has not been done and submit that)

***The end***