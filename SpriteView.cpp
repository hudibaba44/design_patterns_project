#include "SpriteView.h"
#include <QObject>
#include "Game.h"
#include <QDebug>
#include <QPushButton>
#include <QGraphicsWidget>
#include <QLabel>
#include <QIcon>
SpriteView::SpriteView(Character *character):
    sprite(new QGraphicsPixmapItem()),
    character(character),
    attackButton(new QPushButton())
{
    QPixmap pixmap(character->getSprite().c_str());
    sprite->setPixmap(QPixmap(character->getSprite().c_str()));
}

QPushButton *SpriteView::getAttackSprite()
{
    return attackButton;
}

QGraphicsPixmapItem *SpriteView::getViewSprite()
{
    return sprite;
}


void SpriteView::setAttackSignal()
{

    QPixmap pixmap(character->getSprite().c_str());
    QIcon ButtonIcon(pixmap);
    attackButton->setIcon(ButtonIcon);
    attackButton->setIconSize(pixmap.rect().size());
    auto position = character->getPosition();
    attackButton->move(position.first, position.second);
    sprite->setPixmap(QPixmap(character->getSprite().c_str()));
    connect(attackButton, SIGNAL(clicked()),
                     this, SLOT(handleClick()));
    Game *gameInstance = Game::createInstance();
    QObject::connect(this, SIGNAL(spriteClicked(Character *)),
                     gameInstance, SLOT(playerAttack(Character *)));

}

void SpriteView::render()
{
    std::pair<int,int> position = character->getPosition();
    sprite->setPos(position.first, position.second);
    sprite->setPixmap(QPixmap(character->getSprite().c_str()));
}

void SpriteView::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "MOOISE CLICK";
    if(e->button()==Qt::RightButton)
            emit spriteClicked(character);
}
