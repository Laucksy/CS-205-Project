#include "rubric.h"

// basic constructor, closes program
Rubric::Rubric()
{
    isDeduction = true;
}

// full constructor
Rubric::Rubric(DBTool* db, bool d, string n) : Ident::Ident('r'), DBTable::DBTable(db, rubric_table)
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    rubric_row_cnt = size();

    isNew = true; // assumes object is unique and not in table
    toDelete = false;

    // initialize vars
    isDeduction = d;
    title = n;
    grade = 0;
    calc_grade();
}

// destructor
Rubric::~Rubric()
{
    calc_grade();
    // if an object is slated for delete, delete it
    if (toDelete) {
        delete_id(id);
        return;
    }

    // if valid object, adds or updates it in table
    if (isNew && id >= 0) {
        add_row(id, title, grade, convert_name(), (int)isDeduction);
    } else if (!isNew && id >= 0){
        update_id(id, title, grade, convert_name(), (int)isDeduction);
    } else {

    }

    for(Category* k : cat) {
        delete k;
    }
}

void Rubric::set_to_delete()
{
    toDelete = true;
}

// determines the total grade from the grade parts in categories
void Rubric::calc_grade()
{
    grade = 0;
    for (Category* k : cat) {
        grade += k->get_pts();
    }
}

double Rubric::get_grade()
{
    return grade;
}

bool Rubric::is_deduction()
{
    return isDeduction;
}

vector<string> Rubric::get_names()
{
    return name;
}

vector<double> Rubric::get_pts()
{
    vector<double> ret;

    for (Category* k : cat) {
        ret.push_back(k->get_pts());
    }

    return ret;
}

// adds a new category
void Rubric::add_category(Category* c, string n)
{
    cat.push_back(c);
    name.push_back(n);
    calc_grade();
}

// finds the appropriate category quality
string Rubric::find_qual(double p, string c)
{
    int ind = -1;

    for (int i = 0; i < name.size(); i++) {
        if (name[i] == c) {
            ind = i;
        }
    }

    if (ind != -1 && cat[ind]->is_matrix()) {
        return cat[ind]->find_qual(p);
    } else {
        return "NULL";
    }
}

// db parse
// convert list to single string
string Rubric::convert_name()
{
    string ret;

    for (string k : name) {
        ret += k;
        ret += " ";
    }

    return ret;
}

// convert db string to list
void Rubric::parse_name(string s)
{
    stringstream ss(s);

    string i;

    while (ss >> i) {
        name.push_back(i);
    }

}

// database methods
int Rubric::get_row_cnt()
{
    return row_cnt;
}

void Rubric::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void Rubric::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  title TEXT,";
    sql_create += "  grade REAL,";
    sql_create += "  name TEXT,";
    sql_create += "  isDeduction INT";
    sql_create += " );";

}


bool Rubric::add_row(int id, string title, double grade, string name, int isDeduction) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, title, grade, name, isDeduction ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(title);
    sql_add_row += "\", ";

    sprintf (tempval, "%f", grade);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(name);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", isDeduction);
    sql_add_row += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_rubric,
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
bool Rubric::select_id(int i) {

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
                           cb_select_id_rubric,
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
bool Rubric::update_id(int id, string title, double grade, string name, int isDeduction) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_update_id  = "UPDATE ";
    sql_update_id += table_name;
    sql_update_id += " SET ";

    sql_update_id += "title = ";
    sql_update_id += "\"";
    sql_update_id += std::string(title);
    sql_update_id += "\", ";

    sql_update_id += "grade = ";
    sprintf (tempval, "%f", grade);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += "name = ";
    sql_update_id += "\"";
    sql_update_id += std::string(name);
    sql_update_id += "\", ";

    sql_update_id += "isDeduction = ";
    sprintf (tempval, "%d", isDeduction);
    sql_update_id += tempval;

    sql_update_id += " WHERE ";
    sql_update_id += "id = ";
    sprintf (tempval, "%d", id);
    sql_update_id += tempval;

    //sql_update_id += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_update_id.c_str(),
                           cb_update_id_rubric,
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
bool Rubric::delete_id(int i) {

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
                           cb_delete_id_rubric,
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
int cb_add_row_rubric(void  *data,
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

    Rubric *obj = (Rubric *) data;

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

int cb_select_id_rubric(void  *data,
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

    Rubric *obj = (Rubric *) data;
    obj->isNew = false; // object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members from table data
    obj->id = atoi(argv[0]);
    obj->id_rubric = atoi(argv[0]) + 1;
    obj->title = argv[1];
    obj->grade = atof(argv[2]);
    obj->parse_name(argv[3]);
    obj->isDeduction = (bool)atoi(argv[4]);

    return 0;
}

int cb_update_id_rubric(void  *data,
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

    Rubric *obj = (Rubric *) data;

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

int cb_delete_id_rubric(void  *data,
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

    Rubric *obj = (Rubric *) data;

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
