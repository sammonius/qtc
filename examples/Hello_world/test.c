#include <qtc/qapplication.h>
#include <qtc/qpushbutton.h>
#include <stddef.h>
#include <stdio.h>
#include <qtc/qstring.h>
#include <qtc/qicon.h>

int main(int argc, char **argv)
{
	QApplication app = QApplication_new(&argc, argv);
	
	QPushButton btn = QPushButton_new(NULL, QString_new("Hello, world!"), NULL);
	QWidget_show(btn);
	
	return QApplication_exec(&app);
}
