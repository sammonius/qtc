#pragma once

#include <qtc/qstring.h>
#include <qtc/qicon.h>

#ifndef __cplusplus
typedef void* QAbstractButton;
#endif

inline void QAbstractButton_setText(QAbstractButton btn, QString text);
inline QString QAbstractButton_text(QString text);

inline void QAbstractButton_setIcon(QAbstractButton btn, QIcon icon);
inline QIcon QAbstractButton_icon(QAbstractButton btn);

inline void QAbstractButton_setCheckable(QAbstractButton btn, bool b);
inline bool QAbstractButton_checkable(QAbstractButton btn);
inline bool QAbstractButton_isChecked(QAbstractButton btn);

inline void QAbstractButton_setDown(QAbstractButton btn, bool b);
inline bool QAbstractButton_isDown(QAbstractButton btn);

inline void QAbstractButton_setAutoRepeat(QAbstractButton btn, bool b);
inline bool QAbstractButton_autoRepeat(QAbstractButton btn);

inline void QAbstractButton_setAutoRepeatDelay(QAbstractButton btn, int d);
inline int QAbstractButton_autoRepeatDelay(QAbstractButton btn);

inline void QAbstractButton_setAutoRepeatInterval(QAbstractButton btn, int d);
inline int QAbstractButton_autoRepeatInterval(QAbstractButton btn);

inline void QAbstractButton_setAutoExclusive(QAbstractButton btn, bool b);
inline int QAbstractButton_autoExclusive(QAbstractButton btn);

//inline QButtonGroup *QAbstractButton_group(QAbstractButton btn);

void(*QAbstractButton_click)();
