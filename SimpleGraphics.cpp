#include "SimpleGraphics.h"

SimpleGraphics::SimpleGraphics(Shape *shape_inst)
{
    s = shape_inst;
}
Rectangle SimpleGraphics::getBoundingBox()
{
    return s->getBoundingBox();
}
void SimpleGraphics::accept(GraphicsVisitor &v)
{
    v.startNode();
    v.visitSimpleGraphics(this);
    v.endNode();
}
Shape * SimpleGraphics::getShape()
{
    return s;
}
std::string SimpleGraphics::trace()
{
    return getShape()->describe();
}
