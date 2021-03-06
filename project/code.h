#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include "../DataStructure/ident.h"
#include "../DataStructure/dbtool.h"
#include "../DataStructure/dbtable.h"
#include "../DataStructure/feedback.h"
#include "stdexcept"
#include "cstdio"
#include "memory"
#include "string"
#include "array"
#include <sstream>
#include "macros.h"

#ifndef CODE_H
#define CODE_H

using namespace std;

class Feedback;
class DBTool;

class Code : public Ident, public DBTable
{
public:
    Code();
    Code(DBTool* db, string n, int aid);
    vector<string> parse();
    vector<string> tokenize(string line);
    vector<string> delimiters(string line);
    vector<string> fullCode;
    vector<string> comments;
    vector<string> linesOfCode;
    vector<Feedback*> profFeedback;
    void insert(int position,string);
    void set_file(string name);


    void delete_feedback(int x);

    string exec_sec(string cmd);

    string file_path(string file);

    void deleteFeedback(int pos);

    void add_feedback(Feedback* fb);
    void delete_space_for_feedback(int pos);

    int categorize(string word);
    vector<string> get_full_code();

    void set_to_delete();

    ~Code();

    // Database additions
    bool isNew;
    bool toDelete;
    int assignId;
    string fileName;

    // db parse methods
    string convert_full();
    string convert_comments();
    string convert_lines();
    vector<string> parse_full(string s);
    vector<string> parse_comments(string s);
    vector<string> parse_lines(string s);

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
    bool add_row(int id, string name, string full,
                 string comments, string line, int assignId);

    bool select_id(int i);

    bool update_id(int id, string name, string full,
                   string comments, string line, int assignId);

    bool delete_id(int i);

protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;
    std::string sql_delete_id;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_code(void  *data,
                    int    argc,
                    char **argv,
                    char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_code(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_code(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_delete_id_code(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);

#endif // CODE_H
