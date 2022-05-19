#include <qtc/qglobal.h>

extern "C" {

Qt::Alignment classifyEnum_scrollBarPolicy(Qt_ScrollBarPolicy p)
{
	switch(p){
		case Qt_ScrollBarAlwaysOff:
			return Qt::ScrollBarAlwaysOff;
		case Qt_ScrollBarAlwaysOn:
			return Qt::ScrollBarAlwaysOn;
		case Qt_ScrollBarAsNeeded:
			return Qt::ScrollBarAsNeeded;
	}
}

Qt_Alignment declassifyEnum_scrollBarPolicy(Qt::ScrollBarPolicy p)
{
	switch(p){
		case Qt::ScrollBarAlwaysOff:
			return Qt_ScrollBarAlwaysOff;
		case Qt::ScrollBarAlwaysOn:
			return Qt_ScrollBarAlwaysOn;
		case Qt::ScrollBarAsNeeded:
			return Qt_ScrollBarAsNeeded;
	}
}

Qt_Orientation declassifyEnum_orientation(Qt::Orientation o)
{
	switch(o){
		case Qt::Horizontal:
			return Qt_Horizontal;
		case Qt::Vertical:
			return Qt_Vertical;
	}
}

Qt::Orientation classifyEnum_orientation(Qt_Orientation o)
{
	switch(o){
		case Qt_Horizontal:
			return Qt::Horizontal;
		case Qt_Vertical:
			return Qt::Vertical;
	}
}

/*
QComboBox::SizeAdjustPolicy classifyEnum_QComboBox_sizeAdjustPolicy(QComboBox_SizeAdjustPolicy p)
{
	switch(p){
		case QComboBox_AdjustToContents:
			return QComboBox::AdjustToContents;
		case QComboBox_AdjustToContentsOnFirstShow:
			return QComboBox::AdjustToContentsOnFirstShow;
		case QComboBox_AdjustToMinimumContentsLength:
			return QComboBox::AdjustToMinimumContentsLength;
		case QComboBox_AdjustToMinimumContentsLengthWithIcon:
			return QComboBox::AdjustToMinimumContentsLengthWithIcon;
	}
}

QComboBox_SizeAdjustPolicy declassifyEnum_QComboBox_sizeAdjustPolicy(QComboBox::SizeAdjustPolicy p)
{
	switch(p){
		case QComboBox::AdjustToContents:
			return QComboBox_AdjustToContents;
		case QComboBox::AdjustToContentsOnFirstShow:
			return QComboBox_AdjustToContentsOnFirstShow;
		case QComboBox::AdjustToMinimumContentsLength:
			return QComboBox_AdjustToMinimumContentsLength;
		case QComboBox::AdjustToMinimumContentsLengthWithIcon:
			return QComboBox_AdjustToMinimumContentsLengthWithIcon;
	}
}

QAbstractScrollArea::SizeAdjustPolicy classifyEnum_QAbstractScrollArea_sizeAdjustPolicy(QAbstractScrollArea_SizeAdjustPolicy p)
{
	switch(p){
		case QAbstractScrollArea_AdjustToContents:
			return QAbstractScrollArea::AdjustToContents;
		case QAbstractScrollArea_AdjustToContentsOnFirstShow:
			return QAbstractScrollArea::AdjustToContentsOnFirstShow;
		case QAbstractScrollArea_AdjustToMinimumContentsLength:
			return QAbstractScrollArea::AdjustToMinimumContentsLength;
		case QAbstractScrollArea_AdjustIgnored:
			return QAbstractScrollArea:AdjustIgnored;
	}
}

QAbstractScrollArea_SizeAdjustPolicy declassifyEnum_QAbstractScrollArea_sizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy p)
{
	switch(p){
		case QAbstractScrollArea::AdjustToContents:
			return QAbstractScrollArea_AdjustToContents;
		case QAbstractScrollArea::AdjustToContentsOnFirstShow:
			return QAbstractScrollArea_AdjustToContentsOnFirstShow;
		case QAbstractScrollArea::AdjustIgnored:
			return QAbstractScrollArea_AdjustIgnored;
	}
}
*/
}
