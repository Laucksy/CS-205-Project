#include "category.h"

/*	The Category class is used in matrix-style rubric grading systems.
 * A Category contains a name, which is the category header, and a
 * vector of Strings that are the different point options within the
 * category. Category contains a method to get the name of the Category
 * for in an Assignment’s pointBreakdown.
 * */

//basic constructor, will crash program
Category::Category() : Ident::Ident('c')
{
    isMatrix = true;
}

// full constructor
Category::Category(DBTool* db, Rubric* r, double p, bool m) : Ident::Ident('c'), DBTable::DBTable(db, category_table)
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    category_row_cnt = size();

    isNew = true; // assumes object is unique and not in table
    toDelete = false;

    // initialize vars
    pts = p;
    isMatrix = m;
    rubric = r;
    rubricId = r->id;
}

// destructor
Category::~Category()
{
    // if an object is slated for delete, delete it
    if (toDelete) {
        delete_id(id);
        return;
    }

    int mat;
    if (isMatrix) {
        mat = 1;
    } else {
        mat = 0;
    }

    // if valid object, adds or updates it in table
    if (isNew && id >= 0) {
        add_row(id, convert_quality(), convert_points(), pts, mat, rubricId);
    } else if (!isNew && id >= 0){
        update_id(id, convert_quality(), convert_points(), pts, mat, rubricId);
    } else {

    }
}

void Category::set_to_delete()
{
    toDelete = true;
}

double Category::get_pts()
{
    return pts;
}

bool Category::is_matrix()
{
    return isMatrix;
}

vector<string> Category::get_qual()
{
    return quality;
}

vector<double> Category::get_points()
{
    return points;
}

// finds the appropriate quality assessment for a given grade
string Category::find_qual(double p)
{
    if (quality.size() == 0) {
        return "NULL2";
    }

    string ret;

    for (int i = 0; i < points.size(); i++) {
        if (p >= points[i]) {
          ret = quality[i];
          break;
        }
    }

    return ret;

//    int ind = 0;
//    double diff = points[0] - p;
//    double minDiff = fabs(diff);

//    for (int i = 1; i < points.size(); i++) {
//        diff = points[i] - p;
//        if (fabs(diff) < minDiff) {
//            minDiff = fabs(diff);
//            ind= i;
//        }
//    }

//    return quality[ind];
}

// adds a quality value pair
bool Category::add_quality(string s, double p)
{
    if (!isMatrix) {
        return false;
    }

    quality.push_back(s);
    points.push_back(p);
    return true;
}

// db parse
// convert list to single string
string Category::convert_quality()
{
    string ret;

    for (string k : quality) {
        ret += k;
        ret += "#";
    }

    return ret;
}

string Category::convert_points()
{
    string ret;

    for (double k : points) {
        ret += to_string(k);
        ret += " ";
    }

    return ret;
}

// convert db string to list
void Category::parse_quality(string s)
{
    stringstream ss(s);

    string i;

    while (getline(ss, i, '#')) {
        quality.push_back(i);
    }

}

void Category::parse_points(string s)
{
    stringstream ss(s);

    string i;

    while (ss >> i) {
        points.push_back(atof(i.c_str()));
    }
}

// database methods
int Category::get_row_cnt()
{
    return row_cnt;
}

void Category::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void Category::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  quality TEXT,";
    sql_create += "  points TEXT,";
    sql_create += "  pt REAL,";
    sql_create += "  matrix INT,";
    sql_create += "  rubId INT";
    sql_create += " );";

}


bool Category::add_row(int id, string quality, string points,
                     double pt, int matrix, int rubId) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, quality, points, pt, matrix, rubId ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(quality);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(points);
    sql_add_row += "\", ";

    sprintf (tempval, "%f", pt);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", matrix);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", rubId);
    sql_add_row += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_category,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// selects entry by unique id
bool Category::select_id(int i) {

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_id  = "SELECT * FROM ";
    sql_select_id += table_name;
    sql_select_id += " WHERE ";
    sql_select_id += "     id = ";
    sql_select_id += to_string(i);
    sql_select_id += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_id.c_str(),
                           cb_select_id_category,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// updates entry by unique id
bool Category::update_id(int id, string quality, string points,
                       double pt, int matrix, int rubId) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_update_id  = "UPDATE ";
    sql_update_id += table_name;
    sql_update_id += " SET ";

    sql_update_id += "quality = ";
    sql_update_id += "\"";
    sql_update_id += std::string(quality);
    sql_update_id += "\", ";

    sql_update_id += "points = ";
    sql_update_id += "\"";
    sql_update_id += std::string(points);
    sql_update_id += "\", ";

    sql_update_id += "pt = ";
    sprintf (tempval, "%f", pt);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += "matrix = ";
    sprintf (tempval, "%d", matrix);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += "rubId = ";
    sprintf (tempval, "%d", rubId);
    sql_update_id += tempval;

    sql_update_id += " WHERE ";
    sql_update_id += "id = ";
    sprintf (tempval, "%d", id);
    sql_update_id += tempval;

    //sql_update_id += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_update_id.c_str(),
                           cb_update_id_category,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg
                  << std::endl
                  << sql_update_id;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// deletes entry by unique id
bool Category::delete_id(int i) {

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_delete_id  = "DELETE FROM ";
    sql_delete_id += table_name;
    sql_delete_id += " WHERE ";
    sql_delete_id += "     id = ";
    sql_delete_id += to_string(i);
    sql_delete_id += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_delete_id.c_str(),
                           cb_delete_id_category,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

// callbacks
int cb_add_row_category(void  *data,
                      int    argc,
                      char **argv,
                      char **azColName)
{



    std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Category *obj = (Category *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){

        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? argv[i] : "NULL")
                      << std::endl;
    }

    return 0;
}

int cb_select_id_category(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName)
{



    std::cerr << "cb_select_all being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Category *obj = (Category *) data;
    obj->isNew = false; // object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members from table data
    obj->id = atoi(argv[0]);
    obj->id_category = atoi(argv[0]) + 1;
    obj->parse_quality(argv[1]);
    obj->parse_points(argv[2]);
    obj->pts = atof(argv[3]);
    obj->isMatrix = (bool)atoi(argv[4]);
    obj->rubricId = atoi(argv[5]);

    return 0;
}

int cb_update_id_category(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName)
{



    std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Category *obj = (Category *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? argv[i] : "NULL")
                      << std::endl;
    }

    return 0;
}

int cb_delete_id_category(void  *data,
                        int    argc,
                        char **argv,
                        char **azColName)
{



    std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    Category *obj = (Category *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                     << " = "
                     <<  (argv[i] ? argv[i] : "NULL")
                      << std::endl;
    }

    return 0;
}

