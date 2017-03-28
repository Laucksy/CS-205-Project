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
    ifstream file;
    file.open(fileName, ifstream::in);
    //cout << fileName << endl;

    while(file.good())
    {
        cout << "here" << endl;
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
    //prints out all items of fullCode
    //only there to show to demonstrate functionality
//    for (auto i = fullCode.begin(); i != fullCode.end(); ++i)
//        cout << *i << ' ' << endl;
//    return fullCode;
}

/*tokenize is a delimiter method, which parses a single string
 * ( a line of code from vector of strings)
 * this splits up the line into tokens to be passed through categorize method
 */
vector<string> Code::tokenize(string line)
{
    vector<string> tokens;
    vector<char> delimiterChars = { ' ', ',', '.', ':', '\t', '(', ')', '/', ';', '[', ']', '{', '}', '*', '@' };

    stringstream ss(line);

    string i;

    while (ss >> i)
    {
        tokens.push_back(i);

        for(unsigned long x = 0; x < delimiterChars.size(); x++)
        {
            if (ss.peek() == delimiterChars.at(x))
               ss.ignore();
        }
    }

    for (unsigned long j =0; j< tokens.size(); j++)
        cout << tokens.at(j)<< endl;

    return tokens;
}


void Code::insert(int position)
{
    //iterating through code to insert text at a given position inside the vector
    vector<string>::iterator it = fullCode.begin();

    fullCode.insert (it+position," ");
    /*also if we only want to insert blank text as to make room for an overlay comment
      * rather than text, we could take in only position and add in a blank line.
      */
}

//remove blank space (slot for feedback) from given position
void Code::delete_space_for_feedback(int position)
{
        vector<string>::iterator itDelete = fullCode.begin();
        advance(itDelete, position);
        fullCode.erase(itDelete);
}

void Code::add_feedback(Feedback newComment)
{
        profFeedback.push_back(newComment);
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
    if(word=="float" || word=="string" || word=="int" || word=="char" || word=="long" || word=="short" || word=="double" || word=="boolean" || word=="byte" || word=="void")
    {
        return 1;
    }
    else if(word=="static" || word=="final")
    {
        return 2;
    }
    else if(word=="for" || word=="if" || word=="while" || word=="else" || word=="continue" || word=="break" || word == "return")
    {
        return 3;
    }
    else if(word=="import")
    {
        return 4;
    }
    else if(word=="class")
    {
        return 5;
    }
    else if(word=="this")
    {
        return 6;
    }
    else if(word=="public" || word=="protected" || word=="private")
    {
        return 7;
    }
    else if(word=="new")
    {
        return 8;
    }
    //everything else is just normal code, should be black (or some standard color).
    return 0;
}

vector<string> Code::get_full_code()
{
    return fullCode;
}
