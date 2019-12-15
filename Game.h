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
#include "SpriteView.h"
#include "PlayerOverworld.h"
#include "EnemyOverworld.h"
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    ~Game();
    static Game* create_instance();
    void init();
    void initAll();
    std::vector<Character *> getPlayers() const;
    void enemyAttack(std::vector<Character *> enemy, Character *target);
    void battleStart(EnemyOverworld *enemy);
    int loop();
public slots:
    void setMoveSelected(std::vector<Character *>);
    void playerAttack(Character *);
    void setDifficulty();
private:
    Game(QWidget * parent=nullptr);
    Game(const Game&) = delete;
    void makeAtack();
    static Game *instance;
    void generateWorldScene();
    QGraphicsScene *battleScene;
    QGraphicsScene *worldScene;
    QGraphicsScene *winScene;
    QGraphicsScene *loseScene;
    QGraphicsScene *difficultyScene;
    HealthView *healthView;
    TimeComponent *timeComponent;
    std::vector<Character *> players;
    std::vector<Character *> enemies;
    std::vector<Character *> moveSelected;

    struct AttackInfo{
        std::vector<Character *> attacker;
        std::vector<Character *> target;
    };

    std::queue<AttackInfo> attackQueue;
    std::vector<TimeView *> timeViews;
    std::vector<HealthView *> healthViews;
    std::vector<SpriteView *> spriteViews;
    std::vector<SpriteView *> buttonSpriteViews;
    std::vector<EnemyOverworld *> enemyOverworld;
    PlayerOverworld * playerOverworld;
    QGraphicsProxyWidget *enemyProxy;
    Character *activeEnemy;
    std::string difficulty;
};

#endif // GAME_H
