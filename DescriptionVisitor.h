#ifndef DESCRIPTIONVISITOR_H_INCLUDED
#define DESCRIPTIONVISITOR_H_INCLUDED
#include "GraphicsVisitor.h"
#include <vector>

class DescriptionVisitor : public GraphicsVisitor
{
public:
    DescriptionVisitor();
    std::string getDescription();
    void visitSimpleGraphics(SimpleGraphics *s);
    void visitCompositeGraphics(CompositeGraphics *c);
    int area();
protected:
    std::string description;
};

#endif // DESCRIPTIONVISITOR_H_INCLUDED
