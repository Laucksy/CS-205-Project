#include <iostream>
#include "integration.h"

using namespace std;

int main(int argc, char *argv[])
{
    Integration* integ = new Integration(".", "TestDB");

    integ->add_new_class("testClass1");

    integ->add_new_student("test0", "test");
    integ->add_new_student("test1", "test");
    integ->add_new_student("test2", "test");
    integ->add_new_student("test3", "test");

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

    delete integ;

    Integration* integ2 = new Integration(".", "TestDB");

    for (Assignments* k : integ2->assignments) {
        integ2->delete_assignment(k);
    }

    for (Students* k : integ2->students) {
        integ2->delete_class(k);
    }

    for (Rubric* k : integ2->rubrics) {
        integ2->delete_rubric(k);
    }

    delete integ2;
    return 0;
}
