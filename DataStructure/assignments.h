#ifndef ASSIGNMENTS_H
#define ASSIGNMENTS_H

#include <vector>
#include "assignment.h"
#include "rubric.h"

using namespace std;

class Assignment;

class Assignments
{
public:
    Assignments();

    vector<Assignment*> list;
};

#endif // ASSIGNMENTS_H
