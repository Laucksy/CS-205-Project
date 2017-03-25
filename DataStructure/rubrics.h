#ifndef RUBRICS_H
#define RUBRICS_H

#include <vector>
#include <string>
#include "rubric.h"

using namespace std;

class Rubrics
{
public:
    Rubrics();
    Rubrics(string n);
    ~Rubrics();

    vector<Rubric*> rubrics;
    string name;
};

#endif // RUBRICS_H
