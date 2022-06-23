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
static inline QMdiSubWindow QMdiSubWindow_new0();
static inline QMdiSubWindow QMdiSubWindow_new_flags(Qt_WindowFlags flags);
static inline QMdiSubWindow QMdiSubWindow_new_parent(QWidget parent);
static inline QMdiSubWindow QMdiSubWindow_new2(QWidget parent, Qt_WindowFlags flags);

typedef typeof(QMdiSubWindow_RubberBandResize) QMdiSubWindow_SubWindowOptions;

static inline int QMdiSubWindow_keyboardPageStep(QMdiSubWindow window);
static inline void QMdiSubWindow_setKeyboardPageStep(QMdiSubWindow window, int step);

static inline int QMdiSubWindow_keyboardSingleStep(QMdiSubWindow window);
static inline void QMdiSubWindow_setKeyboardSingleStep(QMdiSubWindow window, int step);

static inline QMdiArea QMdiSubWindow_mdiArea(QMdiSubWindow window);
static inline void QMdiSubWindow_showShaded(QMdiSubWindow window);

//void* QMdiSubWindow_aboutToActivate = &QMdiSubWindow::aboutToActivate;}
