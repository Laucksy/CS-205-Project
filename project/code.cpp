#include "code.h"
using namespace std;

Code::Code()
{

}

Code::~Code() {

}

vector<string> Code::parse(string fileName)
{
    string line;
    char commentTest[2];

    //going through each line of the selected file
    ifstream file(fileName);
    if(file.is_open())
    {
        while(getline(file,line))
        {
            fullCode.push_back(line);
            line.copy(commentTest,2,0);
            //if first two lines of code are //, then it is a comment
            if(commentTest[0] == '/' && commentTest[1] == '/')
            {
                comments.push_back(line);
            }
            //otherwise, it is a line of code
            else
                linesOfCode.push_back(line);
        }
        file.close();
    }
    else cout << "Unable to open file" << endl;

    return fullCode;
}


void Code::insert(string text, int position)
{
    //iterating through code to insert text at a given position inside the vector
     vector<string>::iterator it = fullCode.begin();

     fullCode.insert (it+position,text);
     /*also if we only want to insert blank text as to make room for an overlay comment
      * rather than text, we could take in only position and add in a blank line.
      */
}


//THIS METHOD IS INCOMPLETE.
int Code::categorize(string word)
{
    /*here, maybe should traverse through each word in each string of the vector,
     * but then shouldn't take in string. and that seems messier so better not?
     * probably the traversal should happen in the gui so its not collection of ints
     * and each int can be used at the time it's generated. also, the words that
     * are comments don't have to be parsed because they should fall into one specific color.
     * only contents of vector linesOfCode should be categorized.
     * NOTE: needs to be parsed by spaces, periods, parentheses. not only spaces!
     */
    /*categorize returns an int corresponding with the category the word falls in,
     * which can be used in coloring each word via cascade of if statements.
     */
    if(word=="float" || word=="string" || word=="int" || word=="char" || word=="long" || word=="short" || word=="double" || word=="boolean" || word=="byte") //etc.
    {
        return 1;
    }
    else if(word=="static" || word=="final" || word=="void") //etc.
    {
        return 2;
    }
    else if(word=="for" || word=="if" || word=="while") //etc.
    {
        return 3;
    }
    else if(word=="new")
    {
        return 4;
    }
    //everything else is just normal code, should be black (or some standard color).
    return 0;
}
