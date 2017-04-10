#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <vector>
#include <string>
#include <queue>
#include "../DataStructure/assignment.h"
#include "../DataStructure/assignments.h"
#include "../DataStructure/category.h"
#include "../DataStructure/feedback.h"
#include "../DataStructure/rubric.h"
#include "../DataStructure/student.h"
#include "../DataStructure/students.h"
#include "../project/code.h"

class Integration
{
public:
    Integration();
    ~Integration();

    void populate();

    // user actions
    void add_new_class(string name); // new students class instance
    void add_new_student(string first, string last); // new student class instance
    void add_new_assignment(string name); // new assignments class instance
    Assignment* add_new_submission(Rubric* rubric, Student* student); // new assignment class instance
    void add_new_file(Assignment* assign, string name); // new code class instance
    Rubric* add_new_rubric(bool deduction, string name); // new rubric class instance
    void add_new_category(Rubric* rubric, string name, double points, vector<double> markers, vector<string> quality, bool matrix); // new category class instance
    void add_new_feedback(string text, string tag, int position); // new feedback class instance

    void select_random_submission(); // selects student from pool
    void select_assignment_rubric(Rubric* rubric); // sets the rubric for all assignment instances in an assignments instance
    void finish_grading_submission(); // marks ann assignment instance as graded

    void set_active_class(Students* g); // sets the active class
    void set_active_assignment(Assignments* l); // sets the active assignemnt
    void set_active_submission(Assignment* a); // sets the active submission
    void set_active_file(Code* f); // sets the active file

    vector<Rubric*> rubrics;
    vector<Assignments*> assignments;
    vector<Students*> students;

    Students* activeClass;
    Assignments* activeAssignemnt;
    Assignment* activeSubmission;
    Code* activeFile;
    queue<Assignment*> submissionQueue;

    DBTool* db;

};

#endif // INTEGRATION_H
