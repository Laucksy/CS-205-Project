#include "exporthtml.h"

ExportHTML::ExportHTML() {

}

ExportHTML::~ExportHTML() {

}

string ExportHTML::export_assignment(Assignment* a) {
    std::cout << "Test";
    string rawHTML = "";
    rawHTML += "<html><head></head><body>";

    if(a != nullptr) {
        ofstream file;
        string fileName = "assignment_" + a->stu->lastName + "_" + a->stu->firstName + "_" + to_string(a->assignNum);
        file.open(fileName.c_str());

        cout << "ABABAB" << a->files.size();
        Code* firstFile = a->files.at(0);
        vector<string> v = firstFile->parse();
        //cerr<<v.size();
        for(int i = 0; i < v.size(); i++){
            vector<string> tokens = firstFile->tokenize(v.at(i));
            rawHTML += "<p>";
            for(unsigned j = 0; j < tokens.size(); j++) {
                if(firstFile->categorize(tokens.at(j)) == 0)
                    rawHTML += "<span color='black'>" + tokens.at(j) + "</span>";
                else
                    rawHTML += "<span color='red'>" + tokens.at(j) + "</span>";
            }
            rawHTML += "</p>";
            //rawHTML += "<p>" + line + "</p>";
            /*switch(type)
                {
                case 1:
                    ui->textBrowser->setTextColor("red");
                    break;
                case 2:
                    ui->textBrowser->setTextColor("cyan");
                    break;
                case 3:
                    ui->textBrowser->setTextColor("aqua");
                    break;
                case 4:
                    ui->textBrowser->setTextColor("green");
                    break;
                case 5:
                    ui->textBrowser->setTextColor("yellow");
                    break;
                case 6:
                    ui->textBrowser->setTextColor("orange");
                    break;
                case 7:
                    ui->textBrowser->setTextColor("blue");
                    break;
                case 8:
                    ui->textBrowser->setTextColor("pink");
                    break;
                case 0:
                    ui->textBrowser->setTextColor("black");
                    break;
                default:
                    ui->textBrowser->setTextColor("black");
                    break;
                }*/
        }
        cout << "AAAAAA" << firstFile->fullCode.size() << endl;
        /*for(unsigned i = 0; i < firstFile->fullCode.size(); i++) {
            string line = firstFile->fullCode.at(i);
            vector<string> tokens = firstFile->tokenize(line);
            rawHTML += "<p>";
            for(unsigned j = 0; j < tokens.size(); j++) {
                if(firstFile->categorize(tokens.at(j)) == 0)
                    rawHTML += "<span color='black'>" + tokens.at(j) + "</span>";
                else
                    rawHTML += "<span color='red'>" + tokens.at(j) + "</span>";
            }
            rawHTML += "</p>";
            //rawHTML += "<p>" + line + "</p>";
        }*/
        rawHTML += "</body></html>";
        file << rawHTML;
        file.close();
    } else {
        rawHTML += "</body></html>";
    }
    return rawHTML;
}
