#include "Game.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Player.h"
#include "QDebug"
#include "TimeComponent.h"
#include "HealthView.h"
#include <QProgressBar>
#include <QFormLayout>
#include <QPushButton>
#include <QRadioButton>
#include "TimeView.h"
#include <QTest>
#include <QLabel>
#include "MoveView.h"
#include "PlayerGenerator.h"
#include "ViewGenerator.h"
#include "LayoutGenerator.h"
#include "Enemy.h"
#include "SpriteView.h"
#include "AIStrategy.h"
#include "AIStrategyFactory.h"
#include "AIStrategyImpl.h"
Game *Game::instance = nullptr;

Game::~Game()
{
//    move_selected = nullptr;
}

Game *Game::create_instance()
{
    if(instance == nullptr){
        instance = new Game();
    }
    return instance;
}

void Game::setMoveSelected(std::vector<Character *> emitted_move)
{
//    qDebug() << "MOVE SELECTED\n";
    moveSelected = emitted_move;
}

void Game::playerAttack(Character *enemy)
{
    if(moveSelected.size()==0){
        return;
    }
    qDebug() << "ATTACK\n";
    int timeFlag = 1;
    for(auto i:moveSelected){
        if(i->getTime()<100){
            timeFlag = 0;
        }
    }
    if(timeFlag){
        qDebug() << "INSIDE ATTACK\n";
        std::vector<Character *> enemies;
        enemies.push_back(enemy);
        AttackInfo attackInfo;
        attackInfo.target = enemies;
        attackInfo.attacker = moveSelected;
        attackQueue.push(attackInfo);
    }
    //    move_selected = emitted_move;
}

void Game::enemyAttack(std::vector<Character *> enemyMove, Character *target)
{
    if(target == nullptr || enemyMove.size() == 0){
        return;
    }

    int timeFlag = 1;
    for(auto i:enemyMove){
        if(i->getTime()<100){
            timeFlag = 0;
        }
    }
    if(timeFlag){
        std::vector<Character *> players;
        players.push_back(target);
        AttackInfo attackInfo;
        attackInfo.target = players;
        attackInfo.attacker = enemyMove;
        attackQueue.push(attackInfo);
    }
}

void Game::loop()
{
    AIStrategy *temp = new easyAI();
    while(1){
        QTest::qWait(10);
        for(auto j:players){
            j->update();
        }
        for(auto j:timeViews){
            j->render();
        }
        for(auto j:healthViews){
            j->render();
        }
//        temp->AIAttack(enemy1, this);
        enemy1->update();

        makeAtack();
        std::vector<int> deadPlayers;
        for(unsigned long int i =0;i<players.size(); i++){
            if(players[i]->getHealth() == 0){
                deadPlayers.push_back(i);
            }
        }
        for(int i=deadPlayers.size()-1; i>=0;i--){
            players.erase(players.begin()+deadPlayers[i]);
        }
        for(auto i:spriteViews){
            i->render();
        }
        if(players.size() == 0){

            scene = new QGraphicsScene();
            scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

            // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
            // it can be used to visualize scenes)
            setScene(scene);
            scene->setActiveWindow(0);
        }
//            crono->update();
//            marle->update();
//            lucca->update();
//            timeViewCrono->render();
//            timeViewLucca->render();
//            timeViewMarle->render();
//            healthViewCrono->render();
//            healthViewLucca->render();
//            healthViewMarle->render();
//            crono->setHealth(crono->getHealth()-5);
//            lucca->setHealth(lucca->getHealth()-5);
//            marle->setHealth(marle->getHealth()-5);

    }
}

void Game::init()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);
    PlayerGenerator playerGenerator;
    ViewGenerator viewGenerator;
    players = playerGenerator.createPlayers({"crono", "marle", "lucca"});
    timeViews = viewGenerator.createTimeViews(players);
    healthViews = viewGenerator.createHealthViews(players);
    LayoutGenerator layoutGenerator;
    scene->addWidget(layoutGenerator.generateTimeAndHealth(players, timeViews, healthViews));
    show();
    std::vector<std::vector<MoveView *>> movesView = viewGenerator.createMoveViews(players);

    scene->addWidget(layoutGenerator.generateMoves(movesView));
//    show();
    QGraphicsPixmapItem *testItem = new QGraphicsPixmapItem();
    testItem->setPixmap(QPixmap(":/images/Crono - Battle (Front).gif"));
    testItem->setPos(200, 300);
    scene->addItem(testItem);
    AIStrategyFactory *aiStrategyFactory = new AIStrategyFactory;
    AIStrategy *aiStrategy = aiStrategyFactory->getAI(AIStrategyFactory::medium);
    AIComponent *aiComponent = new AIComponent(aiStrategy);
    enemy1 = new Enemy(aiComponent);
    enemy1->setSprite(":/images/Cyrus (Front).gif");
    enemy1->setMaxHealth(1000);
    enemy1->setName("cyrus");
    enemy1->setSpeed(15);
    enemy1->setPower(130);
    enemy1->setRegen(10);
    enemy1->setMoves({{enemy1}});
    spriteViews = viewGenerator.createSpriteViews(players);
    for(auto i:spriteViews){
        scene->addItem(i->getViewSprite());
        i->getViewSprite()->setPos(300, 300);
    }
    SpriteView *spriteView = new SpriteView(enemy1);
//    spriteView->setFlag(QGraphicsItem::ItemIsFocusable);
//    spriteView->getSprite()->setFocus();
    scene->addWidget(spriteView->getAttackSprite());
//    spriteView->
//    spriteView->getSprite()->setPos(300,300);
    spriteView->setAttackSignal();

}

Game::Game(QWidget * parent)
{

}

void Game::makeAtack()
{

    while(!attackQueue.empty()){
        qDebug() << "IN queue\n";
        AttackInfo attackInfo = attackQueue.front();
        attackQueue.pop();
        long long int damage = 0;
        for(auto i:attackInfo.attacker){
            damage *= 1.2;
        qDebug() << "Dmage is "<<i->getPower()<<"\n";
            damage+=i->getPower();
            i->setTime(0);
        }
        qDebug() << "Dmage is "<<damage<<"\n";
        for(auto i:attackInfo.target){
            i->setHealth(i->getHealth()-damage);
            qDebug() << "Targets health is "<< i->getHealth();
        }
    }

}

std::vector<Character *> Game::getPlayers() const
{
    return players;
}

