#ifndef TESTAREAVISITOR_H_INCLUDED
#define TESTAREAVISITOR_H_INCLUDED

#include "cppunitlite/TestHarness.h"
#include "AreaVisitor.h"

TEST (AreaVisitor, first) {
    CompositeGraphics g;
    SimpleGraphics r(new Rectangle (-1,-1,1,3));

    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));
    CompositeGraphics h;
    h.add(&g);
    h.add(&r);

    AreaVisitor v;
    h.accept(v);

    LONGS_EQUAL(10, v.area());

    AreaVisitor v2;
    r.accept(v2);

    LONGS_EQUAL(3, v2.area());

}

TEST(AreaVisitor, derivedFromGaphicsVisitor) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));
    SimpleGraphics r(new Rectangle (-1,-1,1,3));
    CompositeGraphics h;

    h.add(&g);
    h.add(&r);

    GraphicsVisitor * av = new AreaVisitor;
    h.accept(*av);

    LONGS_EQUAL(10, static_cast<AreaVisitor *>(av)->area());
}

#endif // TESTAREAVISITOR_H_INCLUDED
