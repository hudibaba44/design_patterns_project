#include "AIStrategyFactory.h"

#include "AIStrategy.h"
#include "AIStrategyImpl.h"
#include <algorithm>
AIStrategyFactory::AIStrategyFactory()
{

}

AIStrategy *AIStrategyFactory::getAI(AIStrategyFactory::difficulty input)
{
    AIStrategy *aiStrategy = nullptr;
    if(input == AIStrategyFactory::easy){
        aiStrategy = new easyAI();
    }
    else if(input == AIStrategyFactory::medium){
        aiStrategy = new mediumAI();
    }
    return aiStrategy;
}

AIStrategy *AIStrategyFactory::getAI(std::string difficulty)
{
    std::transform(difficulty.begin(), difficulty.end(), difficulty.begin(),
                                [](unsigned char c){ return std::tolower(c); });

    if(difficulty == "easy"){
        return getAI(AIStrategyFactory::easy);
    }
    else if(difficulty == "medium"){
        return getAI(AIStrategyFactory::medium);
    }
    return nullptr;
}
