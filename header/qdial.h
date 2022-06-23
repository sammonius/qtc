#pragma once

#ifndef __cplusplus
typedef void* QDial;
#endif

#include <qtc/qwidget.h>
#include <qtc/qsize.h>
#include <qtc/private_optargs.h>
#include <qtc/qtglobal.h>

#define QDial_new(...) QTC_OPTARG_REGISTER(QDial_new, __VA_ARGS__)
QDial QDial_new0();
QDial QDial_new1(QWidget parent);
void QDial_destroy(QDial dial);

int QDial_notchSize(QDial dial);

qreal QDial_notchTarget(QDial dial);
void QDial_setNotchTarget(QDial dial, qreal target);

bool QDial_notchesVisible(QDial dial);
void QDial_setNotchesVisible(QDial dial, bool visible);

bool QDial_wrapping(QDial dial);
void QDial_setWrapping(QDial dial, bool visible);

QSize QDial_minimumSizeHint(QDial dial);
QSize QDial_sizeHint(QDial dial);