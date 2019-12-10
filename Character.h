#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>

class Character
{
    std::string name;
    int maxHealth;
    int health;
    int power;
    int speed;
    double time;
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
    double getTime() const;
    void setTime(double value);

    std::vector<std::vector<Character *> > getMoves() const;
    void setMoves(const std::vector<std::vector<Character *> > &value);
    std::string getName() const;
    void setName(const std::string &value);
};

#endif // CHARACTER_H
