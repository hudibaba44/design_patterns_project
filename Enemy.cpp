#include "Enemy.h"
Enemy::Enemy(AIComponent *aiComponent) :
    timeComponent(new TimeComponent()),
    aiComponent(aiComponent),
    game(Game::createInstance()){
}

void Enemy::update()
{
    timeComponent->update(this);
    aiComponent->update(this, game);
}
