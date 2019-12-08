#ifndef HEALTHVIEW_H
#define HEALTHVIEW_H

#include <QGraphicsTextItem>

#include <QProgressBar>
#include "Character.h"
#include "ProgressBarView.h"
class HealthView
{
public:
    HealthView(Character *);
    QProgressBar *getProgressBar();
    void render();
private:
    ProgressBarView *progressBarView;
};


#endif // HEALTHVIEW_H
