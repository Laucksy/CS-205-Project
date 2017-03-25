#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "ident.h"
#include "assignment.h"

using namespace std;

class Assignment;

class Student : public Ident
{
public:
    Student();
    Student(string f, string l);
    ~Student();

    void calc_score();
    double get_score();

    vector<Assignment*> list;
    string firstName;
    string lastName;

private:
    double score;
};

#endif // STUDENT_H
