#pragma once

#ifndef __cplusplus
typedef unsigned char *QAbstractSpinBox;
#endif

void QAbstractSpinBox_setAcccelerated(QAbstractSpinBox spinbox, bool b);
bool QAbstractSpinBox_isAcccelerated(QAbstractSpinBox spinbox);

bool QAbstractSpinBox_hasAcceptableInput(QAbstractSpinBox spinbox);

void QAbstractSpinBox_setAlignment(QAbstractSpinBox spinbox, Qt_Alignment a);
Qt_Alignment QAbstractSpinBox_alignment(QAbstractSpinBox spinbox);

#ifdef __cplusplus
extern "C" {
#endif

enum QAbstractSpinBox_ButtonSymbols {
	QAbstractSpinBox_UpDownArrows,
	QAbstractSpinBox_PlusMinus,
	QAbstractSpinBox_NoButtons
}

#ifdef __cplusplus
extern "C" {



#endif