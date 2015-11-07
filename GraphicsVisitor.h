#ifndef GRAPHICSVISITOR_H_INCLUDED
#define GRAPHICSVISITOR_H_INCLUDED
#include <string>

class SimpleGraphics;
class CompositeGraphics;

class GraphicsVisitor
{
public:
    virtual int area() = 0;
    virtual void visitSimpleGraphics(SimpleGraphics *s);
    virtual void visitCompositeGraphics(CompositeGraphics *c);
    void startNode();
    void endNode();
protected:
    int depth;
};

#endif // GRAPHICSVISITOR_H_INCLUDED
