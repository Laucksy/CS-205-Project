#ifndef FEEDBACK_H
#define FEEDBACK_H

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

class Feedback : public Ident, public DBTable
{
public:
    Feedback();
    Feedback(DBTool* db, string te, string ta, int cid, int p);
    ~Feedback();

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
    bool add_row(int id, string text, string tag, int codeId, int position);

    bool select_id(int i);

    bool update_id(int id, string text, string tag, int codeId, int position);

    string text;
    string tag;
    void change_text(string txt);
    void update_tag(string t);

    //this is database stuff
    int codeId;
    int position;
    bool isNew;

protected:
    // sql command templates
    string sql_select_id;
    string sql_update_id;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_feedback(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_feedback(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_feedback(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);

#endif // FEEDBACK_H
