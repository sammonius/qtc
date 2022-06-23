#include <QLayout>

extern "C" {

QLayout::SizeConstraint QLayout_sizeConstraint(QLayout *layout){return layout->sizeConstraint();}
void QLayout_setSizeConstraint(QLayout *layout, QLayout::SizeConstraint sc){layout->setSizeConstraint(sc);}

}
