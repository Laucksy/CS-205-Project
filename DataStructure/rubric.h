#ifndef RUBRIC_H
#define RUBRIC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include <math.h>
#include <stdlib.h>
#include "dbtable.h"
#include "category.h"
#include "ident.h"

using namespace std;

class Category;

// holds a name category mapping and a total point worth
class Rubric : public Ident, public DBTable
{
public:
    // constructors and deconstructors
    Rubric();
    Rubric(DBTool* db, bool d, string n);
    ~Rubric();

    // data methods
    void calc_grade();
    double get_grade();
    bool is_deduction();
    vector<string> get_names();
    vector<double> get_pts();

    // finds the appropriate quality in the appropriate category
    string find_qual(double p, string c);

    // adds a new category name pair
    void add_category(Category*, string n);

    // db parse methods
    string convert_name();
    void parse_name(string s);

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
    bool add_row(int id, string title, double grade, string name, int isDeduction);

    bool select_id(int i);

    bool update_id(int id, string title, double grade, string name, int isDeduction);

    //data members
    string title;
    double grade;
    vector<string> name;
    vector<Category*> cat;
    bool isDeduction;
    bool isNew;

protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_rubric(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_rubric(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_rubric(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);


#endif // RUBRIC_H
