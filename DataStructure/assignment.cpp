#include "assignment.h"

Assignment::Assignment() : Ident::Ident('a')
{

}

Assignment::Assignment(Rubric* r, Student* s, int n) : Ident::Ident('a')
{
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

Assignment::~Assignment()
{
    for (Code* k : files) {
        delete k;
    }
}

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

double Assignment::get_grade()
{
    return grade;
}
