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
  QToolBar QToolBar_new0();
  QToolBar QToolBar_new_title(QString title);
  QToolBar QToolBar_new_parent(QWidget parent);
  QToolBar QToolBar_new2(QString title, QWidget parent);
  void QToolBar_destroy(QToolBar bar);

  Qt_ToolBarAreas QToolBar_allowedAreas(QToolBar bar);
  void QToolBar_setAllowedAreas(QToolBar bar, Qt_ToolBarAreas areas);

  bool QToolBar_isFloatable(QToolBar bar);
  void QToolBar_setFloatable(QToolBar bar, bool floatable);

  bool QToolBar_isFloating(QToolBar bar);

  QSize QToolBar_iconSize(QToolBar bar);
  void QToolBar_setIconSize(QToolBar bar, QSize size);

  bool QToolBar_isMovable(QToolBar bar);
  void QToolBar_setMovable(QToolBar bar, bool movable);

  Qt_Orientation QToolBar_orientation(QToolBar bar);
  void QToolBar_setOrientation(QToolBar bar, Qt_Orientation orientation);

  Qt_ToolButtonStyle QToolBar_toolButtonStyle(QToolBar bar);
  void QToolBar_setToolButtonStyle(QToolBar bar, Qt_ToolButtonStyle toolButtonStyle);

#define QToolBar_actionAt(...) QTC_OPTARG_REGISTER(QToolBar_actionAt, __VA_ARGS__)
  QAction QToolBar_actionAt2(QToolBar bar, QPoint point);
  QAction QToolBar_actionAt3(QToolBar bar, int x, int y);

  QAction QToolBar_addSeparator(QToolBar bar);
  QAction QToolBar_addWidget(QToolBar bar, QWidget widget);
  void QToolBar_clear(QToolBar bar);

  QAction QToolBar_insertSeparator(QToolBar bar, QAction before);
  QAction QToolBar_insertWidget(QToolBar bar, QAction before, QWidget widget);
  bool QToolBar_isAreaAllowed(QToolBar bar, Qt_ToolBarArea area);

  QAction QToolBar_toggleViewAction(QToolBar bar);
  QWidget QToolBar_widgetForAction(QToolBar bar, QAction action);

  void QToolBar_actionTriggered(QAction action);
  void QToolBar_allowedAreasChanged(Qt_ToolBarAreas allowedAreas);
