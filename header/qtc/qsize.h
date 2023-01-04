#pragma once

#ifndef __cplusplus
typedef struct QSize {int w; int h;} QSize;
#endif

#define QSize_new(...) QTC_OPTARG_REGISTER(QSize_new, __VA_ARGS__)
static inline QSize QSize_new0();
static inline QSize QSize_new2(int width, int height);

static inline bool QSize_isNull(QSize size);
static inline bool QSize_isEmpty(QSize size);
static inline bool QSize_isValid(QSize size);

static inline int QSize_width(QSize size);
static inline int QSize_height(QSize size);
static inline void QSize_setHeight(QSize size, int height);
static inline void QSize_setWidth(QSize size, int width);

static inline QSize QSize_transposed(QSize size);
//#define QSize_scale(...) QTC_OPTARG_REGISTER(QSize_scale, __VA_ARGS__)
//static inline void QSize_scale()
