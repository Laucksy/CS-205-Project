#include <iostream>
#include "code.h"

using namespace std;

int main(int argc, char *argv[])
{
    //cout << "Compiles!" << endl;
    Code test;
    test.parse("Users/swein/Desktop/Wheel.java");
    for(unsigned long i = 0; i < test.get_full_code().size(); i++)
    {
        test.tokenize(test.fullCode.at(i));
    }
    return 0;
}
