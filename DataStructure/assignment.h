#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include "student.h"
#include "rubric.h"

using namespace std;

class Student;

class Assignment
{
public:
    Assignment();

    Rubric* rubric;
};

#endif // ASSIGNMENT_H
