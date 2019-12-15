#include "Player.h"
#include "QDebug"
Player::Player() :
    timeComponent(new TimeComponent()),
    healthComponent(new HealthComponent()),
    imageComponent(new ImageComponent()){
}

void Player::update()
{
    timeComponent->update(this);
    healthComponent->update(this);
    imageComponent->update(this);
}
