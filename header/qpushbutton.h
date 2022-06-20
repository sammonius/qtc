#pragma once
#include <qtc/qwidget.h>
#include <qtc/qstring.h>
#include <qtc/qicon.h>
#include <stdbool.h>
#include <qtc/private_optargs.h>

#ifndef __cplusplus
typedef void* QPushButton;
#endif

#define QPushButton_new(...) QTC_OPTARG_REGISTER(QPushButton_new, __VA_ARGS__)
#define QPushButton_new1(A) _Generic((A), QString: QPushButton_new_text, QWidget: QPushButton_new_parent)(A)
#define QPushButton_new2(A, B) _Generic((B), char*: QPushButton_new_icon_text, QWidget: QPushButton_new_icon_parent)(A, B)

inline QPushButton QPushButton_new3(QIcon icon, QString text, QWidget parent);
inline QPushButton QPushButton_new_parent(QWidget parent);
inline QPushButton QPushButton_new_text(QString text);
inline QPushButton QPushButton_new_icon_parent(QIcon icon, QWidget parent);
inline QPushButton QPushButton_new_icon_text(QIcon icon, QString text);
inline QPushButton QPushButton_new0();
	
inline void QPushButton_destroy(QPushButton pushbtn);

inline void QPushButton_setDefault(QPushButton pushbtn, bool b);

inline bool QPushButton_isDefalt(QPushButton pushbtn);
	
inline void QPushButton_setAudoDefault(QPushButton pushbtn, bool b);

inline bool QPushButton_audoDefault(QPushButton pushbtn);
	
inline void QPushButton_setFlat(QPushButton pushbtn, bool b);
inline bool QPushButton_isFlat(QPushButton pushbtn);

//void QPushButton_setMenu(QPushButton *pushbtn, QMenu* menu);
//QMenu* QPushButton_menu(QPushButton *pushbtn);
