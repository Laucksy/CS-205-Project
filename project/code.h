#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>

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
    vector<string> tokenize(string line);
    vector<string> fullCode;
    vector<string> comments;
    vector<string> linesOfCode;
    void insert(int position);
    void deleteFeedback(int pos);
    int categorize(string word);
    vector<string> get_full_code();



    ~Code();
};

#endif // CODE_H
