#include "integration.h"

/* Integration acts as a main class to integrate all different
 * types of objects, unifying the GUI and functionality.
 * */

Integration::Integration(string path, string name)
{
    db = new DBTool(path, name);

    autoComplete = new Feedback(db, "dummy", "test", -1, -1);
    autoComplete->id = -1;
    autoComplete->id_feedback = 0;

    populate();
    if (assignments.size() > 0) {
        set_active_assignment(assignments[0]);
    } else {
        activeAssignemnt = nullptr;
    }

    if (students.size() > 0) {
        set_active_class(students[0]);
    } else {
        activeClass = nullptr;
    }
}

//destructors deletes all created objects
Integration::~Integration()
{
    for (Students* k : students) {
        delete k;
    }

    for (Rubric* k : rubrics) {
        delete k;
    }

    for (Assignments* k : assignments) {
        delete k;
    }
    delete db;
    delete autoComplete;
    Git::push();
}

// creates objects from the data in the database
void Integration::populate()
{
    // create dummy objects to get the table count for eaach table
    Students dg(db, "dummy");
    dg.id = -1;
    dg.id_students = 0;
    int dgc = dg.students_row_cnt;

    Student ds(db, "dummy test");
    ds.id = -1;
    ds.id_student = 0;
    ds.section = &dg;
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
        if (g->called) {
            students.push_back(g);
        } else {
            dgc++;
        }
    }
    
    // student
    vector<Student*> studentList;
    for (int i = 0; i < dsc; i++) {
        Student* s = new Student(db, "");
        s->select_id(i);
        if (s->called) {
            int gid = s->classId;
            for (Students* k : students) {
                if (k->id == gid) {
                    k->list.push_back(s);
                    s->section = k;
                }
            }
            studentList.push_back(s);
        } else {
            dsc++;
        }
    }

    // rubric
    for (int i = 0; i < drc; i++) {
        Rubric* r = new Rubric(db, true, "");
        r->select_id(i);
        if (r->called) {
            rubrics.push_back(r);
        } else {
            drc++;
        }
    }

    // category
    for (int i = 0; i < dcc; i++) {
        Category* c = new Category(db, &dr, -1.0, false);
        c->select_id(i);
        if (c->called) {
            int rid = c->rubricId;
            for (Rubric* k : rubrics) {
                if (k->id == rid) {
                    k->cat.push_back(c);
                    c->rubric = k;
                }
            }
        } else {
            dcc++;
        }
    }

    // assignments
    for (int i = 0; i < dlc; i++) {
        Assignments* l = new Assignments(db, "");
        l->select_id(i);
        if (l->called) {
            assignments.push_back(l);
            int rid = l->rubId;
            int cid = l->classId;
            for (Rubric* k : rubrics) {
                if (k->id == rid) {
                    l->rubric = k;
                }
            }

            for (Students* k : students) {
                if (k->id == cid) {
                    k->assignList.push_back(l);
                }
            }
        } else {
            dlc++;
        }
    }

    // assignment
    vector<Assignment*> assignList;
    for (int i = 0; i < dac; i++) {
        Assignment* a = new Assignment(db, &dr, &ds, -1);
        a->select_id(i);
        if(a->called) {
            assignList.push_back(a);
            int rid = a->rubricId;
            int lid = a->assignNum;
            int sid = a->studentId;
            for (Rubric* k : rubrics) {
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
                    a->stu = k;
                }
            }
        } else {
            dac++;
        }
    }

    // code
    vector<Code*> codeList;
    for (int i = 0; i < duc; i++) {
        Code* u = new Code(db, "", -1);
        u->select_id(i);
        if (u->called) {
            codeList.push_back(u);
            int aid = u->assignId;
            for (Assignment* k : assignList) {
                if (k->id == aid) {
                    k->files.push_back(u);
                }
            }
        } else {
            duc++;
        }
    }

    // feedback
    for (int i = 0; i < dfc; i++) {
        Feedback* f = new Feedback(db, "", "", -1, -1);
        f->select_id(i);
        if (f->called) {
            int uid = f->codeId;
            for (Code* k : codeList) {
                if (k->id == uid) {
                    k->profFeedback.push_back(f);
                }
            }
        } else {
            dfc++;
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
void Integration::add_new_student(string name)
{
    Student* s = new Student(db, name);
    activeClass->list.push_back(s);
    s->classId = activeClass->id;
}

// create a new category of assignemnt submissions
void Integration::add_new_assignment(string name, int classId)
{
    Assignments* l = new Assignments(db, name);
    l->classId = classId;
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
    /*
    cout << "Start new file" << endl;
    string pwd = Bash::exec("pwd");
    //cout << pwd.length() << "," << pwd.length()-1 << endl;
    pwd = pwd.substr(0, pwd.length()-1);
    //cout << pwd << "###" << endl;
    cout << "Before if statement" << endl;
    if(pwd.length() >= name.length()) {
        return;
    }
    //if (name.length() <= pwd.length() && name.substr(0,pwd.length()-1) == pwd) {
    //    return;
    //} else {
    cout << pwd.length() << "," << name.length() << "," << name.length()-1 << endl;
    name = name.substr(pwd.length(), name.length()-1);
    cout << name << endl;
    //}
    //Bash::exec("cp " + Git::escape_spaces(name) + " " + Git::escape_spaces(pwd));
    //string simpleFileName = name.substr(name.find_last_of("/"));
    */
    string newPath = Bash::copy(assign, name);
    cout << "Here new file " << newPath << endl;
    Code* f = new Code(db, newPath, assign->id);
    assign->files.push_back(f);
    //Git::add_file(newPath.substr(1,newPath.length()-1));
    cout << "Finishing method" << endl;
}

// creates  new rubric and adds it to the rubrics list
// returns that rubric to be populated with categories
Rubric* Integration::add_new_rubric(bool deduction, string name)
{
    Rubric* r = new Rubric(db, deduction, name);
    rubrics.push_back(r);
    return r;
}

// adds a new category to the provided rubric
void Integration::add_new_category(Rubric* rubric, string name, double points, vector<double> markers, vector<string> quality, bool matrix)
{
    Category* c = new Category(db, rubric, points, matrix);

    for (unsigned i = 0; i < markers.size(); i++) {
        c->add_quality(quality[i], markers[i]);
    }

    rubric->add_category(c, name);
    rubric->grade += points;
}

// creates  new feedback and adds it to the active file
void Integration::add_new_feedback(string text, string tag, int position)
{
    Feedback* f = new Feedback(db, text, tag, activeFile->id, position);
    f->change_text(text);
    f->update_tag(tag);
    f->codeId = activeFile->id;
    f->position = position;
    activeFile->add_feedback(f);
}

// delete students class instance
void Integration::delete_class(Students* g)
{
    g->set_to_delete();

    for (unsigned i = 0; i < students.size(); i++) {
        if (g == students[i]) {
            for (Student* k : g->list) {
                delete_student(k);
            }
            delete g;
            students.erase(students.begin() + i);
        }
    }
}

// delete student class instance
void Integration::delete_student(Student* s)
{
    s->set_to_delete();
    int classId = s->classId;

    for (Students* k : students) {
        if (k->id == classId) {
            for (unsigned i = 0; i < k->list.size(); i++) {
                if (s == k->list[i]) {
                    for (Assignment* k : s->list) {
                        delete_submission(k);
                    }
                    delete s;
                    k->list.erase(k->list.begin() + i);
                }
            }
        }
    }
}

// delete assignments class instance
void Integration::delete_assignment(Assignments* l)
{
    l->set_to_delete();

    for (unsigned i = 0; i < assignments.size(); i++) {
        if (l == assignments[i]) {
            for (Assignment* k : l->list) {
                delete_submission(k);
            }
            assignments.erase(assignments.begin() + i);
            delete l;
        }
    }
}

// delete assignment class instance
void Integration::delete_submission(Assignment* a)
{
    a->set_to_delete();
    int assignId = a->assignNum;

    for (Assignments* k : assignments) {
        if (k->id == assignId) {
            for (unsigned i = 0; i < k->list.size(); i++) {
                if (a == k->list[i]) {
                    for (Code* k : a->files) {
                        delete_file(k);
                    }
                    k->list.erase(k->list.begin() + i);
                    delete a;
                    return;
                }
            }
        }
    }
}

// delete code class instance
void Integration::delete_file(Code* o)
{
    o->set_to_delete();
    int assignId = o->assignId;

    Assignment* assign = nullptr;
    for (Assignments* k : assignments) {
        for (Assignment* h : k->list) {
            if (h->id == assignId) {
                assign = h;
            }
        }
    }

    if (assign != nullptr) {
        for (unsigned i = 0; i < assign->files.size(); i++) {
            if (o == assign->files[i]) {
                assign->files.erase(assign->files.begin() + i);
                for (Feedback* k : o->profFeedback) {
                    delete_feedback(k);
                }
                delete o;
            }
        }
    }
}

// delete rubric class instance
void Integration::delete_rubric(Rubric* r)
{
    r->set_to_delete();

    for (unsigned i = 0; i < rubrics.size(); i++) {
        if (r == rubrics[i]) {
            for (Category* k : r->cat) {
                delete_category(k);
            }
            delete r;
            rubrics.erase(rubrics.begin() + i);
        }
    }
}

// delete category class instance
void Integration::delete_category(Category* c)
{
    c->set_to_delete();
    int rubId = c->rubricId;

    for (Rubric* k : rubrics) {
        if (k->id == rubId) {
            for (unsigned i = 0; i < k->cat.size(); i++) {
                if (c == k->cat[i]) {
                    delete c;
                    k->cat.erase(k->cat.begin() + i);
                    k->name.erase(k->name.begin() + i);
                }
            }
        }
    }
}

// delete feedback class instance
void Integration::delete_feedback(Feedback* f)
{
    f->set_to_delete();
    int fileId = f->codeId;

    Code* code = nullptr;
    for (Assignments* k : assignments) {
        for (Assignment* h : k->list) {
            for (Code* l : h->files) {
                if (l->id == fileId) {
                    code = l;
                }
            }
        }
    }

    if (code != nullptr) {
        for (unsigned i = 0; i < code->profFeedback.size(); i++) {
            if (f == code->profFeedback[i]) {
                delete f;
                code->profFeedback.erase(code->profFeedback.begin() + i);
            }
        }
    }
}

// imports a rubric from an absolute file address
void Integration::import_rubric(string fileName)
{
    string line;
    //getline(str,line);
    ifstream file;
    file.open(fileName, ifstream::in);

    getline(file,line, ',');
    string name = line;
    getline(file,line, '\n');
    bool deduct = (line == "true");
    Rubric* r = add_new_rubric(deduct, name);

    while(getline(file,line, ','))
    {
        string catName = line;
        getline(file,line, '\n');
        double pointNum = atof(line.c_str());
        //getline(file,line, ',');
        bool m = false;
        vector<double> d;
        vector<string> s;
        add_new_category(r,catName,pointNum, d, s, m);
    }

    file.close();
}

// imports students from an absolute file address
void Integration::import_students(string fileName, Students* s)
{
    vector<string> nameList;
    string line;
    ifstream file;
    file.open(fileName, ifstream::in);
    while(getline(file,line, ','))
    {
        nameList.push_back(line);
    }
    file.close();

    Students* temp = activeClass;
    activeClass = s;
    for (string k : nameList) {
        add_new_student(k);
    }
    activeClass = temp;
}

// imports arubric from an absolute file address
void Integration::add_directory(Assignment* a, string path)
{
    vector<string> f = Git::find_all_files(path);
    //cout << "LENGTH" << f.size() << endl;
    for (string k : f) {
        if(k.find_last_of(".") != string::npos) {
            string extension = k.substr(k.find_last_of("."));
            //cout << "FILE" <<  << endl;
            if(extension == ".java" || extension == ".pde" || extension == ".cpp") {
                add_new_file(a, path + "/" + k);
            }
        }
    }
}

// pulls a random submission out of the assignemnt to grade
void Integration::select_random_submission()
{
    if (!submissionQueue.empty()){
        activeSubmission = submissionQueue.front();
        submissionQueue.pop();
    } else {
        activeSubmission= nullptr;
        activeFile = nullptr;
    }
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
    select_random_submission();
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

    select_random_submission();
}

// sets the active submission
void Integration::set_active_submission(Assignment* a)
{
    activeSubmission = a;
    a->status = 1;
    if (a->files.size() > 0) {
        set_active_file(a->files[0]);
    }
}

// sets the active file
void Integration::set_active_file(Code* f)
{
    activeFile = f;
}

vector<string> Integration::get_similar_feedback(string sim)
{
    autoComplete->select_similar(sim);
    vector<string> ret = autoComplete->simillar;
    autoComplete->simillar.clear();
    return ret;
}
