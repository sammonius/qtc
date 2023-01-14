#pragma once

#ifndef __cplusplus
typedef void* QToolButton;
#endif

#include <qtc/qwidget.h>
#include <qtc/qsize.h>
#include <qtc/qstring.h>
#include <qtc/qt.h>
#include <qtc/qmenu.h>
#include <qtc/qaction.h>
#include <qtc/private_optargs.h>

typedef enum QToolButton_ToolButtonPopupMode {
	QToolButton_DelayedPopup = 0,
	QToolButton_MenuButtonPopup = 1,
	QToolButton_InstantPopup = 2
} QToolButton_ToolButtonPopupMode;

#define QToolButton_new(...) QTC_OPTARG_REGISTER(QToolButton_new, __VA_ARGS__)
QToolButton QToolButton_new0();
QToolButton QToolButton_new1(QWidget parent);
void QToolButton_destroy(QToolButton btn);

  Qt_ArrowType QToolButton_arrowType(QToolButton btn);
  void QToolButton_setArrowType(QToolButton btn, Qt_ArrowType arrowtype);

  bool QToolButton_autoRaise(QToolButton btn);
  void QToolButton_setAutoRaise(QToolButton btn, bool autoraise);

  QAction QToolButton_defaultAction(QToolButton btn);
  void QToolButton_setDefaultAction(QToolButton btn, QAction action);

    Qt_ToolButtonStyle QToolButton_toolButtonStyle(QToolButton btn);
  void QToolButton_setToolButtonStyle(QToolButton btn, Qt_ToolButtonStyle toolButtonStyle);

  QToolButton_ToolButtonPopupMode QToolButton_popupMode(QToolButton btn);
  void QToolButton_setPopupMode(QToolButton btn, QToolButton_ToolButtonPopupMode popupMode);

  QMenu QToolButton_menu(QToolButton btn);
  void QToolButton_setMenu(QToolButton btn, QMenu menu);

  QSize QToolButton_sizeHint(QToolButton btn);
  QSize QToolButton_minimumSizeHint(QToolButton btn);
