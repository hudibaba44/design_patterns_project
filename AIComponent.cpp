#include "AIComponent.h"

AIComponent::AIComponent(AIStrategy *aiStrategy): aiStrategy(aiStrategy)
{

}

void AIComponent::update(Character *character, Game *game)
{
    aiStrategy->AIAttack(character, game);
}
