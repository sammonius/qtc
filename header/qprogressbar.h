#pragma once

#ifndef __cplusplus
typedef void* QProgressBar;
#endif

#include <qtc/qwidget.h>
#include <qtc/qstring.h>
#include <qtc/qt.h>
#include <qtc/private_optargs.h>

#define QProgressBar_new(...) QTC_OPTARG_REGISTER(QProgressBar_new, __VA_ARGS__)

inline QProgressBar QProgressBar_new0();
inline QProgressBar QProgressBar_new1(QWidget parent);
inline void QProgressBar_destroy(QProgressBar bar);

inline Qt_Alignment QProgressBar_alignment(QProgressBar bar);
inline void QProgressBar_setAlignment(QProgressBar bar, Qt_Alignment alignment);

inline QString QProgressBar_format(QProgressBar bar);
inline void QProgressBar_setValue(QProgressBar bar, QString format);
inline void QProgressBar_resetFormat(QProgressBar bar);

inline bool QProgressBar_invertedAppearance(QProgressBar bar);
inline void QProgressBar_setInvertedAppearance(QProgressBar bar, bool invert);

inline bool QProgressBar_isTextVisible(QProgressBar bar);
inline void QProgressBar_setTextVisible(QProgressBar bar, bool visible);

inline int QProgressBar_minimum(QProgressBar bar);
inline void QProgressBar_setMinimum(QProgressBar bar, int minimum);

inline int QProgressBar_maximum(QProgressBar bar);
inline void QProgressBar_setMaximum(QProgressBar bar, int maximum);

inline Qt_Orientation QProgressBar_orientation(QProgressBar bar);
inline void QProgressBar_setOrientation(QProgressBar bar, Qt_Orientation orientation);

inline QProgressBar_Direction QProgressBar_textDirection(QProgressBar bar);
inline void QProgressBar_setTextDirection(QProgressBar bar, QProgressBar_Direction direction);

inline int QProgressBar_value(QProgressBar bar);
inline void QProgressBar_setValue(QProgressBar bar, int value);

inline QString QProgressBar_text(QProgressBar bar);

inline void QProgressBar_reset(QProgressBar bar);
inline void QProgressBar_setRange(int min, int max);

inline QSize QProgressBar_minimumSizeHint(QProgressBar bar);
inline QSize QProgressBar_sizeHint(QProgressBar bar);