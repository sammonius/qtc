#pragma once
#include <qtc/qt.h>

#ifndef __cplusplus
typedef unsigned char QApplication;
typedef unsigned char QCoreApplication;
#endif

#define QApplication_new(argc, argv) qtc_QApplication_new(&argc, argv)
inline QApplication qtc_QApplication_new(int *argc, char **argv);
inline void QApplication_destroy(QApplication app);

inline void QApplication_setCursorFlashTime(QApplication app, int t);
inline int QApplication_cursorFlashTime(QApplication app);

//#if QT_CONFIG(wheelevent)

inline void QApplication_setWheelScrollLines(QApplication app, int l);
inline int QApplication_wheelScrollLines(QApplication app);

//#endif

inline void QApplication_setStartDragTime(QApplication app, int ms);
inline int QApplication_startDragTime(QApplication app);

inline void QApplication_setStartDragDistance(QApplication app, int l);
inline int QApplication_startDragDistance(QApplication app);

inline int QApplication_exec(QApplication app);

//QCoreApplication *a();
//int QCoreApplication_exec(QCoreApplication app);
