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

Code* textView::updateCode(Code* myCode)
{
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
    ui->textBrowser->setText("");
    for(int i=0; i<v.size(); i++){//lines
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

            ui->textBrowser->insertPlainText(temp);
        }

        if(v.at(i)[0] == '`' && v.at(i)[1] == '`' && v.at(i)[v.at(i).length()-1] == '`') {
            ui->textBrowser->setTextColor("Yellow");
            QString qstr = QString::fromStdString("FEEDBACK: ");
            ui->textBrowser->insertPlainText(qstr);
            qstr = QString::fromStdString(v.at(i).substr(2,v.at(i).length()-3));
            ui->textBrowser->insertPlainText(qstr);
            qstr = QString::fromStdString("\n");
            ui->textBrowser->insertPlainText(qstr);
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
            }*/
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
                        ui->textBrowser->insertPlainText("    ");

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
        if (active->gradeQuality[i] == "NULL" || active->gradeQuality[i] == "NULL2") {
            rubric += active->gradeCategory[i] + ": " + to_string(active->gradeComponent[i]) + "/" + to_string(active->rubric->cat[i]->pts) + "\n";
        } else {
            rubric += active->gradeCategory[i] + ": " + to_string(active->gradeComponent[i]) + "/" + to_string(active->rubric->cat[i]->pts) + "; " + active->gradeQuality[i] + "\n";
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
        updateCode(integ->activeFile);
        update_rubric();
    }
}



void textView::mousePressEvent(QMouseEvent *e)
    {



        cerr<<"click";


    }



void textView::on_textBrowser_anchorClicked(const QUrl &arg1)
{
         cerr<<"click";
}



void textView::on_textBrowser_cursorPositionChanged()
{
  //  ui->textBrowser->cursor()
    if(!writing){
       int temp=ui->textBrowser->textCursor().blockNumber();
        this->clickComment(temp,myCode);
    }



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
     this->updateCode(myCode);
}

void textView::on_comboBox_4_activated(const QString &arg1)
{
    ui->lineEdit->clear();
    ui->lineEdit->insert(arg1);
    ui->lineEdit->textEdited(arg1);
}
