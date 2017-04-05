#include "exporthtml.h"

ExportHTML::ExportHTML() {

}

ExportHTML::~ExportHTML() {

}

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
    rawHTML += "</head><body><div class='tab'></div>";

    if(a != nullptr) {
        ofstream file;
        string fileName = "assignment_" + a->stu->lastName + "_" + a->stu->firstName + "_" + to_string(a->assignNum);
        file.open(fileName.c_str());

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
                rawHTML += "<p>";
                for(unsigned j = 0; j < tokens.size(); j++) {
                    rawHTML += "<span>";
                    rawHTML += (j < delims.size()) ? delims.at(j) : " ";
                    rawHTML += "</span>";
                    int type = firstFile->categorize(tokens.at(j));

                    if(j == 0 && type == 11)
                        lineComment=true;
                    else if(j == 0 && type != 11)
                        lineComment=false;
                    if(type == 9)
                        comment=true;
                    else if(type == 10)
                        comment=false;

                    switch(type) {
                    case 1:
                        rawHTML += "<span style='color:Deepskyblue;'>" + tokens.at(j) + "</span>";
                        break;
                    case 2:
                        rawHTML += "<span style='color:Mediumvioletred;'>" + tokens.at(j) + "</span>";
                        break;
                    case 3:
                        rawHTML += "<span style='color:Mediumvioletred;'>" + tokens.at(j) + "</span>";
                        break;
                    case 4:
                        rawHTML += "<span style='color:red;'>" + tokens.at(j) + "</span>";
                        break;
                    case 5:
                        rawHTML += "<span style='color:red;'>" + tokens.at(j) + "</span>";
                        break;
                    case 6:
                        rawHTML += "<span style='color:Dodgerblue;'>" + tokens.at(j) + "</span>";
                        break;
                    case 7:
                        rawHTML += "<span style='color:Mediumvioletred;'>" + tokens.at(j) + "</span>";
                        break;
                    case 8:
                        rawHTML += "<span style='color:Mediumvioletred;'>" + tokens.at(j) + "</span>";
                        break;
                    case 9:
                        rawHTML += "<span style='color:green;'>" + tokens.at(j) + "</span>";
                        break;
                    case 10:
                        rawHTML += "<span style='color:green;'>" + tokens.at(j) + "</span>";
                        break;
                    case 11:
                        rawHTML += "<span style='color:green;'>" + tokens.at(j) + "</span>";
                        break;
                    case 12:
                        tabCounter++;
                        bracket=true;
                        break;
                    case 13:
                        tabCounter--;
                        break;
                    case 0:
                        rawHTML += "<span style='color:black;'>" + tokens.at(j) + "</span>";
                        break;
                    default:
                        rawHTML += "<span cstyle='color:black;'>" + tokens.at(j) + "</span>";
                        break;
                    }
                    if(comment || lineComment) {
                        //ui->textBrowser->setTextColor("green");
                    }
                    if(j == 0) {
                        if(bracket) {
                            for(int tabs = 0; tabs < tabCounter-1; tabs++) {
                                rawHTML += "<span>    </span>";
                            }
                            bracket=false;
                        }
                        else {
                            for(int tabs = 0; tabs < tabCounter; tabs++) {
                                rawHTML += "<span>    </span>";
                            }
                        }
                    }
                }
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
