#include "Player.h"
#include "QDebug"
Player::Player() : timeComponent(new TimeComponent()){
}

void Player::update()
{
    timeComponent->update(this);
}
