### This project is long dead. Sorry to dissappoint :(

# qtc
A work-in-progress C interface for Qt.

(**NOTE**: Development of this is frozen for now. I'm hoping to eventually make a script that generates declarations of the mangled names of Qt's C++ functions for different ABI's, and generate macros that define their actual names as their mangled names. I'm working on other projects for now though but hopefully this is done soon. I'm just kinda sick of unsuccessfully messing with C++ and python scripts so I've been working on other projects for now. The data below should still apply once this script is finished, but I'll change it as necessary once that actually happens)

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

## Contributing
Before contributing new files, it's best to take a look at the
existing ones to see how things are done. An important part is
the use of the ```QTC_OPTARG_REGISTER``` macro to simulate function
overloading.

The script ```qtc.py``` is helpful for writing new contributions.
When placed inside the directory of a qt module (like qtbase) and run
with ```python3 qtc.py``` , it will generate wrappers by reading from
the header files in ```src``` and output them in ```c_src```. The
output files will need lots of tweaking (header names, OPTARGS, private
parameters, rewriting things that should be inline/constexpr) before they
can be used, but it's helpful for a lot of the time-consuming tasks.
The code within the script itself is a bit of a mess though.
