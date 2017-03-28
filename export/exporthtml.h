#ifndef EXPORTHTML_H
#define EXPORTHTML_H
#include "../DataStructure/assignment.h"
#include "../project/code.h"
#include "iostream"
#include "fstream"
#include "string"
#include "vector"
using namespace std;

class ExportHTML
{
public:
    static string export_assignment(Assignment* a);

private:
    ExportHTML();
    ~ExportHTML();
};

#endif // EXPORTHTML_H
