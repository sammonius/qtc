#pragma once
#ifndef __cplusplus
typedef void* QMenuBar;
#endif

#include <qtc/private_optargs.h>
#include <qtc/qaction.h>
#include <qtc/qpoint.h>
#include <qtc/qrect.h>

#define QMenuBar_new(...) QTC_OPTARG_REGISTER(QMenuBar_new, __VA_ARGS__)
  QMenuBar QMenuBar_new0();
  QMenuBar QMenuBar_new1(QWidget parent);
  void QMenuBar_destroy(QMenuBar menubar);

  bool QMenuBar_isDefaultUp(QMenuBar menubar);
  void QMenuBar_setDefaultUp(QMenuBar menubar, bool b);

  bool QMenuBar_isNativeMenuBar(QMenuBar menubar);
  void QMenuBar_setNativeMenuBar(QMenuBar menubar, bool b);

  void QMenuBar_setVisible(QMenuBar menubar, bool visible);
  QAction QMenuBar_actionAt(QMenuBar menubar, QPoint point);
  QRect QMenuBar_actionGeometry(QMenuBar menubar, QAction action);
  QAction QMenuBar_activeAction(QMenuBar menubar);
#define QMenuBar_addMenu(...) QTC_OPTARG_REGISTER(QMenuBar_addMenu, __VA_ARGS__)
#define QMenuBar_addMenu2(A, B) _Generic((B), QMenu: QMenuBar_addMenu_menu, QString: QMenuBar_addMenu_title)(A, B)
  QAction QMenuBar_addMenu_menu(QMenuBar menubar, QMenu menu);
  QMenu QMenuBar_addMenu_title(QMenuBar menubar, QString title);
  QMenu QMenuBar_addMenu3(QMenuBar menubar, QIcon icon, QString title);
  QAction QMenuBar_addSeparator(QMenuBar menubar);
  void QMenuBar_clear(QMenuBar menubar);

  int QMenuBar_heightForWidth(int width);
  QAction QMenuBar_insertMenu(QMenuBar menubar, QAction before, QMenu menu);
  QAction QMenuBar_insertSeparator(QMenuBar menubar, QAction before);
  QSize QMenuBar_minimumSizeHint(QMenuBar menubar);
  QSize QMenuBar_sizeHint(QMenuBar menubar);
  void QMenuBar_setActiveAction(QMenuBar menubar, QAction action);
#define QMenuBar_setCornerWidget(...) QTC_OPTARG_REGISTER(QMenuBar_setCornerWidget, __VA_ARGS__)
  void QMenuBar_setCornerWidget2(QMenuBar menubar, QWidget widget);
  void QMenuBar_setCornerWidget3(QMenuBar menubar, QWidget widget, Qt_Corner corner);
