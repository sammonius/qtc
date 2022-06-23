#include <QDial>

extern "C" {

QDial *QDial_new0(){return new QDial();}
QDial *QDial_new1(QWidget *parent){return new QDial(parent);}
void QDial_destroy(QDial *dial){delete dial;}

int QDial_notchSize(QDial *dial){return dial->notchSize();}

qreal QDial_notchTarget(QDial *dial){return dial->notchTarget();}
void QDial_setNotchTarget(QDial *dial, qreal target){dial->setNotchTarget(target);}

bool QDial_notchesVisible(QDial *dial){return dial->notchesVisible();}
void QDial_setNotchesVisible(QDial *dial, bool visible){dial->setNotchesVisible(visible);}

bool QDial_wrapping(QDial *dial){return dial->wrapping();}
void QDial_setWrapping(QDial *dial, bool wrapping){dial->setWrapping(wrapping);}

QSize QDial_minimumSizeHint(QDial *dial){return dial->minimumSizeHint();}
QSize QDial_sizeHint(QDial *dial){return dial->sizeHint();}

}
