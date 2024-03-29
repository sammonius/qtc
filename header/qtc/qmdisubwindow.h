#pragma once

#ifndef __cplusplus
typedef void* QMdiSubWindow;
#endif

#include <qtc/private_optargs.h>
#include <qtc/qt.h>
#include <qtc/qmdiarea.h>

typedef enum QMdiSubWindow_SubWindowOption {
	QMdiSubWindow_RubberBandResize = 0x4,
	QMdiSubWindow_RubberBandMove = 0x8
} QMdiSubWindow_SubWindowOption;

#define QMdiSubWindow_new(...) QTC_OPTARG_REGISTER(QMdiSubWindow_new, __VA_ARGS__)
#define QMdiSubWindow_new1(A) _Generic((A), QWidget: QMdiSubWindow_new_parent, Qt_WindowFlags: QMdiSubWindow_new_flags)(A)
  QMdiSubWindow QMdiSubWindow_new0();
  QMdiSubWindow QMdiSubWindow_new_flags(Qt_WindowFlags flags);
  QMdiSubWindow QMdiSubWindow_new_parent(QWidget parent);
  QMdiSubWindow QMdiSubWindow_new2(QWidget parent, Qt_WindowFlags flags);

typedef typeof(QMdiSubWindow_RubberBandResize) QMdiSubWindow_SubWindowOptions;

  int QMdiSubWindow_keyboardPageStep(QMdiSubWindow window);
  void QMdiSubWindow_setKeyboardPageStep(QMdiSubWindow window, int step);

  int QMdiSubWindow_keyboardSingleStep(QMdiSubWindow window);
  void QMdiSubWindow_setKeyboardSingleStep(QMdiSubWindow window, int step);

  QMdiArea QMdiSubWindow_mdiArea(QMdiSubWindow window);
  void QMdiSubWindow_showShaded(QMdiSubWindow window);

//void* QMdiSubWindow_aboutToActivate = &QMdiSubWindow::aboutToActivate;}
