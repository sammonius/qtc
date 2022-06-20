#include <QPushButton>

extern "C" {

QPushButton* QPushButton_new3(QIcon icon, QString &text, QWidget *parent){return new QPushButton(icon, text, parent);}
QPushButton* QPushButton_new_icon_text(QIcon icon, QString &text, QWidget *parent){return new QPushButton(icon, text, parent);}
QPushButton* QPushButton_new_text_parent(QIcon icon, QString &text, QWidget *parent){return new QPushButton(icon, text, parent);}
QPushButton* QPushButton_new_text(QString &text){return new QPushButton(text);}
QPushButton* QPushButton_new0(){return new QPushButton();}
void QPushButton_destroy(QPushButton *pushbtn){delete pushbtn;}

void QPushBtton_setDefault(QPushButton *pushbtn, bool b){pushbtn->setDefault(b);}
bool QPushButton_isDefalt(QPushButton *pushbtn){return pushbtn->isDefault();}

void QPushButton_setAudoDefault(QPushButton *pushbtn, bool b){pushbtn->setAutoDefault(b);}
bool QPushButton_audoDefault(QPushButton *pushbtn){return pushbtn->autoDefault();}

void QPushButton_setFlat(QPushButton *pushbtn, bool b){pushbtn->setFlat(b);}
bool QPushButton_isFlat(QPushButton *pushbtn){return pushbtn->isFlat();}

void QPushButton_setMenu(QPushButton *pushbtn, QMenu *menu){pushbtn->setMenu(menu);}

}
