#include "LayoutGenerator.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QObject>
#include "Game.h"
LayoutGenerator::LayoutGenerator()
{

}

QWidget *LayoutGenerator::generateTimeAndHealth(std::vector<Character *> players,
                                                std::vector<TimeView *> timeViews,
                                                std::vector<HealthView *> healthViews)
{

    QWidget *window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    QLabel *nameLabel = new QLabel(QObject::tr("Name"));
    int row_index = 0;
    layout->addWidget(nameLabel, row_index, 0);
    for(unsigned long i=0;i<players.size(); i++){
        layout->addWidget(
                    new QLabel(
                        QObject::tr(
                            players[i]->getName().c_str())), row_index, static_cast<int>(i)+1);
    }
    row_index +=1;
    QLabel *timeLabel = new QLabel(QObject::tr("Time"));
    layout->addWidget(timeLabel, row_index, 0);
    for(unsigned long i=0;i<timeViews.size(); i++){
        layout->addWidget(timeViews[i]->getProgressBar(), row_index, static_cast<int>(i)+1);
    }
    row_index +=1;
    QLabel *healthLabel = new QLabel(QObject::tr("Health"));
    layout->addWidget(healthLabel, row_index, 0);
    for(unsigned long i=0;i<healthViews.size(); i++){
        layout->addWidget(healthViews[i]->getProgressBar(), row_index, static_cast<int>(i)+1);
    }
    window->setLayout(layout);
    window->show();
    window->move(0,0);
    return window;
}

QWidget *LayoutGenerator::generateMoves(std::vector<std::vector<MoveView *> > movesView)
{
//    connect(cronoMovesView[0], SIGNAL(movePressed(std::vector<Character *>)), timeComponent,
//            SLOT(temp1(std::vector<Character *>)));
    Game *gameInstance = Game::create_instance();
    QWidget *window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    for(unsigned long i=0;i<movesView.size();i++){
        for(unsigned long j=0;j<movesView[i].size(); j++){
            layout->addWidget(movesView[i][j]->getQRadioButton(), static_cast<int>(j), static_cast<int>(i));
            QObject::connect(movesView[i][j], SIGNAL(movePressed(std::vector<Character *>)),
                    gameInstance, SLOT(setMoveSelected(std::vector<Character *>)));
            //connect
        }
    }
    window->setLayout(layout);
    window->move(500,500);
    return window;
}
