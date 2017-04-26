#include "textview.h"
#include "ui_textview.h"
#include <iostream>
#include "dataview.h"
#include <QMouseEvent>
using namespace std;


textView::textView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::textView)
{

    ui->setupUi(this);
    ui->textBrowser->setMouseTracking(true);

}


textView::~textView()
{
    delete ui;
}

void textView::set_integ(Integration *i)
{
    integ = i;

    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();

    ui->assignmentLabel->setText(QString::fromStdString("Assignment: " + integ->activeAssignemnt->name));

    for (Code* k : integ->activeSubmission->files) {
        string obfuscatedFileName = k->fileName.substr(k->fileName.find_last_of("/")+1);
        ui->comboBox_2->addItem(QString::fromStdString(obfuscatedFileName));
    }

    ui->comboBox_3->addItem("None");

    for (string k : integ->activeSubmission->gradeCategory) {
        ui->comboBox->addItem(QString::fromStdString(k));
        ui->comboBox_3->addItem(QString::fromStdString(k));
    }

    tag = "None";

    if (integ->activeSubmission->gradeCategory.size() > 0) {
        categoryIndex = 0;
        //tag = integ->activeSubmission->gradeCategory[0];
    } else {
        categoryIndex = -1;
    }

    if (integ->activeSubmission->files.size() > 0) {
        updateCode(integ->activeSubmission->files[0]);
        integ->activeFile = integ->activeSubmission->files[0];
        myCode = integ->activeFile;
    }

    update_rubric();
}

void textView::makeComment(Code* myCode){
    myCode->insert(commentLoc,newFeedback + ":: " + tag);
    integ->add_new_feedback(newFeedback, tag, commentLoc);
    //ui->textBrowser->clear();
    this->updateCode(myCode);
    this->update_rubric();
}

void textView::clickComment(int pos, Code* myCode){
    myCode->insert(pos,newFeedback + ":: " + tag);
    integ->add_new_feedback(newFeedback, tag, pos);
    //ui->textBrowser->clear();
    this->updateCode(myCode);
    this->update_rubric();
}

