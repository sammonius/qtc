#pragma once

#ifndef __cplusplus
typedef void* QObject;
#endif

#include <qtc/qstring.h>

inline void QObject_connect(QObject *sender, char *signal, QObject *receiver, char *slot);


