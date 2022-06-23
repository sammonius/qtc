#pragma once

#ifndef __cplusplus
typedef void* QToolBar;
#endif

#include <qtc/qwidget.h>
#include <qtc/qstring.h>
#include <qtc/qt.h>
#include <qtc/qaction.h>
#include <qtc/qpoint.h>
#include <qtc/qsize.h>
#include <qtc/private_optargs.h>

#define QToolBar_new(...) QTC_OPTARG_REGISTER(QToolBar_new, __VA_ARGS__)
#define QToolBar_new1(A) _Generic((A), QString: QToolBar_new_title, QWidget: QToolBar_new_parent)(A)
inline QToolBar QToolBar_new0();
inline QToolBar QToolBar_new_title(QString title);
inline QToolBar QToolBar_new_parent(QWidget parent);
inline QToolBar QToolBar_new2(QString title, QWidget parent);
inline void QToolBar_destroy(QToolBar bar);

inline Qt_ToolBarAreas QToolBar_allowedAreas(QToolBar bar);
inline void QToolBar_setAllowedAreas(QToolBar bar, Qt_ToolBarAreas areas);

inline bool QToolBar_isFloatable(QToolBar bar);
inline void QToolBar_setFloatable(QToolBar bar, bool floatable);

inline bool QToolBar_isFloating(QToolBar bar);

inline QSize QToolBar_iconSize(QToolBar bar);
inline void QToolBar_setIconSize(QToolBar bar, QSize size);

inline bool QToolBar_isMovable(QToolBar bar);
inline void QToolBar_setMovable(QToolBar bar, bool movable);

inline Qt_Orientation QToolBar_orientation(QToolBar bar);
inline void QToolBar_setOrientation(QToolBar bar, Qt_Orientation orientation);

inline Qt_ToolButtonStyle QToolBar_toolButtonStyle(QToolBar bar);
inline void QToolBar_setToolButtonStyle(QToolBar bar, Qt_ToolButtonStyle toolButtonStyle);

#define QToolBar_actionAt(...) QTC_OPTARG_REGISTER(QToolBar_actionAt, __VA_ARGS__)
inline QAction QToolBar_actionAt2(QToolBar bar, QPoint point);
inline QAction QToolBar_actionAt3(QToolBar bar, int x, int y);

inline QAction QToolBar_addSeparator(QToolBar bar);
inline QAction QToolBar_addWidget(QToolBar bar, QWidget widget);
inline void QToolBar_clear(QToolBar bar);

inline QAction QToolBar_insertSeparator(QToolBar bar, QAction before);
inline QAction QToolBar_insertWidget(QToolBar bar, QAction before, QWidget widget);
inline bool QToolBar_isAreaAllowed(QToolBar bar, Qt_ToolBarArea area);

inline QAction QToolBar_toggleViewAction(QToolBar bar);
inline QWidget QToolBar_widgetForAction(QToolBar bar, QAction action);

inline void QToolBar_actionTriggered(QAction action);
inline void QToolBar_allowedAreasChanged(Qt_ToolBarAreas allowedAreas);
