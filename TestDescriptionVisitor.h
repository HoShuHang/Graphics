#ifndef TESTDESCRIPTIONVISITOR_H_INCLUDED
#define TESTDESCRIPTIONVISITOR_H_INCLUDED

#include "cppunitlite/TestHarness.h"
#include "DescriptionVisitor.h"

TEST (DescVisitor, SimpleGraphics) {
    SimpleGraphics s(new Rectangle(0,0,2,3));
    DescriptionVisitor dv;
    s.accept(dv);

    CHECK(std::string("R(0,0,2,3)\n")==dv.getDescription());
}

TEST (DescVisitor, CompositeGraphics) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    DescriptionVisitor dv;
    g.accept(dv);

    std::string ans("Comp R(-2,-2,3,3)\n");
    ans += std::string("  C(0,0,1)\n");
    ans += std::string("  S(-2,-2,2)\n");
    std::cout << dv.getDescription();
    CHECK(ans==dv.getDescription());
//    std::cout << dv.getDescription() << std::endl;
}

TEST (DescVisitor, CompositeGraphicsWithComposite) {
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    SimpleGraphics r(new Rectangle (-1,-1,1,3));

    CompositeGraphics h;
    h.add(&g);
    h.add(&r);

    DescriptionVisitor dv;
    h.accept(dv);

    std::string ans("Comp R(-2,-2,3,4)\n");
    ans += std::string("  Comp R(-2,-2,3,3)\n");
    ans += std::string("    C(0,0,1)\n");
    ans += std::string("    S(-2,-2,2)\n");
    ans += std::string("  R(-1,-1,1,3)\n");
    std::cout << dv.getDescription();
    CHECK(ans==dv.getDescription());
    //std::cout << dv.getDescription() << std::endl;
}

#endif // TESTDESCRIPTIONVISITOR_H_INCLUDED
