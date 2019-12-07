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

Game::Game(QWidget * parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    healthView = new HealthView();
    scene->addItem(healthView);

    player = new Player();
    player->update();
    player->setPower(10);
    qDebug() << player->getPower();

     timeComponent = new TimeComponent();
//    for(int i=0;i<100;i++){
//        timeComponent->update(player);
//    }

    HealthView *healthView = new HealthView();
    scene->addItem(healthView);
    healthView->setHealth(100);

    QWidget *dummyWidget = new QWidget();
    QFormLayout *formLayout = new QFormLayout;
    TimeView *timeView = new TimeView(player);

    QProgressBar *bar1 = timeView->getProgressBar();
    QProgressBar *bar2 = new QProgressBar();
//    bar1->setValue(20);
    bar2->setValue(100);
//    formLayout->addRow("&Health:", bar1);
    formLayout->addRow("&Energy:", bar2);
    dummyWidget->setLayout(formLayout);
    dummyWidget->show();
//    dummyWidget->move(100,100);
    scene->addWidget(dummyWidget);
//    show();


//    connect(timeComponent, &TimeComponent::valueChanged, bar1, &QProgressBar::setValue);
//    for(int i=0;i<100;i++){
//        timeComponent->update(player);
//    }

       QWidget *window = new QWidget;
       QRadioButton *button1 = new QRadioButton("asdasdgasuidj");
       QRadioButton *button2 = new QRadioButton("Two");
       QRadioButton *button3 = new QRadioButton("Three");
       QRadioButton *button4 = new QRadioButton("Four");
       QRadioButton *button5 = new QRadioButton("Five");

       QLabel *temp = new QLabel(tr("Health"));
       temp->setBuddy(bar1);
       QGridLayout *layout = new QGridLayout;
       layout->addWidget(temp, 0, 0);
       layout->addWidget(bar1, 0, 1);
       layout->addWidget(button3, 1, 0);
//       layout->addWidget(button3, 1, 1);
       layout->addWidget(button4, 2, 0);
       layout->addWidget(button5, 2, 1);

       connect(button1, &QRadioButton::clicked, timeComponent, &TimeComponent::temp);

       window->setLayout(layout);
       window->show();
       window->move(200,200);
       scene->addWidget(window);

       show();

       for(int i=0;i<100;i++){
           QTest::qWait(100);
           timeComponent->update(player);
           timeView->render();
       }



}
