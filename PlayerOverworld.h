#ifndef PLAYEROVERWORLD_H
#define PLAYEROVERWORLD_H


#include <QGraphicsPixmapItem>
class PlayerOverworld: public QGraphicsPixmapItem
{
public:
    PlayerOverworld();
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYEROVERWORLD_H
