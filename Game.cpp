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
#include "CharacterGenerator.h"
#include "ViewGenerator.h"
#include "LayoutGenerator.h"
#include "Enemy.h"
#include "SpriteView.h"
#include "AIStrategy.h"
#include "AIStrategyFactory.h"
#include "AIStrategyImpl.h"
#include "PlayerOverworld.h"
#include "EnemyOverworld.h"
#include <QGraphicsProxyWidget>
#include <iostream>

Game *Game::instance = nullptr;

Game::~Game()
{
//    move_selected = nullptr;
}

Game *Game::createInstance()
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

void Game::setDifficulty()
{
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());
    difficulty = pButton->text().toStdString();
    qDebug() << difficulty.c_str();
    setScene(worldScene);
    initBattleScene();
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

void Game::battleStart(EnemyOverworld *enemy)
{
    worldScene->removeItem(enemy);
    playerOverworld->clearFocus();
    worldScene->removeItem(playerOverworld);
    delete playerOverworld;
    qDebug() << enemy->getName().c_str();
    if(enemyProxy){
        battleScene->removeItem(enemyProxy);
        enemyProxy->setWidget(nullptr);
        delete enemyProxy;
        enemyProxy = nullptr;
    }

    SpriteView *enemyView = nullptr;
    int enemyIndex = -1;
    for(unsigned long int i=0;i<enemies.size(); i++){
        if(enemy->getName() == enemies[i]->getName()){
            activeEnemy = enemies[i];
            enemyView = buttonSpriteViews[i];
            enemyIndex = i;
            break;
        }
    }
    qDebug() << "ENEMY view is "<< enemyView;
    enemyProxy = battleScene->addWidget(enemyView->getAttackSprite());
    setScene(battleScene);
    int result = loop();
    if(!result){
        setScene(loseScene);
    }
    if(result){
        if(enemyIndex>=0){
            enemies.erase(enemies.begin() + enemyIndex);
            buttonSpriteViews.erase(buttonSpriteViews.begin() + enemyIndex);
        }
        qDebug() << "ENEMY ERSULT IS "<<enemyIndex;
        qDebug() << "ENEMY ERSULT IS "<<enemies.size();
        if(enemies.size() == 0){
            setScene(winScene);
            return;
        }
        playerOverworld = new PlayerOverworld();
        QPixmap pixmap(":/images/Crono - Battle (Front).gif");
        playerOverworld->setPixmap(pixmap);
        playerOverworld->setPos(400, 400);
        playerOverworld->setFlag(QGraphicsItem::ItemIsFocusable);
        playerOverworld->setFocus();
        worldScene->addItem(playerOverworld);
        setScene(worldScene);
        battleScene->removeItem(enemyProxy);
        enemyProxy->setWidget(nullptr);
        delete enemyProxy;
        enemyProxy = nullptr;
        viewport()->update();
        //        enemyProxy = nullptr;
//        worldScene->removeItem(enemy);
    }
    viewport()->update();
}

int Game::loop()
{
    unsigned long long int previous = QDateTime::currentMSecsSinceEpoch();
    unsigned long long int lag = 0;
    while(1){
        unsigned long long int current = QDateTime::currentMSecsSinceEpoch();
        unsigned long long int elapsed = current-previous;
        previous = current;
        lag+=elapsed;
        while(lag >= 10){
            for(auto j:players){
                j->update();
            }
            activeEnemy->update();
            makeAtack();
            lag-=10;
        }
        QTest::qWait(10);
        render();
        if(activeEnemy->getHealth()<=0){
            return 1;
        }
        removeDeadPlayers();
        if(players.size() == 0){
            return 0;
        }
    }
}

void Game::generateWorldScene()
{
    worldScene = new QGraphicsScene();
    generatePlayerOverworld();
    generateEnemiesOverworld();
}

void Game::generateDifficultyScene()
{
    difficultyScene = new QGraphicsScene();
    QPushButton *buttonEasy= new QPushButton("Easy");
    buttonEasy->move(300, 300);
    difficultyScene->addWidget(buttonEasy);

    QPushButton *buttonMedium= new QPushButton("Medium");
    buttonMedium->move(400, 300);
    difficultyScene->addWidget(buttonMedium);
    connect(buttonEasy, SIGNAL(clicked()), this, SLOT(setDifficulty()));
    connect(buttonMedium, SIGNAL(clicked()), this, SLOT(setDifficulty()));
}

