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
