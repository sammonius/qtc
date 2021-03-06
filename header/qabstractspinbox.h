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

static inline void QAbstractSpinBox_setWrapping(QAbstractSpinBox spinbox, bool b);
static inline bool QAbstractSpinBox_wrapping(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setFrame(QAbstractSpinBox spinbox, bool b);
static inline bool QAbstractSpinBox_hasFrame(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setAlignment(QAbstractSpinBox spinbox, Qt_Alignment a);
static inline Qt_Alignment QAbstractSpinBox_alignment(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setReadOnly(QAbstractSpinBox spinbox, bool b);
static inline bool QAbstractSpinBox_isReadOnly(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setButtonSymbols(QAbstractSpinBox spinbox, QAbstractSpinBox_ButtonSymbols symbols);
static inline QAbstractSpinBox_ButtonSymbols QAbstractSpinBox_buttonSymbols(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setSpecialValueText(QAbstractSpinBox spinbox, QString *text);
static inline QString *QAbstractSpinBox_specialValueText(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setText(QAbstractSpinBox spinbox, QString *text);
static inline QString *QAbstractSpinBox_text(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setAcccelerated(QAbstractSpinBox spinbox, bool b);
static inline bool QAbstractSpinBox_isAcccelerated(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setCorrectionMode(QAbstractSpinBox spinbox, QAbstractSpinBox_CorrectionMode mode);
static inline QAbstractSpinBox_CorrectionMode QAbstractSpinBox_correctionMode(QAbstractSpinBox spinbox);

static inline bool QAbstractSpinBox_hasAcceptableInput(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setKeyboardTracking(QAbstractSpinBox spinbox, bool b);
static inline bool QAbstractSpinBox_keyboardTracking(QAbstractSpinBox spinbox);

static inline void QAbstractSpinBox_setGroupSeparatorShown(QAbstractSpinBox spinbox, bool b);
static inline bool QAbstractSpinBox_isGroupSeparatorShown(QAbstractSpinBox spinbox);
