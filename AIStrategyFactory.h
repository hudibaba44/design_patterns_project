#ifndef AISTRATEGYFACTORY_H
#define AISTRATEGYFACTORY_H

#include "AIStrategy.h"

class AIStrategyFactory
{
public:
    AIStrategyFactory();
    enum difficulty{
        easy,
        medium
    };
    AIStrategy *getAI(difficulty);
};

#endif // AISTRATEGYFACTORY_H
