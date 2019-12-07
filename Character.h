#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>

class Character
{
    int health;
    int power;
    int speed;
    int time;
    std::vector<std::vector<Character *>> moves;

public:
    virtual ~Character();
    Character();
    int getHealth() const;
    void setHealth(int value);
    int getSpeed() const;
    void setSpeed(int value);
    int getPower() const;
    void setPower(int value);
    virtual void update() = 0;
    int getTime() const;
    void setTime(int value);

    std::vector<std::vector<Character *> > getMoves() const;
    void setMoves(const std::vector<std::vector<Character *> > &value);
};

#endif // CHARACTER_H
