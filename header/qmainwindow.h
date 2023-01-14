#pragma once

#ifndef __cplusplus
typedef void* QMainWindow;
#endif

typedef enum QMainWindow_DockOption {
	QMainWindow_AnimatedDocks = 0x01,
	QMainWindow_AllowNestedDocks = 0x02,
	QMainWindow_AllowTabbedDocks = 0x04,
	QMainWindow_ForceTabbedDocks = 0x08,
	QMainWindow_VerticalTabs = 0x10,
	QMainWindow_GroupedDragging = 0x20
} QMainWindow_DockOption;

QMainWindow_DockOption QMainWindow_DockOptions;

#include <qtc/qwidget.h>
#include <qtc/qsize.h>
#include <qtc/private_optargs.h>
#include <qtc/qt.h>
#include <qtc/qtabwidget.h>

#define QMainWindow_new(...) QTC_OPTARG_REGISTER(QMainWindow_new, __VA_ARGS__)
#define QMainWindow_new1(A) _Generic((A), Qt_WindowFlags: QMainWindow_newFlags, QWidget: QMainWindow_newParent)(A)

  QMainWindow QMainWindow_new0();
  QMainWindow QMainWindow_newFlags(Qt_WindowFlags flags);
  QMainWindow QMainWindow_newParent(QWidget parent);
  QMainWindow QMainWindow_new2(QWidget parent, Qt_WindowFlags flags);
  void QMainWindow_destroy(QMainWindow win);

  bool QMainWindow_isAnimated(QMainWindow win);
  void QMainWindow_setAnimated(QMainWindow win, bool animated);

  bool QMainWindow_isDockNestingEnabled(QMainWindow win);
  void QMainWindow_setDockNestingEnabled(QMainWindow win, bool enabled);

  bool QMainWindow_isDockNestingEnabled(QMainWindow win);
  void QMainWindow_setDockNestingEnabled(QMainWindow win, bool enabled);

  QMainWindow_DockOptions QMainWindow_dockOptions(QMainWindow win);
  void QMainWindow_setDockOptions(QMainWindow win, QMainWindow_DockOptions opts);

  bool QMainWindow_documentMode(QMainWindow win);
  void QMainWindow_setDocumentMode(QMainWindow win, bool docmode);

  QSize QMainWindow_iconSize(QMainWindow win);
  void QMainWindow_setIconSize(QMainWindow win, QSize size);

  QTabWidget_TabShape QMainWindow_tabShape(QMainWindow win);
  void QMainWindow_setTabShape(QMainWindow win, QTabWidget_TabShape shape);

  Qt_ToolButtonStyle QMainWindow_toolButtonStyle(QMainWindow win);
  void QMainWindow_setToolButtonStyle(QMainWindow win, Qt_ToolButtonStyle tbstyle);

  bool QMainWindow_unifiedTitleAndToolBarOnMac(QMainWindow win);
  void QMainWindow_setUnifiedTitleAndToolBarOnMac(QMainWindow win, bool set);
