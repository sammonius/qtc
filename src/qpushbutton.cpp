#include <QPushButton>
#include "qapplication.h"
#include "qbitmap.h"
#include "qdrawutil.h"
#include "qevent.h"
#include "qfontmetrics.h"
#include "qstylepainter.h"
#include "qpixmap.h"
#include "qpointer.h"
#include "qpushbutton.h"
#include "qstyle.h"
#include "qstyleoption.h"
#include "qtoolbar.h"
#include "qdebug.h"
#include "qlayoutitem.h"
#include "qdialogbuttonbox.h"
#ifndef QT_NO_ACCESSIBILITY
#include "qaccessible.h"
#endif

#include "qmenu.h"

extern "C" {

void* QPushButton_new(QIcon *icon, QString text, QWidget *parent)
{
	if(icon == NULL) return new QPushButton(text, parent);
	else return new QPushButton(*icon, text, parent);	
}

void QPushButton_destroy(QPushButton *pushbtn)
{
	delete pushbtn;
}

void QPushBtton_setDefault(QPushButton *pushbtn, bool b)
{
	pushbtn->setDefault(b);
}

bool QPushButton_isDefalt(QPushButton *pushbtn)
{
	return pushbtn->isDefault();
}

void QPushButton_setAudoDefault(QPushButton *pushbtn, bool b)
{
	pushbtn->setAutoDefault(b);
}

bool QPushButton_audoDefault(QPushButton *pushbtn)
{
	return pushbtn->autoDefault();
}

void QPushButton_setFlat(QPushButton *pushbtn, bool b)
{
	pushbtn->setFlat(b);
}

bool QPushButton_isFlat(QPushButton *pushbtn)
{
	return pushbtn->isFlat();
}

void QPushButton_setMenu(QPushButton *pushbtn, QMenu *menu)
{
	pushbtn->setMenu(menu);
}

}
