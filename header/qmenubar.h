#pragma once
#ifndef __cplusplus
typedef void* QMenuBar;
#endif

#include <qtc/private_optargs.h>
#include <qtc/qaction.h>
#include <qtc/qpoint.h>
#include <qtc/qrect.h>

#define QMenuBar_new(...) QTC_OPTARG_REGISTER(QMenuBar_new, __VA_ARGS__)
inline QMenuBar QMenuBar_new0();
inline QMenuBar QMenuBar_new1(QWidget parent);
inline void QMenuBar_destroy(QMenuBar menubar);

inline bool QMenuBar_isDefaultUp(QMenuBar menubar);
inline void QMenuBar_setDefaultUp(QMenuBar menubar, bool b);

inline bool QMenuBar_isNativeMenuBar(QMenuBar menubar);
inline void QMenuBar_setNativeMenuBar(QMenuBar menubar, bool b);

inline void QMenuBar_setVisible(QMenuBar menubar, bool visible);
inline QAction QMenuBar_actionAt(QMenuBar menubar, QPoint point);
inline QRect QMenuBar_actionGeometry(QMenuBar menubar, QAction action);
inline QAction QMenuBar_activeAction(QMenuBar menubar);
#define QMenuBar_addMenu(...) QTC_OPTARG_REGISTER(QMenuBar_addMenu, __VA_ARGS__)
#define QMenuBar_addMenu2(A, B) _Generic((B), QMenu: QMenuBar_addMenu_menu, QString: QMenuBar_addMenu_title)(A, B)
inline QAction QMenuBar_addMenu_menu(QMenuBar menubar, QMenu menu);
inline QMenu QMenuBar_addMenu_title(QMenuBar menubar, QString title);
inline QMenu QMenuBar_addMenu3(QMenuBar menubar, QIcon icon, QString title);
inline QAction QMenuBar_addSeparator(QMenuBar menubar);
inline void QMenuBar_clear(QMenuBar menubar);

inline int QMenuBar_heightForWidth(int width);
inline QAction QMenuBar_insertMenu(QMenuBar menubar, QAction before, QMenu menu);
inline QAction QMenuBar_insertSeparator(QMenuBar menubar, QAction before);
inline QSize QMenuBar_minimumSizeHint(QMenuBar menubar);
inline QSize QMenuBar_sizeHint(QMenuBar menubar);
inline void QMenuBar_setActiveAction(QMenuBar menubar, QAction action);
#define QMenuBar_setCornerWidget(...) QTC_OPTARG_REGISTER(QMenuBar_setCornerWidget, __VA_ARGS__)
inline void QMenuBar_setCornerWidget2(QMenuBar menubar, QWidget widget);
inline void QMenuBar_setCornerWidget3(QMenuBar menubar, QWidget widget, Qt_Corner corner);
