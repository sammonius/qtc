#include <Qt>
#include <QAbstractSpinBox>
#include <qtc/private_returnpointer.h>

extern "C" {

void QAbstractSpinBox_setWrapping(QAbstractSpinBox *spinbox, bool b){spinbox->setWrapping(b);}
bool QAbstractSpinBox_wrapping(QAbstractSpinBox *spinbox){return spinbox->wrapping();}

void QAbstractSpinBox_setFrame(QAbstractSpinBox *spinbox, bool b){spinbox->setFrame(b);}
bool QAbstractSpinBox_hasFrame(QAbstractSpinBox *spinbox){return spinbox->hasFrame();}

void QAbstractSpinBox_setAlignment(QAbstractSpinBox *spinbox, Qt::Alignment a){spinbox->setAlignment(a);}
Qt::Alignment QAbstractSpinBox_alignment(QAbstractSpinBox *spinbox){return spinbox->alignment();}

void QAbstractSpinBox_setReadOnly(QAbstractSpinBox *spinbox, bool b){spinbox->setReadOnly(b);}
bool QAbstractSpinBox_isReadOnly(QAbstractSpinBox *spinbox){return spinbox->isReadOnly();}

void QAbstractSpinBox_setButtonSymbols(QAbstractSpinBox *spinbox, QAbstractSpinBox::ButtonSymbols symbols){spinbox->setButtonSymbols(symbols);}
QAbstractSpinBox::ButtonSymbols QAbstractSpinBox_buttonSymbols(QAbstractSpinBox *spinbox){return spinbox->buttonSymbols();}

void QAbstractSpinBox_setSpecialValueText(QAbstractSpinBox *spinbox, QString *text){spinbox->setSpecialValueText(*text);}
QString *QAbstractSpinBox_specialValueText(QAbstractSpinBox *spinbox){QTC_RETURN_POINTER(QString, spinbox->specialValueText())}

QString *QAbstractSpinBox_text(QAbstractSpinBox *spinbox){QTC_RETURN_POINTER(QString, spinbox->text())}

void QAbstractSpinBox_setAcccelerated(QAbstractSpinBox *spinbox, bool b){spinbox->setAccelerated(b);}
bool QAbstractSpinBox_isAcccelerated(QAbstractSpinBox *spinbox){return spinbox->isAccelerated();}

void QAbstractSpinBox_setCorrectionMode(QAbstractSpinBox *spinbox, QAbstractSpinBox::CorrectionMode mode){spinbox->setCorrectionMode(mode);}
QAbstractSpinBox::CorrectionMode QAbstractSpinBox_correctionMode(QAbstractSpinBox *spinbox){return spinbox->correctionMode();}

bool QAbstractSpinBox_hasAcceptableInput(QAbstractSpinBox *spinbox){return spinbox->hasAcceptableInput();}

void QAbstractSpinBox_setKeyboardTracking(QAbstractSpinBox *spinbox, bool b){spinbox->setKeyboardTracking(b);}
bool QAbstractSpinBox_keyboardTracking(QAbstractSpinBox *spinbox){return spinbox->keyboardTracking();}

void QAbstractSpinBox_setGroupSeparatorShown(QAbstractSpinBox *spinbox, bool b){spinbox->setGroupSeparatorShown(b);}
bool QAbstractSpinBox_isGroupSeparatorShown(QAbstractSpinBox *spinbox){return spinbox->isGroupSeparatorShown();}

}
