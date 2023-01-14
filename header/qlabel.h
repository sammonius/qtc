#pragma once

#include <stdbool.h>
#include <qtc/qstring.h>
#include <qtc/qt.h>
#include <qtc/qwidget.h>
#include <qtc/private_optargs.h>

#ifndef __cplusplus
typedef void* QLabel;
#endif


#define QLabel_new(...) QTC_OPTARG_REGISTER(QLabel_new, __VA_ARGS__)
#define QLabel_new1(A) _Generic((A), QString: QLabel_new_text, QWidget: QLabel_new_parent)(A)

  QLabel QLabel_new2(QString text, QWidget parent);
  QLabel QLabel_new_text(QString text);
  QLabel QLabel_new_parent(QWidget parent);
  QLabel QLabel_new0();
  void QLabel_destroy(QLabel label);

  void QLabel_setText(QLabel label, QString text);
  QString QLabel_text(QLabel label);

  Qt_Alignment QLabel_alignment(QLabel label);
  void QLabel_setAlignment(QLabel label, Qt_Alignment align);

  bool QLabel_hasScaledContents(QLabel label);
  void QLabel_setScaledContents(QLabel label, bool b);

  int QLabel_margin(QLabel label);
  void QLabel_setMargin(QLabel label, int margin);

  int QLabel_indent(QLabel label);
  void QLabel_setIndent(QLabel label, int indent);

  bool QLabel_openExternalLinks(QLabel label);
  void QLabel_setOpenExternalLinks(QLabel label, bool b);

  bool QLabel_hasSelectedText(QLabel label);
  QString QLabel_selectedText(QLabel label);
