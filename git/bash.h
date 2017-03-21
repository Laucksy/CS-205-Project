#ifndef BASH_H
#define BASH_H
#include "stdexcept"
#include "iostream"
#include "cstdio"
#include "memory"
#include "string"
#include "array"
using namespace std;

class Bash
{
public:
    Bash();

    static string exec(string cmd);
};

#endif // BASH_H
