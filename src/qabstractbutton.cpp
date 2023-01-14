#include <QAbstractButton>
#include <qtc/private_signal.h>

extern "C" {

void QAbstractButton_setText(QAbstractButton *btn, QString &text){btn->setText(text);}
QString QAbstractButton_text(QAbstractButton *btn){return btn->text();}

void QAbstractButton_setIcon(QAbstractButton *btn, QIcon &icon){btn->setIcon(icon);}
QIcon QAbstractButton_icon(QAbstractButton *btn){return btn->icon();}

void QAbstractButton_setIconSize(QAbstractButton *btn, QSize size){btn->setIconSize(size);}
QSize QAbstractButton_iconSize(QAbstractButton *btn){return btn->iconSize();}

void QAbstractButton_setCheckable(QAbstractButton *btn, bool b){btn->setCheckable(b);}
bool QAbstractButton_checkable(QAbstractButton *btn){return btn->isCheckable();}

bool QAbstractButton_isChecked(QAbstractButton *btn){return btn->isChecked();}
void QAbstractButton_setChecked(QAbstractButton *btn, bool checked){btn->setChecked(checked);}

void QAbstractButton_setDown(QAbstractButton *btn, bool b){btn->setDown(b);}
bool QAbstractButton_isDown(QAbstractButton *btn){return btn->isDown();}

void QAbstractButton_setAutoRepeat(QAbstractButton *btn, bool b){btn->setAutoRepeat(b);}
bool QAbstractButton_autoRepeat(QAbstractButton *btn){return btn->autoRepeat();}

void QAbstractButton_setAutoRepeatDelay(QAbstractButton *btn, int d){btn->setAutoRepeatDelay(d);}
int QAbstractButton_autoRepeatDelay(QAbstractButton *btn){return btn->autoRepeatDelay();}

void QAbstractButton_setAutoRepeatInterval(QAbstractButton *btn, int i){btn->setAutoRepeatInterval(i);}
int QAbstractButton_autoRepeatInterval(QAbstractButton *btn){return btn->autoRepeatInterval();}

void QAbstractButton_setAutoExclusive(QAbstractButton *btn, bool b){btn->setAutoExclusive(b);}
bool QAbstractButton_autoExclusive(QAbstractButton *btn){return btn->autoExclusive();}

QButtonGroup *QAbstractButton_group(QAbstractButton *btn){return btn->group();}

void(QAbstractButton::*QAbstractButton_click)() = &QAbstractButton::click;

}
