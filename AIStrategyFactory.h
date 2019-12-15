#ifndef AISTRATEGYFACTORY_H
#define AISTRATEGYFACTORY_H

#include "AIStrategy.h"
#include <string>
class AIStrategyFactory
{
public:
    AIStrategyFactory();
    enum difficulty{
        easy,
        medium
    };
    AIStrategy *getAI(difficulty);
    AIStrategy *getAI(std::string difficulty);
};

#endif // AISTRATEGYFACTORY_H
