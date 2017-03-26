#ifndef EXPORTHTML_H
#define EXPORTHTML_H
#include "../DataStructure/assignment.h"
#include "iostream"
#include "string"
using namespace std;

class ExportHTML
{
public:
    static void export_assignment(Assignment* a);

private:
    ExportHTML();
    ~ExportHTML();
};

#endif // EXPORTHTML_H
