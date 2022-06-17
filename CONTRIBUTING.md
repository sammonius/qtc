If you're new to git, you may want to use github client to contribute changes
https://github.com/shiftkey/desktop/releases

To make a new widget:
 1. make widgetname.cpp in the src folder
 2. make widgetname.h 
 3. find the widget in https://github.com/qt/qtbase/tree/dev/src/widgets/widgets
 4. copy the widget functions to the 2 new files using other files beside them as a referance
 6. run ```sudo sh install.sh``` to compile and install the library with your new code
 7. edit a program in the examples folder to include<widgetname.h> and test your functions
 8. once it works, commit it to the github repo
