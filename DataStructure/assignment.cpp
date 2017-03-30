#include "assignment.h"

// basic constructor, do not use
Assignment::Assignment() : Ident::Ident('a')
{

}

// full constructor
Assignment::Assignment(DBTool* db, Rubric* r, Student* s, int n) : Ident::Ident('a'), DBTable::DBTable(db, assignment_table)
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    assignment_row_cnt = size();

    isNew = true; // assumes object is unique and not in table

    // initialize vars
    stu = s;
    rubric = r;
    assignNum = n;

    if (r->is_deduction()) {
        grade = r->get_grade();
    } else {
        grade = 0;
    }

    gradeCategory = r->get_names();
    gradeComponent = r->get_pts();

    for (int i = 0; i < gradeCategory.size(); i ++) {
        gradeQuality.push_back(r->find_qual(gradeComponent[i], gradeCategory[i]));
    }
}

// destructor
Assignment::~Assignment()
{
    // if valid object, adds or updates it in table
    if (isNew && id >= 0) {
        add_row(id, grade, convert_category(), convert_component(),
                convert_quality(), status, rubric->id, stu->id, assignNum);
    } else if (!isNew && id >= 0){
        update_id(id, grade, convert_category(), convert_component(),
                  convert_quality(), status, rubric->id, stu->id, assignNum);
    } else {

    }

    for (Code* k : files) {
        delete k;
    }
}

// affects a grade category
void Assignment::change_grade(double g, string c)
{
    int ind = -1;

    for (int i = 0; i < gradeCategory.size(); i++) {
        if (gradeCategory[i] == c) {
            ind = i;
        }
    }

    if (ind != -1) {
        gradeComponent[ind] = g;
        gradeQuality[ind] = rubric->find_qual(g, gradeCategory[ind]);
    }

    for (double k : gradeComponent) {
        grade += k;
    }
}

// return grade
double Assignment::get_grade()
{
    return grade;
}

void Assignment::add_code(Code *c) {
    files.push_back(c);
}

// db parse
// convert list to single string
string Assignment::convert_category()
{
    string ret;

    for (string k : gradeCategory) {
        ret += k;
        ret += " ";
    }

    return ret;
}

string Assignment::convert_component()
{
    string ret;

    for (double k : gradeComponent) {
        ret += to_string(k);
        ret += " ";
    }

    return ret;
}

string Assignment::convert_quality()
{
    string ret;

    for (string k : gradeQuality) {
        ret += k;
        ret += " ";
    }

    return ret;
}

// convert db string to list
void Assignment::parse_category(string s)
{
    stringstream ss(s);

    string i;

    while (ss >> i) {
        gradeCategory.push_back(i);
    }

}

void Assignment::parse_component(string s)
{
    stringstream ss(s);

    string i;

    while (ss >> i) {
        gradeComponent.push_back(atof(i.c_str()));
    }
}

void Assignment::parse_quality(string s)
{
    stringstream ss(s);

    string i;

    while (ss >> i) {
        gradeQuality.push_back(i);
    }

}

// database methods
int Assignment::get_row_cnt()
{
    return row_cnt;
}

void Assignment::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void Assignment::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  gradet REAL,";
    sql_create += "  category TEXT,";
    sql_create += "  component TEXT,";
    sql_create += "  quality TEXT,";
    sql_create += "  status INT,";
    sql_create += "  rubId INT";
    sql_create += "  stuId INT,";
    sql_create += "  assignNum INT";
    sql_create += " );";

}


bool Assignment::add_row(int id, double grade, string category, string component,
                         string quality, int status, int rubId, int stuId, int assignNum) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, grade, category, component, quality, status, rubId, stuId, assignNum ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%f", grade);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(category);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(component);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(quality);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", status);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", rubId);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", stuId);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", assignNum);
    sql_add_row += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_assignment,
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
bool Assignment::select_id(int i) {

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
                           cb_select_id_assignment,
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
bool Assignment::update_id(int id, double grade, string category, string component,
                           string quality, int status, int rubId, int stuId, int assignNum) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_update_id  = "UPDATE ";
    sql_update_id += table_name;
    sql_update_id += " SET ";

    sql_update_id += "grade = ";
    sprintf (tempval, "%f", grade);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += "category = ";
    sql_update_id += "\"";
    sql_update_id += std::string(category);
    sql_update_id += "\", ";

    sql_update_id += "component = ";
    sql_update_id += "\"";
    sql_update_id += std::string(component);
    sql_update_id += "\", ";

    sql_update_id += "quality = ";
    sql_update_id += "\"";
    sql_update_id += std::string(quality);
    sql_update_id += "\", ";

    sql_update_id += "status = ";
    sprintf (tempval, "%d", status);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += "rubId = ";
    sprintf (tempval, "%d", rubId);
    sql_update_id += tempval;

    sql_update_id += "stuId = ";
    sprintf (tempval, "%d", stuId);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += "assignNum = ";
    sprintf (tempval, "%d", assignNum);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += " WHERE ";
    sql_update_id += "id = ";
    sprintf (tempval, "%d", id);
    sql_update_id += tempval;

    sql_update_id += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_update_id.c_str(),
                           cb_update_id_assignment,
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
int cb_add_row_assignment(void  *data,
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

    Assignment *obj = (Assignment *) data;

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

int cb_select_id_assignment(void  *data,
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

    Assignment *obj = (Assignment *) data;
    obj->isNew = false; // object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members from table data
    obj->grade = atof(argv[1]);
    obj->parse_category(argv[2]);
    obj->parse_component(argv[3]);
    obj->parse_quality(argv[4]);
    obj->status = (int)*argv[5];
    obj->rubricId = (int)*argv[6];
    obj->studentId = (int)*argv[7];
    obj->assignNum = (int)*argv[8];

    return 0;
}

int cb_update_id_assignment(void  *data,
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

    Assignment *obj = (Assignment *) data;

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


