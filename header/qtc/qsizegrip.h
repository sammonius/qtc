#pragma once

#ifndef __cplusplus
typedef void* QSizeGrip;
#endif

#include <qtc/qwidget.h>
#include <qtc/qsize.h>

static inline QSizeGrip QSizeGrip_new(QWidget parent);

static inline QSize QSizeGrip_minimumSizeHint(QSizeGrip grip);
static inline QSize QSizeGrip_sizeHint(QSizeGrip grip);
