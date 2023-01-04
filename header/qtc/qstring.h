#pragma once
#ifndef __cplusplus

#include <uchar.h>

typedef char *QChar;
typedef char *QString;

#endif //__cplusplus

static inline QString QString_new(char *text);
