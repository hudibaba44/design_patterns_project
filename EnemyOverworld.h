#ifndef ENEMYOVERWORLD_H
#define ENEMYOVERWORLD_H

#include <QGraphicsPixmapItem>
#include <string>
class EnemyOverworld: public QGraphicsPixmapItem
{
public:
    EnemyOverworld(std::string name);
    std::string getName() const;

private:
    std::string name;
};

#endif // ENEMYOVERWORLD_H
