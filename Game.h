#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "HealthView.h"
#include "TimeComponent.h"
#include "Player.h"
#include <QObject>
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    ~Game();
    static Game* create_instance();
    void init();
public slots:
    void set_move_selected(std::vector<Character *>);
    void playerAttack(Character *);
private:
    Game(QWidget * parent=nullptr);
    Game(const Game&) = delete;
    static Game *instance;

    QGraphicsScene *scene;
    HealthView *healthView;
    TimeComponent *timeComponent;
    Player *player;
    std::vector<Character *> move_selected;
};

#endif // GAME_H
