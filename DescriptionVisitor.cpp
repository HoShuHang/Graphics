#include "DescriptionVisitor.h"
#include "SimpleGraphics.h"
#include "CompositeGraphics.h"
#include <iostream>

DescriptionVisitor::DescriptionVisitor()
{
    description = "";
    depth = -1;
}
int DescriptionVisitor::area()
{
    return 0;
}
void DescriptionVisitor::visitCompositeGraphics(CompositeGraphics *c)
{
    std::string d_comp = c -> getBoundingBox().describe();
    for(int i = 1 ; i <= depth; i++)
        description += "  ";
    description += ("Comp " + d_comp + "\n");
}
void DescriptionVisitor::visitSimpleGraphics(SimpleGraphics *s)
{
    for(int i = 1 ; i <= depth; i++)
        description += "  ";
    description += (s->getShape()-> describe() + "\n");
}
std::string DescriptionVisitor::getDescription()
{
    return description;
}
