#ifndef TESTUTIL_H_INCLUDED
#define TESTUTIL_H_INCLUDED

#include "cppunitlite/TestHarness.h"
#include "util.h"

TEST(areaSum, Circle) {
    Circle c1(0,0,1), c2(0,0,2),c3(0,0,3);
    std::vector<Shape *> v;
    v.push_back(&c1);
    v.push_back(&c2);
    v.push_back(&c3);
    LONGS_EQUAL(42,areaSum(v));
}

TEST(areaSum, Square) {
    Square s1(0,0,1), s2(0,0,2),s3(0,0,3);
    std::vector<Shape *> v;
    v.push_back(&s1);
    v.push_back(&s2);
    v.push_back(&s3);
    LONGS_EQUAL(14,areaSum(v));
}

TEST(areaSum, Rectangle) {
    Rectangle r1(0,0,1,2), r2(0,0,2,3),r3(0,0,3,4);
    std::vector<Shape *> v;
    v.push_back(&r1);
    v.push_back(&r2);
    v.push_back(&r3);
    LONGS_EQUAL(20,areaSum(v));
}

TEST(areaSum, allShapes) {
    Shape *c= new Circle(0,0,1);
    Shape *s=new Square(0,0,2);
    Shape *r=new Rectangle(0,0,3,4);
    std::vector<Shape *> v;
    v.push_back(c);
    v.push_back(s);
    v.push_back(r);
    LONGS_EQUAL(19,areaSum(v));
    delete c;
    delete s;
    delete r;
}

#endif // TESTUTIL_H_INCLUDED
