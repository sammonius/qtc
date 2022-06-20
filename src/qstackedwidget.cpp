#include <QStackedWidget>

QStackedWidget *QStackedWidget_new1(QWidget *parent){return new QStackedWidget(parent);}
QStackedWidget *QStackedWidget_new0(){return new QStackedWidget();}
int QStackedWidget_addWidget(QStackedWidget *stackedwidget, QWidget *widget){return stackedwidget->addWidget(widget);}
int QStackedWidget_count(QStackedWidget *stackedwidget){return stackedwidget->count();}
int QStackedWidget_currentIndex(QStackedWidget *stackedwidget){return stackedwidget->currentIndex();}
QWidget *QStackedWidget_currentWidget(QStackedWidget *stackedwidget){return stackedwidget->currentWidget();}
int QStackedWidget_indexOf(QStackedWidget *stackedwidget, QWidget *widget){return stackedwidget->indexOf(widget);}
int QStackedWidget_insertWidget(QStackedWidget *stackedwidget, int index, QWidget *widget){return stackedwidget->insertWidget(index, widget);}
void QStackedWidget_removeWidget(QStackedWidget *stackedwidget, QWidget *widget){stackedwidget->removeWidget(widget);}
QWidget *QStackedWidget_widget(QStackedWidget *stackedwidget, int index){return stackedwidget->widget(index);}

void QStackedWidget_setCurrentIndex(QStackedWidget *stackedwidget, int index){stackedwidget->setCurrentIndex(index);}
void QStackedWidget_setCurrentWidget(QStackedWidget *stackedwidget, QWidget *widget){stackedwidget->setCurrentWidget(widget);}
