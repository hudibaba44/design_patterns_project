#include "PlayerGenerator.h"

PlayerGenerator::PlayerGenerator()
{

}

std::vector<Character *> PlayerGenerator::createPlayers(std::vector<std::string> names)
{
    assert(names.size() == 3);
    std::vector<Character *> players;
    for(auto i:names){
        players.push_back(createPlayer(i));
    }

    players[0]->setMoves({{players[0]},{players[0], players[1]}, {players[0], players[2]}});
    players[1]->setMoves({{players[1]},{players[1], players[2]}, {players[1], players[0]}});
    players[2]->setMoves({{players[2]},{players[2], players[0]}, {players[2], players[1]}});
    return players;
}

Character *PlayerGenerator::createPlayer(std::string name)
{
    Character *character = nullptr;
    if(name == "crono"){
        character = new Player();
        character->setName("crono");
        character->setSpeed(15);
        character->setHealth(300);
        character->setPower(13);
    }
    if(name == "marle"){
        character = new Player();
        character->setName("marle");
        character->setSpeed(10);
        character->setHealth(200);
        character->setPower(12);
    }
    if(name == "lucca"){
        character = new Player();
        character->setName("lucca");
        character->setSpeed(5);
        character->setHealth(100);
        character->setPower(11);
    }
    return character;
}
