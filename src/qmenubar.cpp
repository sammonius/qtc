#include <QMenuBar>
#include <QAction>
#include <QPoint>
#include <QRect>

QMenuBar *QMenuBar_new0(){return new QMenuBar();}
QMenuBar *QMenuBar_new1(QWidget *parent){return new QMenuBar(parent);}
void QMenuBar_destroy(QMenuBar *menubar){delete menubar;}

bool QMenuBar_isDefaultUp(QMenuBar *menubar){return menubar->isDefaultUp();}
void QMenuBar_setDefaultUp(QMenuBar *menubar, bool b){menubar->setDefaultUp(b);}

bool QMenuBar_isNativeMenuBar(QMenuBar *menubar){return menubar->isDefaultUp();}
void QMenuBar_setNativeMenuBar(QMenuBar *menubar, bool b){menubar->setNativeMenuBar(b);}

void QMenuBar_setVisible(QMenuBar *menubar, bool visible){menubar->setVisible(visible);}
QAction *QMenuBar_actionAt(QMenuBar *menubar, QPoint &point){return menubar->actionAt(point);}
/*QRect *QMenuBar_actionGeometry(QMenuBar *menubar, QAction *action)
QAction *QMenuBar_activeAction(QMenuBar *menubar)
QAction *QMenuBar_addMenu_menu(QMenuBar *menubar, QMenu *menu)
QMenu *QMenuBar_addMenu_title(QMenuBar *menubar, QString *title)
QMenu *QMenuBar_addMenu3(QMenuBar *menubar, QIcon *icon, QString *title)
QAction *QMenuBar_addSeparator(QMenuBar *menubar)
void QMenuBar_clear(QMenuBar *menubar)
int QMenuBar_heightForWidth(int width)
QAction *QMenuBar_insertMenu(QMenuBar *menubar, QAction *before, QMenu *menu)
QAction *QMenuBar_insertSeparator(QMenuBar *menubar, QAction *before)
QSize QMenuBar_minimumSizeHint(QMenuBar *menubar)
QSize QMenuBar_sizeHint(QMenuBar *menubar)
void QMenuBar_setActiveAction(QMenuBar *menubar, QAction *action)

void QMenuBar_setCornerWidget2(QMenuBar *menubar, QWidget *widget)
void QMenuBar_setCornerWidget3(QMenuBar *menubar, QWidget *widget, Qt::Corner corner);*/
