#ifndef MOVEVIEW_H
#define MOVEVIEW_H

#include <QRadioButton>
#include <vector>
#include "Character.h"
#include <QString>
#include <QObject>
class MoveView: public QObject
{
    Q_OBJECT
public:
    MoveView(const std::vector<Character *> &moves);
    QRadioButton *getQRadioButton() const;
    ~MoveView();

signals:
    void movePressed(std::vector<Character *>);

public slots:
    void handleClick(){
        emit movePressed(moves);
    }

private:
    QRadioButton *qRadioButton;
    QString getQStringForMoves(const std::vector<Character *> &moves);
    std::vector<Character *> moves;


};

#endif // MOVEVIEW_H
