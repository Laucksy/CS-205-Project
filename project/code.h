#include <iostream>
#include <fstream>
#include <string>

#ifndef CODE_H
#define CODE_H

using namespace std;

class Code
{
public:
    Code();
    string* res;
    string* parse(string fileName);
    string* fullCode;
    string* comments;
    string* linesOfCode;
    ~Code();
};

#endif // CODE_H
