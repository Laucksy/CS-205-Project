#include "mainwindow.h"
#include "../project/code.h"
#include "../Integration/integration.h"


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
    //Integration integ(".", "TestDB"); //= new Integration();
    QApplication a(argc, argv);
    MainWindow w;
    //w.set_integ(&integ);

    w.show();




  //  Code x;

    //DBTool* tool = new DBTool("TestDB");
    //Code* x = new Code(tool,"/Users/drewcarleton/Project205/axolotl/GUI/Student.java",0);

    //vector<string> v;
   //vector<string> v = x.parse("/Users/drewcarleton/Project205/axolotl/GUI/Student.java");
   //cerr<<v.size();

    //cerr<<"hi";

    return a.exec();
}
