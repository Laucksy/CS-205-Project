#ifndef CATEGORY_H
#define CATEGORY_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include <math.h>
#include <stdlib.h>
#include "dbtable.h"
#include "rubric.h"
#include "ident.h"

class Rubric; // forward declaration

using namespace std;

/* class holds a point value for a rubric category and different
 * value/point pairings for possible scores
 */

class Category : public Ident, public DBTable
{
public:
    //Constructors and Deconstructor
    Category();
    Category(DBTool* db, Rubric* r, double p, bool m);
    ~Category();

    void set_to_delete();

    // data methods
    double get_pts();
    bool is_matrix();
    vector<string> get_qual();
    vector<double> get_points();
    string find_qual(double p);

    // adds a quality/point pair
    bool add_quality(string s, double p);

    // db parse methods
    string convert_quality();
    string convert_points();
    void parse_quality(string s);
    void parse_points(string s);

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
    bool add_row(int id, string quality, string points,
                 double pt, int matrix, int rubId);

    bool select_id(int i);

    bool update_id(int id, string quality, string points,
                   double pt, int matrix, int rubId);

    bool delete_id(int i);

    Rubric* rubric;
    double pts; // total points
    bool isMatrix; // uses quality descriptions
    bool isNew; //used for db tracking
    int rubricId;
    bool toDelete;

private:
    vector<string> quality; // quality descrpictions
    vector<double> points; // point thresholds

protected:
    // sql command templates
    std::string sql_select_id;
    std::string sql_update_id;
    std::string sql_delete_id;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row_category(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_id_category(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_update_id_category(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);
// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_delete_id_category(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName);



#endif // CATEGORY_H
