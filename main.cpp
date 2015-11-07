#include "cppunitlite/TestHarness.h"

#include "utHW3.h"
#include "TestDescriptionVisitor.h"
#include "TestShape.h"
#include "TestUtil.h"
#include "TestAreaVisitor.h"
#include "TestCompositeGraphics.h"
#include "TestSimpleGraphics.h"

int main(int argc, char** argv) {
	TestResult tr;
	TestRegistry::runAllTests(tr);

	return 0;
}

TEST(Shapes0915, first_success) {
    CHECK(true);
}

TEST(Test, test){
    std::stringstream s;
    string st;
    s << "abcde" << "\n" << "edcba";
    std::getline(s, st);
    std::cout << st << endl;
    CHECK("abcde"== st);
}

/*
TEST(SimpleGraphics, AddingGraphicsObjectShouldThrowException) {
    SimpleGraphics g(new Circle(0,0,1));
    // adding Graphics throws an exception
    try {
        g.add(new Graphics);
    } catch (std::string s) {
        CHECK(std::string("Cannot add child")==s);
    }
    // adding SimpleGraphics throws an exception
    try {
        g.add(new SimpleGraphics(new Circle(0,0,1)));
    } catch (std::string s) {
        CHECK(std::string("Cannot add child")==s);
    }

    // adding CompositeGraphics throws an exception
    try {
        g.add(new CompositeGraphics);
    } catch (std::string s) {
        CHECK(std::string("Cannot add child")==s);
    }
}
*/
