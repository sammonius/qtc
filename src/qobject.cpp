#include <QObject>

extern "C" {

void QObject_connect(QObject *sender, char *signal, QObject *receiver, char *slot){
	QObject::connect(sender, signal, receiver, slot);
}

} 
