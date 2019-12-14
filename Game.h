#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "HealthView.h"
#include "TimeComponent.h"
#include "Player.h"
#include <QObject>
#include <queue>
#include <TimeView.h>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    ~Game();
    static Game* create_instance();
    void init();
    std::vector<Character *> getPlayers() const;
    void enemyAttack(std::vector<Character *> enemy, Character *target);
    void loop();
public slots:
    void setMoveSelected(std::vector<Character *>);
    void playerAttack(Character *);
private:
    Game(QWidget * parent=nullptr);
    Game(const Game&) = delete;
    void makeAtack();
    static Game *instance;

    QGraphicsScene *scene;
    HealthView *healthView;
    TimeComponent *timeComponent;
    std::vector<Character *> players;
    std::vector<Character *> moveSelected;

    struct AttackInfo{
        std::vector<Character *> attacker;
        std::vector<Character *> target;
    };

    std::queue<AttackInfo> attackQueue;
    std::vector<TimeView *> timeViews;
    std::vector<HealthView *> healthViews;
    Character *enemy1;
};

#endif // GAME_H
