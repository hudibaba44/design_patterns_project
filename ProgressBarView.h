#ifndef PROGRESSBARVIEW_H
#define PROGRESSBARVIEW_H


#include <QProgressBar>
#include "Character.h"
class ProgressBarView
{
public:
    ProgressBarView(Character *);
    QProgressBar *getProgressBar();
    Character *getCharacter();
private:
    Character *character;
    QProgressBar *qProgressBar;
};

#endif // PROGRESSBARVIEW_H
