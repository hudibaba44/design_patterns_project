#ifndef HEALTHVIEW_H
#define HEALTHVIEW_H

#include <QGraphicsTextItem>

class HealthView: public QGraphicsTextItem{
public:
    HealthView(QGraphicsItem * parent=nullptr);
    int getHealth() const;
    void setHealth(int value);

private:
    int health;
};



#endif // HEALTHVIEW_H
