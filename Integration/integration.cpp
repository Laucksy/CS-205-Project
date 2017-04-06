#include "integration.h"

Integration::Integration()
{
    db = new DBTool("database");
    rubrics = new Rubrics("main");
    populate();
}

Integration::~Integration()
{
    delete rubrics;

    for (Assignments* k : assignments) {
        delete k;
    }

    for (Students* k : students) {
        delete k;
    }

    delete db;
}

// creates objects from the data in the database
void Integration::populate()
{
    // create dummy objects to get the table count for eaach table
    Students dg(db, "dummy");
    dg.id = -1;
    dg.id_students = 0;
    int dgc = dg.students_row_cnt;

    Student ds(db, "dummy", "test");
    ds.id = -1;
    ds.id_student = 0;
    int dsc = ds.student_row_cnt;

    Rubric dr(db, true, "dummy");
    dr.id = -1;
    dr.id_rubric = 0;
    int drc = dr.rubric_row_cnt;

    Category dc(db, &dr, 1.0, false);
    dc.id = -1;
    dc.id_category = 0;
    int dcc = dc.category_row_cnt;

    Assignments dl(db, "dummy");
    dl.id = -1;
    dl.id_assignments = 0;
    int dlc = dl.assignments_row_cnt;

    Assignment da(db, &dr, &ds, -1);
    da.id = -1;
    da.id_assignment = 0;
    int dac = dl.assignment_row_cnt;

    Code du(db, "dummy", -1);
    du.id = -1;
    du.id_code = 0;
    int duc = du.code_row_cnt;

    Feedback df(db, "dummy", "test", -1, -1);
    df.id = -1;
    df.id_feedback = 0;
    int dfc = df.feedback_row_cnt;

    // generate objects from database
    // students
    for (int i = 0; i < dgc; i++) {
        Students* g = new Students(db, "");
        g->select_id(i);
        students.push_back(g);
    }
    
    // student
    vector<Student*> studentList;
    for (int i = 0; i < dsc; i++) {
        Student* s = new Student(db, "", "");
        s->select_id(i);
        int gid = s->classId;
        for (Students* k : students) {
            if (k->id == gid) {
                k->list.push_back(s);
            }
        } 
        studentList.push_back(s);
    }

    // rubric
    for (int i = 0; i < drc; i++) {
        Rubric* r = new Rubric(db, true, "");
        r->select_id(i);
        rubrics->rubrics.push_back(r);
    }

    // category
    for (int i = 0; i < dcc; i++) {
        Category* c = new Category(db, &dr, -1.0, false);
        c->select_id(i);
        int rid = c->rubricId;
        for (Rubric* k : rubrics->rubrics) {
            if (k->id == rid) {
                k->cat.push_back(c);
                c->rubric = k;
            }
        }
    }

    // assignments
    for (int i = 0; i < dlc; i++) {
        Assignments* l = new Assignments(db, "");
        l->select_id(i);
        assignments.push_back(l);
        int rid = l->rubId;
        for (Rubric* k : rubrics->rubrics) {
            if (k->id == rid) {
                l->rubric = k;
            }
        }
    }

    // assignment
    vector<Assignment*> assignList;
    for (int i = 0; i < dac; i++) {
        Assignment* a = new Assignment(db, &dr, &ds, -1);
        a->select_id(i);
        assignList.push_back(a);
        int rid = a->rubricId;
        int lid = a->assignNum;
        int sid = a->studentId;
        for (Rubric* k : rubrics->rubrics) {
            if (k->id == rid) {
                a->rubric = k;
            }
        }

        for (Assignments* k : assignments) {
            if (k->id == lid) {
                k->list.push_back(a);
            }
        }

        for (Student* k : studentList) {
            if (k->id == sid) {
                k->list.push_back(a);
            }
        }
    }

    // code
    vector<Code*> codeList;
    for (int i = 0; i < duc; i++) {
        Code* u = new Code(db, "", -1);
        u->select_id(i);
        codeList.push_back(u);
        int aid = u->assignId;
        for (Assignment* k : assignList) {
            if (k->id == aid) {
                k->files.push_back(u);
            }
        }
    }

    // feedback
    for (int i = 0; i < dfc; i++) {
        Feedback* f = new Feedback(db, "", "", -1, -1);
        f->select_id(i);
        int uid = f->codeId;
        for (Code* k : codeList) {
            if (k->id == uid) {
                k->profFeedback.push_back(f);
            }
        }
    }
}

