#include <iostream>
#include "gtest/gtest.h"
#include "integration.h"

using namespace std;

// The fixture for testing class Foo.
class IntegTest : public ::testing::Test {
protected:

    // You can remove any or all of the following functions if its body

    // is empty.


    IntegTest() {

        // You can do set-up work for each test here.

        integ = new Integration(".", "TestDB2");
    }


    virtual ~IntegTest() {

        // You can do clean-up work that doesn't throw exceptions here.

        delete integ;
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

    Integration* integ;
};

//Test if testing works
TEST_F(IntegTest, TESTTESTTEST) {

    if (true) {

        ASSERT_TRUE(true);
    }
}

//Test if adding works
TEST_F(IntegTest, ADDTEST) {

    integ->add_new_class("testClass1");

    integ->add_new_student("test0");
    integ->add_new_student("test1");
    integ->add_new_student("test2");
    integ->add_new_student("test3");

    integ->add_new_assignment("test_lab_0");
    //integ->set_active_assignment(integ->assignments[0]);

    Rubric* testRubric = integ->add_new_rubric(true, "test_lab_0_rubric");

    vector<double> testMarkers;
    testMarkers.push_back(0.0);
    testMarkers.push_back(1.0);
    testMarkers.push_back(2.0);
    testMarkers.push_back(3.0);
    testMarkers.push_back(4.0);
    testMarkers.push_back(5.0);

    vector<string> testQuality;
    testQuality.push_back("0.0");
    testQuality.push_back("1.0");
    testQuality.push_back("2.0");
    testQuality.push_back("3.0");
    testQuality.push_back("4.0");
    testQuality.push_back("5.0");

    integ->add_new_category(testRubric, "test_cat_0", 5.0, testMarkers, testQuality, true);

    integ->select_assignment_rubric(integ->rubrics[0]);

    Assignment* test0 = integ->add_new_submission(integ->activeAssignemnt->rubric, integ->students[0]->list[0]);
    integ->add_new_file(test0, "class1.java");
    integ->add_new_file(test0, "class2.java");

    Assignment* test1 = integ->add_new_submission(integ->activeAssignemnt->rubric, integ->students[0]->list[1]);
    integ->add_new_file(test1, "class1.java");
    integ->add_new_file(test1, "class2.java");

    Assignment* test2 = integ->add_new_submission(integ->activeAssignemnt->rubric, integ->students[0]->list[2]);
    integ->add_new_file(test2, "class1.java");
    integ->add_new_file(test2, "class2.java");

    Assignment* test3 = integ->add_new_submission(integ->activeAssignemnt->rubric, integ->students[0]->list[3]);
    integ->add_new_file(test3, "class1.java");
    integ->add_new_file(test3, "class2.java");

    integ->set_active_assignment(integ->assignments[0]);

    integ->set_active_submission(test0);
    integ->set_active_file(integ->activeSubmission->files[0]);
    integ->add_new_feedback("cat", "", 0);
    integ->set_active_file(integ->activeSubmission->files[1]);
    integ->add_new_feedback("dog", "", 0);

    integ->set_active_submission(test1);
    integ->set_active_file(integ->activeSubmission->files[0]);
    integ->add_new_feedback("bat", "", 0);
    integ->set_active_file(integ->activeSubmission->files[1]);
    integ->add_new_feedback("bog", "", 0);

    integ->set_active_submission(test2);
    integ->set_active_file(integ->activeSubmission->files[0]);
    integ->add_new_feedback("hat", "", 0);
    integ->set_active_file(integ->activeSubmission->files[1]);
    integ->add_new_feedback("cog", "", 0);

    integ->set_active_submission(test3);
    integ->set_active_file(integ->activeSubmission->files[0]);
    integ->add_new_feedback("mat", "", 0);
    integ->set_active_file(integ->activeSubmission->files[1]);
    integ->add_new_feedback("clog", "", 0);

    ASSERT_EQ(integ->students.size(), 1);
    ASSERT_EQ(integ->students[0]->name, "testClass1");
    ASSERT_EQ(integ->students[0]->list.size(), 4);

    ASSERT_EQ(integ->students[0]->list[0]->name, "test0");
    ASSERT_EQ(integ->students[0]->list[1]->name, "test1");
    ASSERT_EQ(integ->students[0]->list[2]->name, "test2");
    ASSERT_EQ(integ->students[0]->list[3]->name, "test3");

    ASSERT_EQ(integ->rubrics.size(), 1);
    ASSERT_EQ(integ->rubrics[0]->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->rubrics[0]->name.size(), 1);
    ASSERT_EQ(integ->rubrics[0]->name.size(), integ->rubrics[0]->cat.size());

    ASSERT_EQ(integ->rubrics[0]->name[0], "test_cat_0");
    ASSERT_EQ(integ->rubrics[0]->cat[0]->pts, 5);
    ASSERT_EQ(integ->rubrics[0]->cat[0]->get_qual().size(), 6);
    ASSERT_EQ(integ->rubrics[0]->cat[0]->get_points().size(), 6);

    ASSERT_EQ(integ->assignments.size(), 1);
    ASSERT_EQ(integ->assignments[0]->name, "test_lab_0");
    ASSERT_EQ(integ->assignments[0]->list.size(), 4);

    ASSERT_EQ(integ->assignments[0]->list[0]->stu->name, "test0");
    ASSERT_EQ(integ->assignments[0]->list[0]->rubric->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->assignments[0]->list[0]->files.size(), 2);

    ASSERT_EQ(integ->assignments[0]->list[0]->files[0]->fileName, "class1.java");
    ASSERT_EQ(integ->assignments[0]->list[0]->files[0]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[0]->files[0]->profFeedback[0]->text, "cat");

    ASSERT_EQ(integ->assignments[0]->list[0]->files[1]->fileName, "class2.java");
    ASSERT_EQ(integ->assignments[0]->list[0]->files[1]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[0]->files[1]->profFeedback[0]->text, "dog");

    ASSERT_EQ(integ->assignments[0]->list[1]->stu->name, "test1");
    ASSERT_EQ(integ->assignments[0]->list[1]->rubric->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->assignments[0]->list[1]->files.size(), 2);

    ASSERT_EQ(integ->assignments[0]->list[1]->files[0]->fileName, "class1.java");
    ASSERT_EQ(integ->assignments[0]->list[1]->files[0]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[1]->files[0]->profFeedback[0]->text, "bat");

    ASSERT_EQ(integ->assignments[0]->list[1]->files[1]->fileName, "class2.java");
    ASSERT_EQ(integ->assignments[0]->list[1]->files[1]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[1]->files[1]->profFeedback[0]->text, "bog");

    ASSERT_EQ(integ->assignments[0]->list[2]->stu->name, "test2");
    ASSERT_EQ(integ->assignments[0]->list[2]->rubric->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->assignments[0]->list[2]->files.size(), 2);

    ASSERT_EQ(integ->assignments[0]->list[2]->files[0]->fileName, "class1.java");
    ASSERT_EQ(integ->assignments[0]->list[2]->files[0]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[2]->files[0]->profFeedback[0]->text, "hat");

    ASSERT_EQ(integ->assignments[0]->list[2]->files[1]->fileName, "class2.java");
    ASSERT_EQ(integ->assignments[0]->list[2]->files[1]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[2]->files[1]->profFeedback[0]->text, "cog");

    ASSERT_EQ(integ->assignments[0]->list[3]->stu->name, "test3");
    ASSERT_EQ(integ->assignments[0]->list[3]->rubric->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->assignments[0]->list[3]->files.size(), 2);

    ASSERT_EQ(integ->assignments[0]->list[3]->files[0]->fileName, "class1.java");
    ASSERT_EQ(integ->assignments[0]->list[3]->files[0]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[3]->files[0]->profFeedback[0]->text, "mat");

    ASSERT_EQ(integ->assignments[0]->list[3]->files[1]->fileName, "class2.java");
    ASSERT_EQ(integ->assignments[0]->list[3]->files[1]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[3]->files[1]->profFeedback[0]->text, "clog");

}

//Test if populating from the database works
TEST_F(IntegTest, POPULATETEST) {

    ASSERT_EQ(integ->students.size(), 1);
    ASSERT_EQ(integ->students[0]->name, "testClass1");
    ASSERT_EQ(integ->students[0]->list.size(), 4);

    ASSERT_EQ(integ->students[0]->list[0]->name, "test0");
    ASSERT_EQ(integ->students[0]->list[1]->name, "test1");
    ASSERT_EQ(integ->students[0]->list[2]->name, "test2");
    ASSERT_EQ(integ->students[0]->list[3]->name, "test3");

    ASSERT_EQ(integ->rubrics.size(), 1);
    ASSERT_EQ(integ->rubrics[0]->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->rubrics[0]->name.size(), 1);
    ASSERT_EQ(integ->rubrics[0]->name.size(), integ->rubrics[0]->cat.size());

    ASSERT_EQ(integ->rubrics[0]->name[0], "test_cat_0");
    ASSERT_EQ(integ->rubrics[0]->cat[0]->pts, 5);
    ASSERT_EQ(integ->rubrics[0]->cat[0]->get_qual().size(), 6);
    ASSERT_EQ(integ->rubrics[0]->cat[0]->get_points().size(), 6);

    ASSERT_EQ(integ->assignments.size(), 1);
    ASSERT_EQ(integ->assignments[0]->name, "test_lab_0");
    ASSERT_EQ(integ->assignments[0]->list.size(), 4);

    ASSERT_EQ(integ->assignments[0]->list[0]->stu->name, "test0");
    ASSERT_EQ(integ->assignments[0]->list[0]->rubric->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->assignments[0]->list[0]->files.size(), 2);

    ASSERT_EQ(integ->assignments[0]->list[0]->files[0]->fileName, "class1.java");
    ASSERT_EQ(integ->assignments[0]->list[0]->files[0]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[0]->files[0]->profFeedback[0]->text, "cat");

    ASSERT_EQ(integ->assignments[0]->list[0]->files[1]->fileName, "class2.java");
    ASSERT_EQ(integ->assignments[0]->list[0]->files[1]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[0]->files[1]->profFeedback[0]->text, "dog");

    ASSERT_EQ(integ->assignments[0]->list[1]->stu->name, "test1");
    ASSERT_EQ(integ->assignments[0]->list[1]->rubric->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->assignments[0]->list[1]->files.size(), 2);

    ASSERT_EQ(integ->assignments[0]->list[1]->files[0]->fileName, "class1.java");
    ASSERT_EQ(integ->assignments[0]->list[1]->files[0]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[1]->files[0]->profFeedback[0]->text, "bat");

    ASSERT_EQ(integ->assignments[0]->list[1]->files[1]->fileName, "class2.java");
    ASSERT_EQ(integ->assignments[0]->list[1]->files[1]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[1]->files[1]->profFeedback[0]->text, "bog");

    ASSERT_EQ(integ->assignments[0]->list[2]->stu->name, "test2");
    ASSERT_EQ(integ->assignments[0]->list[2]->rubric->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->assignments[0]->list[2]->files.size(), 2);

    ASSERT_EQ(integ->assignments[0]->list[2]->files[0]->fileName, "class1.java");
    ASSERT_EQ(integ->assignments[0]->list[2]->files[0]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[2]->files[0]->profFeedback[0]->text, "hat");

    ASSERT_EQ(integ->assignments[0]->list[2]->files[1]->fileName, "class2.java");
    ASSERT_EQ(integ->assignments[0]->list[2]->files[1]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[2]->files[1]->profFeedback[0]->text, "cog");

    ASSERT_EQ(integ->assignments[0]->list[3]->stu->name, "test3");
    ASSERT_EQ(integ->assignments[0]->list[3]->rubric->title, "test_lab_0_rubric");
    ASSERT_EQ(integ->assignments[0]->list[3]->files.size(), 2);

    ASSERT_EQ(integ->assignments[0]->list[3]->files[0]->fileName, "class1.java");
    ASSERT_EQ(integ->assignments[0]->list[3]->files[0]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[3]->files[0]->profFeedback[0]->text, "mat");

    ASSERT_EQ(integ->assignments[0]->list[3]->files[1]->fileName, "class2.java");
    ASSERT_EQ(integ->assignments[0]->list[3]->files[1]->profFeedback.size(), 1);
    ASSERT_EQ(integ->assignments[0]->list[3]->files[1]->profFeedback[0]->text, "clog");

}

//Test if active assignment randomization works
TEST_F(IntegTest, RANDOMTEST) {

    int id1, id2, sub1, sub2;
    integ->set_active_assignment(integ->assignments[0]);
    id1 = integ->activeSubmission->id;
    sub1 = integ->submissionQueue.size();
    integ->finish_grading_submission();
    id2 = integ->activeSubmission->id;
    sub2 = integ->submissionQueue.size();

    ASSERT_FALSE (id1 == id2);
    ASSERT_EQ(sub1, 3);
    ASSERT_EQ(sub2, 2);

}

//Test if autocomplete works
TEST_F(IntegTest, AUTOTEST) {

    vector<string> aut = integ->get_similar_feedback("at");
    vector<string> aut1 = integ->get_similar_feedback("og");
    vector<string> aut2 = integ->get_similar_feedback("b");

    for (string k : aut) {
       cerr << k << endl;
    }

    for (string k : aut1) {
        cerr << k << endl;
    }

    for (string k : aut2) {
        cerr << k << endl;
    }

    ASSERT_EQ(aut[0], "cat");
    ASSERT_EQ(aut[1], "bat");
    ASSERT_EQ(aut[2], "hat");
    ASSERT_EQ(aut[3], "mat");

    ASSERT_EQ(aut1[0], "dog");
    ASSERT_EQ(aut1[1], "bog");
    ASSERT_EQ(aut1[2], "cog");
    ASSERT_EQ(aut1[3], "clog");

    ASSERT_EQ(aut2[0], "bat");
    ASSERT_EQ(aut2[1], "bog");
}

//Test if deleting from the program works
TEST_F(IntegTest, DELETETEST0) {

    for (Assignments* k : integ->assignments) {
        integ->delete_assignment(k);
    }

    for (Students* k : integ->students) {
        integ->delete_class(k);
    }

    for (Rubric* k : integ->rubrics) {
        integ->delete_rubric(k);
    }

    ASSERT_EQ(integ->students.size(), 0);
    ASSERT_EQ(integ->rubrics.size(), 0);
    ASSERT_EQ(integ->assignments.size(), 0);
}

//Test if deltion occurred in the db
TEST_F(IntegTest, DELETETEST1) {

    ASSERT_EQ(integ->students.size(), 0);
    ASSERT_EQ(integ->rubrics.size(), 0);
    ASSERT_EQ(integ->assignments.size(), 0);
}

int main(int argc, char *argv[])
{
//    Integration* integ = new Integration(".", "TestDB");

//    integ->add_new_class("testClass1");

//    integ->add_new_student("test0");
//    integ->add_new_student("test1");
//    integ->add_new_student("test2");
//    integ->add_new_student("test3");

//    integ->add_new_assignment("test_lab_0");
//    //integ->set_active_assignment(integ->assignments[0]);

//    Rubric* testRubric = integ->add_new_rubric(true, "test_lab_0_rubric");

//    vector<double> testMarkers;
//    testMarkers.push_back(0.0);
//    testMarkers.push_back(1.0);
//    testMarkers.push_back(2.0);
//    testMarkers.push_back(3.0);
//    testMarkers.push_back(4.0);
//    testMarkers.push_back(5.0);

//    vector<string> testQuality;
//    testQuality.push_back("0.0");
//    testQuality.push_back("1.0");
//    testQuality.push_back("2.0");
//    testQuality.push_back("3.0");
//    testQuality.push_back("4.0");
//    testQuality.push_back("5.0");

//    integ->add_new_category(testRubric, "test_cat_0", 5.0, testMarkers, testQuality, true);

//    integ->select_assignment_rubric(integ->rubrics[0]);

//    Assignment* test0 = integ->add_new_submission(integ->activeAssignemnt->rubric, integ->students[0]->list[0]);
//    integ->add_new_file(test0, "class1.java");
//    integ->add_new_file(test0, "class2.java");

//    Assignment* test1 = integ->add_new_submission(integ->activeAssignemnt->rubric, integ->students[0]->list[1]);
//    integ->add_new_file(test1, "class1.java");
//    integ->add_new_file(test1, "class2.java");

//    Assignment* test2 = integ->add_new_submission(integ->activeAssignemnt->rubric, integ->students[0]->list[2]);
//    integ->add_new_file(test2, "class1.java");
//    integ->add_new_file(test2, "class2.java");

//    Assignment* test3 = integ->add_new_submission(integ->activeAssignemnt->rubric, integ->students[0]->list[3]);
//    integ->add_new_file(test3, "class1.java");
//    integ->add_new_file(test3, "class2.java");

//    integ->set_active_assignment(integ->assignments[0]);

//    integ->set_active_submission(test0);
//    integ->set_active_file(integ->activeSubmission->files[0]);
//    integ->add_new_feedback("cat", "", 0);
//    integ->set_active_file(integ->activeSubmission->files[1]);
//    integ->add_new_feedback("dog", "", 0);

//    integ->set_active_submission(test1);
//    integ->set_active_file(integ->activeSubmission->files[0]);
//    integ->add_new_feedback("bat", "", 0);
//    integ->set_active_file(integ->activeSubmission->files[1]);
//    integ->add_new_feedback("bog", "", 0);

//    integ->set_active_submission(test2);
//    integ->set_active_file(integ->activeSubmission->files[0]);
//    integ->add_new_feedback("hat", "", 0);
//    integ->set_active_file(integ->activeSubmission->files[1]);
//    integ->add_new_feedback("cog", "", 0);

//    integ->set_active_submission(test3);
//    integ->set_active_file(integ->activeSubmission->files[0]);
//    integ->add_new_feedback("mat", "", 0);
//    integ->set_active_file(integ->activeSubmission->files[1]);
//    integ->add_new_feedback("clog", "", 0);

//    vector<string> aut = integ->get_similar_feedback("at");
//    vector<string> aut1 = integ->get_similar_feedback("og");
//    vector<string> aut2 = integ->get_similar_feedback("b");

//    for (string k : aut) {
//        cerr << k << endl;
//    }

//    for (string k : aut1) {
//        cerr << k << endl;
//    }

//    for (string k : aut2) {
//        cerr << k << endl;
//    }

//    delete integ;

//    Integration* integ2 = new Integration(".", "TestDB");

//    for (Assignments* k : integ2->assignments) {
//        integ2->delete_assignment(k);
//    }

//    for (Students* k : integ2->students) {
//        integ2->delete_class(k);
//    }

//    for (Rubric* k : integ2->rubrics) {
//        integ2->delete_rubric(k);
//    }

//    delete integ2;

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
