#include "ViewGenerator.h"

ViewGenerator::ViewGenerator()
{

}

std::vector<TimeView *> ViewGenerator::createTimeViews(std::vector<Character *> characters)
{
    std::vector<TimeView *> vec;
    for(auto i:characters){
        vec.push_back(new TimeView(i));
    }
    return vec;
}

std::vector<HealthView *> ViewGenerator::createHealthViews(std::vector<Character *> characters)
{
    std::vector<HealthView *> vec;
    for(auto i:characters){
        vec.push_back(new HealthView(i));
    }
    return vec;

}

std::vector<std::vector<MoveView *>> ViewGenerator::createMoveViews(std::vector<Character *> characters)
{
    std::vector<std::vector<MoveView *>> allMovesView;
    for(auto i:characters){
        std::vector<std::vector<Character *>> characterMoves = i->getMoves();
        std::vector<MoveView *> movesView;
        for(auto j:characterMoves){
            movesView.push_back(new MoveView(j));
        }
        allMovesView.push_back(movesView);
    }
    return allMovesView;
}
