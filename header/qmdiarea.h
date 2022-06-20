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

inline QMdiArea QMdiArea_new1(QWidget parent);
inline QMdiArea QMdiArea_new0();
inline void QMdiArea_destroy(QMdiArea area);

inline QMdiArea_WindowOrder QMdiArea_activationOrder(QMdiArea area);
inline void QMdiArea_setActivationOrder(QMdiArea area, QMdiArea_WindowOrder order);

//QBrush QMdiArea_background(QMdiArea area);
//void QMdiArea_setBackground(QMdiArea area, QBrush brush);

inline bool QMdiArea_documentMode(QMdiArea area);
inline void QMdiArea_setDocumentMode(QMdiArea area, bool enabled);

inline QTabWidget_TabPosition QMdiArea_tabPosition(QMdiArea area);
inline void QMdiArea_setTabPosition(QMdiArea area, QTabWidget_TabPosition position);

inline QTabWidget_TabShape QMdiArea_tabShape(QMdiArea area);
inline void QMdiArea_setTabShape(QMdiArea area, QTabWidget_TabShape shape);

inline bool QMdiArea_tabsMovable(QMdiArea area);
inline void QMdiArea_setTabsMovable(QMdiArea area, bool movable);

inline QMdiArea_ViewMode QMdiArea_viewMode(QMdiArea area);
inline void QMdiArea_setViewMode(QMdiArea area, QMdiArea_ViewMode mode);

inline void QMdiArea_activateNextSubWindow(QMdiArea area);
inline void QMdiArea_activatePreviousSubWindow(QMdiArea area);
inline void QMdiArea_cascadeSubWindows(QMdiArea area);
inline void QMdiArea_closeActiveSubWindow(QMdiArea area);
inline void QMdiArea_closeAllSubWindows(QMdiArea area);
inline void QMdiArea_setActiveSubWindows(QMdiArea area, QMdiSubWindow window);
inline void QMdiArea_setupViewport(QMdiArea area, QWidget viewport);
inline void QMdiArea_tileSubWindows(QMdiArea area);
inline QMdiSubWindow QMdiArea_activeSubWindow(QMdiArea area);
#define QMdiArea_addSubWindow(...) QTC_OPTARG_REGISTER(QMdiArea_addSubWindow, __VA_ARGS__)
inline QMdiSubWindow QMdiArea_addSubWindow3(QMdiArea area, QWidget widget, Qt_WindowFlags flags);
inline QMdiSubWindow QMdiArea_addSubWindow2(QMdiArea area, QWidget widget);
inline void QMdiArea_removeSubWindow(QMdiArea area, QWidget widget);
#define QMdiArea_setOption(...) QTC_OPTARG_REGISTER(QMdiArea_setOption, __VA_ARGS__)
inline void QMdiArea_setOption2(QMdiArea area, QMdiArea_AreaOption option, bool on);
inline void QMdiArea_setOption1(QMdiArea area, QMdiArea_AreaOption option);
inline bool QMdiArea_testOption(QMdiArea area, QMdiArea_AreaOption option);

//inline void(*QMdiArea_subWindowActivated)(QMdiSubWindow);
