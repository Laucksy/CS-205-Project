#ifndef IDENT_H
#define IDENT_H

#include <string>

using namespace std;

class Ident
{
public:
    Ident();
    Ident(char k);
    ~Ident();

    static int id_student;
    static int id_assignment;
    static int id_rubric;
    static int id_category;
    static int id_code;
    static int id_feedback;

    static int student_row_cnt;
    static int assignment_row_cnt;
    static int rubric_row_cnt;
    static int category_row_cnt;
    static int code_row_cnt;
    static int feedback_row_cnt;

    static string student_table;
    static string assignment_table;
    static string rubric_table;
    static string category_table;
    static string code_table;
    static string feedback_table;

    int id;
};

#endif // IDENT_H
