#ifndef STUDENTS_H
#define STUDENTS_H

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
#include "student.h"

using namespace std;

// list class to hold Student submissions
class Students : public Ident, public DBTable
{
public:
    Students();
    Students(DBTool* db, string n);
    ~Students();

    void set_to_delete();

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
    bool add_row(int id, string name);

    bool select_id(int i);

    bool update_id(int id, string name);

    bool delete_id(int i);

    vector<Student*> list;
    string name;
    bool isNew;
    bool toDelete;

protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;
    std::string sql_delete_id;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_students(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_students(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_students(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_delete_id_students(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);

#endif // STUDENTS_H
