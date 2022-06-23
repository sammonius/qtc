#pragma once
#ifndef __cplusplus
typedef void* QMenuBar;
#endif

#include <qtc/private_optargs.h>
#include <qtc/qaction.h>
#include <qtc/qpoint.h>
#include <qtc/qrect.h>

#define QMenuBar_new(...) QTC_OPTARG_REGISTER(QMenuBar_new, __VA_ARGS__)
static inline QMenuBar QMenuBar_new0();
static inline QMenuBar QMenuBar_new1(QWidget parent);
static inline void QMenuBar_destroy(QMenuBar menubar);

static inline bool QMenuBar_isDefaultUp(QMenuBar menubar);
static inline void QMenuBar_setDefaultUp(QMenuBar menubar, bool b);

static inline bool QMenuBar_isNativeMenuBar(QMenuBar menubar);
static inline void QMenuBar_setNativeMenuBar(QMenuBar menubar, bool b);

static inline void QMenuBar_setVisible(QMenuBar menubar, bool visible);
static inline QAction QMenuBar_actionAt(QMenuBar menubar, QPoint point);
static inline QRect QMenuBar_actionGeometry(QMenuBar menubar, QAction action);
static inline QAction QMenuBar_activeAction(QMenuBar menubar);
#define QMenuBar_addMenu(...) QTC_OPTARG_REGISTER(QMenuBar_addMenu, __VA_ARGS__)
#define QMenuBar_addMenu2(A, B) _Generic((B), QMenu: QMenuBar_addMenu_menu, QString: QMenuBar_addMenu_title)(A, B)
static inline QAction QMenuBar_addMenu_menu(QMenuBar menubar, QMenu menu);
static inline QMenu QMenuBar_addMenu_title(QMenuBar menubar, QString title);
static inline QMenu QMenuBar_addMenu3(QMenuBar menubar, QIcon icon, QString title);
static inline QAction QMenuBar_addSeparator(QMenuBar menubar);
static inline void QMenuBar_clear(QMenuBar menubar);

static inline int QMenuBar_heightForWidth(int width);
static inline QAction QMenuBar_insertMenu(QMenuBar menubar, QAction before, QMenu menu);
static inline QAction QMenuBar_insertSeparator(QMenuBar menubar, QAction before);
static inline QSize QMenuBar_minimumSizeHint(QMenuBar menubar);
static inline QSize QMenuBar_sizeHint(QMenuBar menubar);
static inline void QMenuBar_setActiveAction(QMenuBar menubar, QAction action);
#define QMenuBar_setCornerWidget(...) QTC_OPTARG_REGISTER(QMenuBar_setCornerWidget, __VA_ARGS__)
static inline void QMenuBar_setCornerWidget2(QMenuBar menubar, QWidget widget);
static inline void QMenuBar_setCornerWidget3(QMenuBar menubar, QWidget widget, Qt_Corner corner);
