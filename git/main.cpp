#include <iostream>
#include "git.h"

using namespace std;

int main(int argc, char *argv[])
{
    argc = 0;
    argv = nullptr;

    cout << "Hello World!" << endl;
    Git::init();
    Git::add_file("test.txt");
    //cout << Git::status() << endl;
    //system("clear");
    cout << Git::pull() << endl;
    cout << Git::push() << endl;
    cout << Git::reset() << endl;
    return 0;
}
