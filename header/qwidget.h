#pragma once

#ifndef __cplusplus
typedef void* QWidget;
#endif

#include <qtc/qlayout.h>

inline void QWidget_show(QWidget w);

inline void QWidget_setLayout(QWidget widget, QLayout layout);
inline QLayout QWidget_layout(QWidget widget);
