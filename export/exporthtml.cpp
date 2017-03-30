#include "exporthtml.h"

ExportHTML::ExportHTML() {

}

ExportHTML::~ExportHTML() {

}

string ExportHTML::export_assignment(Assignment* a) {
    string rawHTML = "";
    rawHTML += "<html><head><style>p {margin: 2px;} span {font-size:75%;}</style></head><body>";

    if(a != nullptr) {
        ofstream file;
        string fileName = "assignment_" + a->stu->lastName + "_" + a->stu->firstName + "_" + to_string(a->assignNum);
        file.open(fileName.c_str());

        Code* firstFile = a->files.at(0);
        vector<string> v = firstFile->parse();
        for(int i = 0; i < v.size(); i++){
            vector<string> tokens = firstFile->tokenize(v.at(i));
            vector<string> delims = firstFile->delimiters(v.at(i));
            rawHTML += "<p>";
            for(unsigned j = 0; j < tokens.size(); j++) {
                rawHTML += "<span>";
                rawHTML += (j < delims.size()) ? delims.at(j) : " ";
                rawHTML += "</span>";
                int type = firstFile->categorize(tokens.at(j));
                switch(type)
                {
                case 1:
                    rawHTML += "<span style='color:red;'>" + tokens.at(j) + "</span>";
                    break;
                case 2:
                    rawHTML += "<span style='color:cyan;'>" + tokens.at(j) + "</span>";
                    break;
                case 3:
                    rawHTML += "<span style='color:aqua;'>" + tokens.at(j) + "</span>";
                    break;
                case 4:
                    rawHTML += "<span style='color:green;'>" + tokens.at(j) + "</span>";
                    break;
                case 5:
                    rawHTML += "<span style='color:yellow;'>" + tokens.at(j) + "</span>";
                    break;
                case 6:
                    rawHTML += "<span style='color:orange;'>" + tokens.at(j) + "</span>";
                    break;
                case 7:
                    rawHTML += "<span style='color:blue;'>" + tokens.at(j) + "</span>";
                    break;
                case 8:
                    rawHTML += "<span style='color:pink;'>" + tokens.at(j) + "</span>";
                    break;
                case 0:
                    rawHTML += "<span style='color:black;'>" + tokens.at(j) + "</span>";
                    break;
                default:
                    rawHTML += "<span cstyle='color:black;'>" + tokens.at(j) + "</span>";
                    break;
                }
                //rawHTML += " ";
                //rawHTML += (j < delims.size()) ? delims.at(j) : " ";
            }
            rawHTML += "</p>";
        }
        rawHTML += "</body></html>";
        file << rawHTML;
        file.close();
    } else {
        rawHTML += "</body></html>";
    }
    return rawHTML;
}
