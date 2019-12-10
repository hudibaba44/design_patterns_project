#ifndef VIEWGENERATOR_H
#define VIEWGENERATOR_H


#include <vector>
#include "TimeView.h"
#include "HealthView.h"
#include "MoveView.h"
class ViewGenerator
{
public:
    ViewGenerator();
    std::vector<TimeView *> createTimeViews(std::vector<Character *>);
    std::vector<HealthView *> createHealthViews(std::vector<Character *>);
    std::vector<std::vector<MoveView *>> createMoveViews(std::vector<Character *>);

};

#endif // VIEWGENERATOR_H
