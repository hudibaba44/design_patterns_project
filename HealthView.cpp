#include "HealthView.h"

HealthView::HealthView(QGraphicsItem * parent): QGraphicsTextItem(parent){

}

//int HealthView::getHealth() const
//{
//    return health;
//}

void HealthView::setHealth(int value)
{
    health = value;
//    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}
