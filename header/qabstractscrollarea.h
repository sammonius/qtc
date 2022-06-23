#pragma once
#include <qtc/qt.h>

#ifndef __cplusplus
typedef void* QAbstractScrollArea;
#endif

static inline void QAbstractScrollArea_setVerticalScrollBarPolicy(QAbstractScrollArea a, Qt_ScrollBarPolicy p);
static inline Qt_ScrollBarPolicy QAbstractScrollArea_verticalScrollBarPolicy(QAbstractScrollArea a);

static inline void QAbstractScrollArea_setHorizontalScrollBarPolicy(QAbstractScrollArea a, Qt_ScrollBarPolicy p);
static inline Qt_ScrollBarPolicy QAbstractScrollArea_horizontalScrollBarPolicy(QAbstractScrollArea a);

static inline void QAbstractScrollArea_setSizeAdjustPolicy(QAbstractScrollArea a, QAbstractScrollArea_SizeAdjustPolicy p);
static inline QAbstractScrollArea_SizeAdjustPolicy QAbstractScrollArea_sizeAdjustPolicy(QAbstractScrollArea a);
