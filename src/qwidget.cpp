#include <QWidget>

extern "C" {

void QWidget_show(QWidget *w)
{
	w->show();
}

}
