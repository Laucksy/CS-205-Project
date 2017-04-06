#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

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
#include "rubric.h"

using namespace std;

// list class to hold assignment submissions
class Assignment;

class Assignments : public Ident, public DBTable
{
public:
    Assignments();
    Assignments(DBTool* db, string n);
    ~Assignments();

    void set_rubric(Rubric* r);

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
    bool add_row(int id, string name, int rubId);

    bool select_id(int i);

    bool update_id(int id, string name, int rubId);

    vector<Assignment*> list;
    string name;
    Rubric* rubric;
    int rubId;
    bool isNew;

protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_assignments(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_assignments(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_assignments(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);

#endif // ASSIGNMENTS_H
