#ifndef PLAYERGENERATOR_H
#define PLAYERGENERATOR_H


#include "Character.h"
#include "Player.h"
#include <string>
#include <vector>
class PlayerGenerator
{
private:
    Character * createPlayer(std::string name);
public:
    PlayerGenerator();
    std::vector<Character *> createPlayers(std::vector<std::string> names);
};

#endif // PLAYERGENERATOR_H
