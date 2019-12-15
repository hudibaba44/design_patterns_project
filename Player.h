#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "TimeComponent.h"
#include "HealthComponent.h"
#include "ImageComponent.h"

class Player : public Character
{
public:
    Player();
    void update();
private:
    TimeComponent *timeComponent;
    HealthComponent *healthComponent;
    ImageComponent *imageComponent;
};

#endif // PLAYER_H
