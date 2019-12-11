#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "TimeComponent.h"
#include <QGraphicsPixmapItem>

class Enemy : public Character
{
public:
    Enemy();
    void update();
private:
    TimeComponent *timeComponent;
    QGraphicsPixmapItem *sprite;

};
#endif // ENEMY_H
