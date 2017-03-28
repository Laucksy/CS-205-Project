#include "assignments.h"

// basic constructor
Assignments::Assignments()
{

}

// constructor
Assignments::Assignments(string n)
{
    name = n;
}

// destructor
Assignments::~Assignments()
{
    // deletes all assignments
    if (list.size() >= 1) {
        for (Assignment* k : list) {
            delete k;
        }
    }
}
