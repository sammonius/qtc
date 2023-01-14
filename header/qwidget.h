#pragma once

#ifndef __cplusplus
typedef void* QWidget;
#endif

#include <qtc/qlayout.h>

  void QWidget_show(QWidget w);

  void QWidget_setLayout(QWidget widget, QLayout layout);
  QLayout QWidget_layout(QWidget widget);
