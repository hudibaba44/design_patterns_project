#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "TimeComponent.h"

class Player : public Character
{
public:
    Player();
    void update();
private:
    TimeComponent *timeComponent;

};

#endif // PLAYER_H
