#ifndef GIT_H
#define GIT_H
#include "iostream"
#include "string"
#include "stdio.h"
#include "stdlib.h"
#include "include/git2.h"
#include "vector"
#include "bash.h"
using namespace std;

class Git
{
public:
    static void init();
    static string get_repo();
    static void set_repo(string r);
    static void add_file(string path);
    static string get_file(int index);
    static string status();
    static string push();
    static string pull();
    static string reset();

private:
    Git();
    ~Git();

    //static void add();
    //static void commit();

    static string repo;
    static bool initialized;
    static vector<string> files;
};

#endif // GIT_H
