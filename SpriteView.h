#ifndef SPRITEVIEW_H
#define SPRITEVIEW_H
#include <QObject>
#include "QMouseEvent"
#include "Character.h"
#include <QGraphicsLayoutItem>
#include <QLabel>
#include <QPushButton>
class SpriteView: public QObject
{
    Q_OBJECT
public:
    SpriteView(Character *);
    QPushButton *getSprite();
    void setAttackSignal();
    void render();

signals:
    void spriteClicked(Character *);

public slots:
    void mousePressEvent(QMouseEvent *e);
    void handleClick(){
        emit spriteClicked(character);
    }
private:
    QGraphicsPixmapItem *sprite;
    Character *character;
    QPushButton *l;
};

#endif // SPRITEVIEW_H
