#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include "Character.h"
#include "Game.h"
#include <AIStrategy.h>
class AIComponent
{
public:
    AIComponent(AIStrategy *);
    void update(Character *, Game *);
private:
    AIStrategy *aiStrategy;
};

#endif // AICOMPONENT_H
