#pragma once

#ifndef __cplusplus
typedef unsigned char *QAbstractSlider;
#endif

static inline void QAbstractSlider_setMinimum(QAbstractSlider slider, int m);
static inline int QAbstractSlider_minimum(QAbstractSlider slider);

static inline void QAbstractSlider_setMaximum(QAbstractSlider slider, int m);
static inline int QAbstractSlider_maximum(QAbstractSlider slider);

static inline void QAbstractSlider_setSingleStep(QAbstractSlider slider, int s);
static inline int QAbstractSlider_singleStep(QAbstractSlider slider);

static inline void QAbstractSlider_setPageStep(QAbstractSlider slider, int s);
static inline int QAbstractSlider_pageStep(QAbstractSlider slider);

static inline void QAbstractSlider_setValue(QAbstractSlider slider, int v);
static inline int QAbstractSlider_value(QAbstractSlider slider);

static inline void QAbstractSlider_setSliderPosition(QAbstractSlider slider, int p);
static inline int QAbstractSlider_sliderPosition(QAbstractSlider slider);

static inline void QAbstractSlider_setTracking(QAbstractSlider slider, bool b);
static inline bool QAbstractSlider_hasTracking(QAbstractSlider slider);

static inline void QAbstractSlider_setOrientation(QAbstractSlider slider, Qt_Orientation o);
static inline Qt_Orientation QAbstractSlider_orientation(QAbstractSlider slider);

static inline void QAbstractSlider_setInvertedAppearance(QAbstractSlider slider, bool b);
static inline bool QAbstractSlider_invertedAppearance(QAbstractSlider slider);

static inline void QAbstractSlider_setInvertedControlls(QAbstractSlider slider, bool b);
static inline bool QAbstractSlider_invertedControlls(QAbstractSlider slider);

static inline void QAbstractSlider_setSliderDown(QAbstractSlider slider, bool b);
static inline bool QAbstractSlider_isSliderDown(QAbstractSlider slider);
