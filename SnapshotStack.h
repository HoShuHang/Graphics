#ifndef SNAPSHOTSTACK_H_INCLUDED
#define SNAPSHOTSTACK_H_INCLUDED
#include <stack>
#include <typeinfo>
#include "Graphics.h"
#include <vector>

class SnapshotStack : public std::stack<Graphics *>
{
public:
    void push(Graphics *g);
    void pop();
    void setCurrentLevel(int level);
private:
    std::vector<Graphics *> graphicsStack;
    std::vector<int> levelStack;
};

#endif // SNAPSHOTSTACK_H_INCLUDED
