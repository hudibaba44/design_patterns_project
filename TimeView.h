#ifndef TIMEVIEW_H
#define TIMEVIEW_H

#include <QProgressBar>
#include "Character.h"
#include "ProgressBarView.h"
class TimeView
{
public:
    TimeView(Character *);
    QProgressBar *getProgressBar();
    void render();
private:
    ProgressBarView *progressBarView;
};

#endif // TIMEVIEW_H
