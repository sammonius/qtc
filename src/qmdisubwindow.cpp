#include <Qt>
#include <QMdiArea>
#include <QMdiSubWindow>

extern "C" {

QMdiSubWindow *QMdiSubWindow_new0(){return new QMdiSubWindow();};
QMdiSubWindow *QMdiSubWindow_new_flags(Qt::WindowFlags flags){return new QMdiSubWindow(nullptr, flags);};
QMdiSubWindow *QMdiSubWindow_new_parent(QWidget *parent){return new QMdiSubWindow(parent);};
QMdiSubWindow *QMdiSubWindow_new2(QWidget *parent, Qt::WindowFlags flags){return new QMdiSubWindow(parent, flags);};

int QMdiSubWindow_keyboardPageStep(QMdiSubWindow *window){return window->keyboardPageStep();}
void QMdiSubWindow_setKeyboardPageStep(QMdiSubWindow *window, int step){window->setKeyboardPageStep(step);}

int QMdiSubWindow_keyboardSingleStep(QMdiSubWindow *window){return window->keyboardSingleStep();}
void QMdiSubWindow_setKeyboardSingleStep(QMdiSubWindow *window, int step){window->setKeyboardSingleStep(step);}

QMdiArea *QMdiSubWindow_mdiArea(QMdiSubWindow *window){return window->mdiArea();}
void QMdiSubWindow_showShaded(QMdiSubWindow *window){window->showShaded();}

}
