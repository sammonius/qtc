#include <qtc/qglobal.h>
#include <QLabel>
#include <QString>

extern "C" {

QLabel *QLabel_new(QString text, QWidget *parent)
{
	return new QLabel(text, parent);
}

QString QLabel_text(QLabel *label)
{
	return label->text();
}

void QLabel_setText(QLabel *label, QString &text)
{
	label->setText(text);
}

Qt_Alignment QLabel_alignment(QLabel *label)
{
	return declassifyEnum_alignment(label->alignment());
}

void QLabel_setAlignment(QLabel *label, Qt_Alignment a)
{
	label->setAlignment(classifyEnum_alignment(a));
}
	
bool QLabel_hasScaledContents(QLabel *label)
{
	return label->hasScaledContents();
}

void QLabel_setScaledContents(QLabel *label, bool b)
{
	label->setScaledContents(b);
}

int QLabel_margin(QLabel *label)
{
	return label->margin();
}

void QLabel_setMargin(QLabel *label, int margin)
{
	label->setMargin(margin);
}

int QLabel_indent(QLabel *label)
{
	return label->indent();
}

void QLabel_setIndent(QLabel *label, int indent)
{
	label->setMargin(indent);
}

bool QLabel_openExternalLinks(QLabel *label)
{
	return label->openExternalLinks();
}

void QLabel_setOpenExternalLinks(QLabel *label, bool b)
{
	label->setOpenExternalLinks(b);
}

bool QLabel_hasSelectedText(QLabel *label)
{
	return label->hasSelectedText();
}

QString QLabel_selectedText(QLabel *label)
{
	return label->selectedText();
}

}
