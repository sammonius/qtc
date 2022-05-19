#pragma once

#include <Qt>

enum Qt_Alignment {
	Qt_AlignLeft = 0,
	Qt_AlignRight = 1,
	Qt_AlignHCenter = 2,
	Qt_AlignJustify = 3,
	
	Qt_AlignTop = 4,
	Qt_AlignBottom = 5,
	Qt_AlignVCenter = 7,
	Qt_AlignBaseline = 8
} Qt_Alignment;

enum Qt_ScrollBarPolicy {
	Qt_ScrollBarAlwaysOff = 9,
	Qt_ScrollBarAlwaysOn = 10,
	Qt_ScrollBarAsNeeded = 11
} Qt_ScrollBarPolicy;

enum QComboBox_SizeAdjustPolicy {
	QComboBox_AdjustIgnored = 12,
	QComboBox_AdjustToContents = 13,
	QComboBox_AdjustToContentsOnFirstShow = 14,
	QComboBox_AdjustToMinimumContentsLength = 15,
	QComboBox_AdjustToMinimumContentsLengthWithIcon = 16
} QComboBox_SizeAdjustPolicy;

enum QAbstractScrollArea_SizeAdjustPolicy {
	QAbstractScrollArea_AdjustIgnored = 17,
	QAbstractScrollArea_AdjustToContents = 18,
	QAbstractScrollArea_AdjustToContentsOnFirstShow = 19
} QAbstractScrollArea_SizeAdjustPolicy;

enum Qt_Orientation {
	Qt_Horizontal = 20,
	Qt_Vertical = 21,
} Qt_Orientation;

#ifdef __cplusplus

Qt::Alignment classifyEnum_alignment(Qt_Alignment a);
Qt_Alignment declassifyEnum_alignment(Qt::Alignent a);

Qt::Alignment classifyEnum_scrollBarPolicy(Qt_ScrollBarPolicy p);
Qt_Alignment declassifyEnum_scrollBarPolicy(Qt::ScrollBarPolicy p);

Qt_Orientation declassifyEnum_orientation(Qt::Orientation o);
Qt::Orientation classifyEnum_orientation(Qt_Orientation o);

//QComboBox::SizeAdjustPolicy classifyEnum_QComboBox_sizeAdjustPolicy(QComboBox_SizeAdjustPolicy p);
//QComboBox_SizeAdjustPolicy declassifyEnum_QComboBox_sizeAdjustPolicy(QComboBox::SizeAdjustPolicy p);

//QAbstractScrollArea::SizeAdjustPolicy classifyEnum_QAbstractScrollArea_sizeAdjustPolicy(QAbstractScrollArea_SizeAdjustPolicy p);
//QAbstractScrollArea_SizeAdjustPolicy declassifyEnum_QAbstractScrollArea_sizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy p);

#endif //__cplusplus
