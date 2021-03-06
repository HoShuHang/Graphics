#include "CompositeGraphics.h"
#include <algorithm>
#include "AreaVisitor.h"
#include <iostream>

CompositeGraphics::CompositeGraphics() {}
void CompositeGraphics::add(Graphics *g)
{
    g_obj.push_back(g);
}
Rectangle CompositeGraphics::getBoundingBox()
{
    if (g_obj.size() == 0)
        return Graphics::getBoundingBox();

    std::vector<int> minx;
    std::vector<int> miny;
    std::vector<int> maxx;
    std::vector<int> maxy;

    std::vector<Graphics *>::iterator i;
    for (i=g_obj.begin(); i!=g_obj.end(); ++i)
    {
        minx.push_back((*i)->getBoundingBox().llx());
        miny.push_back((*i)->getBoundingBox().lly());
        maxx.push_back((*i)->getBoundingBox().urx());
        maxy.push_back((*i)->getBoundingBox().ury());
    }
    int llx = *min_element(minx.begin(),minx.end());
    int lly = *min_element(miny.begin(),miny.end());
    int urx = *max_element(maxx.begin(),maxx.end());
    int ury = *max_element(maxy.begin(),maxy.end());

    return Rectangle(llx,lly,urx-llx,ury-lly);
}

void CompositeGraphics::accept(GraphicsVisitor & v)
{
//    for (auto e: g_obj)
//        e->accept(v);
    v.startNode();
    v.visitCompositeGraphics(this);
    std::vector<Graphics *>::iterator i;
    for (i=g_obj.begin(); i != g_obj.end(); ++i)
        (*i)->accept(v);
    v.endNode();
}

std::string CompositeGraphics::trace()
{
    if(g_obj.size() == 0)
        return "Comp";
    else
    {
        std::stringstream sstm;
        sstm << "Comp " << getBoundingBox().describe() << "[";

        for (int i = 0; i < g_obj.size(); i++)
        {
            sstm << g_obj[i]->trace();
            if(i != g_obj.size() - 1)
                sstm << ", ";
            else
                sstm << "]";
        }
        return sstm.str();
    }
}
