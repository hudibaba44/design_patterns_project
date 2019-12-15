#ifndef PLAYERGENERATOR_H
#define PLAYERGENERATOR_H


#include "Character.h"

#include <string>
#include <vector>
#include <AIComponent.h>
class CharacterGenerator
{
private:
    Character *createPlayer(std::string name);
    Character *createEnemy(std::string name, AIComponent *aiComponent);
public:
    CharacterGenerator();
    std::vector<Character *> createPlayers(std::vector<std::string> names);
    std::vector<Character *> createEnemies(std::vector<std::string> names, AIComponent *aiComponent);
};

#endif // PLAYERGENERATOR_H
