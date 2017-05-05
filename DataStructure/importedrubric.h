#ifndef IMPORTEDRUBRIC_H
#define IMPORTEDRUBRIC_H
#include "rubric.h"

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../project/macros.h"


class ImportedRubric
{
public:
    ImportedRubric();
    Rubric* parse_rubric(string fileName);

};

#endif // IMPORTEDRUBRIC_H
