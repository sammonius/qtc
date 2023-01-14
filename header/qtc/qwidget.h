#pragma once

#ifndef __cplusplus
typedef void* QWidget;
#endif

#include <qtc/qlayout.h>

static inline void QWidget_show(QWidget w);

static inline void QWidget_setLayout(QWidget widget, QLayout layout);
static inline QLayout QWidget_layout(QWidget widget);
