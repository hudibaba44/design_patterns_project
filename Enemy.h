#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "TimeComponent.h"
#include <QGraphicsPixmapItem>
#include "Game.h"
#include "AIComponent.h"
class Enemy : public Character
{
public:
    Enemy(AIComponent *aiComponent);
    void update();
private:
    TimeComponent *timeComponent;
    AIComponent *aiComponent;
    QGraphicsPixmapItem *sprite;
    Game *game;
};
#endif // ENEMY_H