/*Code* textView::updateCode(Code* myCode)
{
    if (myCode != nullptr) {
        writing=true;

        ui->textBrowser->clear();
        int tabCounter=0;
        vector<string> lines;
        bool comment=false;
        bool lineComment=false;
        bool bracket=false;

        QString code1="hi";
        QString code2="there";
        DBTool* tool = new DBTool("TestDB");
        Code* x=myCode;

        cout << "Got here 1" << endl;

        vector<string> v = x->parse();
        cerr<<v.size();
        ui->textBrowser->setHTML("<html><head><style>a {text-decoration: none; color: black;}</style></head><body>");
        for(int i=0; i<v.size(); i++){//lines
            ext += "<a href='" + temp->name + "'>" + temp->name + "</a></span><br/>";
            ui->textBrowser->insertHtml("<a href='" + i + "'>");
            vector<string> tokens = x->tokenize(v[i]);
            vector<string> delims = x->delimiters(v.at(i));
            if(1){
                std::string s = std::to_string(i);
                if(i<10){
                    s=s+"  | ";
                }
                else if(i<100){
                    s=s+" | ";
                }
                else if(i<1000){
                    s=s+"| ";
                }
                ui->textBrowser->setTextColor("Orange");
                QString temp= QString::fromStdString(s);

                ui->textBrowser->insertHtml(temp);
            }

            if(v.at(i)[0] == '`' && v.at(i)[1] == '`' && v.at(i)[v.at(i).length()-1] == '`') {
                ui->textBrowser->setTextColor("Yellow");
                QString qstr = QString::fromStdString("FEEDBACK: ");
                ui->textBrowser->insertHtml(qstr);
                qstr = QString::fromStdString(v.at(i).substr(2,v.at(i).length()-3));
                ui->textBrowser->insertHtml(qstr);
                qstr = QString::fromStdString("\n");
                ui->textBrowser->insertHtml(qstr);
                continue;
            }

            string cumulativeLine = "";
            lineComment = false;
            int j = 0;
            while(tokens.size() > 0) {
                //string rawHTML = (a < delims.size()) ? delims.at(a) : " ";
                //QString qstr1 = QString::fromStdString(rawHTML);
                //ui->textBrowser->setTextColor("Cornsilk ");
                //ui->textBrowser->insertPlainText(qstr1);

                //QString qstr = QString::fromStdString(tokens.at(0));
                int type = x->categorize(tokens.at(0));

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
                    if(v.at(i)[cumulativeLine.length()] == '*' && v.at(i)[cumulativeLine.length()+1] == '/') {
                        comment = false;
                        type = 10;
                    }
                }

                if(comment)
                    type = 9;


                //  int dtype = x->categorize()
                // int delimType= x->categorize(delims[a]);
                /*if(a==0&&type==11)
            {
                lineComment=true;
            }
            else if(a==0&&type!=11)
            {
                lineComment=false;
            }

            if(type==9){
                comment=true;
            }
            if(type==10)
            {
                comment=false;
            }
                switch(type)
                {
                case 1:
                    ui->textBrowser->setTextColor("Deepskyblue");
                    break;
                case 2:
                    ui->textBrowser->setTextColor("Plum");
                    break;
                case 3:
                    ui->textBrowser->setTextColor("Plum");
                    break;
                case 4:
                    ui->textBrowser->setTextColor("Salmon");
                    break;
                case 5:
                    ui->textBrowser->setTextColor("Salmon");
                    break;
                case 6:
                    ui->textBrowser->setTextColor("Dodgerblue");
                    break;
                case 7:
                    ui->textBrowser->setTextColor("Plum");
                    break;
                case 8:
                    ui->textBrowser->setTextColor("Plum");
                    break;
                case 9:
                    ui->textBrowser->setTextColor("Lightgreen");
                    break;
                case 10:
                    ui->textBrowser->setTextColor("Lightgreen");
                    break;
                case 11:
                    ui->textBrowser->setTextColor("Lightgreen");
                    break;
                case 12:
                    tabCounter++;
                    bracket=true;
                    break;
                case 13:
                    tabCounter--;
                    break;
                case 0:
                    ui->textBrowser->setTextColor("Cornsilk ");
                    break;
                default:
                    ui->textBrowser->setTextColor("Cornsilk ");
                    break;
                }

                if(comment||lineComment)
                {
                    ui->textBrowser->setTextColor("Lightgreen");

                }


                if(j == 0){
                    //for(int tabs=0;tabs<tabCounter;tabCounter++){
                    if(bracket){
                        for(int tabs=0;tabs<tabCounter-1;tabs++)
                        {
                            ui->textBrowser->insertHtml("    ");

                        }
                        bracket=false;


                    }
                    else
                    {

                        for(int tabs=0;tabs<tabCounter;tabs++)
                        {
                            ui->textBrowser->insertPlainText("    ");

                        }
                    }
                }

                QString qstr;
                bool delimFound = delims.size() > 0 ? v.at(i).find(cumulativeLine + delims.at(0)) == 0 : false;
                bool tokenFound = tokens.size() > 0 ? v.at(i).find(cumulativeLine + tokens.at(0)) == 0 : false;
                if(delims.size() > 0 && delimFound && !tokenFound) {
                    if(!comment && !lineComment)
                        ui->textBrowser->setTextColor("Cornsilk ");
                    qstr = QString::fromStdString(delims.at(0));
                    cumulativeLine += delims.at(0);
                    delims.erase(delims.begin());
                }
                else if(tokens.size() > 0 && tokenFound) {
                    qstr = QString::fromStdString(tokens.at(0));
                    cumulativeLine += tokens.at(0);
                    tokens.erase(tokens.begin());
                } else if(tokens.size() > 0 && delims.size() == 0) {
                    qstr = QString::fromStdString(tokens.at(0));
                    cumulativeLine += tokens.at(0);
                    tokens.erase(tokens.begin());
                }

                ui->textBrowser->insertPlainText(qstr);
            }

            while(delims.size() > 0) {
                if(delims.size() >= 3 && delims.at(0) == "/" && delims.at(1) == "*" && delims.at(2) == "*"
                        && v.at(i)[cumulativeLine.length()] == '/' && v.at(i)[cumulativeLine.length()+1] == '*'
                        && v.at(i)[cumulativeLine.length()+2] == '*') {
                    comment = true;
                }

                QString qstr;
                if(comment) {
                    ui->textBrowser->setTextColor("Lightgreen");
                    qstr = QString::fromStdString(delims.front());
                } else {
                    ui->textBrowser->setTextColor("Cornsilk ");
                    qstr = QString::fromStdString(delims.front());
                }
                ui->textBrowser->insertPlainText(qstr);

                if(delims.size() >= 1 && delims.at(0) == "/") {
                    if(cumulativeLine.length() > 0 && v.at(i)[cumulativeLine.length()-1] == '*' && v.at(i)[cumulativeLine.length()] == '/') {
                        comment = false;
                    }
                }
                cumulativeLine += delims.at(0);
                delims.erase(delims.begin());
            }
            ui->textBrowser->append("");
        }
        writing=false;
        return x;
    } else {
        ui->textBrowser->clear();
        return myCode;
    }

}*/

