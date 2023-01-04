#include <memory>
#define QTC_RETURN_POINTER(TYPE, VAL) TYPE * newobj = new (TYPE)(); *newobj = (VAL); return newobj;
