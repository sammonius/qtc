#pragma once

#ifndef __cplusplus
typedef unsigned char *QAbstractSpinBox;
#endif

typedef enum QAbstractSpinBox_ButtonSymbols {
	QAbstractSpinBox_UpDownArrows = 0,
	QAbstractSpinBox_PlusMinus = 1,
	QAbstractSpinBox_NoButtons = 2
} QAbstractSpinBox_ButtonSymbols;

typedef enum QAbstractSpinBox_CorrectionMode{
	QAbstractSpinBox_CorrectToPreviousValue = 0,
	QAbstractSpinBox_CorrectToNearestValue = 1
} QAbstractSpinBox_CorrectionMode;

typedef enum QAbstractSpinBox_StepEnabledFlag {
	QAbstractSpinBox_StepNone = 0x00,
	QAbstractSpinBox_StepUpEnabled = 0x01,
	QAbstractSpinBox_StepDownEnabled = 0x02
} QAbstractSpinBox_StepEnabledFlag;
typedef typeof(QAbstractSpinBox_StepNone) QAbstractSpinBox_StepEnabled;

typedef enum QAbstractSpinBox_StepType {
	QAbstractSpinBox_DefaultStepType = 0,
	QAbstractSpinBox_AdaptiveDecimalStepType = 1
} QAbstractSpinBox_StepType;

  void QAbstractSpinBox_setWrapping(QAbstractSpinBox spinbox, bool b);
  bool QAbstractSpinBox_wrapping(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setFrame(QAbstractSpinBox spinbox, bool b);
  bool QAbstractSpinBox_hasFrame(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setAlignment(QAbstractSpinBox spinbox, Qt_Alignment a);
  Qt_Alignment QAbstractSpinBox_alignment(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setReadOnly(QAbstractSpinBox spinbox, bool b);
  bool QAbstractSpinBox_isReadOnly(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setButtonSymbols(QAbstractSpinBox spinbox, QAbstractSpinBox_ButtonSymbols symbols);
  QAbstractSpinBox_ButtonSymbols QAbstractSpinBox_buttonSymbols(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setSpecialValueText(QAbstractSpinBox spinbox, QString *text);
  QString *QAbstractSpinBox_specialValueText(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setText(QAbstractSpinBox spinbox, QString *text);
  QString *QAbstractSpinBox_text(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setAcccelerated(QAbstractSpinBox spinbox, bool b);
  bool QAbstractSpinBox_isAcccelerated(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setCorrectionMode(QAbstractSpinBox spinbox, QAbstractSpinBox_CorrectionMode mode);
  QAbstractSpinBox_CorrectionMode QAbstractSpinBox_correctionMode(QAbstractSpinBox spinbox);

  bool QAbstractSpinBox_hasAcceptableInput(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setKeyboardTracking(QAbstractSpinBox spinbox, bool b);
  bool QAbstractSpinBox_keyboardTracking(QAbstractSpinBox spinbox);

  void QAbstractSpinBox_setGroupSeparatorShown(QAbstractSpinBox spinbox, bool b);
  bool QAbstractSpinBox_isGroupSeparatorShown(QAbstractSpinBox spinbox);
