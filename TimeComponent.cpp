#include "TimeComponent.h"

#include "QDebug"
TimeComponent::TimeComponent()
{

}

void TimeComponent::update(Character *character)
{
    if(character->getHealth() <= 0){
        character->setTime(0);
        return;
    }
    if(character->getTime()>=100){
        return;
    }
    character->setTime(character->getTime()+(static_cast<double>(character->getSpeed())/10));
    if(character->getTime()>100){
        character->setTime(100);
    }
}

void TimeComponent::temp1(std::vector<Character *> moves){
    qDebug() << "PRESSED\n";
    for(auto i:moves){
        qDebug() << QString::fromStdString(i->getName());
    }
}

