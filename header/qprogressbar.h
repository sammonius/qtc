#pragma once

#ifndef __cplusplus
typedef void* QProgressBar;
#endif

#include <qtc/qwidget.h>
#include <qtc/qstring.h>
#include <qtc/qt.h>
#include <qtc/private_optargs.h>

#define QProgressBar_new(...) QTC_OPTARG_REGISTER(QProgressBar_new, __VA_ARGS__)

  QProgressBar QProgressBar_new0();
  QProgressBar QProgressBar_new1(QWidget parent);
  void QProgressBar_destroy(QProgressBar bar);

  Qt_Alignment QProgressBar_alignment(QProgressBar bar);
  void QProgressBar_setAlignment(QProgressBar bar, Qt_Alignment alignment);

  QString QProgressBar_format(QProgressBar bar);
  void QProgressBar_setValue(QProgressBar bar, QString format);
  void QProgressBar_resetFormat(QProgressBar bar);

  bool QProgressBar_invertedAppearance(QProgressBar bar);
  void QProgressBar_setInvertedAppearance(QProgressBar bar, bool invert);

  bool QProgressBar_isTextVisible(QProgressBar bar);
  void QProgressBar_setTextVisible(QProgressBar bar, bool visible);

  int QProgressBar_minimum(QProgressBar bar);
  void QProgressBar_setMinimum(QProgressBar bar, int minimum);

  int QProgressBar_maximum(QProgressBar bar);
  void QProgressBar_setMaximum(QProgressBar bar, int maximum);

  Qt_Orientation QProgressBar_orientation(QProgressBar bar);
  void QProgressBar_setOrientation(QProgressBar bar, Qt_Orientation orientation);

  QProgressBar_Direction QProgressBar_textDirection(QProgressBar bar);
  void QProgressBar_setTextDirection(QProgressBar bar, QProgressBar_Direction direction);

  int QProgressBar_value(QProgressBar bar);
  void QProgressBar_setValue(QProgressBar bar, int value);

  QString QProgressBar_text(QProgressBar bar);

  void QProgressBar_reset(QProgressBar bar);
  void QProgressBar_setRange(int min, int max);

  QSize QProgressBar_minimumSizeHint(QProgressBar bar);
  QSize QProgressBar_sizeHint(QProgressBar bar);
