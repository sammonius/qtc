#pragma once

#ifndef __cplusplus
typedef unsigned char *QAbstractSlider;
#endif

inline void QAbstractSlider_setMinimum(QAbstractSlider slider, int m);
inline int QAbstractSlider_minimum(QAbstractSlider slider);

inline void QAbstractSlider_setMaximum(QAbstractSlider slider, int m);
inline int QAbstractSlider_maximum(QAbstractSlider slider);

inline void QAbstractSlider_setSingleStep(QAbstractSlider slider, int s);
inline int QAbstractSlider_singleStep(QAbstractSlider slider);

inline void QAbstractSlider_setPageStep(QAbstractSlider slider, int s);
inline int QAbstractSlider_pageStep(QAbstractSlider slider);

inline void QAbstractSlider_setValue(QAbstractSlider slider, int v);
inline int QAbstractSlider_value(QAbstractSlider slider);

inline void QAbstractSlider_setSliderPosition(QAbstractSlider slider, int p);
inline int QAbstractSlider_sliderPosition(QAbstractSlider slider);

inline void QAbstractSlider_setTracking(QAbstractSlider slider, bool b);
inline bool QAbstractSlider_hasTracking(QAbstractSlider slider);

inline void QAbstractSlider_setOrientation(QAbstractSlider slider, Qt_Orientation o);
inline Qt_Orientation QAbstractSlider_orientation(QAbstractSlider slider);

inline void QAbstractSlider_setInvertedAppearance(QAbstractSlider slider, bool b);
inline bool QAbstractSlider_invertedAppearance(QAbstractSlider slider);

inline void QAbstractSlider_setInvertedControlls(QAbstractSlider slider, bool b);
inline bool QAbstractSlider_invertedControlls(QAbstractSlider slider);

inline void QAbstractSlider_setSliderDown(QAbstractSlider slider, bool b);
inline bool QAbstractSlider_isSliderDown(QAbstractSlider slider);
