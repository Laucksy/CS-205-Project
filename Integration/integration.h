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
#include "../git/git.h"

class Integration
{
public:
    Integration(string path, string name);
    ~Integration();

    void populate();

    // user actions
    void add_new_class(string name); // new students class instance
    void add_new_student(string name); // new student class instance
    void add_new_assignment(string name, int classId); // new assignments class instance
    Assignment* add_new_submission(Rubric* rubric, Student* student); // new assignment class instance
    void add_new_file(Assignment* assign, string name); // new code class instance
    Rubric* add_new_rubric(bool deduction, string name); // new rubric class instance
    void add_new_category(Rubric* rubric, string name, double points, vector<double> markers, vector<string> quality, bool matrix); // new category class instance
    void add_new_feedback(string text, string tag, int position); // new feedback class instance

    void delete_class(Students* g); // delete students class instance
    void delete_student(Student* s); // delete student class instance
    void delete_assignment(Assignments* l); // delete assignments class instance
    void delete_submission(Assignment* a); // delete assignment class instance
    void delete_file(Code* o); // delete code class instance
    void delete_rubric(Rubric* r); // delete rubric class instance
    void delete_category(Category* c); // delete category class instance
    void delete_feedback(Feedback* f); // delete feedback class instance

    void select_random_submission(); // selects student from pool
    void select_assignment_rubric(Rubric* rubric); // sets the rubric for all assignment instances in an assignments instance
    void finish_grading_submission(); // marks ann assignment instance as graded

    void set_active_class(Students* g); // sets the active class
    void set_active_assignment(Assignments* l); // sets the active assignemnt
    void set_active_submission(Assignment* a); // sets the active submission
    void set_active_file(Code* f); // sets the active file

    vector<string> get_similar_feedback(string sim);

    vector<Rubric*> rubrics;
    vector<Assignments*> assignments;
    vector<Students*> students;

    Students* activeClass;
    Assignments* activeAssignemnt;
    Assignment* activeSubmission;
    Code* activeFile;
    queue<Assignment*> submissionQueue;
    Feedback* autoComplete;

    DBTool* db;

};

#endif // INTEGRATION_H