void Game::generateWinAndLoseScene()
{
    loseScene = new QGraphicsScene();
    QGraphicsTextItem *textLose = new QGraphicsTextItem("You Lose");
    textLose->setPos(400, 400);
    loseScene->addItem(textLose);

    winScene = new QGraphicsScene();
    QGraphicsTextItem *textWin = new QGraphicsTextItem("You Win");
    textWin->setPos(400, 400);
    winScene->addItem(textWin);
}

void Game::generatePlayerOverworld()
{
    playerOverworld = new PlayerOverworld();
    QPixmap pixmap(":/images/Crono - Battle (Front).gif");
    playerOverworld->setPixmap(pixmap);
    playerOverworld->setPos(400,400);
    playerOverworld->setFlag(QGraphicsItem::ItemIsFocusable);
    playerOverworld->setFocus();
    worldScene->addItem(playerOverworld);
}

void Game::generateEnemiesOverworld()
{
    EnemyOverworld *enemy1 = new EnemyOverworld("Gato");
    QPixmap pixmap1(":/images/Gato (Front).gif");
    enemy1->setPixmap(pixmap1);
    enemy1->setPos(0,400);

    EnemyOverworld *enemy2 = new EnemyOverworld("Cyrus");
    QPixmap pixmap2(":/images/Cyrus (Front).gif");
    enemy2->setPixmap(pixmap2);
    enemy2->setPos(400,0);

    EnemyOverworld *enemy3 = new EnemyOverworld("Heckran");
    QPixmap pixmap3(":/images/Heckran (Front).gif");
    enemy3->setPixmap(pixmap3);
    enemy3->setPos(800,400);

    worldScene->addItem(enemy1);
    worldScene->addItem(enemy2);
    worldScene->addItem(enemy3);
    enemyOverworld.push_back(enemy1);
    enemyOverworld.push_back(enemy2);
    enemyOverworld.push_back(enemy3);
}

void Game::render()
{
    for(auto j:timeViews){
        j->render();
    }
    for(auto j:healthViews){
        j->render();
    }
    for(auto i:spriteViews){
        i->render();
    }
}

void Game::removeDeadPlayers()
{
    std::vector<int> deadPlayers;
    for(unsigned long int i =0;i<players.size(); i++){
        if(players[i]->getHealth() == 0){
            deadPlayers.push_back(i);
        }
    }
    for(int i=deadPlayers.size()-1; i>=0;i--){
        players.erase(players.begin()+deadPlayers[i]);
    }
}

void Game::init(){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);
    generateDifficultyScene();
    generateWinAndLoseScene();
    generateWorldScene();
    setScene(difficultyScene);
}
void Game::initBattleScene()
{
    battleScene = new QGraphicsScene();
    CharacterGenerator playerGenerator;
    ViewGenerator viewGenerator;
    players = playerGenerator.createPlayers({"crono", "marle", "lucca"});
    timeViews = viewGenerator.createTimeViews(players);
    healthViews = viewGenerator.createHealthViews(players);
    LayoutGenerator layoutGenerator;
    battleScene->addWidget(layoutGenerator.generateTimeAndHealth(players, timeViews, healthViews));
    std::vector<std::vector<MoveView *>> movesView = viewGenerator.createMoveViews(players);
    battleScene->addWidget(layoutGenerator.generateMoves(movesView));
    AIStrategyFactory *aiStrategyFactory = new AIStrategyFactory;
    AIStrategy *aiStrategy = aiStrategyFactory->getAI(difficulty);
    AIComponent *aiComponent = new AIComponent(aiStrategy);
    enemies = playerGenerator.createEnemies({"Gato", "Cyrus", "Heckran"}, aiComponent);
    spriteViews = viewGenerator.createSpriteViews(players);
    for(auto i:spriteViews){
        battleScene->addItem(i->getViewSprite());
//        i->getViewSprite()->setPos(300, 300);
    }
    buttonSpriteViews = viewGenerator.createSpriteViews(enemies);
    for(auto i:buttonSpriteViews){
        i->setAttackSignal();
    }
}

Game::Game(QWidget * parent)
{
    enemyProxy = nullptr;
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

