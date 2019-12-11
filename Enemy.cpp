#include "Enemy.h"
Enemy::Enemy() : timeComponent(new TimeComponent()){
}

void Enemy::update()
{
    timeComponent->update(this);
}
