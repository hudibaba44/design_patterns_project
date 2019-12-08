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

void temp1(std::vector<Character *> moves){
    qDebug() << "PRESSED\n";
    for(auto i:moves){
        qDebug() << QString::fromStdString(i->getName());
    }
}

Game::Game(QWidget * parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

//    healthView = new HealthView();
//    scene->addItem(healthView);


//    for(int i=0;i<100;i++){
//        timeComponent->update(player);
//    }

//    HealthView *healthView = new HealthView();
//    scene->addItem(healthView);
//    healthView->setHealth(100);

//    QWidget *dummyWidget = new QWidget();
//    QFormLayout *formLayout = new QFormLayout;


//    QProgressBar *bar2 = new QProgressBar();
////    bar1->setValue(20);
//    bar2->setValue(100);
////    formLayout->addRow("&Health:", bar1);
//    formLayout->addRow("&Energy:", bar2);
//    dummyWidget->setLayout(formLayout);
//    dummyWidget->show();
////    dummyWidget->move(100,100);
//    scene->addWidget(dummyWidget);
////    show();


//    connect(timeComponent, &TimeComponent::valueChanged, bar1, &QProgressBar::setValue);
//    for(int i=0;i<100;i++){
//        timeComponent->update(player);
//    }

        Character *crono = new Player();
        crono->setName("crono");
        crono->setSpeed(15);
        crono->setHealth(300);
        Character *marle = new Player();
        marle->setName("marle");
        marle->setSpeed(10);
        marle->setHealth(200);
        Character *lucca = new Player();
        lucca->setName("lucca");
        lucca->setSpeed(5);
        lucca->setHealth(100);

        crono->setMoves({{crono},{crono, marle}, {crono, lucca}});
        marle->setMoves({{marle},{marle, crono}, {marle, lucca}});
        lucca->setMoves({{lucca},{lucca, marle}, {lucca, crono}});

//        player->update();
//        player->setPower(10);
//        qDebug() << player->getPower();

        timeComponent = new TimeComponent();

        TimeView *timeViewCrono = new TimeView(crono);
        QProgressBar *timeBarCrono = timeViewCrono->getProgressBar();

        TimeView *timeViewMarle= new TimeView(marle);
        QProgressBar *timeBarMarle= timeViewMarle->getProgressBar();

        TimeView *timeViewLucca= new TimeView(lucca);
        QProgressBar *timeBarLucca= timeViewLucca->getProgressBar();

        HealthView *healthViewCrono = new HealthView(crono);
        QProgressBar *healthBarCrono = healthViewCrono->getProgressBar();

        HealthView *healthViewMarle= new HealthView(marle);
        QProgressBar *healthBarMarle= healthViewMarle->getProgressBar();

        HealthView *healthViewLucca= new HealthView(lucca);
        QProgressBar *healthBarLucca= healthViewLucca->getProgressBar();



        QWidget *window = new QWidget;
        QGridLayout *layout = new QGridLayout;
        QLabel *timeLabel = new QLabel(tr("Time"));
        layout->addWidget(timeLabel, 0, 0);
        layout->addWidget(timeBarCrono, 0, 1);
        layout->addWidget(timeBarMarle, 0, 2);
        layout->addWidget(timeBarLucca, 0, 3);

        QLabel *healthLabel = new QLabel(tr("Health"));
        layout->addWidget(healthLabel, 1, 0);
        layout->addWidget(healthBarCrono, 1, 1);
        layout->addWidget(healthBarMarle, 1, 2);
        layout->addWidget(healthBarLucca, 1, 3);

        //       connect(button1, &QRadioButton::clicked, timeComponent, &TimeComponent::temp);

        window->setLayout(layout);
        window->show();
        window->move(0,0);
        scene->addWidget(window);

        show();
        std::vector<std::vector<Character *>> cronoMoves = crono->getMoves();
        std::vector<std::vector<Character *>> marleMoves = marle->getMoves();
        std::vector<std::vector<Character *>> luccaMoves = lucca->getMoves();
        std::vector<MoveView *> cronoMovesView;
        std::vector<MoveView *> marleMovesView;
        std::vector<MoveView *> luccaMovesView;

        for(auto i:cronoMoves){
            cronoMovesView.push_back(new MoveView(i));
        }
        for(auto i:marleMoves){
            marleMovesView.push_back(new MoveView(i));
        }
        for(auto i:luccaMoves){
            luccaMovesView.push_back(new MoveView(i));
        }
        QRadioButton *button1 = cronoMovesView[0]->getQRadioButton();
        QRadioButton *button2 = cronoMovesView[1]->getQRadioButton();
        QRadioButton *button3 = cronoMovesView[2]->getQRadioButton();

//        for(auto i:cronoMovesView){
//            connect(i, )
//        }
        connect(cronoMovesView[0], SIGNAL(movePressed(std::vector<Character *>)), timeComponent,
                SLOT(temp1(std::vector<Character *>)));



        QWidget *window1 = new QWidget;
        QGridLayout *layout1 = new QGridLayout;
        layout1->addWidget(button1, 0, 0);
        layout1->addWidget(button2, 1, 0);
        layout1->addWidget(button3, 2, 0);
//        button1->hide();
        window1->setLayout(layout1);
//        window1->show();
        window1->move(500,500);
        scene->addWidget(window1);

        for(int i=0;i<100;i++){
            QTest::qWait(100);
            crono->update();
            marle->update();
            lucca->update();
            timeViewCrono->render();
            timeViewLucca->render();
            timeViewMarle->render();
            healthViewCrono->render();
            healthViewLucca->render();
            healthViewMarle->render();
            crono->setHealth(crono->getHealth()-5);
            lucca->setHealth(lucca->getHealth()-5);
            marle->setHealth(marle->getHealth()-5);

        }



}
