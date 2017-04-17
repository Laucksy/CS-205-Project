#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include <math.h>
#include <stdlib.h>
#include "dbtable.h"
#include "ident.h"
#include "assignment.h"
#include "students.h"

using namespace std;

class Assignment;
class Students;

// holds the grade and information for a student
class Student : public Ident, public DBTable
{
public:
    // constuctors and deconstructors
    Student();
    Student(DBTool* db, string n);
    ~Student();

    void set_to_delete();

    // manipulate score
    void calc_score();
    double get_score();

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
    bool add_row(int id, string name, int classId, double score);

    bool select_id(int i);

    bool update_id(int id, string name, int classId, double score);

    bool delete_id(int i);

    //members
    vector<Assignment*> list;
    Students* section;
    string name;
    double score;
    bool isNew;
    int classId;
    bool toDelete;

protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;
    std::string sql_delete_id;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_student(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_student(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_student(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_delete_id_student(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);

#endif // STUDENT_H
