#include <iostream>
#include "dbtool.h"
#include "gtest/gtest.h"
#include "assignments.h"
#include "assignment.h"
#include "../project/code.h"
#include "feedback.h"
#include "rubric.h"
#include "category.h"
#include "students.h"
#include "student.h"

using namespace std;

// The fixture for testing class Foo.
class DSTest : public ::testing::Test {
protected:

    // You can remove any or all of the following functions if its body

    // is empty.


    DSTest() {

        // You can do set-up work for each test here.
        db = new DBTool("Test2DB");
        r1 = new Rubric(db, false, "r1");
        r2 = new Rubric(db, true, "r2");
        c1 = new Category(db, r1, 10, false);
        r1->add_category(c1, "c1");
        c2 = new Category(db, r2, 10, true);
        r2->add_category(c2, "c2");
        g = new Students(db, "g");
        s = new Student(db, "s");
        g->list.push_back(s);
        l = new Assignments(db, "l");
        a1 = new Assignment(db, r1, s, l->id);
        l->list.push_back(a1);
        a2 = new Assignment(db, r2, s, l->id);
        l->list.push_back(a2);
        u1 = new Code(db, "u1", a1->id);
        a1->add_code(u1);
        u2 = new Code(db, "u2", a2->id);
        a2->add_code(u2);
        f1 = new Feedback(db, "test", "tag", u1->id, 0);
        u1->add_feedback(f1);
        f2 = new Feedback(db, "test", "tag", u2->id, 0);
        u2->add_feedback(f2);


    }


    virtual ~DSTest() {

        // You can do clean-up work that doesn't throw exceptions here.
        delete r1;
        delete r2;
        delete g;
        delete l;
        delete db;
    }


    // If the constructor and destructor are not enough for setting up

    // and cleaning up each test, you can define the following methods:


    virtual void SetUp() {

        // Code here will be called immediately after the constructor (right

        // before each test).
    }


    virtual void TearDown() {

        // Code here will be called immediately after each test (right

        // before the destructor).
    }


    // Objects declared here can be used by all tests in the test case for Foo.
    DBTool* db;
    Rubric* r1;
    Rubric* r2;
    Category* c1;
    Category* c2;
    Students* g;
    Student* s;
    Assignments* l;
    Assignment* a1;
    Assignment* a2;
    Code* u1;
    Feedback* f1;
    Code* u2;
    Feedback* f2;

};

//Test if testing works
TEST_F(DSTest, TESTTESTTEST) {

    if (true) {

        ASSERT_TRUE(true);
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
