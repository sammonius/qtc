#include <QWidget>
#include <QLayout>
#include <Qt>

extern "C" {

void QWidget_show(QWidget *w){w->show();}

void QWidget_setLayout(QWidget *w, QLayout *l){w->setLayout(l);}
QLayout *QWidget_layout(QWidget *w){return w->layout();}

}
