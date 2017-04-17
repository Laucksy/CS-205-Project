#include "assignments.h"

// basic constructor
Assignments::Assignments() : Ident::Ident('l')
{

}

// constructor
Assignments::Assignments(DBTool* db, string n) : Ident::Ident('l'), DBTable::DBTable(db, assignments_table)
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    assignments_row_cnt = size();

    isNew = true; // assumes object is unique and not in table
    toDelete = false;

    // initialize vars
    name = n;
}

// destructor
Assignments::~Assignments()
{
    //if toDelete, delete
    if (toDelete) {
        delete_id(id);
        return;
    }

    //if valid object, adds or updates it in table
    if (isNew && id >= 0) {
        add_row(id, name, classId, rubId);
    } else if (!isNew && id >= 0){
        update_id(id, name, classId, rubId);
    } else {

    }

    // deletes all assignments
    if (list.size() >= 1) {
        for (Assignment* k : list) {
            delete k;
        }
    }
}

void Assignments::set_rubric(Rubric *r)
{
    rubric = r;
    rubId = r->id;
    for (Assignment* k : list) {
        k->rubric = rubric;
    }
}

void Assignments::set_to_delete()
{
    toDelete = true;
}

bool Assignments::did_submit(Student *s)
{
    bool ret = false;
    for (Assignment* k : list) {
        if (k->stu == s) {
            ret = true;
        }
    }

    return ret;
}

// database methods
int Assignments::get_row_cnt()
{
    return row_cnt;
}

void Assignments::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void Assignments::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  name TEXT,";
    sql_create += "  classId INT,";
    sql_create += "  rubId INT";
    sql_create += " );";

}


bool Assignments::add_row(int id, string name, int classId, int rubId) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, name, classId, rubId ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(name);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", classId);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", rubId);
    sql_add_row += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_assignments,
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
bool Assignments::select_id(int i) {

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
                           cb_select_id_assignments,
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
bool Assignments::update_id(int id, string name, int classId, int rubId) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_update_id  = "UPDATE ";
    sql_update_id += table_name;
    sql_update_id += " SET ";

    sql_update_id += "name = ";
    sql_update_id += "\"";
    sql_update_id += std::string(name);
    sql_update_id += "\", ";

    sql_update_id += "classId = ";
    sprintf (tempval, "%d", classId);
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
                           cb_update_id_assignments,
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
bool Assignments::delete_id(int i) {

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
                           cb_delete_id_assignments,
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
int cb_add_row_assignments(void  *data,
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

    Assignments *obj = (Assignments *) data;

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

int cb_select_id_assignments(void  *data,
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

    Assignments *obj = (Assignments *) data;
    obj->isNew = false; // object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members from table data
    obj->id = atoi(argv[0]);
    obj->id_assignments = atoi(argv[0]) + 1;
    obj->name =argv[1];
    obj->classId = atoi(argv[2]);
    obj->rubId = atoi(argv[3]);

    return 0;
}

int cb_update_id_assignments(void  *data,
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

    Assignments *obj = (Assignments *) data;

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

int cb_delete_id_assignments(void  *data,
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

    Assignments *obj = (Assignments *) data;

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
