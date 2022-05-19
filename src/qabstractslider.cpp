#include <QAbstractSlider>

extern "C" {

void QAbstractSlider_setMinimum(QAbstractSlider *slider, int m)
{
	slider->setMinimum(m);
}

int QAbstractSlider_minimum(QAbstractSlider slider)
{
	return slider->minimum();
}

void QAbstractSlider_setMaximum(QAbstractSlider *slider, int m)
{
	slider->setMaximum(m);
}

int QAbstractSlider_maximum(QAbstractSlider slider)
{
	return slider->maximum();
}

void QAbstractSlider_setSingleStep(QAbstractSlider *slider, int s)
{
	slider->setSingleStep(s);
}

int QAbstractSlider_singleStep(QAbstractSlider *slider)
{
	return slider->singleStep();
}

void QAbstractSlider_setPageStep(QAbstractSlider *slider, int s)
{
	slider->setPageStep(s);
}

int QAbstractSlider_setPageStep(QAbstractSlider *slider)
{
	return slider->pageStep();
}

void QAbstractSlider_setValue(QAbstractSlider *slider, int v)
{
	slider->setValue(v);
}

int QAbstractSlider_value(QAbstractSlider *slider)
{
	return slider->value();
}

void QAbstractSlider_setSliderPosition(QAbstractSlider *slider, int p)
{
	slider->setSliderPosition(p);
}

int QAbstractSlider_sliderPosition(QAbstractSlider *slider)
{
	return slider->sliderPosition();
}

void QAbstractSlider_setTracking(QAbstractSlider *slider, bool b)
{
	slider->setTracking(b);
}

bool QAbstractSlider_hasTracking(QAbstractSlider *slider)
{
	return slider->hasTracking();
}

void QAbstractSlider_setOrientation(QAbstractSlider slider, Qt_Orientation o)
{
	slider->setOrientation(classifyEnum_orientation(o));
}

Qt_Orientation QAbstractSlider_orientation(QAbstractSlider slider)
{
	return declassifyEnum_orientation(slider->orientation());
}

void QAbstractSlider_setInvertedAppearance(QAbstractSlider slider, bool b)
{
	slider->setInvertedAppearance(b);
}

bool QAbstractSlider_invertedAppearance(QAbstractSlider slider)
{
	return slider->invertedAppearance();
}

void QAbstractSlider_setInvertedControlls(QAbstractSlider slider, bool b)
{
	slider->setInvertedControlls(b);
}

bool QAbstractSlider_invertedControlls(QAbstractSlider slider)
{
	return slider->invertedControlls();
}

void QAbstractSlider_setSliderDown(QAbstractSlider slider, bool b)
{
	slider->setSliderDown();
}

bool QAbstractSlider_isSliderDown(QAbstractSlider slider)
{
	return slider->isSliderDown();
}

}