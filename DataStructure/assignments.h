#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <vector>
#include <string>
#include "assignment.h"
#include "rubric.h"

using namespace std;

// list class to hold assignment submissions
class Assignment;

class Assignments
{
public:
    Assignments();
    Assignments(string n);
    ~Assignments();

    vector<Assignment*> list;
    string name;
};

#endif // ASSIGNMENTS_H