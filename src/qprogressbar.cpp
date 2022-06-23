#include <QProgressBar>
#include <qtc/private_returnpointer.h>

extern "C" {

QProgressBar *QProgressBar_new0(){return new QProgressBar();}
QProgressBar *QProgressBar_new1(QWidget *parent){return new QProgressBar(parent);}
void QProgressBar_destroy(QProgressBar *bar){delete bar;}

Qt::Alignment QProgressBar_alignment(QProgressBar *bar){return bar->alignment();}
void QProgressBar_setAlignment(QProgressBar *bar, Qt::Alignment alignment){bar->setAlignment(alignment);}

QString *QProgressBar_format(QProgressBar *bar){QTC_RETURN_POINTER(QString, bar->format())}
void QProgressBar_setFormat(QProgressBar *bar, QString *format){bar->setFormat(*format);}
void QProgressBar_resetFormat(QProgressBar *bar){bar->resetFormat();}

bool QProgressBar_invertedAppearance(QProgressBar *bar){return bar->invertedAppearance();}
void QProgressBar_setInvertedAppearance(QProgressBar *bar, bool invert){bar->setInvertedAppearance(invert);}

bool QProgressBar_isTextVisible(QProgressBar *bar){return bar->isTextVisible();}
void QProgressBar_setTextVisible(QProgressBar *bar, bool visible){bar->setTextVisible(visible);}

int QProgressBar_minimum(QProgressBar *bar){return bar->minimum();}
void QProgressBar_setMinimum(QProgressBar *bar, int minimum){bar->setMinimum(minimum);}

int QProgressBar_maximum(QProgressBar *bar){return bar->maximum();}
void QProgressBar_setMaximum(QProgressBar *bar, int maximum){bar->setMaximum(maximum);}

Qt::Orientation QProgressBar_orientation(QProgressBar *bar){return bar->orientation();}
void QProgressBar_setOrientation(QProgressBar *bar, Qt::Orientation orientation){bar->setOrientation(orientation);}

QProgressBar::Direction QProgressBar_textDirection(QProgressBar *bar){return bar->textDirection();}
void QProgressBar_setTextDirection(QProgressBar *bar, QProgressBar::Direction direction){bar->setTextDirection(direction);}

int QProgressBar_value(QProgressBar *bar){return bar->value();}
void QProgressBar_setValue(QProgressBar *bar, int value){bar->setValue(value);}

QString *QProgressBar_text(QProgressBar *bar){QTC_RETURN_POINTER(QString, bar->text())}

void QProgressBar_reset(QProgressBar *bar){bar->reset();}
void QProgressBar_setRange(QProgressBar *bar, int min, int max){bar->setRange(min, max);}

QSize QProgressBar_minimumSizeHint(QProgressBar *bar){return bar->minimumSizeHint();}
QSize QProgressBar_sizeHint(QProgressBar *bar){return bar->sizeHint();}

}
