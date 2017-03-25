#include "rubric.h"

Rubric::Rubric()
{
    isDeduction = true;
}

Rubric::Rubric(bool d)
{
    isDeduction = d;
}

Rubric::~Rubric()
{
    for(Category* k : cat) {
        delete k;
    }
}

void Rubric::calc_grade()
{
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

bool Rubric::add_category(Category* c, string n)
{
    cat.push_back(c);
    name.push_back(n);
}

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
