#include "Enemy.h"
Enemy::Enemy(AIComponent *aiComponent) :
    timeComponent(new TimeComponent()),
    aiComponent(aiComponent){
    game = Game::create_instance();
}

void Enemy::update()
{
    timeComponent->update(this);
    aiComponent->update(this, game);
}
