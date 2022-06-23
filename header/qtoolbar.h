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
static inline QToolBar QToolBar_new0();
static inline QToolBar QToolBar_new_title(QString title);
static inline QToolBar QToolBar_new_parent(QWidget parent);
static inline QToolBar QToolBar_new2(QString title, QWidget parent);
static inline void QToolBar_destroy(QToolBar bar);

static inline Qt_ToolBarAreas QToolBar_allowedAreas(QToolBar bar);
static inline void QToolBar_setAllowedAreas(QToolBar bar, Qt_ToolBarAreas areas);

static inline bool QToolBar_isFloatable(QToolBar bar);
static inline void QToolBar_setFloatable(QToolBar bar, bool floatable);

static inline bool QToolBar_isFloating(QToolBar bar);

static inline QSize QToolBar_iconSize(QToolBar bar);
static inline void QToolBar_setIconSize(QToolBar bar, QSize size);

static inline bool QToolBar_isMovable(QToolBar bar);
static inline void QToolBar_setMovable(QToolBar bar, bool movable);

static inline Qt_Orientation QToolBar_orientation(QToolBar bar);
static inline void QToolBar_setOrientation(QToolBar bar, Qt_Orientation orientation);

static inline Qt_ToolButtonStyle QToolBar_toolButtonStyle(QToolBar bar);
static inline void QToolBar_setToolButtonStyle(QToolBar bar, Qt_ToolButtonStyle toolButtonStyle);

#define QToolBar_actionAt(...) QTC_OPTARG_REGISTER(QToolBar_actionAt, __VA_ARGS__)
static inline QAction QToolBar_actionAt2(QToolBar bar, QPoint point);
static inline QAction QToolBar_actionAt3(QToolBar bar, int x, int y);

static inline QAction QToolBar_addSeparator(QToolBar bar);
static inline QAction QToolBar_addWidget(QToolBar bar, QWidget widget);
static inline void QToolBar_clear(QToolBar bar);

static inline QAction QToolBar_insertSeparator(QToolBar bar, QAction before);
static inline QAction QToolBar_insertWidget(QToolBar bar, QAction before, QWidget widget);
static inline bool QToolBar_isAreaAllowed(QToolBar bar, Qt_ToolBarArea area);

static inline QAction QToolBar_toggleViewAction(QToolBar bar);
static inline QWidget QToolBar_widgetForAction(QToolBar bar, QAction action);

static inline void QToolBar_actionTriggered(QAction action);
static inline void QToolBar_allowedAreasChanged(Qt_ToolBarAreas allowedAreas);
