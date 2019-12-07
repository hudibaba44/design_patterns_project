#ifndef TIMEVIEW_H
#define TIMEVIEW_H

#include <QProgressBar>
#include "Character.h"
class TimeView
{
public:
    TimeView(Character *);
    QProgressBar *getProgressBar();
    void render();
private:
    Character *character;
    QProgressBar *qProgressBar;

};

#endif // TIMEVIEW_H
