#ifndef LAYOUTGENERATOR_H
#define LAYOUTGENERATOR_H

#include "QWidget"
#include <vector>
#include "TimeView.h"
#include "HealthView.h"
#include "MoveView.h"
class LayoutGenerator
{
public:
    LayoutGenerator();
    QWidget *generateTimeAndHealth(
            std::vector<Character *> players,
            std::vector<TimeView *> timeViews,
            std::vector<HealthView *> healthViews);
    QWidget *generateMoves(
            std::vector<std::vector<MoveView *>> movesView);
};

#endif // LAYOUTGENERATOR_H
