#ifndef SIMPLEGRAPHICS_H_INCLUDED
#define SIMPLEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include "Shape.h"
#include "GraphicsVisitor.h"

class SimpleGraphics : public Graphics
{
public:
    SimpleGraphics (Shape *shape_inst);
    Rectangle getBoundingBox();
    Shape * getShape();
    void accept(GraphicsVisitor &v) ;
    std::string trace();
private:
    Shape * s;
};


#endif // SIMPLEGRAPHICS_H_INCLUDED
