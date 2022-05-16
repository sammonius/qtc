#pragma once

#include <qtc/qstring.h>
#include <qtc/qicon.h>

#ifndef __cplusplus
typedef unsigned char QPushButton;
#endif

void QAbstractButton_setText(QAbstractButton *btn, QString &text);
QString QAbstractButton_text(QString &text);

void QAbstractButton_setIcon(QAbstractButton *btn, QIcon &icon);
QIcon* QAbstractButton_icon(QabstractButton *btn);

void QAbstractButton_setCheckable(QAbstractButton *btn, bool b);
bool QAbstractButton_checkable(QAbstractButton *btn);
bool QAbstractButton_isChecked(QAbstractButton *btn);

void QAbstractButton_setDown(QAbstractButton *btn, bool b);
bool QAbstractButton_isDown(QAbstractButton *btn);

void QAbstractButton_setAutoRepeat(QAbstractButton *btn, bool b);
bool QAbstractButton_autoRepeat(QAbstractButton *btn);

void QAbstractButton_setAutoRepeatDelay(QAbstractButton *btn, int d);
int QAbstractButton_autoRepeatDelay(QAbstractButton *btn);

void QAbstractButton_setAutoRepeatInterval(QAbstractButton *btn, int d);
int QAbstractButton_autoRepeatInterval(QAbstractButton *btn);

void QAbstractButton_setAutoExclusive(QAbstractButton *btn, bool b);
int QAbstractButton_autoExclusive(QAbstractButton *btn);

#if QT_CONFIG(buttongroup)
    QButtonGroup *QAbstractButton_group(QAbstractButton *btn);
#endif

}
