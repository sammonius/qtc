#include <QObject>

extern "C" {

void QObject_connect3(QObject *sender, void(QObject::*signal)(), void(*callback)()){
	QObject::connect(sender, signal, callback);
}

void QObject_connect4(QObject *sender, char* signal, QObject *receiver, char* slot){
	QObject::connect(sender, signal, receiver, slot);
}

}
