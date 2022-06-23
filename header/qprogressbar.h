#pragma once

#ifndef __cplusplus
typedef void* QProgressBar;
#endif

#include <qtc/qwidget.h>
#include <qtc/qstring.h>
#include <qtc/qt.h>
#include <qtc/private_optargs.h>

#define QProgressBar_new(...) QTC_OPTARG_REGISTER(QProgressBar_new, __VA_ARGS__)

static inline QProgressBar QProgressBar_new0();
static inline QProgressBar QProgressBar_new1(QWidget parent);
static inline void QProgressBar_destroy(QProgressBar bar);

static inline Qt_Alignment QProgressBar_alignment(QProgressBar bar);
static inline void QProgressBar_setAlignment(QProgressBar bar, Qt_Alignment alignment);

static inline QString QProgressBar_format(QProgressBar bar);
static inline void QProgressBar_setValue(QProgressBar bar, QString format);
static inline void QProgressBar_resetFormat(QProgressBar bar);

static inline bool QProgressBar_invertedAppearance(QProgressBar bar);
static inline void QProgressBar_setInvertedAppearance(QProgressBar bar, bool invert);

static inline bool QProgressBar_isTextVisible(QProgressBar bar);
static inline void QProgressBar_setTextVisible(QProgressBar bar, bool visible);

static inline int QProgressBar_minimum(QProgressBar bar);
static inline void QProgressBar_setMinimum(QProgressBar bar, int minimum);

static inline int QProgressBar_maximum(QProgressBar bar);
static inline void QProgressBar_setMaximum(QProgressBar bar, int maximum);

static inline Qt_Orientation QProgressBar_orientation(QProgressBar bar);
static inline void QProgressBar_setOrientation(QProgressBar bar, Qt_Orientation orientation);

static inline QProgressBar_Direction QProgressBar_textDirection(QProgressBar bar);
static inline void QProgressBar_setTextDirection(QProgressBar bar, QProgressBar_Direction direction);

static inline int QProgressBar_value(QProgressBar bar);
static inline void QProgressBar_setValue(QProgressBar bar, int value);

static inline QString QProgressBar_text(QProgressBar bar);

static inline void QProgressBar_reset(QProgressBar bar);
static inline void QProgressBar_setRange(int min, int max);

static inline QSize QProgressBar_minimumSizeHint(QProgressBar bar);
static inline QSize QProgressBar_sizeHint(QProgressBar bar);
