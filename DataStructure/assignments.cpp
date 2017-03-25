#include "assignments.h"

Assignments::Assignments()
{

}

Assignments::Assignments(string n)
{
    name = n;
}

Assignments::~Assignments()
{
    if (list.size() >= 1) {
        for (Assignment* k : list) {
            delete k;
        }
    }
}
