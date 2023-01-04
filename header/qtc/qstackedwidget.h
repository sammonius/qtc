#pragma once

#ifndef __cplusplus
typedef void* QStackedWidget;
#endif

#include <qtc/qwidget.h>

#define QStackedWidget_new(...) QTC_OPTARG_REGISTER(QStackedWidget_new, __VA_ARGS__)
static inline QStackedWidget QStackedWidget_new1(QWidget parent);
static inline QStackedWidget QStackedWidget_new0();
static inline int QStackedWidget_addWidget(QStackedWidget stackedwidget, QWidget widget);
static inline int QStackedWidget_count(QStackedWidget stackedwidget);
static inline int QStackedWidget_currentIndex(QStackedWidget stackedwidget);
static inline QWidget QStackedWidget_currentWidget(QStackedWidget stackedwidget);
static inline int QStackedWidget_indexOf(QStackedWidget stackedwidget, QWidget widget);
static inline int QStackedWidget_insertWidget(QStackedWidget stackedwidget, int index, QWidget widget);
static inline void QStackedWidget_removeWidget(QStackedWidget stackedwidget, QWidget widget);
static inline QWidget QStackedWidget_widget(QStackedWidget stackedwidget, int index);

static inline void QStackedWidget_setCurrentIndex(QStackedWidget stackedwidget, int index);
static inline void QStackedWidget_setCurrentWidget(QStackedWidget stackedwidget, QWidget widget);
