#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "HealthView.h"
#include "TimeComponent.h"
#include "Player.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent=nullptr);

    QGraphicsScene *scene;
    HealthView *healthView;
    TimeComponent *timeComponent;
    Player *player;
};

#endif // GAME_H
