#pragma once
#include <qtc/qglobal.h>

#ifndef __cplusplus
typedef unsigned char QApplication;
typedef unsigned char QCoreApplication;
#endif

QApplication QApplication_new(int *argc, char **argv);
void QApplication_destroy(QApplication *app);

void QApplication_setCursorFlashTime(QApplication *app, int t);
int QApplication_cursorFlashTime(QApplication *app);

//#if QT_CONFIG(wheelevent)

void QApplication_setWheelScrollLines(QApplication *app, int l);
int QApplication_wheelScrollLines(QApplication *app);

//#endif

void QApplication_setStartDragTime(QApplication *app, int ms);
int QApplication_startDragTime(QApplication *app);

void QApplication_setStartDragDistance(QApplication *app, int l);
int QApplication_startDragDistance(QApplication *app);

int QApplication_exec(QApplication *app);

QCoreApplication *a();
int QCoreApplication_exec(QCoreApplication *app);
