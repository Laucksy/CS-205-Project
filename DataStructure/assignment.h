#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include <vector>
#include "../project/code.h"
#include "student.h"
#include "rubric.h"
#include "ident.h"

using namespace std;

class Student;

class Assignment : public Ident
{
public:
    Assignment();
    Assignment(Rubric* r, Student* s, int n);
    ~Assignment();

    void change_grade(double g, string c);
    double get_grade();

    Rubric* rubric;
    Student* stu;
    int assignNum;

    int status;

private:
    double grade;
    vector<string> gradeCategory;
    vector<double> gradeComponent;
    vector<string> gradeQuality;
    vector<Code*> files;

};

#endif // ASSIGNMENT_H
