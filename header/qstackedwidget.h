#pragma once

#ifndef __cplusplus
typedef void* QStackedWidget;
#endif

#include <qtc/qwidget.h>

#define QStackedWidget_new(...) QTC_OPTARG_REGISTER(QStackedWidget_new, __VA_ARGS__)
  QStackedWidget QStackedWidget_new1(QWidget parent);
  QStackedWidget QStackedWidget_new0();
  int QStackedWidget_addWidget(QStackedWidget stackedwidget, QWidget widget);
  int QStackedWidget_count(QStackedWidget stackedwidget);
  int QStackedWidget_currentIndex(QStackedWidget stackedwidget);
  QWidget QStackedWidget_currentWidget(QStackedWidget stackedwidget);
  int QStackedWidget_indexOf(QStackedWidget stackedwidget, QWidget widget);
  int QStackedWidget_insertWidget(QStackedWidget stackedwidget, int index, QWidget widget);
  void QStackedWidget_removeWidget(QStackedWidget stackedwidget, QWidget widget);
  QWidget QStackedWidget_widget(QStackedWidget stackedwidget, int index);

  void QStackedWidget_setCurrentIndex(QStackedWidget stackedwidget, int index);
  void QStackedWidget_setCurrentWidget(QStackedWidget stackedwidget, QWidget widget);
