#pragma once

#include <qtc/qstring.h>
#include <qtc/qt.h>
#include <qtc/qwidget.h>
#include <qtc/private_optargs.h>

#ifndef __cplusplus
typedef void* QLabel;
#endif


#define QLabel_new(...) QTC_OPTARG_REGISTER(QLabel_new, __VA_ARGS__)
#define QLabel_new1(A) _Generic((A), QString: QLabel_new_text, QWidget: QLabel_new_parent)(A)

inline QLabel QLabel_new2(QString text, QWidget parent);
inline QLabel QLabel_new_text(QString text);
inline QLabel QLabel_new_parent(QWidget parent);
inline QLabel QLabel_new0();
inline void QLabel_destroy(QLabel label);

inline void QLabel_setText(QLabel label, QString text);
inline QString QLabel_text(QLabel label);

inline Qt_Alignment QLabel_alignment(QLabel label);
inline void QLabel_setAlignment(QLabel label, Qt_Alignment align);

inline bool QLabel_hasScaledContents(QLabel label);
inline void QLabel_setScaledContents(QLabel label, bool b);

inline int QLabel_margin(QLabel label);
inline void QLabel_setMargin(QLabel label, int margin);

inline int QLabel_indent(QLabel label);
inline void QLabel_setIndent(QLabel label, int indent);

inline bool QLabel_openExternalLinks(QLabel label);
inline void QLabel_setOpenExternalLinks(QLabel label, bool b);

inline bool QLabel_hasSelectedText(QLabel label);
inline QString QLabel_selectedText(QLabel label);
