#ifndef TESTSHAPE_H_INCLUDED
#define TESTSHAPE_H_INCLUDED

#include "cppunitlite/TestHarness.h"

TEST(Circle, area) {
    Circle circle(0,0,1);
    LONGS_EQUAL(3,circle.area());
}

TEST(Shape, getBoundingBox) {
    Circle c(0,0,1);
    Rectangle r(1,1,1,2);
    Square s(0,0,3);

    // bounding box of a shape is a rectangle
    LONGS_EQUAL(-1,c.getBoundingBox().llx());
    LONGS_EQUAL(-1,c.getBoundingBox().lly());
    LONGS_EQUAL(1,c.getBoundingBox().urx());
    LONGS_EQUAL(1,c.getBoundingBox().ury());

    LONGS_EQUAL(1,r.getBoundingBox().llx());
    LONGS_EQUAL(1,r.getBoundingBox().lly());
    LONGS_EQUAL(2,r.getBoundingBox().urx());
    LONGS_EQUAL(3,r.getBoundingBox().ury());

    LONGS_EQUAL(0,s.getBoundingBox().llx());
    LONGS_EQUAL(0,s.getBoundingBox().lly());
    LONGS_EQUAL(3,s.getBoundingBox().urx());
    LONGS_EQUAL(3,s.getBoundingBox().ury());

    LONGS_EQUAL(4,c.getBoundingBox().area());
    LONGS_EQUAL(2,r.getBoundingBox().area());
    LONGS_EQUAL(9,s.getBoundingBox().area());
}

TEST (Shape, descriptions) {
    Shape * c = new Circle(0,0,1);
    CHECK(std::string("C(0,0,1)")== c->describe());
    c = new Square(0,0,1);
    CHECK(std::string("S(0,0,1)")== c->describe());
    c = new Rectangle(0,0,1,2);
    CHECK(std::string("R(0,0,1,2)")== c->describe());
}

#endif // TESTSHAPE_H_INCLUDED
