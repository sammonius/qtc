#include <QSizeGrip>

extern "C" {

QSizeGrip *QSizeGrip_new(QWidget *parent){return new QSizeGrip(parent);}
void QSizeGrip_destroy(QSizeGrip *grip){delete grip;}

QSize QSizeGrip_sizeHint(QSizeGrip *grip){return grip->sizeHint();}
QSize QSizeGrip_minimumSizeHint(QSizeGrip *grip){return grip->minimumSizeHint();}

}
