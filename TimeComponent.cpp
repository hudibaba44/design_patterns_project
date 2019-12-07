#include "TimeComponent.h"

#include "QDebug"
TimeComponent::TimeComponent()
{

}

void TimeComponent::update(Character *character)
{
    character->setTime(character->getTime()+1);
    emit valueChanged(character->getTime());
    qDebug() << character->getTime();
}

void TimeComponent::temp()
{
    qDebug() << "TEMP";
}
