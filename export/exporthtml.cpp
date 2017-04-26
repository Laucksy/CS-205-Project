#include "exporthtml.h"
/*ExportHTML class, which is used to export the feedback files.
 * ExportHTML has a method to export the HTML for a given assignment.
*/

//constructor
ExportHTML::ExportHTML() {

}

//destructor
ExportHTML::~ExportHTML() {

}

//constructs an HTML file for a specified assignment
string ExportHTML::export_assignment(Assignment* a) {
    string rawHTML = "";
    rawHTML += "<html><head><style>p {margin: 2px;} span {font-size:75%;}</style>";
    rawHTML += "<style>div.tab {overflow: hidden;border: 1px solid #ccc;background-color: #f1f1f1;}"
               "div.tab button {background-color: inherit;float: left;border: none;outline: none;"
               "cursor: pointer;padding: 14px 16px;transition: 0.3s;}"
               "div.tab button:hover {background-color: #ddd;}"
               "div.tab button.active {background-color: #ccc;}"
               ".tabcontent {display: none;padding: 6px 12px;border: 1px solid #ccc;"
               "border-top: none;}</style>";
    rawHTML += "</head><body style='background-color:#333333'>";

    if(a != nullptr) {
        rawHTML += "<p style='color:Yellow;'>Assignment Grading Breakdown: </p>";
        for(unsigned i = 0; i < a->gradeCategory.size(); i++) {
            rawHTML += "<span style='color:Yellow;'>" + a->gradeCategory.at(i) + " - " + to_string(a->gradeComponent.at(i)) + "</span>";
        }
        rawHTML += "<p style='color:Yellow;'>Total Grade: " + to_string(a->grade) + "</p>";
        ofstream file;
        string fileName = "assignment_" + a->stu->name + "_" + to_string(a->assignNum) + ".html";
        file.open(fileName.c_str());
        rawHTML += "<div class='tab'></div>";

        for(unsigned f = 0; f < a->files.size(); f++) {
            Code* firstFile = a->files.at(f);

            string fileName = firstFile->fileName.substr(firstFile->fileName.find_last_of("/")+1);
            rawHTML += "<script>var newButton = document.createElement('button');"
                       "newButton.className = 'tablinks';";
            if(f == 0)
                rawHTML += "newButton.id = 'defaultTab';";
            rawHTML += "newButton.addEventListener('click', function(event) {openTab(event, \"" + fileName + "\");});"
                                                                                                             "newButton.innerHTML = '" + fileName + "';"
                                                                                                                                                    "document.getElementsByClassName('tab')[0].appendChild(newButton);</script>";
            rawHTML += "<div id='" + fileName + "' class='tabcontent'>";

            int tabCounter=0;
            bool comment=false;
            bool lineComment=false;
            bool bracket=false;

            vector<string> v = firstFile->parse();
            for(unsigned i = 0; i < v.size(); i++){
                vector<string> tokens = firstFile->tokenize(v.at(i));
                vector<string> delims = firstFile->delimiters(v.at(i));
                //if(true || i == 6)
                    //cout << v.at(i) << endl;
                for(unsigned j = 0; j < delims.size(); j++) {
                    //cout << "DELIMS" << delims.at(j) << endl;
                }
                //if(i == 6)
                    //cout << endl << endl << endl;
                //cout << endl;
                string cumulativeLine = "";
                //if(i > 0 && v.at(i-1) == "    public Student()")
                    //cout << "AAAA" << delims.size() << "AAAA" << endl;
                rawHTML += "<p>";
                //for(unsigned j = 0; j < delims.size() && j < tokens.size(); j++)
                //cout << tokens.at(j) + ".........." + delims.at(j) << endl;

                if(v.at(i)[0] == '`' && v.at(i)[1] == '`' && v.at(i)[v.at(i).length()-1] == '`') {
                    rawHTML += "<span style='color:yellow;'>FEEDBACK: ";
                    rawHTML += v.at(i).substr(2,v.at(i).length()-3);
                    rawHTML += "\n";
                    rawHTML += "</span>";
                    continue;
                }

                //cout << "HEHERERER" << endl;
                lineComment = false;
                int j = 0;
                while(tokens.size() > 0/* && delims.size() > 0*/) {
                    for(unsigned j = 0; j < tokens.size(); j++) {
                        //cout << "Token size: " << tokens.size() << endl;
                    }
                    int type = firstFile->categorize(tokens.at(j));

                    if(j == 0 && type == 11)
                        lineComment=true;
                    else if(j == 0 && type != 11)
                        lineComment=false;
                    if(type == 9)
                        comment=true;
                    else if(type == 10)
                        comment=false;

                    if(delims.size() > 0 && delims.at(0) == "/" && delims.at(1) == "*" && delims.at(2) == "*"
                            && v.at(i)[cumulativeLine.length()] == '/' && v.at(i)[cumulativeLine.length()+1] == '*'
                            && v.at(i)[cumulativeLine.length()+2] == '*') {
                        comment = true;
                        type = 9;
                    }
                    if(delims.size() > 0 && delims.at(0) == "*" && delims.at(1) == "/") {
                        //cout << "TESTING COMMENT" << endl;
                        //cout << v.at(i) << ",,,," << cumulativeLine << endl;
                        if(v.at(i)[cumulativeLine.length()] == '*' && v.at(i)[cumulativeLine.length()+1] == '/') {
                            comment = false;
                            //cout << "AAAAAAAAAcoment" << endl;
                            type = 10;
                        }
                    }

                    if(comment)
                        type = 9;

                    /*if(j == 0) {
                        if(bracket) {
                            for(int tabs = 0; tabs < tabCounter-1; tabs++) {
                                rawHTML += "<span>&emsp;</span>";
                            }
                            bracket=false;
                        }
                        else {
                            for(int tabs = 0; tabs < tabCounter; tabs++) {
                                rawHTML += "<span>&emsp;</span>";
                            }
                        }
                    }*/

                    switch(type) {
                    case 1:
                        rawHTML += "<span style='color:Deepskyblue;'>";
                        break;
                    case 2:
                        rawHTML += "<span style='color:Plum;'>";
                        break;
                    case 3:
                        rawHTML += "<span style='color:Plum;'>";
                        break;
                    case 4:
                        rawHTML += "<span style='color:Salmon;'>";
                        break;
                    case 5:
                        rawHTML += "<span style='color:Salmon;'>";
                        break;
                    case 6:
                        rawHTML += "<span style='color:Dodgerblue;'>";
                        break;
                    case 7:
                        rawHTML += "<span style='color:Plum;'>";
                        break;
                    case 8:
                        rawHTML += "<span style='color:Plum;'>";
                        break;
                    case 9:
                        rawHTML += "<span style='color:Lightgreen;'>";
                        break;
                    case 10:
                        rawHTML += "<span style='color:Lightgreen;'>";
                        break;
                    case 11:
                        rawHTML += "<span style='color:Lightgreen;'>";
                        break;
                    case 12:
                        tabCounter++;
                        bracket=true;
                        break;
                    case 13:
                        tabCounter--;
                        break;
                    case 0:
                        rawHTML += "<span style='color:Cornsilk;'>";
                        break;
                    default:
                        rawHTML += "<span cstyle='color:Cornsilk;'>";
                        break;
                    }

                    //cout << (cumulativeLine + tokens.at(0)) << "AAAA" << v.at(i).find(cumulativeLine + tokens.at(0)) << "AAAA" << v.at(i).length() << endl;
                    //cout << cumulativeLine << "BBBBBB" << v.at(i) << endl;

                    //if(delims.size() > 0)
                        //cout << delims.front();
                    //cout << "CCCCCC";
                    //if(tokens.size() > 0)
                        //cout << tokens.front();
                    //cout << endl;
                    //if(delims.size() > 0)
                        //cout << v.at(i).length() << "AAAA" << v.at(i).find(cumulativeLine + delims.at(0)) < v.at(i).length() << "BBBB:" << v.at(i).find(cumulativeLine + delims.at(0)) << endl;
                    bool delimFound = delims.size() > 0 ? v.at(i).find(cumulativeLine + delims.at(0)) == 0 : false;
                    bool tokenFound = tokens.size() > 0 ? v.at(i).find(cumulativeLine + tokens.at(0)) == 0 : false;
                    if(delims.size() > 0 && delimFound && !tokenFound) {
                        //cout << "delims" << endl;
                        if(!comment && !lineComment)
                            rawHTML += "<span style='color:Cornsilk;'>";
                        if(delims.at(0) != " ")
                            rawHTML += delims.at(0);
                        else
                            rawHTML += "&nbsp;";
                        if(!comment && !lineComment)
                            rawHTML += "</span>";
                        cumulativeLine += delims.at(0);
                        //cout << "ZZZZZZZZZZZ" << delims.at(0) << "ZZZZZZZZZZZZ" << endl;
                        delims.erase(delims.begin());
                    }
                    else if(tokens.size() > 0 && tokenFound) {
                        //cout << "token" << endl;
                        rawHTML += tokens.at(0);
                        cumulativeLine += tokens.at(0);
                        tokens.erase(tokens.begin());
                    } else if(tokens.size() > 0 && delims.size() == 0) {
                        //cout << "token" << endl;
                        rawHTML += tokens.at(0);
                        cumulativeLine += tokens.at(0);
                        tokens.erase(tokens.begin());
                    }
                    rawHTML += "</span>";
                    //cout << "End of loop" << endl;
                }
                //cout << "ITHERE" << endl;
                while(delims.size() > 0) {
                    if(delims.size() >= 3 && delims.at(0) == "/" && delims.at(1) == "*" && delims.at(2) == "*"
                            && v.at(i)[cumulativeLine.length()] == '/' && v.at(i)[cumulativeLine.length()+1] == '*'
                            && v.at(i)[cumulativeLine.length()+2] == '*') {
                        comment = true;
                    }

                    if(comment)
                        rawHTML += "<span style='color:Lightgreen;'>" + delims.front() + "</span>";
                    else
                        rawHTML += "<span style='color:Cornsilk;'>" + delims.front() + "</span>";
                    if(delims.size() >= 1 && delims.at(0) == "/") {
                        //cout << "TESTING COMMENT" << endl;
                        //cout << v.at(i) << ",,,," << cumulativeLine << ",,,,," << endl;
                        if(cumulativeLine.length() > 0 && v.at(i)[cumulativeLine.length()-1] == '*' && v.at(i)[cumulativeLine.length()] == '/') {
                            comment = false;
                            //cout << "AAAAAAAAAcoment" << endl;
                        }
                    }
                    cumulativeLine += delims.at(0);
                    delims.erase(delims.begin());
                }
                //cout << "AFTERDELIM" << endl;
                rawHTML += "</p>";
            }
            rawHTML += "</div>";
            if(f == 0) {

            }
        }

        rawHTML += "<script>function openTab(evt, tab) {"
                   "var tabcontent = document.getElementsByClassName('tabcontent');"
                   "for (var i = 0; i < tabcontent.length; i++) {"
                   "tabcontent[i].style.display = 'none'; }"
                   "var tablinks = document.getElementsByClassName('tablinks');"
                   "for (var i = 0; i < tablinks.length; i++) {"
                   "tablinks[i].className = tablinks[i].className.replace(' active', ''); }"
                   "document.getElementById(tab).style.display = 'block';"
                   "evt.currentTarget.className += ' active';}"
                   "document.getElementById('defaultTab').click();</script>";
        rawHTML += "</body></html>";
        file << rawHTML;
        file.close();
    } else {
        rawHTML += "</body></html>";
    }
    return rawHTML;
}

