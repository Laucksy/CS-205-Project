#include "rubrics.h"

Rubrics::Rubrics()
{

}

Rubrics::Rubrics(string n)
{
    name = n;
}

Rubrics::~Rubrics()
{
    for (Rubric* k : rubrics) {
        delete k;
    }
}
