#ifndef AISTRATEGYIMPL_H
#define AISTRATEGYIMPL_H


#include "AIStrategy.h"

#include <random>
#include <chrono>


class MoveChooser{
public:
    int chooseRandomMove(Character *character){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine generator (seed);
            std::uniform_int_distribution<int> distribution(1,100000);


            int moveSize = character->getMoves().size();
            int moveNo = distribution(generator)%moveSize;
            return moveNo;
    }
};
class easyAI : public AIStrategy{
public:
    easyAI();
    void AIAttack(Character *character, Game *game);
};

class mediumAI : public AIStrategy{
public:
    mediumAI();
    void AIAttack(Character *character, Game *game);
};

#endif // AISTRATEGYIMPL_H
