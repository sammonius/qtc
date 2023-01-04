#pragma once

#ifndef __cplusplus
typedef void* QMdiArea;
#endif

#include <qtc/private_optargs.h>
#include <qtc/qwidget.h>
#include <qtc/qbrush.h>
#include <qtc/qtabwidget.h>
#include <qtc/qmdisubwindow.h>
#include <qtc/qt.h>

typedef enum QMdiArea_AreaOption {
	QMdiArea_DontMaximizeSubWindowOnActivation = 0x1
} QMdiArea_AreaOption;

typedef typeof(QMdiArea_DontMaximizeSubWindowOnActivation) QMdiArea_AreaOptions;

typedef enum QMdiArea_ViewMode {
	QMdiArea_SubWindowView = 0,
	QMdiArea_TabbedView = 1
} QMdiArea_ViewMode;

typedef enum QMdiArea_WindowOrder {
	QMdiArea_CreationOrder = 0,
	QMdiArea_StackingOrder = 1,
	QMdiArea_ActivationHistoryOrder = 2
} QMdiArea_WindowOrder;

#define QMdiArea_new(...) QTC_OPTARG_REGISTER(QMdiArea_new, __VA_ARGS__)

static inline QMdiArea QMdiArea_new1(QWidget parent);
static inline QMdiArea QMdiArea_new0();
static inline void QMdiArea_destroy(QMdiArea area);

static inline QMdiArea_WindowOrder QMdiArea_activationOrder(QMdiArea area);
static inline void QMdiArea_setActivationOrder(QMdiArea area, QMdiArea_WindowOrder order);

//QBrush QMdiArea_background(QMdiArea area);
//void QMdiArea_setBackground(QMdiArea area, QBrush brush);

static inline bool QMdiArea_documentMode(QMdiArea area);
static inline void QMdiArea_setDocumentMode(QMdiArea area, bool enabled);

static inline QTabWidget_TabPosition QMdiArea_tabPosition(QMdiArea area);
static inline void QMdiArea_setTabPosition(QMdiArea area, QTabWidget_TabPosition position);

static inline QTabWidget_TabShape QMdiArea_tabShape(QMdiArea area);
static inline void QMdiArea_setTabShape(QMdiArea area, QTabWidget_TabShape shape);

static inline bool QMdiArea_tabsMovable(QMdiArea area);
static inline void QMdiArea_setTabsMovable(QMdiArea area, bool movable);

static inline QMdiArea_ViewMode QMdiArea_viewMode(QMdiArea area);
static inline void QMdiArea_setViewMode(QMdiArea area, QMdiArea_ViewMode mode);

static inline void QMdiArea_activateNextSubWindow(QMdiArea area);
static inline void QMdiArea_activatePreviousSubWindow(QMdiArea area);
static inline void QMdiArea_cascadeSubWindows(QMdiArea area);
static inline void QMdiArea_closeActiveSubWindow(QMdiArea area);
static inline void QMdiArea_closeAllSubWindows(QMdiArea area);
static inline void QMdiArea_setActiveSubWindows(QMdiArea area, QMdiSubWindow window);
static inline void QMdiArea_setupViewport(QMdiArea area, QWidget viewport);
static inline void QMdiArea_tileSubWindows(QMdiArea area);
static inline QMdiSubWindow QMdiArea_activeSubWindow(QMdiArea area);
#define QMdiArea_addSubWindow(...) QTC_OPTARG_REGISTER(QMdiArea_addSubWindow, __VA_ARGS__)
static inline QMdiSubWindow QMdiArea_addSubWindow3(QMdiArea area, QWidget widget, Qt_WindowFlags flags);
static inline QMdiSubWindow QMdiArea_addSubWindow2(QMdiArea area, QWidget widget);
static inline void QMdiArea_removeSubWindow(QMdiArea area, QWidget widget);
#define QMdiArea_setOption(...) QTC_OPTARG_REGISTER(QMdiArea_setOption, __VA_ARGS__)
static inline void QMdiArea_setOption2(QMdiArea area, QMdiArea_AreaOption option, bool on);
static inline void QMdiArea_setOption1(QMdiArea area, QMdiArea_AreaOption option);
static inline bool QMdiArea_testOption(QMdiArea area, QMdiArea_AreaOption option);

//static inline void(*QMdiArea_subWindowActivated)(QMdiSubWindow);
