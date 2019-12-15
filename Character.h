#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <QGraphicsPixmapItem>
class Character
{
    std::string name;
    int maxHealth;
    double health;
    int power;
    int speed;
    int regen;
    double time;
    std::pair<int,int> position;
    std::vector<std::vector<Character *>> moves;
    std::vector<std::string> sprites;
    std::string sprite;
public:
    virtual ~Character();
    Character();
    double getHealth() const;
    void setHealth(double value);
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
    std::string getSprite() const;
    void setSprite(std::string path);
    int getRegen() const;
    void setRegen(int value);
    int getMaxHealth() const;
    void setMaxHealth(int value);
    void setSprites(const std::vector<std::string> &value);
    std::pair<int, int> getPosition() const;
    void setPosition(const std::pair<int, int> &value);
    std::vector<std::string> getSprites() const;
};

#endif // CHARACTER_H
