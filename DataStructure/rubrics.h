#ifndef RUBRICS_H
#define RUBRICS_H

#include <vector>
#include <string>
#include "rubric.h"

using namespace std;

// holds all rubrics made by instructor
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
