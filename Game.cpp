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
Game *Game::instance = nullptr;
void temp1(std::vector<Character *> moves){
    qDebug() << "PRESSED\n";
    for(auto i:moves){
        qDebug() << QString::fromStdString(i->getName());
    }
}

Game::~Game()
{

}

Game *Game::create_instance()
{
    if(instance == nullptr){
        instance = new Game();
    }
    return instance;
}

void Game::set_move_selected(std::vector<Character *> emitted_move)
{
    qDebug() << "MOVE SELECTED\n";
    move_selected = emitted_move;
}

void Game::playerAttack(Character *)
{
    qDebug() << "ATTACK\n";
//    move_selected = emitted_move;
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
    std::vector<Character *> players = playerGenerator.createPlayers({"crono", "marle", "lucca"});
    std::vector<TimeView *> timeViews = viewGenerator.createTimeViews(players);
    std::vector<HealthView *> healthViews = viewGenerator.createHealthViews(players);
    LayoutGenerator layoutGenerator;
    scene->addWidget(layoutGenerator.generateTimeAndHealth(players, timeViews, healthViews));
    show();
    std::vector<std::vector<MoveView *>> movesView = viewGenerator.createMoveViews(players);

    scene->addWidget(layoutGenerator.generateMoves(movesView));
//    show();
    QGraphicsPixmapItem *testItem = new QGraphicsPixmapItem();
    testItem->setPixmap(QPixmap(":/images/Crono - Battle (Front).gif"));
    testItem->setPos(200, 200);
    scene->addItem(testItem);

    Character *enemy1 = new Enemy();
    enemy1->setSprite(":/images/Cyrus (Front).gif");
    SpriteView *spriteView = new SpriteView(enemy1);
//    spriteView->setFlag(QGraphicsItem::ItemIsFocusable);
//    spriteView->getSprite()->setFocus();
    scene->addWidget(spriteView->getSprite());
//    spriteView->
//    spriteView->getSprite()->setPos(300,300);
    spriteView->setAttackSignal();
    for(int i=0;i<100;i++){
        QTest::qWait(100);
        for(auto j:players){
            j->update();
        }
        for(auto j:timeViews){
            j->render();
        }
        for(auto j:healthViews){
            j->render();
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

Game::Game(QWidget * parent)
{

}
