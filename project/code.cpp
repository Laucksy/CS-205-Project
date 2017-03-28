#include "code.h"

using namespace std;

Code::Code() : Ident::Ident('o')
{

}

Code::Code(DBTool* db, string n, int aid) : Ident::Ident('o'), DBTable::DBTable(db, code_table)
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
    category_row_cnt = size();

    isNew = true; // assumes object is unique and not in table

    //initialize vars
    fileName = n;
    assignId = aid;
}

Code::~Code() {
    // if valid object, adds or updates it in table
    if (isNew && id >= 0) {
        add_row(id, fileName, convert_full(), convert_comments(),convert_lines(), assignId);
    } else if (!isNew && id >= 0){
        update_id(id, fileName, convert_full(), convert_comments(),convert_lines(), assignId);
    } else {

    }
}

vector<string> Code::parse(string fileName)
{

    string line;
    char commentTest[2];

    //going through each line of the selected file
    ifstream file;
    file.open(fileName, ifstream::in);
    //cout << fileName << endl;

    while(file.good())
    {
        cout << "here" << endl;
        while(getline(file,line))
        {
            fullCode.push_back(line);
            line.copy(commentTest,2,0);
            //if first two lines of code are //, then it is a comment
            if(commentTest[0] == '/' && commentTest[1] == '/')
            {
                comments.push_back(line);
            }
            //otherwise, it is a line of code
            else
                linesOfCode.push_back(line);
        }
        file.close();
    }
    //prints out all items of fullCode
    //only there to show to demonstrate functionality
    for (auto i = fullCode.begin(); i != fullCode.end(); ++i)
        cout << *i << ' ' << endl;
    return fullCode;
}

/*tokenize is a delimiter method, which parses a single string
 * ( a line of code from vector of strings)
 * this splits up the line into tokens to be passed through categorize method
 */
vector<string> Code::tokenize(string line)
{
    vector<string> tokens;
    vector<char> delimiterChars = { ' ', ',', '.', ':', '\t', '(', ')', '/', ';', '[', ']', '{', '}', '*' };

    stringstream ss(line);

    string i;

    while (ss >> i)
    {
        tokens.push_back(i);

        for(unsigned long x = 0; x < delimiterChars.size(); x++)
        {
            if (ss.peek() == delimiterChars[x])
                ss.ignore();
        }
    }

    for (unsigned long j =0; j< tokens.size(); j++)
        cout << tokens.at(j)<< endl;

    return tokens;
}


void Code::insert(int position)
{
    //iterating through code to insert text at a given position inside the vector
    vector<string>::iterator it = fullCode.begin();

    fullCode.insert (it+position," ");
    /*also if we only want to insert blank text as to make room for an overlay comment
      * rather than text, we could take in only position and add in a blank line.
      */
}

//remove blank space (slot for feedback) from given position
void Code::delete_space_for_feedback(int position)
{
        vector<string>::iterator itDelete = fullCode.begin();
        advance(itDelete, position);
        fullCode.erase(itDelete);
}

void Code::add_feedback(Feedback newComment)
{
        profFeedback.push_back(newComment);
}


//THIS METHOD IS INCOMPLETE.
int Code::categorize(string word)
{
    /*here, maybe should traverse through each word in each string of the vector,
     * but then shouldn't take in string. and that seems messier so better not?
     * probably the traversal should happen in the gui so its not collection of ints
     * and each int can be used at the time it's generated. also, the words that
     * are comments don't have to be parsed because they should fall into one specific color.
     * only contents of vector linesOfCode should be categorized.
     * NOTE: needs to be parsed by spaces, periods, parentheses. not only spaces!
     */
    /*categorize returns an int corresponding with the category the word falls in,
     * which can be used in coloring each word via cascade of if statements.
     */
    if(word=="float" || word=="string" || word=="int" || word=="char" || word=="long" || word=="short" || word=="double" || word=="boolean" || word=="byte" || word=="void")
    {
        return 1;
    }
    else if(word=="static" || word=="final")
    {
        return 2;
    }
    else if(word=="for" || word=="if" || word=="while" || word=="else" || word=="continue" || word=="break" || word == "return")
    {
        return 3;
    }
    else if(word=="import")
    {
        return 4;
    }
    else if(word=="class")
    {
        return 5;
    }
    else if(word=="this")
    {
        return 6;
    }
    else if(word=="public" || word=="protected" || word=="private")
    {
        return 7;
    }
    else if(word=="new")
    {
        return 8;
    }
    //everything else is just normal code, should be black (or some standard color).
    return 0;
}

vector<string> Code::get_full_code()
{
    return fullCode;
}

// db parse
// convert list to single string
string Code::convert_full()
{
    string ret;

    return ret;
}

string Code::convert_comments()
{
    string ret;

    return ret;
}

string Code::convert_lines()
{
    string ret;

    return ret;
}

// convert db string to list
void Code::parse_full(string s)
{
    stringstream ss(s);

    string i;

}

void Code::parse_comments(string s)
{
    stringstream ss(s);

    string i;

}

void Code::parse_lines(string s)
{
    stringstream ss(s);

    string i;

}

// database methods
int Code::get_row_cnt()
{
    return row_cnt;
}

void Code::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void Code::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  name TEXT,";
    sql_create += "  full TEXT,";
    sql_create += "  comments TEXT,";
    sql_create += "  line TEXT,";
    sql_create += "  assignId INT";
    sql_create += " );";

}


bool Code::add_row(int id, string name, string full,
                   string comments, string line, int assignId) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, name, full, comments, line, assignId ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(name);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(full);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(comments);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(line);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", assignId);
    sql_add_row += tempval;

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row_code,
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
bool Code::select_id(int i) {

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
                           cb_select_id_code,
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
bool Code::update_id(int id, string name, string full,
                     string comments, string line, int assignId) {
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

    sql_update_id += "full = ";
    sql_update_id += "\"";
    sql_update_id += std::string(full);
    sql_update_id += "\", ";

    sql_update_id += "comments = ";
    sql_update_id += "\"";
    sql_update_id += std::string(comments);
    sql_update_id += "\", ";

    sql_update_id += "line = ";
    sql_update_id += "\"";
    sql_update_id += std::string(line);
    sql_update_id += "\", ";

    sql_update_id += "assignId = ";
    sprintf (tempval, "%d", assignId);
    sql_update_id += tempval;

    sql_update_id += " WHERE ";
    sql_update_id += "id = ";
    sprintf (tempval, "%d", id);
    sql_update_id += tempval;

    sql_update_id += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_update_id.c_str(),
                           cb_update_id_code,
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
int cb_add_row_code(void  *data,
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

    Code *obj = (Code *) data;

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

int cb_select_id_code(void  *data,
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

    Code *obj = (Code *) data;
    obj->isNew = false; // object was generated from table

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    // assign object members from table data
    obj->fileName = argv[1];
    obj->parse_full(argv[2]);
    obj->parse_comments(argv[3]);
    obj->parse_lines(argv[4]);
    obj->assignId = (int)*argv[5];

    return 0;
}

int cb_update_id_code(void  *data,
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

    Code *obj = (Code *) data;

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


