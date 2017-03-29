#include "mainwindow.h"
#include "../project/code.h"

#include <QApplication>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();



    Code x;
    //vector<string> v;
   vector<string> v = x.parse("/Users/drewcarleton/Project205/axolotl/GUI/Student.java");
   cerr<<v.size();

    cerr<<"hi";

    return a.exec();
}
