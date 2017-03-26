#ifndef RUBRIC_H
#define RUBRIC_H

#include <string>
#include <vector>
#include "category.h"
#include "ident.h"

using namespace std;

class Category;

class Rubric : public Ident
{
public:
    Rubric();
    Rubric(bool d);
    ~Rubric();

    void calc_grade();
    double get_grade();
    bool is_deduction();
    vector<string> get_names();
    vector<double> get_pts();

    string find_qual(double p, string c);

    bool add_category(Category*, string n);

private:
    double grade;
    vector<string> name;
    vector<Category*> cat;
    bool isDeduction;
};

#endif // RUBRIC_H
