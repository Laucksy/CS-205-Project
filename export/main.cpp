#include "iostream"
#include "../export/exporthtml.h"
#include "../DataStructure/assignment.h"
#include "../DataStructure/rubric.h"
#include "../DataStructure/student.h"
using namespace std;

int main(int argc, char *argv[])
{
    argc = 0;
    argv = nullptr;

    cout << "Hello World!" << endl;

    DBTool* tool = new DBTool("TestDB");
    Student* student = new Student(tool, "Erik Laucks");
    Rubric* rubric = new Rubric(tool, false, "Test Rubric");
    Assignment* assignment = new Assignment(tool, rubric, student, 0);
    Code* x = new Code(tool,"/home/erik/Desktop/Student.java",0);
    assignment->add_code(x);
    cout << "First " << x << endl;
    Code* y = new Code(tool,"/home/erik/Desktop/JavaIntro.java",0);
    assignment->add_code(y);
    cout << "First " << y << endl;

    //cout << ExportHTML::export_assignment(assignment) << endl;
    ExportHTML::export_assignment(assignment);

    delete assignment;
    delete student;
    delete rubric;

    return 0;
}
