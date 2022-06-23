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

static inline QLabel QLabel_new2(QString text, QWidget parent);
static inline QLabel QLabel_new_text(QString text);
static inline QLabel QLabel_new_parent(QWidget parent);
static inline QLabel QLabel_new0();
static inline void QLabel_destroy(QLabel label);

static inline void QLabel_setText(QLabel label, QString text);
static inline QString QLabel_text(QLabel label);

static inline Qt_Alignment QLabel_alignment(QLabel label);
static inline void QLabel_setAlignment(QLabel label, Qt_Alignment align);

static inline bool QLabel_hasScaledContents(QLabel label);
static inline void QLabel_setScaledContents(QLabel label, bool b);

static inline int QLabel_margin(QLabel label);
static inline void QLabel_setMargin(QLabel label, int margin);

static inline int QLabel_indent(QLabel label);
static inline void QLabel_setIndent(QLabel label, int indent);

static inline bool QLabel_openExternalLinks(QLabel label);
static inline void QLabel_setOpenExternalLinks(QLabel label, bool b);

static inline bool QLabel_hasSelectedText(QLabel label);
static inline QString QLabel_selectedText(QLabel label);
