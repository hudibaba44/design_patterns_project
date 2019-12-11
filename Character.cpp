#include "Character.h"

int Character::getHealth() const
{
    return health;
}

void Character::setHealth(int value)
{

    health = value;
    if(maxHealth == 0){
        maxHealth = health;
    }
}


int Character::getSpeed() const
{
    return speed;
}

void Character::setSpeed(int value)
{
    speed = value;
}

int Character::getPower() const
{
    return power;
}

void Character::setPower(int value)
{
    power = value;
}

double Character::getTime() const
{
    return time;
}

void Character::setTime(double value)
{
    time = value;
}

std::vector<std::vector<Character *> > Character::getMoves() const
{
    return moves;
}

void Character::setMoves(const std::vector<std::vector<Character *> > &value)
{
    moves = value;
}

std::string Character::getName() const
{
    return name;
}

void Character::setName(const std::string &value)
{
    name = value;
}

std::string Character::getSprite() const
{
    return sprite;
}

void Character::setSprite(std::string path)
{
    sprite = path;
}

Character::~Character()
{
    
}

Character::Character(): maxHealth(0), time(0)
{
}
