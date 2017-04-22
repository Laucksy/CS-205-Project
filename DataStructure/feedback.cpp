#include "feedback.h"

Feedback::Feedback()
{

}

Feedback::Feedback(DBTool* db, std::string te, std::string ta, int cid, int p): Ident::Ident('f'), DBTable::DBTable(db, feedback_table)
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    feedback_row_cnt = size();

    isNew = true; // assumes object is unique and not in table
    toDelete = false;

    // initialize vars
    string text = te;
    string tag = ta;
    int codeId = cid;
    int position = p;
}

void Feedback::change_text(string txt)
{
    text = txt;
    store_in_db();
}

void Feedback::update_tag(string t)
{
    tag = t;
    store_in_db();
}

Feedback::~Feedback()
{
    store_in_db();
}

// database methods
void Feedback::store_in_db()
{
    if (toDelete) {
        delete_id(id);
        return;
    }
    // if valid object, adds or updates it in table
    if (isNew && id >= 0) {
        add_row(id, text, tag, codeId, position);
        isNew = false;
    } else if (!isNew && id >= 0){
        update_id(id, text, tag, codeId, position);
    } else {

    }
}

void Feedback::set_to_delete()
{
    toDelete = true;
}

int Feedback::get_row_cnt()
{
    return row_cnt;
}

void Feedback::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void Feedback::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  text TEXT,";
    sql_create += "  tag TEXT,";
    sql_create += "  codeId INT,";
    sql_create += "  position INT";
    sql_create += " );";

}


bool Feedback::add_row(int id, string text, string tag, int codeId, int position) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, text, tag, codeId, position ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(text);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(tag);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", codeId);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", position);
    sql_add_row += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_feedback,
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
bool Feedback::select_id(int i) {

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
                           cb_select_id_feedback,
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
bool Feedback::update_id(int id, string text, string tag, int codeId, int position) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_update_id  = "UPDATE ";
    sql_update_id += table_name;
    sql_update_id += " SET ";

    sql_update_id += "text = ";
    sql_update_id += "\"";
    sql_update_id += std::string(text);
    sql_update_id += "\", ";

    sql_update_id += "tag = ";
    sql_update_id += "\"";
    sql_update_id += std::string(tag);
    sql_update_id += "\", ";

    sql_update_id += "codeId = ";
    sprintf (tempval, "%d", codeId);
    sql_update_id += tempval;
    sql_update_id += ", ";

    sql_update_id += "position = ";
    sprintf (tempval, "%d", position);
    sql_update_id += tempval;

    sql_update_id += " WHERE ";
    sql_update_id += "id = ";
    sprintf (tempval, "%d", id);
    sql_update_id += tempval;

    //sql_update_id += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_update_id.c_str(),
                           cb_update_id_feedback,
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
bool Feedback::delete_id(int i) {

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
                           cb_delete_id_feedback,
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

// selects entry by similarity to provied string
bool Feedback::select_similar(string sim) {

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_similar  = "SELECT text FROM ";
    sql_select_similar += table_name;
    sql_select_similar += " WHERE ";
    sql_select_similar += "     text LIKE ";
    sql_select_similar += "\"";
    sql_select_similar += "%";
    sql_select_similar += sim;
    sql_select_similar += "%";
    sql_select_similar += "\"";
    sql_select_similar += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_similar.c_str(),
                           cb_select_similar_feedback,
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
int cb_add_row_feedback(void  *data,
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

    Feedback *obj = (Feedback *) data;

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

int cb_select_id_feedback(void  *data,
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

    Feedback *obj = (Feedback *) data;
    obj->isNew = false; // object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members from table data
    obj->id = atoi(argv[0]);
    obj->id_feedback = atoi(argv[0]) + 1;
    obj->text = argv[1];
    obj->tag = argv[2];
    obj->codeId = atoi(argv[3]);
    obj->position = atoi(argv[4]);

    return 0;
}

int cb_update_id_feedback(void  *data,
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

    Feedback *obj = (Feedback *) data;

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

int cb_delete_id_feedback(void  *data,
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

    Feedback *obj = (Feedback *) data;

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

int cb_select_similar_feedback(void  *data,
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

    Feedback *obj = (Feedback *) data;
    obj->isNew = false; // object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members from table data
    bool has= false;
    for (int i = 0; i < argc; i++) {
        for (string k : obj->simillar) {
            if (k == argv[i]) {
                has = true;
            }
        }
        if (!has) {
            obj->simillar.push_back(argv[i]);
        }
        has = false;
    }

    return 0;
}



