#include <qtc/qglobal.h>
#include <QAbstractScrollArea>

extern "C" {

void QAbstractScrollArea_setVerticalScrollBarPolicy(QAbstractScrollArea *a, Qt_ScrollBarPolicy p)
{
	a->setVerticalScrollBarPolicy(classifyEnum_ScrollBarPolicy(p));
}

Qt_ScrollBarPolicy QAbstractScrollArea_verticalScrollBarPolicy(QAbstractScrollArea *a)
{
	return declassifyEnum_ScrollBarPolicy(a->verticalScrollBarPolicy());
}

void QAbstractScrollArea_setHorizontalScrollBarPolicy(QAbstractScrollArea *a, Qt_ScrollBarPolicy p)
{
	a->setHorizontalScrollBarPolicy(classifyEnum_ScrollBarPolicy(p));
}

Qt_ScrollBarPolicy QAbstractScrollArea_horizontalScrollBarPolicy(QAbstractScrollArea *a)
{
	return declassifyEnum_ScrollBarPolicy(a->horizontalScrollBarPolicy());
}

void QAbstractScrollArea_setSizeAdjustPolicy(QAbstractScrollArea *a, QAbstractScrollArea_SizeAdjustPolicy p)
{
	a->setSizeAdjustPolicy(classifyEnum_QAbstractScrollArea_sizeAdjustPolicy(p));
}

QAbstractScrollArea_SizeAdjustPolicy QAbstractScrollArea_sizeAdjustPolicy(QAbstractScrollArea *a)
{
	return declassifyEnum_QAbstractScrollArea_sizeAdjustPolicy(a->sizeAdjustPolicy());
}

}