#ifndef TESTCOMPOSITEGRAPHICS_H_INCLUDED
#define TESTCOMPOSITEGRAPHICS_H_INCLUDED

#include "cppunitlite/TestHarness.h"

TEST (CompositeGraphics, defaultBoundingBox) {
    CompositeGraphics g;
    // CompositeGraphics object has a default bounding box of
    // rectangle (0,0,0,0)
    LONGS_EQUAL(0,g.getBoundingBox().llx());
    LONGS_EQUAL(0,g.getBoundingBox().lly());
    LONGS_EQUAL(0,g.getBoundingBox().urx());
    LONGS_EQUAL(0,g.getBoundingBox().ury());
    LONGS_EQUAL(0,g.getBoundingBox().area());
}

TEST(CompositeGraphics, addingOneChild) {
    CompositeGraphics g;

    try {
        g.add(new SimpleGraphics(new Circle(0,0,2)));
    } catch (std::string s) {
        FAIL("Should not throw exception");
    }

    LONGS_EQUAL(16,g.getBoundingBox().area());
}

TEST(CompositeGraphics, addingTwoChildrenAndGetBoundingBox) {
    CompositeGraphics g;

    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    LONGS_EQUAL(-2,g.getBoundingBox().llx());
    LONGS_EQUAL(-2,g.getBoundingBox().lly());
    LONGS_EQUAL(1,g.getBoundingBox().urx());
    LONGS_EQUAL(1,g.getBoundingBox().ury());
}

TEST(CompositeGraphics, SimpleAndCompositeChildrenAndGetBoundingBox) {
    CompositeGraphics g;
    SimpleGraphics r(new Rectangle (-1,-1,1,3));

    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));
    CompositeGraphics h;
    h.add(&g);
    h.add(&r);

    LONGS_EQUAL(-2,h.getBoundingBox().llx());
    LONGS_EQUAL(-2,h.getBoundingBox().lly());
    LONGS_EQUAL(1,h.getBoundingBox().urx());
    LONGS_EQUAL(2,h.getBoundingBox().ury());

}

#endif // TESTCOMPOSITEGRAPHICS_H_INCLUDED
