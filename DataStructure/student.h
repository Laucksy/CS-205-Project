#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "assignments.h"

using namespace std;

class Assignment;
class Assignments;

class Student
{
public:
    Student();

    Assignments* list;
};

#endif // STUDENT_H
