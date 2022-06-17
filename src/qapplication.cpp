#include <QtWidgets/qtwidgetsglobal.h>
#include <QtCore/qcoreapplication.h>
#include <QtGui/qwindowdefs.h>
#include <QtCore/qpoint.h>
#include <QtCore/qsize.h>
#include <QtGui/qcursor.h>
#include <QtGui/qguiapplication.h>
#include <QApplication>
#include <qpointer.h>

extern "C" {

QApplication *qtc_QApplication_new(int &argc, char **argv)
{
	return new QApplication(argc, argv);
}

void QApplication_destroy(QApplication *app)
{
	delete app;
}

void QApplication_setCursorFlashTime(QApplication *app, int t)
{
	app->setCursorFlashTime(t);
}

int QApplication_cursorFlashTime(QApplication *app)
{
	return app->cursorFlashTime();
}

#if QT_CONFIG(wheelevent)

void QApplication_setWheelScrollLines(QApplication *app, int l)
{
	app->setWheelScrollLines(l);
}

int QApplication_wheelScrollLines(QApplication *app)
{
	return app->wheelScrollLines();
}

#endif

void QApplication_setStartDragTime(QApplication *app, int ms)
{
	app->setStartDragTime(ms);
}

int QApplication_startDragTime(QApplication *app)
{
	return app->startDragTime();
}

void QApplication_setStartDragDistance(QApplication *app, int l)
{
	app->setStartDragDistance(l);
}

int QApplication_startDragDistance(QApplication *app)
{
	return app->startDragDistance();
}
	
int QApplication_exec(QApplication *app){
	return app->exec();
}

QCoreApplication *a(int &argc, char **argv)
{
	return new QCoreApplication(argc, argv);
}

int QCoreApplication_exec(QCoreApplication *app){
	return app->exec();
}

}
