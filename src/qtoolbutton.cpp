#include <QToolButton>
#include <QMenu>
#include <QSize>
#include <qtc/private_returnpointer.h>

extern "C" {

QToolButton *QToolButton_new0(){return new QToolButton();}
QToolButton *QToolButton_new1(QWidget *parent){return new QToolButton(parent);}
void QToolButton_destroy(QToolButton *btn){delete btn;}

Qt::ArrowType QToolButton_arrowType(QToolButton *btn){return btn->arrowType();}
void QToolButton_setArrowType(QToolButton *btn, Qt::ArrowType arrowtype){btn->setArrowType(arrowtype);}

bool QToolButton_autoRaise(QToolButton *btn){return btn->autoRaise();}
void QToolButton_setAutoRaise(QToolButton *btn, bool autoraise){btn->setAutoRaise(autoraise);}

QAction *QToolButton_defaultAction(QToolButton *btn){return btn->defaultAction();}
void QToolButton_setDefaultAction(QToolButton *btn, QAction *action){btn->setDefaultAction(action);}

Qt::ToolButtonStyle QToolButton_toolButtonStyle(QToolButton *btn){return btn->toolButtonStyle();}
void QToolButton_setToolButtonStyle(QToolButton *btn, Qt::ToolButtonStyle toolButtonStyle){btn->setToolButtonStyle(toolButtonStyle);}

QToolButton::ToolButtonPopupMode QToolButton_popupMode(QToolButton *btn){return btn->popupMode();}
void QToolButton_setPopupMode(QToolButton *btn, QToolButton::ToolButtonPopupMode popupMode){btn->setPopupMode(popupMode);}

QMenu *QToolButton_menu(QToolButton *btn){return btn->menu();}
void QToolButton_setMenu(QToolButton *btn, QMenu *menu){btn->setMenu(menu);}

QSize QToolButton_sizeHint(QToolButton *btn){return btn->sizeHint();}
QSize QToolButton_minimumSizeHint(QToolButton *btn){return btn->minimumSizeHint();}

void QToolButton_showMenu(QToolButton btn);

}
