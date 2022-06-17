#pragma once

#ifndef __cplusplus
typedef unsigned char *QAbstractSlider;
#endif

void QAbstractSlider_setMinimum(QAbstractSlider slider, int m);
int QAbstractSlider_minimum(QAbstractSlider slider);

void QAbstractSlider_setMaximum(QAbstractSlider slider, int m);
int QAbstractSlider_maximum(QAbstractSlider slider);

void QAbstractSlider_setSingleStep(QAbstractSlider slider, int s);
int QAbstractSlider_singleStep(QAbstractSlider slider);

void QAbstractSlider_setPageStep(QAbstractSlider slider, int s);
int QAbstractSlider_pageStep(QAbstractSlider slider);

void QAbstractSlider_setValue(QAbstractSlider slider, int v);
int QAbstractSlider_value(QAbstractSlider slider);

void QAbstractSlider_setSliderPosition(QAbstractSlider slider, int p);
int QAbstractSlider_sliderPosition(QAbstractSlider slider);

void QAbstractSlider_setTracking(QAbstractSlider slider, bool b);
bool QAbstractSlider_hasTracking(QAbstractSlider slider);

void QAbstractSlider_setOrientation(QAbstractSlider slider, Qt_Orientation o);
Qt_Orientation QAbstractSlider_orientation(QAbstractSlider slider);

void QAbstractSlider_setInvertedAppearance(QAbstractSlider slider, bool b);
bool QAbstractSlider_invertedAppearance(QAbstractSlider slider);

void QAbstractSlider_setInvertedControlls(QAbstractSlider slider, bool b);
bool QAbstractSlider_invertedControlls(QAbstractSlider slider);

void QAbstractSlider_setSliderDown(QAbstractSlider slider, bool b);
bool QAbstractSlider_isSliderDown(QAbstractSlider slider);
