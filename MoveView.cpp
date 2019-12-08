#include "MoveView.h"
#include <QStringBuilder>
#include <string>

MoveView::MoveView(const std::vector<Character *> &moves): moves(moves)
{
    QString moves_name = getQStringForMoves(moves);
    qRadioButton = new QRadioButton(moves_name);
    connect(qRadioButton, SIGNAL(clicked()), this, SLOT(handleClick()));
}

QRadioButton *MoveView::getQRadioButton() const
{
    return qRadioButton;
}

MoveView::~MoveView()
{

}

QString MoveView::getQStringForMoves(const std::vector<Character *> &moves)
{
    QString temp = "";
    unsigned long size = moves.size();
    for(unsigned long i = 0;i<size-1;i++){
        temp = temp % QString::fromStdString(moves[i]->getName()) % "+";
    }
    temp = temp % QString::fromStdString(moves[size-1]->getName());
    return temp;
}

//void MoveView::handleClick()
//{
//    emit movePressed(moves);
//}
