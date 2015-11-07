#ifndef UTHW3_H_INCLUDED
#define UTHW3_H_INCLUDED
#include "cppunitlite/TestHarness.h"
#include <string>
#include "GraphicsFactory.h"
#include "SimpleGraphicsFactory.h"
#include "DescriptionVisitor.h"
#include <Queue>

using namespace std;

TEST(GraphicsFactory, buildGraphicsFromFileInErrorPath)
{
    try
    {
        GraphicsFactory  g;
        g.buildGraphicsFromFile("f2.txt");
        FAIL("File is exist.");
    }
    catch (string s)
    {
        CHECK(s == "File does not exist.");
    }
}

TEST(GraphicsFactory, buildGraphicsFromFile)
{
    GraphicsFactory *sg = new SimpleGraphicsFactory();
    Graphics *g = sg->buildGraphicsFromFile("f1.txt");

    std::string expect("Comp R(-2,-2,3,4)\n");
    expect += std::string("  Comp R(-2,-2,3,3)\n");
    expect += std::string("    C(0,0,1)\n");
    expect += std::string("    S(-2,-2,2)\n");
    expect += std::string("  R(-1,-1,1,3)\n");

    DescriptionVisitor dv;
    g->accept(dv);
    CHECK(expect==dv.getDescription());
}

TEST(GraphicsFactory, fileContentsAsString)
{
    GraphicsFactory  g;
    std::string expect("Comp R(-2,-2,3,4)\n");
    expect += std::string("  Comp R(-2,-2,3,3)\n");
    expect += std::string("    C(0,0,1)\n");
    expect += std::string("    S(-2,-2,2)\n");
    expect += std::string("  R(-1,-1,1,3)\n");
    CHECK(expect == g.fileContentsAsString("f1.txt"));
}

TEST(SimpleGraphicsFactory, extractSimpleGraphicsCircle)
{
    SimpleGraphicsFactory sg;
    SimpleGraphics *circle = new SimpleGraphics(new Circle(0,0,1));
    std::string c = "C(0,0,1)";
    int l = 0;
    Graphics *actual = sg.extractGraphicsFromOneLine(c, l);
    DescriptionVisitor dvc;
    actual->accept(dvc);
    CHECK(std::string(c + "\n")==dvc.getDescription());
}

TEST(SimpleGraphicsFactory, extractSimpleGraphicsSquare)
{
    SimpleGraphicsFactory sg;
    std::string s = "S(-2,-2,2)";
    int l = 0;
    Graphics *actual = sg.extractGraphicsFromOneLine(s, l);
    DescriptionVisitor dvs;
    actual->accept(dvs);
    CHECK(std::string(s + "\n")==dvs.getDescription());
}

TEST(SimpleGraphicsFactory, extractSimpleGraphicsRectangle)
{
    SimpleGraphicsFactory sg;
    std::string r = "R(-1,-1,1,3)";
    int l = 0;
    Graphics *actual = sg.extractGraphicsFromOneLine(r, l);
    DescriptionVisitor dvr;
    actual->accept(dvr);
    CHECK(std::string(r + "\n")==dvr.getDescription());
}

TEST(SimpleGraphicsFactory, extractCompositeGraphics)
{
    SimpleGraphicsFactory sg;
    std::string comp = "Comp R(-2,-2,3,4)";
    int l = 0;
    Graphics *actual = sg.extractGraphicsFromOneLine(comp, l);
    DescriptionVisitor dv;
    actual->accept(dv);
    CHECK(std::string("Comp R(0,0,0,0)\n")==dv.getDescription());
}

TEST(GraphicsFactory, traceStack)
{
    GraphicsFactory *sg = new SimpleGraphicsFactory();
    Graphics *g = sg->buildGraphicsFromFile("f1.txt");

    std::string expect("\n");
    expect += std::string("0, Comp\n");
    expect += std::string("\n");
    expect += std::string("0, Comp\n");
    expect += std::string("1, Comp\n");
    expect += std::string("\n");
    expect += std::string("0, Comp\n");
    expect += std::string("1, Comp\n");
    expect += std::string("2, C(0,0,1)\n");
    expect += std::string("\n");
    expect += std::string("0, Comp\n");
    expect += std::string("1, Comp\n");
    expect += std::string("2, C(0,0,1)\n");
    expect += std::string("2, S(-2,-2,2)\n");
    expect += std::string("\n");
    expect += std::string("0, Comp\n");
    expect += std::string("1, Comp R(-2,-2,3,3)[C(0,0,1), S(-2,-2,2)]\n");
    expect += std::string("1, R(-1,-1,1,3)\n");
    expect += std::string("\n");
    expect += std::string("0, Comp R(-2,-2,3,4)[Comp R(-2,-2,3,3)[C(0,0,1), S(-2,-2,2)], R(-1,-1,1,3)]\n");
    cout << sg->getStackTrace();
    CHECK(expect == sg->getStackTrace());
}

