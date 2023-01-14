#pragma once

#ifndef __cplusplus
typedef void* QSizeGrip;
#endif

#include <qtc/qwidget.h>
#include <qtc/qsize.h>

  QSizeGrip QSizeGrip_new(QWidget parent);

  QSize QSizeGrip_minimumSizeHint(QSizeGrip grip);
  QSize QSizeGrip_sizeHint(QSizeGrip grip);
