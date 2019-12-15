#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H


#include "Character.h"

class HealthComponent
{
public:
    HealthComponent();
    void update(Character *);
};

#endif // HEALTHCOMPONENT_H
