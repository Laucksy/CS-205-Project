#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include "../DataStructure/feedback.h"
#include "../DataStructure/ident.h"
#include "../DataStructure/dbtool.h"
#include "../DataStructure/dbtable.h"

#ifndef CODE_H
#define CODE_H

using namespace std;

class Code : public Ident, public DBTable
{
public:
    Code();
    Code(DBTool* db, string n, int aid);
    vector<string> parse(string fileName);
    vector<string> tokenize(string line);
    vector<string> fullCode;
    vector<string> comments;
    vector<string> linesOfCode;
    vector<Feedback> profFeedback;
    void insert(int position);
    void add_feedback(Feedback fb);
    void delete_space_for_feedback(int pos);
    int categorize(string word);
    vector<string> get_full_code();



    ~Code();

    // Database additions
    bool isNew;
    int assignId;
    string fileName;

    // db parse methods
    string convert_full();
    string convert_comments();
    string convert_lines();
    void parse_full(string s);
    void parse_comments(string s);
    void parse_lines(string s);

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

protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;
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

#endif // CODE_H
