#include "StackVisitor.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include <iostream>

StackVisitor::StackVisitor()
{
    depth = -1;
    compositeDepth = -1;
}

int StackVisitor::area()
{
    return 0;
}

void StackVisitor::visitSimpleGraphics(SimpleGraphics *s)
{
    stackDes += (s->getShape()-> describe());
    std::cout << "depth = " << depth << std::endl;
    std::cout << "compositeDepth = " << compositeDepth << std::endl;
    if(depth == 0 && compositeDepth == -1)
        stackDes += '\n';
    else if(depth == compositeDepth + 1)
    {
        stackDes += ", ";
    }
    else
        stackDes += "]\n";
}

void StackVisitor::visitCompositeGraphics(CompositeGraphics *c)
{
    compositeDepth = depth;
    std::string d_comp = c -> getBoundingBox().describe();
    stackDes += ("Comp " + d_comp);
}

std::string StackVisitor::getStackDescription()
{
    return stackDes;
}
