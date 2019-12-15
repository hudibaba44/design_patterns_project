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
        character->setMaxHealth(300);
        character->setPower(13);
        character->setRegen(10);
        character->setSprites({
                                ":/images/Crono - Dead.gif",
                                ":/images/Crono - Kneel (Front).gif",
                                ":/images/Crono - Hit (Front).gif",
                                ":/images/Crono - Battle (Front).gif"
                              });
        character->setPosition({200, 300});
    }
    if(name == "marle"){
        character = new Player();
        character->setName("marle");
        character->setSpeed(10);
        character->setMaxHealth(200);
        character->setPower(12);
        character->setRegen(10);
        character->setSprites({
                                ":/images/Lucca - Dead.gif",
                                ":/images/Lucca - Kneel (Front).gif",
                                ":/images/Lucca - Hit (Front).gif",
                                ":/images/Lucca - Mallet (Front).gif"
                              });
        character->setPosition({300, 300});
    }
    if(name == "lucca"){
        character = new Player();
        character->setName("lucca");
        character->setSpeed(5);
        character->setMaxHealth(100);
        character->setPower(11);
        character->setRegen(10);
        character->setSprites({
                                ":/images/Marle - Dead.gif",
                                ":/images/Marle - Kneel (Front).gif",
                                ":/images/Marle - Hit (Front).gif",
                                ":/images/Marle - Ready1 (Front).gif"
                              });
    character->setPosition({400, 300});
    }
    return character;
}