// creates a new class ofstudents
void Integration::add_new_class(string name)
{
    Students* g = new Students(db, name);
    students.push_back(g);
    set_active_class(g);
}

// creates aa new student and adds it to the active class
void Integration::add_new_student(string first, string last)
{
    Student* s = new Student(db, first, last);
    activeClass->list.push_back(s);
    s->classId = activeClass->id;
}

// create a new category of assignemnt submissions
void Integration::add_new_assignment(string name)
{
    Assignments* l = new Assignments(db, name);
    assignments.push_back(l);
    set_active_assignment(l);
}

// create a new assignemnt submission and add it to the active assignment
// return that assignemnt to be populated with code files
Assignment* Integration::add_new_submission(Rubric* rubric, Student* student)
{
    Assignment* a = new Assignment(db, rubric, student, activeAssignemnt->id);
    activeAssignemnt->list.push_back(a);
    student->list.push_back(a);
    return a;
}

// add new code files to the provided assignemnt
void Integration::add_new_file(Assignment* assign, string name)
{
    Code* f = new Code(db, name, assign->id);
    assign->files.push_back(f);
}

// creates  new rubric and adds it to the rubrics list
// returns that rubric to be populated with categories
Rubric* Integration::add_new_rubric(bool deduction, string name)
{
    Rubric* r = new Rubric(db, deduction, name);
    rubrics->rubrics.push_back(r);
    return r;
}

// adds a new category to the provided rubric
void Integration::add_new_category(Rubric* rubric, string name, double points, vector<double> markers, vector<string> quality, bool matrix)
{
    Category* c = new Category(db, rubric, points, matrix);

    for (int i = 0; i < markers.size(); i++) {
        c->add_quality(quality[i], markers[i]);
    }

    rubric->add_category(c, name);
    rubric->grade += points;
}

// creates  new feedback and adds it to the active file
void Integration::add_new_feedback(string text, string tag, int position)
{
    Feedback* f = new Feedback(db, text, tag, activeFile->id, position);
    activeFile->add_feedback(f);
}

// pulls a random submission out of the assignemnt to grade
void Integration::select_random_submission()
{
    activeSubmission = submissionQueue.front();
    submissionQueue.pop();
}

// sets the rubrirc for all submissions in the active assignemnt
void Integration::select_assignment_rubric(Rubric* rubric)
{
    activeAssignemnt->set_rubric(rubric);
}

// mark a submission as graded and call select_random_submission
void Integration::finish_grading_submission()
{
    activeSubmission->status = 2;
}

// sets the active class
void Integration::set_active_class(Students* g)
{
    activeClass = g;
}

// sets the active assignemnt
void Integration::set_active_assignment(Assignments* l)
{
    while (!submissionQueue.empty()) {
        submissionQueue.pop();
    }

    activeAssignemnt = l;
    vector<Assignment*> temp;

    for (Assignment* k : l->list) {
        temp.push_back(k);
    }

    vector<Assignment*> temp0;
    vector<Assignment*> temp1;

    while (temp.size() != 0) {
        int i = rand()%temp.size();

        if (temp[i]->status == 0) {
            temp0.push_back(temp[i]);
        } else if (temp[i]->status == 1) {
            temp1.push_back(temp[i]);
        }

        temp.erase(temp.begin()+i);
    }

    for ( Assignment* k : temp1) {
        submissionQueue.push(k);
    }

    for ( Assignment* k : temp0) {
        submissionQueue.push(k);
    }
}

// sets the active submission
void Integration::set_active_submission(Assignment* a)
{
    activeSubmission = a;
    a->status = 1;
}

// sets the active file
void Integration::set_active_file(Code* f)
{
    activeFile = f;
}
