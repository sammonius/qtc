#pragma once

#ifndef __cplusplus
typedef void* QLayout;
#endif

typedef enum QLayout_SizeConstraint {
	QLayout_SetDefaultConstraint = 0,
	QLayout_SetFixedSize = 3,
	QLayout_SetMinimumSize = 2,
	QLayout_SetMaximumSize = 4,
	QLayout_SetMinAndMaxSize = 5,
	QLayout_SetNoConstraint = 1
} QLayout_SizeConstraint;

inline QLayout_SizeConstraint QLayout_sizeConstraint(QLayout layout);
inline void QLayout_setSizeConstraint(QLayout layout, QLayout_SizeConstraint sc);
