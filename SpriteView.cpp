#include "SpriteView.h"
#include <QObject>
#include "Game.h"
#include <QDebug>
#include <QPushButton>
#include <QGraphicsWidget>
#include <QLabel>
#include <QIcon>
SpriteView::SpriteView(Character *character): sprite(new QGraphicsPixmapItem()), character(character), l(new QPushButton())
{
    QPixmap pixmap(character->getSprite().c_str());
    QIcon ButtonIcon(pixmap);
    l->setIcon(ButtonIcon);
    l->setIconSize(pixmap.rect().size());

    sprite->setPixmap(QPixmap(character->getSprite().c_str()));
//    spriteWidget = new SpriteWidget();
//    spriteWidget->setGraphicsItem(sprite);
    connect(l, SIGNAL(clicked()),
                     this, SLOT(handleClick()));
    //    connect(this, SIGNAL(mousePressEvent(QMouseEvent *)), this, SLOT(handleClick()));
}

QPushButton *SpriteView::getSprite()
{
    return l;
}

void SpriteView::setAttackSignal()
{

    //    QPushButton *attackButton = new QPushButton("Attack!", this);
    Game *gameInstance = Game::create_instance();
    QObject::connect(this, SIGNAL(spriteClicked(Character *)),
                     gameInstance, SLOT(playerAttack(Character *)));
//    QObject::connect(l, SIGNAL(clicked()),
//                     gameInstance, SLOT(playerAttack(Character *)));

}

void SpriteView::render()
{
    sprite->setPixmap(QPixmap(character->getSprite().c_str()));
}

void SpriteView::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "MOOISE CLICK";
    if(e->button()==Qt::RightButton)
            emit spriteClicked(character);
}
