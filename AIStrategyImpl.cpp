#include "AIStrategyImpl.h"
#include <random>
#include <chrono>
#include <limits.h>
easyAI::easyAI()
{

}

void easyAI::AIAttack(Character *character, Game *game)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(1,100000);

    MoveChooser moveChooser;
    int moveNo = moveChooser.chooseRandomMove(character);
    std::vector<Character *> move = character->getMoves()[moveNo];
    std::vector<Character *> players = game->getPlayers();
    int playerSize = players.size();
    int playerNo = distribution(generator)%playerSize;
    Character *attackedPlayer = players[playerNo];
    game->enemyAttack(move, attackedPlayer);
}


mediumAI::mediumAI()
{

}

void mediumAI::AIAttack(Character *character, Game *game)
{
    MoveChooser moveChooser;
    int moveNo = moveChooser.chooseRandomMove(character);
    std::vector<Character *> move = character->getMoves()[moveNo];
    std::vector<Character *> players = game->getPlayers();
    Character *attackedPlayer = nullptr;
    int minHealth = INT_MAX;
    for(unsigned int i = 0;i<players.size(); i++){
        if(players[i]->getHealth() < minHealth){
            attackedPlayer = players[i];
            minHealth = players[i]->getHealth();
        }
    }
    game->enemyAttack(move, attackedPlayer);
}
