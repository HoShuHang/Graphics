#ifndef COMPOSITEGRAPHICS_H_INCLUDED
#define COMPOSITEGRAPHICS_H_INCLUDED

#include "Graphics.h"
#include <vector>

class CompositeGraphics : public Graphics {
public:
    CompositeGraphics();
    void add (Graphics *g);
    Rectangle getBoundingBox();
    void accept(GraphicsVisitor & v);
    std::string trace();
private:
    std::vector<Graphics *> g_obj;
};

#endif // COMPOSITEGRAPHICS_H_INCLUDED
