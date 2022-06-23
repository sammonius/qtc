#pragma once

#ifndef __cplusplus
typedef void* QDial;
#endif

#include <qtc/qwidget.h>
#include <qtc/qsize.h>
#include <qtc/private_optargs.h>
#include <qtc/qtglobal.h>

#define QDial_new(...) QTC_OPTARG_REGISTER(QDial_new, __VA_ARGS__)
static inline QDial QDial_new0();
static inline QDial QDial_new1(QWidget parent);
static inline void QDial_destroy(QDial dial);

static inline int QDial_notchSize(QDial dial);

static inline qreal QDial_notchTarget(QDial dial);
static inline void QDial_setNotchTarget(QDial dial, qreal target);

static inline bool QDial_notchesVisible(QDial dial);
static inline void QDial_setNotchesVisible(QDial dial, bool visible);

static inline bool QDial_wrapping(QDial dial);
static inline void QDial_setWrapping(QDial dial, bool visible);

static inline QSize QDial_minimumSizeHint(QDial dial);
static inline QSize QDial_sizeHint(QDial dial);
