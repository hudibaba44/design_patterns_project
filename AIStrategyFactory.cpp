#include "AIStrategyFactory.h"

#include "AIStrategy.h"
#include "AIStrategyImpl.h"

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
