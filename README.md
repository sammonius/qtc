# qtc
A far from complete C interface for Qt.

## compiling
To compile qtc, you can just run the install.sh file.
```sudo sh install.sh``` should do the trick.

## usage
Documentation is coming soon, but be sure to check the
examples folder. Generally, the syntax is equal to the
syntax of Qt in c++, with minor changes:

		QPushButton btn = new QPushButton("hello"); // C++
		QPushButton btn = QPushButton_new(NULL, "hello", NULL); /* C */
		
		btn.show() // C++
		QPushButton_show(btn); /* C */

To compile an app that uses qtc:
1. run ```qmake -project``` as usual
2. open the resulting .pro file and add ```LIBS += qtc```
3. run ```qmake``` followed by ```make```
