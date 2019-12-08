#include "HealthView.h"

HealthView::HealthView(Character *character) : progressBarView(new ProgressBarView(character)){
    progressBarView->getProgressBar()->setRange(0, character->getHealth());
}

QProgressBar *HealthView::getProgressBar()
{
    return progressBarView->getProgressBar();
}
void HealthView::render()
{
    progressBarView->getProgressBar()->
            setValue(static_cast<int>(
                         progressBarView->getCharacter()->getHealth()));
}

