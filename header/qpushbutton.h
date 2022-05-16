#pragma once

#include <qtc/qstring.h>
#include <qtc/qicon.h>
#include <stdbool.h>

#ifndef __cplusplus
typedef unsigned char *QPushButton;
#endif

QPushButton QPushButton_new(QIcon icon, QString text, QWidget parent);

void QPushButton_show(QPushButton btn);
	
void QPushButton_destroy(QPushButton pushbtn);

void QPushButton_setDefault(QPushButton pushbtn, bool b);

bool QPushButton_isDefalt(QPushButton pushbtn);
	
void QPushButton_setAudoDefault(QPushButton pushbtn, bool b);

bool QPushButton_audoDefault(QPushButton pushbtn);
	
void QPushButton_setFlat(QPushButton pushbtn, bool b);
bool QPushButton_isFlat(QPushButton pushbtn);

//void QPushButton_setMenu(QPushButton *pushbtn, QMenu* menu);
//QMenu* QPushButton_menu(QPushButton *pushbtn);
