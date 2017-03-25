#include "ident.h"

int Ident::id_student = 0;
int Ident::id_assignment = 0;
int Ident::id_rubric = 0;
int Ident::id_category = 0;
int Ident::id_code = 0;
int Ident::id_feedback = 0;

int Ident::student_row_cnt = 0;
int Ident::assignment_row_cnt = 0;
int Ident::rubric_row_cnt = 0;
int Ident::category_row_cnt = 0;
int Ident::code_row_cnt = 0;
int Ident::feedback_row_cnt = 0;

string Ident::student_table;
string Ident::assignment_table;
string Ident::rubric_table;
string Ident::category_table;
string Ident::code_table;
string Ident::feedback_table;

Ident::Ident()
{
    // object is none of above, id irrelevant
    id = -1;
}

Ident::Ident(char k)
{
    switch (k) {
    case 's':
        // object is student, increment student id
        id = id_student;
        id_student++;
        break;

    case 'a':
        // object is assignment, increment assignment id
        id = id_assignment;
        id_assignment++;
        break;

    case 'r':
        // object is rubric, increment rubric id
        id = id_rubric;
        id_rubric++;
        break;

    case 'c':
        // object is assignment, increment assignment id
        id = id_category;
        id_category++;
        break;

    case 'o':
        // object is code, increment code id
        id = id_code;
        id_code++;
        break;

    case 'f':
        // object is feedback, increment feedback id
        id = id_feedback;
        id_feedback++;
        break;

    default:
        // object is none of above, id irrelevant
        id = -1;
        break;

    }
}

Ident::~Ident()
{

}
