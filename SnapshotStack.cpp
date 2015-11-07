#include "SnapshotStack.h"
#include <iostream>
void SnapshotStack::push(Graphics *g)
{
    std::cout << std::endl;
    std::stack<Graphics *>::push(g);
    graphicsStack.push_back(g);
//    for(int i = 0; i < graphicsStack.size(); i++)
//    {
//        std::stringstream sstm;
////        std::cout << "levelStack[i] = " << levelStack[i] << std::endl;
//        sstm << levelStack[i] << ", " << graphicsStack[i]->trace();
//        std::cout << sstm.str() << std::endl;
//    }
}

void SnapshotStack::pop()
{
    std::stack<Graphics *>::pop();
    graphicsStack.pop_back();
    levelStack.pop_back();
}

void SnapshotStack::setCurrentLevel(int level)
{
    levelStack.push_back(level);
}