TEST(GraphicsFactory, composeBeforeLine5)
{
    GraphicsFactory *sg = new SimpleGraphicsFactory();

    Graphics *g = new CompositeGraphics();
    Graphics *g1 = new CompositeGraphics();
    Graphics *c = new SimpleGraphics(new Circle(0,0,1));
    Graphics *s = new SimpleGraphics(new Square(-2,-2,2));
    sg->graphicsStack.push_back(g);
    sg->graphicsStack.push_back(g1);
    sg->graphicsStack.push_back(c);
    sg->graphicsStack.push_back(s);
    sg->levelStack.push_back(0);
    sg->levelStack.push_back(1);
    sg->levelStack.push_back(2);
    sg->levelStack.push_back(2);
    sg -> compose();
    CHECK("Comp R(-2,-2,3,3)[C(0,0,1), S(-2,-2,2)]" == sg->graphicsStack.back()->trace());
    LONGS_EQUAL(2, sg->graphicsStack.size());
}

TEST(GraphicsFactory, composeBeforeLine9)
{
    GraphicsFactory *sg = new SimpleGraphicsFactory();

    Graphics *g = new CompositeGraphics();
    Graphics *g1 = new CompositeGraphics();
    Graphics *c = new SimpleGraphics(new Circle(0,0,1));
    Graphics *s = new SimpleGraphics(new Square(-2,-2,2));
    Graphics *r = new SimpleGraphics(new Rectangle(-1,-1,1,3));
    g1->add(c);
    g1->add(s);
    sg->graphicsStack.push_back(g);
    sg->graphicsStack.push_back(g1);
    sg->graphicsStack.push_back(r);
    sg->levelStack.push_back(0);
    sg->levelStack.push_back(1);
    sg->levelStack.push_back(1);
    sg -> compose();
    CHECK("Comp R(-2,-2,3,4)[Comp R(-2,-2,3,3)[C(0,0,1), S(-2,-2,2)], R(-1,-1,1,3)]" == sg->graphicsStack.back()->trace());
    LONGS_EQUAL(1, sg->graphicsStack.size());
}

TEST(StackVisitor, visitSimpleGraphics)
{
    SimpleGraphics s(new Rectangle(0,0,2,3));
    CHECK(std::string("R(0,0,2,3)")==s.trace());
}

TEST(StackVisitor, visitCompositeGraphics)
{
    CompositeGraphics g;
    g.add(new SimpleGraphics(new Circle(0,0,1)));
    g.add(new SimpleGraphics(new Square(-2,-2,2)));

    std::string ans("Comp R(-2,-2,3,3)[C(0,0,1), S(-2,-2,2)]");
    CHECK(ans==g.trace());
}

TEST(GraphicsFactory, split)
{
    vector<string> expect;
    std::string first("Comp R(-2,-2,3,4)");
    std::string second("  Comp R(-2,-2,3,3)");
    std::string third("    C(0,0,1)");
    std::string s = first + '\n' + second + '\n' + third;
    expect.push_back(first);
    expect.push_back(second);
    expect.push_back(third);
    GraphicsFactory  g;
    CHECK(expect == g.split(s, '\n'));
}

TEST(GraphicsFactory, getLevel)
{
    GraphicsFactory g;
    LONGS_EQUAL(0, g.getLevel("Comp R(-2,-2,3,4)"));
    LONGS_EQUAL(1, g.getLevel("  Comp R(-2,-2,3,3)"));
    LONGS_EQUAL(2, g.getLevel("    Comp R(-2,-2,3,4)"));
}

TEST(GraphicsFactory, pureString)
{
    GraphicsFactory  g;
    CHECK("-2,-2,3,3" == g.pureString("Comp R(-2,-2,3,3)"));
}

#endif // UTHW3_H_INCLUDED
