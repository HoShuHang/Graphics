#include "GraphicsVisitor.h"

void GraphicsVisitor::startNode()
{
    depth += 1;
}
void GraphicsVisitor::endNode()
{
    depth -= 1;
}
