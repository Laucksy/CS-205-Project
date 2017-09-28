#ifndef EXPORTHTML_H
#define EXPORTHTML_H
#include "../DataStructure/assignments.h"
#include "../DataStructure/assignment.h"
#include "../DataStructure/students.h"
#include "../project/code.h"
#include "../git/bash.h"
#include "iostream"
#include "fstream"
#include "string"
#include "vector"
#include "../project/macros.h"
using namespace std;

class ExportHTML
{
public:
    static string export_assignment(Assignment* a);
    static void export_csv_assignment(Assignments* a);
    static void export_csv_section(Students* s);

private:
    ExportHTML();
    ~ExportHTML();
};

#endif // EXPORTHTML_H
