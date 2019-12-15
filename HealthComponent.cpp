#include "HealthComponent.h"
#include <QDebug>
HealthComponent::HealthComponent()
{

}

void HealthComponent::update(Character *character)
{
    double currentHealth = character->getHealth();
    if(currentHealth<=0){
        character->setHealth(0);
        return;
    }
    if(currentHealth>=character->getMaxHealth()){
        return;
    }
//    qDebug() << "Current " << currentHealth << "\n";
//    qDebug() << "Addition" << static_cast<double>(character->getRegen())/20<<"\n";
//    qDebug() << "Hearlth" << (currentHealth + static_cast<double>(character->getRegen())/100);
    character->setHealth(currentHealth + static_cast<double>(character->getRegen())/100);
}
