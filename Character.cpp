#include "Character.h"

int Character::getHealth() const
{
    return health;
}

void Character::setHealth(int value)
{
    health = value;
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

Character::~Character()
{

}

Character::Character()
{
    time = 0;
    health = 100;
}
