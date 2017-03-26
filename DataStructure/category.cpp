#include "category.h"

Category::Category() : Ident::Ident('c')
{
    isMatrix = true;
}

Category::Category(Rubric* r, double p) : Ident::Ident('c')
{
    pts = p;
    isMatrix = false;
    rubric = r;
}

Category::~Category()
{

}

double Category::get_pts()
{
    return pts;
}

bool Category::is_matrix()
{
    return isMatrix;
}

vector<string> Category::get_qual()
{
    return quality;
}

vector<double> Category::get_points()
{
    return points;
}

string Category::find_qual(double p)
{
    if (quality.size() == 0) {
        return "NULL";
    }

    int ind = 0;
    double diff = points[0] - p;
    double minDiff = fabs(diff);

    for (int i = 1; i < points.size(); i++) {
        diff = points[i] - p;
        if (fabs(diff) < minDiff) {
            minDiff = fabs(diff);
            ind= i;
        }
    }

    return quality[ind];
}

bool Category::add_quality(string s, double p)
{
    if (!isMatrix) {
        return false;
    }

    quality.push_back(s);
    points.push_back(p);
    return true;
}
