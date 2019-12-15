#include "Character.h"

double Character::getHealth() const
{
    return health;
}

void Character::setHealth(double value)
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

std::string Character::getSprite() const
{
    return sprite;
}

void Character::setSprite(std::string path)
{
    sprite = path;
}

int Character::getRegen() const
{
    return regen;
}

void Character::setRegen(int value)
{
    regen = value;
}

int Character::getMaxHealth() const
{
    return maxHealth;
}

void Character::setMaxHealth(int value)
{
    maxHealth = value;
    if(health == 0){
        health = maxHealth;
    }
}

void Character::setSprites(const std::vector<std::string> &value)
{
    sprites = value;
    sprite = sprites[sprites.size()-1];
}

std::pair<int, int> Character::getPosition() const
{
    return position;
}

void Character::setPosition(const std::pair<int, int> &value)
{
    position = value;
}

std::vector<std::string> Character::getSprites() const
{
    return sprites;
}

Character::~Character()
{
    
}

Character::Character(): health(0), time(0)
{
}
