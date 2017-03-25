#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifndef CODE_H
#define CODE_H

using namespace std;

class Code
{
public:
    Code();
    vector<string> res;
    //string* res;
    vector<string> parse(string fileName);
    vector<string> fullCode;
    vector<string> comments;
    vector<string> linesOfCode;
    void insert(int position);

    //THIS METHOD IS INCOMPLETE.
    int categorize(string word);

    ~Code();
};

#endif // CODE_H
