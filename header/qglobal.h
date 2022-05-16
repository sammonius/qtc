#pragma once

#ifndef __cplusplus
typedef unsigned char *QWidget;
#endif

typedef enum Qt_Alignment {
	Qt_AlignLeft = 0,
	Qt_AlignRight = 1,
	Qt_AlignHCenter = 2,
	Qt_AlignJustify = 3,
	
	Qt_AlignTop = 4,
	Qt_AlignBottom = 5,
	Qt_AlignVCenter = 7,
	Qt_AlignBaseline = 8
}Qt_Alignment;

#ifdef __cplusplus
#include <Qt>

Qt::Alignment classifyEnum_alignment(Qt_Alignment a)
{
	return Qt::AlignLeft;
}

Qt_Alignment declassifyEnum_alignment(Qt::Alignment a)
{
	return Qt_AlignLeft;
}
#endif
