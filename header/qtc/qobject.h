#pragma once

#ifndef __cplusplus
typedef void* QObject;
#endif

#include <qtc/qstring.h>
#include <qtc/private_optargs.h>

#define QObject_connect(...) QTC_OPTARG_REGISTER(QObject_connect, __VA_ARGS__)
  void QObject_connect3(QObject sender, void(*signal)(), void(*callback)());
  void QObject_connect4(QObject sender, char* signal, QObject receiver, char *slot);
