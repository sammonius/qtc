#include <Qt>
#include <QAbstractScrollArea>

extern "C" {

void QAbstractScrollArea_setVerticalScrollBarPolicy(QAbstractScrollArea *a, Qt::ScrollBarPolicy p){a->setVerticalScrollBarPolicy(p);}
Qt::ScrollBarPolicy QAbstractScrollArea_verticalScrollBarPolicy(QAbstractScrollArea *a){return a->verticalScrollBarPolicy();}

void QAbstractScrollArea_setHorizontalScrollBarPolicy(QAbstractScrollArea *a, Qt::ScrollBarPolicy p){a->setHorizontalScrollBarPolicy(p);}
Qt::ScrollBarPolicy QAbstractScrollArea_horizontalScrollBarPolicy(QAbstractScrollArea *a){return a->horizontalScrollBarPolicy();}

void QAbstractScrollArea_setSizeAdjustPolicy(QAbstractScrollArea *a, QAbstractScrollArea::SizeAdjustPolicy p){a->setSizeAdjustPolicy(p);}
QAbstractScrollArea::SizeAdjustPolicy QAbstractScrollArea_sizeAdjustPolicy(QAbstractScrollArea *a){return a->sizeAdjustPolicy();}

}
