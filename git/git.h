#ifndef GIT_H
#define GIT_H
#include "iostream"
#include "string"
#include "stdio.h"
#include "stdlib.h"
#include "sstream"
#include "vector"
#include "bash.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Git
{
public:
    static bool init();
    static string get_repo();
    static void set_repo(string r);
    static string get_name();
    static void set_name(string n);
    static void add_file(string path);
    static string get_file(int index);
    static string find_file_path(string fileName);
    static vector<string> find_all_files(string pathName);
    static string escape_spaces(string str);

    static string status();
    static bool push();
    static bool pull();
    static bool reset();

private:
    Git();
    ~Git();

    //static void add();
    //static void commit();

    static string repo;
    static string name;
    static bool initialized;
    static vector<string> files;
};

#endif // GIT_H
