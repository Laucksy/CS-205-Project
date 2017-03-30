#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include <math.h>
#include <stdlib.h>
#include "dbtable.h"
#include "../project/code.h"
#include "student.h"
#include "rubric.h"
#include "ident.h"

using namespace std;

class Student; // forward declaration

// holds a grade, ref to a rubric, ref to a student
class Assignment : public Ident, public DBTable
{
public:
    // constructors and deconstructor
    Assignment();
    Assignment(DBTool* db, Rubric* r, Student* s, int n);
    ~Assignment();

    // manipulate grade
    void change_grade(double g, string c);
    double get_grade();

    void add_code(Code* c);

    // db parse methods
    string convert_category();
    string convert_component();
    string convert_quality();
    void parse_category(string s);
    void parse_component(string s);
    void parse_quality(string s);

    // database methods
    // returns the row count of the categories table
    int get_row_cnt();
    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    // executes specific sql
    bool add_row(int id, double grade, string category, string component,
                 string quality, int status, int rubId, int stuId, int assignNum);

    bool select_id(int i);

    bool update_id(int id, double grade, string category, string component,
                   string quality, int status, int rubId, int stuId, int assignNum);

    // object refs
    Rubric* rubric;
    Student* stu;
    int rubricId;
    int studentId;
    int assignNum;
    bool isNew;

    // grading status
    int status;

    // data
    double grade;
    vector<string> gradeCategory;
    vector<double> gradeComponent;
    vector<string> gradeQuality;
    vector<Code*> files;

protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_assignment(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_assignment(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_assignment(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);

#endif // ASSIGNMENT_H
