(This project is abandoned since I just realized it's extremely easy to use C++ code in C and vice verca)

# qtc
A far from complete C interface for Qt.

## compiling
To compile qtc, you can just run the install.sh file.
```sudo sh install.sh``` should do the trick.

## usage
Documentation is coming soon, but be sure to check the
examples folder. Generally, the syntax is equal to the
syntax of Qt in c++, with minor changes:

	#include <qtc/qapplication.h>
	#include <qtc/qlabel.h>
	#include <qtc/qwidget.h>
	#include <qtc/qt.h>
	#include <qtc/qstring.h>

	int main(int argc, char** argv){
		QApplication app = QApplication_new(argc, argv);
		QLabel mylabel = QLabel_new(QString_new("Hello there!"));

		QLabel_setAlignment(mylabel, Qt_AlignCenter);

		QWidget_show(mylabel);
		QApplication_exec(app);
	}

To compile an app that uses qtc:
1. run ```qmake -project``` as usual
2. open the resulting .pro file and add ```LIBS += -lqtc```
3. run ```qmake && make```

#### 2022, June 15, Wednsday update: THIS PROJECT IS NOT DEAD!
I've been working on a python script that automatically generates all the bindings by parsing a text file called ```bindings.txt```. Over the past month, I've been copying functions from the qt docs and source code into the file and it's almost finished. Once it's done (hopefully very soon), I'll publish the generated code to this repo, and the binder file/script to a subfolder in the repo (which may be a hidden file, still not sure).
_____
June 17 update: the script was a terrible idea, but the bindings file will make a good reference to write the code manually. Still planning on finishing most of this project soon.
