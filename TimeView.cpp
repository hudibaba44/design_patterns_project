#include "TimeView.h"

TimeView::TimeView(Character *character) : progressBarView(new ProgressBarView(character)){
}

QProgressBar *TimeView::getProgressBar()
{
    return progressBarView->getProgressBar();
}
void TimeView::render()
{
    progressBarView->getProgressBar()->
            setValue(static_cast<int>(
                         progressBarView->getCharacter()->getTime()));
}


