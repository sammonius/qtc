#include <QString>
#include <QPointer>
#include <uchar.h>

extern "C" {

void* QString_new(char *text) {
	return new QString(text);
}

}
