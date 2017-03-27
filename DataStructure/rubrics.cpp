#include "rubrics.h"

//basic constructor
Rubrics::Rubrics()
{

}

// ful constructor
Rubrics::Rubrics(string n)
{
    name = n;
}

// destructor
Rubrics::~Rubrics()
{
    for (Rubric* k : rubrics) {
        delete k;
    }
}
