#pragma once

#ifndef __cplusplus
typedef struct QSize {int w; int h;} QSize;
#endif

#define QSize_new(...) QTC_OPTARG_REGISTER(QSize_new, __VA_ARGS__)
QSize QSize_new0();
QSize QSize_new2(int width, int height);

bool QSize_isNull(QSize size);
bool QSize_isEmpty(QSize size);
bool QSize_isValid(QSize size);

int QSize_width(QSize size);
int QSize_height(QSize size);
void QSize_setHeight(QSize size, int height);
void QSize_setWidth(QSize size, int width);

QSize QSize_transposed(QSize size);
//#define QSize_scale(...) QTC_OPTARG_REGISTER(QSize_scale, __VA_ARGS__)
//void QSize_scale()
