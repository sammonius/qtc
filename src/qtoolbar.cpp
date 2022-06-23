#include <QToolBar>

extern "C" {

QToolBar *QToolBar_new0(){return new QToolBar();}
QToolBar *QToolBar_new_title(QString &title){return new QToolBar(title);}
QToolBar *QToolBar_new_parent(QWidget *parent){return new QToolBar(parent);}
QToolBar *QToolBar_new2(QString &title, QWidget *parent){return new QToolBar(title, parent);}
void QToolBar_destroy(QToolBar *bar){delete bar;}

Qt::ToolBarAreas QToolBar_allowedAreas(QToolBar* bar){return bar->allowedAreas();}
void QToolBar_setAllowedAreas(QToolBar *bar, Qt::ToolBarAreas areas){bar->setAllowedAreas(areas);}

bool QToolBar_isFloatable(QToolBar *bar){return bar->isFloatable();}
void QToolBar_setFloatable(QToolBar *bar, bool floatable){bar->setFloatable(floatable);}

bool QToolBar_isFloating(QToolBar *bar){return bar->isFloating();}

QSize QToolBar_iconSize(QToolBar *bar){return bar->iconSize();}
void QToolBar_setIconSize(QToolBar *bar, QSize *size){bar->setIconSize(*size);}

bool QToolBar_isMovable(QToolBar *bar){return bar->isMovable();}
void QToolBar_setMovable(QToolBar *bar, bool movable){bar->setMovable(movable);}

Qt::Orientation QToolBar_orientation(QToolBar *bar){return bar->orientation();}
void QToolBar_setOrientation(QToolBar *bar, Qt::Orientation o){bar->setOrientation(o);}

Qt::ToolButtonStyle QToolBar_toolButtonStyle(QToolBar *bar){return bar->toolButtonStyle();}
void QToolBar_setToolButtonStyle(QToolBar *bar, Qt::ToolButtonStyle tbs){bar->setToolButtonStyle(tbs);}

QAction *QToolBar_actionAt2(QToolBar *bar, QPoint &point){return bar->actionAt(point);}
QAction *QToolBar_actionAt3(QToolBar *bar, int x, int y){return bar->actionAt(x, y);}

QAction *QToolBar_addSeparator(QToolBar *bar){return bar->addSeparator();}
QAction *QToolBar_addWidget(QToolBar *bar, QWidget *widget){return bar->addWidget(widget);}
void QToolBar_clear(QToolBar *bar){bar->clear();}

QAction *QToolBar_insertSeparator(QToolBar *bar, QAction *before){return bar->insertSeparator(before);}
QAction *QToolBar_insertWidget(QToolBar *bar, QAction *before, QWidget *widget){return bar->insertWidget(before, widget);}
bool QToolBar_isAreaAllowed(QToolBar *bar, Qt::ToolBarArea area){return bar->isAreaAllowed(area);}

QAction *QToolBar_toggleViewAction(QToolBar *bar){return bar->toggleViewAction();}
QWidget *QToolBar_widgetForAction(QToolBar *bar, QAction *action){return bar->widgetForAction(action);}

}
