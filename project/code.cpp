#include "code.h"
using namespace std;

Code::Code()
{

}

Code::~Code() {

}

std::string* Code::parse(string fileName)
{
    string line;
    char commentTest[2];
   // string* test = linesOfCode;

    ifstream file(fileName);
    if(file.is_open())
    {
        while(getline(file,line))
        {
            fullCode->append(line);
            line.copy(commentTest,2,0);
            if(commentTest[0] == '/' && commentTest[1] == '/')
            {
                comments->append(line);
            }
            else
                linesOfCode->append(line);
        }
        file.close();
    }
    else cout << "Unable to open file" << endl;

    return fullCode;
}