Code* textView::updateCode(Code* myCode) {
    string rawHTML = "";
    rawHTML += "<html><head><style>a {text-decoration: none; color: black;}</style></head><body style='background-color:#333333'>";

    if(myCode != nullptr) {
        Code* firstFile = myCode;

        string fileName = firstFile->fileName.substr(firstFile->fileName.find_last_of("/")+1);

        int tabCounter=0;
        bool comment=false;
        bool lineComment=false;
        bool bracket=false;

        vector<string> v = firstFile->parse();
        for(unsigned i = 0; i < v.size(); i++){
            rawHTML += "<a href='" + to_string(i) + "'>";
            vector<string> tokens = firstFile->tokenize(v.at(i));
            vector<string> delims = firstFile->delimiters(v.at(i));
            string cumulativeLine = "";
            //rawHTML += "<p>";

            if(true) {
                std::string s = std::to_string(i);
                if(i<10){
                    s=s+"  | ";
                }
                else if(i<100){
                    s=s+" | ";
                }
                else if(i<1000){
                    s=s+"| ";
                }
                rawHTML += "<span style='color:orange;'>" + s + "</span>";
            }

            if(v.at(i)[0] == '`' && v.at(i)[1] == '`' && v.at(i)[v.at(i).length()-1] == '`') {
                rawHTML += "<span style='color:yellow;'>FEEDBACK: ";
                rawHTML += v.at(i).substr(2,v.at(i).length()-3);
                rawHTML += "\n";
                rawHTML += "</span></a><br/>";
                continue;
            }

            lineComment = false;
            int j = 0;
            while(tokens.size() > 0) {
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
                    if(cumulativeLine.length() > 0 && v.at(i)[cumulativeLine.length()-1] == '*' && v.at(i)[cumulativeLine.length()] == '/') {
                        comment = false;
                    }
                }
                cumulativeLine += delims.at(0);
                delims.erase(delims.begin());
            }
            rawHTML += "</a><br/>";
        }
        rawHTML += "</div>";
    }
    rawHTML += "</body></html>";
    ui->textBrowser->setHtml(QString::fromStdString(rawHTML));
    return myCode;
}

void textView::on_lineEdit_2_textChanged(const QString &arg1)
{
    commentLoc=arg1.toInt();
    cerr<<"comment location "<<commentLoc;
}

void textView::on_lineEdit_textEdited(const QString &arg1)
{
    newFeedback= arg1.toStdString();

    ui->comboBox_4->clear();

    vector<string> r = integ->get_similar_feedback(newFeedback);

    for (string k : r) {
        ui->comboBox_4->addItem(QString::fromStdString(k));
    }
}

void textView::on_pushButton_2_clicked()
{
    DataView *rv= new DataView();
    rv->set_integ(integ);

    rv->show();
    this->hide();
}



void textView::on_comboBox_2_activated(const QString &arg1)
{
    for (Code* k : integ->activeSubmission->files) {
        if (arg1 == QString::fromStdString(k->fileName)) {
            integ->activeFile = k;
            myCode = integ->activeFile;
        }
    }

    if (integ->activeFile != nullptr) {
        updateCode(integ->activeFile);

    }
}

