#pragma once

#include <qtc/qstring.h>
#include <qtc/qicon.h>

#ifndef __cplusplus
typedef void* QAbstractButton;
#endif

static inline void QAbstractButton_setText(QAbstractButton btn, QString text);
static inline QString QAbstractButton_text(QString text);

static inline void QAbstractButton_setIcon(QAbstractButton btn, QIcon icon);
static inline QIcon QAbstractButton_icon(QAbstractButton btn);

static inline void QAbstractButton_setCheckable(QAbstractButton btn, bool b);
static inline bool QAbstractButton_checkable(QAbstractButton btn);
static inline bool QAbstractButton_isChecked(QAbstractButton btn);

static inline void QAbstractButton_setDown(QAbstractButton btn, bool b);
static inline bool QAbstractButton_isDown(QAbstractButton btn);

static inline void QAbstractButton_setAutoRepeat(QAbstractButton btn, bool b);
static inline bool QAbstractButton_autoRepeat(QAbstractButton btn);

static inline void QAbstractButton_setAutoRepeatDelay(QAbstractButton btn, int d);
static inline int QAbstractButton_autoRepeatDelay(QAbstractButton btn);

static inline void QAbstractButton_setAutoRepeatInterval(QAbstractButton btn, int d);
static inline int QAbstractButton_autoRepeatInterval(QAbstractButton btn);

static inline void QAbstractButton_setAutoExclusive(QAbstractButton btn, bool b);
static inline int QAbstractButton_autoExclusive(QAbstractButton btn);

//static inline QButtonGroup *QAbstractButton_group(QAbstractButton btn);

void(*QAbstractButton_click)();
