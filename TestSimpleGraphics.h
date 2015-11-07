#ifndef TESTSIMPLEGRAPHICS_H_INCLUDED
#define TESTSIMPLEGRAPHICS_H_INCLUDED

#include "cppunitlite/TestHarness.h"

TEST(SimpleGraphics, ctor_BoundingBox)
{
    // SimpleGraphics object points to a Shape object
    Graphics *g1 = new SimpleGraphics(new Circle(0,0,1));
    Graphics *g2 = new SimpleGraphics(new Square(0,0,2));
    Graphics *g3 = new SimpleGraphics(new Rectangle(5,6,3,4));

    LONGS_EQUAL(-1,g1->getBoundingBox().llx());
    LONGS_EQUAL(-1,g1->getBoundingBox().lly());
    LONGS_EQUAL(1,g1->getBoundingBox().urx());
    LONGS_EQUAL(1,g1->getBoundingBox().ury());

    LONGS_EQUAL(0,g2->getBoundingBox().llx());
    LONGS_EQUAL(0,g2->getBoundingBox().lly());
    LONGS_EQUAL(2,g2->getBoundingBox().urx());
    LONGS_EQUAL(2,g2->getBoundingBox().ury());

    LONGS_EQUAL(5,g3->getBoundingBox().llx());
    LONGS_EQUAL(6,g3->getBoundingBox().lly());
    LONGS_EQUAL(8,g3->getBoundingBox().urx());
    LONGS_EQUAL(10,g3->getBoundingBox().ury());

}

#endif // TESTSIMPLEGRAPHICS_H_INCLUDED