void textView::update_rubric()
{
    Assignment* active = integ->activeSubmission;

    for (int i = 0; i < active->gradeCategory.size(); i++) {
        active->change_grade(active->gradeComponent[i], active->gradeCategory[i]);
    }

    vector<Feedback*> comments;
    for (Code* k : integ->activeSubmission->files) {
        for (Feedback* j : k->profFeedback) {
            comments.push_back(j);
        }
    }

    string rubric;
    for (int i = 0; i < integ->activeSubmission->gradeCategory.size(); i++) {
        string component = to_string(roundf(active->gradeComponent[i]*100)/100);
        string total = to_string(roundf(active->rubric->cat[i]->pts*100)/100);
        if (active->gradeQuality[i] == "NULL" || active->gradeQuality[i] == "NULL2") {
            rubric += active->gradeCategory[i] + ": " + component.substr(0,component.length()-5) + "/" + total.substr(0,total.length()-5) + "\n";
        } else {
            rubric += active->gradeCategory[i] + ": " + component.substr(0,component.length()-5) + "/" + total.substr(0,total.length()-5) + "; " + active->gradeQuality[i] + "\n";
        }

        for (Feedback* k : comments) {
            if (k->tag == active->gradeCategory[i]) {
                rubric += "       " + k->text + "\n";
            }
        }

        ui->textBrowser_2->setText(QString::fromStdString(rubric));
    }
}

void textView::on_comboBox_3_activated(const QString &arg1)
{
    tag = arg1.toStdString();
}

void textView::on_comboBox_activated(const QString &arg1)
{
    for (int i = 0; i <integ->activeSubmission->gradeCategory.size(); i++) {
        if (arg1.toStdString() == integ->activeSubmission->gradeCategory[i]) {
            categoryIndex = i;
        }
    }
}

void textView::on_lineEdit_3_textChanged(const QString &arg1)
{
    integ->activeSubmission->change_grade(arg1.toDouble(), integ->activeSubmission->gradeCategory[categoryIndex]);
    update_rubric();
}

void textView::on_pushButton_3_clicked()
{
    integ->finish_grading_submission();

    if (integ->activeSubmission == nullptr) {
        DataView *rv= new DataView();
        rv->set_integ(integ);

        rv->show();
        this->hide();
    } else {
        set_integ(integ);
        if (integ->activeSubmission->files.size() > 0) {
            updateCode(integ->activeFile);
        } else {
            updateCode(nullptr);
        }
        update_rubric();
    }
}



void textView::mousePressEvent(QMouseEvent *e)
{
    cout << "mouse press" << endl;
    if(e->button() == Qt::LeftButton)
    {
        int temp=ui->textBrowser->textCursor().blockNumber();
        this->clickComment(temp,myCode);
    }
    if(e->button() == Qt::RightButton)
    {
        //delete comment
        on_pushButton_4_clicked();
    }
    //cerr<<"click";
}



void textView::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    cout << "anchor" << endl;
    string url = arg1.url().toStdString();
    this->clickComment(atoi(url.c_str()), myCode);
}



void textView::on_textBrowser_cursorPositionChanged()
{
    //  ui->textBrowser->cursor()
    /*if(!writing){
        int temp=ui->textBrowser->textCursor().blockNumber();
        this->clickComment(temp,myCode);
    }*/

}

bool textView::eventFilter(QObject *watched, QEvent *event){
    if(event->type()==QMouseEvent::MouseButtonDblClick)
    {
        cerr<<"double";
    }
}


void textView::on_pushButton_4_clicked()
{
    myCode->delete_space_for_feedback(commentLoc);
    //iterate through the professorial feedback and delete one at comment location
    myCode->delete_feedback(commentLoc);
    this->updateCode(myCode);
}

void textView::on_comboBox_4_activated(const QString &arg1)
{
    ui->lineEdit->clear();
    ui->lineEdit->insert(arg1);
    ui->lineEdit->textEdited(arg1);
}
