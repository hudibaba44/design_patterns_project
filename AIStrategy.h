#ifndef AISTRATEGY_H
#define AISTRATEGY_H

#include "Game.h"
#include "Character.h"
class AIStrategy
{
public:
    AIStrategy();
    virtual void AIAttack(Character *character, Game *game) = 0;
};

#endif // AISTRATEGY_H
