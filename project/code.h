#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>
#include "../DataStructure/feedback.h"
#include "../DataStructure/ident.h"

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
    vector<Feedback> profFeedback;
    void insert(int position);
    void add_feedback(Feedback fb);
    void delete_space_for_feedback(int pos);
    int categorize(string word);
    vector<string> get_full_code();



    ~Code();
};

#endif // CODE_H
