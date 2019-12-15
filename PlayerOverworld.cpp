#include "PlayerOverworld.h"
#include <QKeyEvent>
#include <EnemyOverworld.h>
#include <QDebug>
#include "Game.h"
PlayerOverworld::PlayerOverworld()
{

}


void PlayerOverworld::keyPressEvent(QKeyEvent *event){
    qDebug() << "key pressed\n";
    // move the player left and right
    if (event->key() == Qt::Key_Left){
//        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
//        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Up){
//        if (pos().x() + 100 < 800)
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
//        if (pos().x() + 100 < 800)
        setPos(x(),y()+10);
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    qDebug() <<colliding_items.size();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
//        QGraphicsItem *item = colliding_items[i];
//        qDebug() <<typeid(item);
        if (typeid(*(colliding_items[i])) == typeid(EnemyOverworld)){
            Game *game = Game::createInstance();
            qDebug() << "COLLIDE";
            game->battleStart(static_cast<EnemyOverworld*>(colliding_items[i]));
//           delete colliding_items[i];
        }
    }

}
