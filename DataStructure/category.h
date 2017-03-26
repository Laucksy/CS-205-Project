#ifndef CATEGORY_H
#define CATEGORY_H


#include <string>
#include <vector>
#include <math.h>
#include "rubric.h"
#include "ident.h"

class Rubric;

using namespace std;

class Category : public Ident
{
public:
    Category();
    Category(Rubric* r, double p);
    ~Category();

    double get_pts();
    bool is_matrix();
    vector<string> get_qual();
    vector<double> get_points();
    string find_qual(double p);

    bool add_quality(string s, double p);

    Rubric* rubric;

private:
    vector<string> quality;
    vector<double> points;
    double pts;
    bool isMatrix;
};

#endif // CATEGORY_H
