#pragma once

#include <qtc/qstring.h>
#include <qtc/qglobal.h>

#ifndef __cplusplus
typedef unsigned char QLabel;
#endif

QLabel *QLabel_new(QWidget parent);
void QLabel_destroy(QLabel *label);

void QLabel_setText(QLabel *label, QString &text);
QString QLabel_text(QLabel *label);

Qt_Alignment QLabel_alignment(QLabel *label);
void QLabel_setAlignment(QLabel *label, Qt_Alignment align);

bool QLabel_hasScaledContents(QLabel *label);
void QLabel_setScaledContents(QLabel *label, bool b);

int QLabel_margin(QLabel *label);
void QLabel_setMargin(QLabel *label, int margin);

int QLabel_indent(QLabel *label);
void QLabel_setIndent(QLabel *label, int indent);

bool QLabel_openExternalLinks(QLabel *label);
void QLabel_setOpenExternalLinks(QLabel *label, bool b);

bool QLabel_hasSelectedText(QLabel *label);
QString QLabel selectedText(QLabel *label);