//exports csv for professor of assignments
//csv contains all information about assignments
void ExportHTML::export_csv_assignment(Assignments* a) {
    ofstream file;
    string fileName = "assignment_" + a->name + ".csv";
    file.open(fileName.c_str());
    file << a->name << "\n";
    file << "Student Name,Grade" << "\n";
    for(unsigned i = 0; i < a->list.size(); i++) {
        Assignment* temp = a->list.at(i);
        file << temp->stu->name << "," << temp->grade << "\n";
        file.flush();
    }
    file.close();
}

/*Changing csv to loop through students in section, print name, loop
 * through assignments in section, if submitted print grade, else 0, print get_score()*/
void ExportHTML::export_csv_section(Students* s) {
    ofstream file;
    string fileName = "section_" + s->name + ".csv";
    file.open(fileName.c_str());
    file << s->name << "\n";
    file << "Student Name,List of Grades" << "\n";
    for(unsigned i = 0; i < s->list.size(); i++) {
        Student* stu = s->list.at(i);
        file << stu->name << ",";
        for(unsigned j = 0; j < s->assignList.size(); j++) {
            Assignments* assign = s->assignList.at(j);
            if(assign->did_submit(stu)) {
                file << assign->get_assignment(stu)->get_grade() << ",";
            } else {
                file << "0" << ",";
            }
        }
        file << "\n";
        file.flush();
    }
    file.close();
}
