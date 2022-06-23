#include <QMdiArea>
#include <QMdiSubWindow>
#include <Qt>
#include <QTabWidget>

extern "C" {

QMdiArea *QMdiArea_new1(QWidget *parent){return new QMdiArea(parent);}
QMdiArea *QMdiArea_new0(){return new QMdiArea();}
void QMdiArea_destroy(QMdiArea *area){delete area;}

QMdiArea::WindowOrder QMdiArea_activationOrder(QMdiArea *area){return area->activationOrder();}
void QMdiArea_setActivationOrder(QMdiArea *area, QMdiArea::WindowOrder order){area->setActivationOrder(order);}

// TODO qbrush.h/cpp
//QBrush QMdiArea_background(QMdiArea *area){return (area->background());}
void QMdiArea_setBackground(QMdiArea *area, QBrush &brush){area->setBackground(brush);}

bool QMdiArea_documentMode(QMdiArea *area){return area->documentMode();}
void QMdiArea_setDocumentMode(QMdiArea *area, bool enabled){area->setDocumentMode(enabled);}

QTabWidget::TabPosition QMdiArea_tabPosition(QMdiArea *area){return area->tabPosition();}
void QMdiArea_setTabPosition(QMdiArea *area, QTabWidget::TabPosition position){area->setTabPosition(position);}

QTabWidget::TabShape QMdiArea_tabShape(QMdiArea *area){return area->tabShape();}
void QMdiArea_setTabShape(QMdiArea *area, QTabWidget::TabShape shape){area->setTabShape(shape);}

bool QMdiArea_tabsMovable(QMdiArea *area){return area->tabsMovable();}
void QMdiArea_setTabsMovable(QMdiArea *area, bool movable){area->setTabsMovable(movable);}

QMdiArea::ViewMode QMdiArea_viewMode(QMdiArea *area){return area->viewMode();}
void QMdiArea_setViewMode(QMdiArea *area, QMdiArea::ViewMode mode){area->setViewMode(mode);}

void QMdiArea_activateNextSubWindow(QMdiArea *area){area->activateNextSubWindow();}
void QMdiArea_activatePreviousSubWindow(QMdiArea *area){area->activatePreviousSubWindow();}
void QMdiArea_cascadeSubWindows(QMdiArea *area){area->cascadeSubWindows();}
void QMdiArea_closeActiveSubWindow(QMdiArea *area){area->closeActiveSubWindow();}
void QMdiArea_closeAllSubWindows(QMdiArea *area){area->closeAllSubWindows();}
void QMdiArea_setActiveSubWindow(QMdiArea *area, QMdiSubWindow *window){area->setActiveSubWindow(window);}
void QMdiArea_tileSubWindows(QMdiArea *area){area->tileSubWindows();}
QMdiSubWindow *QMdiArea_activeSubWindow(QMdiArea *area){return area->activeSubWindow();}
QMdiSubWindow *QMdiArea_addSubWindow3(QMdiArea *area, QWidget *widget, Qt::WindowFlags flags){return area->addSubWindow(widget, flags);}
QMdiSubWindow *QMdiArea_addSubWindow2(QMdiArea *area, QWidget *widget){return area->addSubWindow(widget);}
void QMdiArea_removeSubWindow(QMdiArea *area, QWidget *widget){area->removeSubWindow(widget);}
void QMdiArea_setOption3(QMdiArea *area, QMdiArea::AreaOption option, bool on){area->setOption(option, on);}
void QMdiArea_setOption2(QMdiArea *area, QMdiArea::AreaOption option){area->setOption(option);}
bool QMdiArea_testOption(QMdiArea *area, QMdiArea::AreaOption option){return area->testOption(option);};

//void(QMdiArea::*QMdiArea_subWindowActivated)(QMdiSubWindow*) = &QMdiArea::subWindowActivated;

}
