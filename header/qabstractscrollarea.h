#pragma once
#include <qtc/qt.h>

#ifndef __cplusplus
typedef void* QAbstractScrollArea;
#endif

void QAbstractScrollArea_setVerticalScrollBarPolicy(QAbstractScrollArea a, Qt_ScrollBarPolicy p);
Qt_ScrollBarPolicy QAbstractScrollArea_verticalScrollBarPolicy(QAbstractScrollArea a);

void QAbstractScrollArea_setHorizontalScrollBarPolicy(QAbstractScrollArea a, Qt_ScrollBarPolicy p);
Qt_ScrollBarPolicy QAbstractScrollArea_horizontalScrollBarPolicy(QAbstractScrollArea a);

void QAbstractScrollArea_setSizeAdjustPolicy(QAbstractScrollArea a, QAbstractScrollArea_SizeAdjustPolicy p);
QAbstractScrollArea_SizeAdjustPolicy QAbstractScrollArea_sizeAdjustPolicy(QAbstractScrollArea a);
