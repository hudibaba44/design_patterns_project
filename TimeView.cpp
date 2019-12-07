#include "TimeView.h"

TimeView::TimeView(Character *character_arg) : character(character_arg), qProgressBar(new QProgressBar()){
    qProgressBar->setRange(0, 100);
}

QProgressBar *TimeView::getProgressBar()
{
    return qProgressBar;
}

void TimeView::render()
{
    qProgressBar->setValue(static_cast<int>(character->getTime()));
}


