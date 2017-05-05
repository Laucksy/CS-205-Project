#ifndef BASH_H
#define BASH_H
#include "../DataStructure/assignment.h"
#include "stdexcept"
#include "iostream"
#include "cstdio"
#include "memory"
#include "string"
#include "array"
#include "ctime"
#include "git.h"
#include "../project/macros.h"
using namespace std;

class Assignment;

class Bash
{
public:
    Bash();

    static string exec(string cmd);
    static string copy(Assignment* assignment, string fn);
    static void make_dirs(string fn);
};

#endif // BASH_H
