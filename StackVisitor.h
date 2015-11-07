#ifndef STACKVISITOR_H_INCLUDED
#define STACKVISITOR_H_INCLUDED
#include "GraphicsVisitor.h"

class StackVisitor : public GraphicsVisitor
{
public:
    StackVisitor();
    void visitSimpleGraphics(SimpleGraphics *s);
    void visitCompositeGraphics(CompositeGraphics *c);
    int area();
    std::string getStackDescription();
private:
    std::string stackDes;
    int compositeDepth;
};

#endif // STACKVISITOR_H_INCLUDED
