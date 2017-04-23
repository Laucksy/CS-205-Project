/*ImportedRubric is used to create a Rubric via csv.
 * ImportedRubric parses a file organized in the specified
 * fashion by commas and then uses them to make a Rubric
 * with the specified Category objects.
 * */

#include "importedrubric.h"

using namespace std;

ImportedRubric::ImportedRubric()
{

}

//parse the csv into Rubric and Category objects
Rubric* ImportedRubric::parse_rubric(string fileName)
{
    DBTool* db = new DBTool();
    string line;
    //getline(str,line);
    ifstream file;
    file.open(fileName, ifstream::in);

    getline(file,line, ',');
    string name = line;
    getline(file,line, ',');
    bool deduct = (line == "true");
    Rubric* newRubric = new Rubric(db,deduct,name);
    while(getline(file,line, ','))
    {
        string catName = line;
        getline(file,line, ',');
        double pointNum = atof(line.c_str());
        getline(file,line, ',');
        bool m = false;
        Category* tempCat = new Category(db,newRubric,pointNum,m);
        newRubric->add_category(tempCat,catName);
    }
    file.close();
    return newRubric;
}
