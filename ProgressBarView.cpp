#include "ProgressBarView.h"


ProgressBarView::ProgressBarView(Character * character)
    : character(character), qProgressBar(new QProgressBar()){
    qProgressBar->setRange(0, 100);
}

QProgressBar *ProgressBarView::getProgressBar()
{
    return qProgressBar;
}

Character *ProgressBarView::getCharacter()
{
    return character;
}
