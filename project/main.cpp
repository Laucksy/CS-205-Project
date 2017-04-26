#include <iostream>
#include "code.h"
#include <QDir>

using namespace std;

//int main(int argc, char *argv[])
//{

//    //cout << "Compiles!" << endl;

//    //cout << "Compiles!" << endl;
//    cout << "foo" << endl;
//    cout << QDir::currentPath().toStdString() << endl;
//    //DBTool* t = new DBTool("BaseDrop");
//    vector<string> testVect;
//    testVect.push_back("first");
//    testVect.push_back("second");
//    testVect.push_back("third");

//    // test.set_file("/Users/swein/Desktop/205 Project/Wheel.java");

//    //test.parse("Users/swein/Desktop/Wheel.java");

//    // test.parse();
//    //cout << "Compiles! 2" << endl;


//    //    for(unsigned long i = 0; i < test.get_full_code().size(); i++)
//    //    {

//    //        test.tokenize(test.fullCode.at(i));
//    //    }

//    return 0;
//}

// The fixture for testing class Foo.
class ProjectTest : public ::testing::Test {
protected:

    // You can remove any or all of the following functions if its body

    // is empty.


    ProjectTest() {




    }


    virtual ~ProjectTest() {


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


};

//Test if testing works
TEST_F(ProjectTest, TESTONE) {

    if (true) {

        ASSERT_TRUE(true);
    }
}

TEST_F(ProjectTest, TESTTWO) {

   // r1->calc_grade();
   // ASSERT_EQ(10, r1->get_grade());
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

