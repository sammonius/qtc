#include <QLabel>
#include <QString>

extern "C" {

QLabel *QLabel_new2(QString text, QWidget *parent){return new QLabel(text, parent);}
QLabel *QLabel_new_text(QString text){return new QLabel(text);}
QLabel *QLabel_new_parent(QWidget *parent){return new QLabel(parent);}
QLabel *QLabel_new0(){return new QLabel();}

QString QLabel_text(QLabel *label){return label->text();}
void QLabel_setText(QLabel *label, QString &text){label->setText(text);}

Qt::Alignment QLabel_alignment(QLabel *label){return label->alignment();}
void QLabel_setAlignment(QLabel *label, Qt::Alignment a){label->setAlignment(a);}
	
bool QLabel_hasScaledContents(QLabel *label){return label->hasScaledContents();}
void QLabel_setScaledContents(QLabel *label, bool b){label->setScaledContents(b);}

int QLabel_margin(QLabel *label){return label->margin();}
void QLabel_setMargin(QLabel *label, int margin){label->setMargin(margin);}

int QLabel_indent(QLabel *label){return label->indent();}
void QLabel_setIndent(QLabel *label, int indent){label->setMargin(indent);}

bool QLabel_openExternalLinks(QLabel *label){return label->openExternalLinks();}
void QLabel_setOpenExternalLinks(QLabel *label, bool b){label->setOpenExternalLinks(b);}

bool QLabel_hasSelectedText(QLabel *label){return label->hasSelectedText();}
QString QLabel_selectedText(QLabel *label){return label->selectedText();}

}
