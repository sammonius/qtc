#include<QAbstractButton>
#include<QString>
#include<QIcon>

extern "C" {

void QAbstractButton_setText(QAbstractButton *btn, QString &text)
{
	btn->setText(text);
}

QString QAbstractButton_text(QAbstractButton *btn)
{
	return btn->text();
}

void QAbstractButton_setIcon(QAbstractButton *btn, QIcon &icon)
{
	btn->setIcon(icon);
}

QIcon QAbstractButton_icon(QAbstractButton *btn)
{
	return btn->icon();
}

void QAbstractButton_setCheckable(QAbstractButton *btn, bool b)
{
	btn->setCheckable(b);
}

bool QAbstractButton_checkable(QAbstractButton *btn)
{
	return btn->isCheckable();
}
	
bool QAbstractButton_isChecked(QAbstractButton *btn)
{
	return btn->isChecked();
}

void QAbstractButton_setDown(QAbstractButton *btn, bool b)
{
	btn->setDown(b);
}
	
bool QAbstractButton_isDown(QAbstractButton *btn)
{
	return btn->isDown();
}

void QAbstractButton_setAutoRepeat(QAbstractButton *btn, bool b)
{
	btn->setAutoRepeat(b);
}

bool QAbstractButton_autoRepeat(QAbstractButton *btn)
{
	return btn->autoRepeat();
}

void QAbstractButton_setAutoRepeatDelay(QAbstractButton *btn, int d)
{
	btn->setAutoRepeatDelay(d);
}

int QAbstractButton_autoRepeatDelay(QAbstractButton *btn)
{
	return btn->autoRepeatDelay();
}

void QAbstractButton_setAutoRepeatInterval(QAbstractButton *btn, int i)
{
	btn->setAutoRepeatInterval(i);
}

int QAbstractButton_autoRepeatInterval(QAbstractButton *btn)
{
	return btn->autoRepeatInterval();
}

void QAbstractButton_setAutoExclusive(QAbstractButton *btn, bool b)
{
	btn->setAutoExclusive(b);
}

int QAbstractButton_autoExclusive(QAbstractButton *btn)
{
	return btn->autoExclusive();
}

#if QT_CONFIG(buttongroup)
QButtonGroup *QAbstractButton_group(QAbstractButton *btn)
{
	return btn->group();
}
#endif

}
