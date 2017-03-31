#include "textview.h"
#include "ui_textview.h"
#include <iostream>
using namespace std;


textView::textView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::textView)
{
    ui->setupUi(this);
}

textView::~textView()
{
    delete ui;
}

void textView::updateCode(int index)
{
    int tabCounter=0;
    vector<string> lines;
    bool comment=false;
    bool lineComment=false;
    bool bracket=false;

    // ui->textBrowser->setSizePolicy();
    QString code1="hi";
    QString code2="there";
    switch(index){
    case 0 :
        ui->textBrowser->setTextColor("red");
        ui->textBrowser->setText(code1);
        break;
    case 1 :
        DBTool* tool = new DBTool("TestDB");
        Code* x = new Code(tool,"/Users/drewcarleton/Project205/axolotl/GUI/BinaryTree.java",0);

        cout << "Got here 1" << endl;

        //vector<string> v;
        vector<string> v = x->parse();
        cerr<<v.size();
        ui->textBrowser->setText("");
        for(int i=0; i<v.size(); i++){
            vector<string> t = x->tokenize(v[i]);
            vector<string> delims = x->delimiters(v.at(i));
            for(int a=0; a<t.size();a++){
                string rawHTML = (a < delims.size()) ? delims.at(a) : " ";
                QString qstr1 = QString::fromStdString(rawHTML);
                ui->textBrowser->setTextColor("black");
                ui->textBrowser->insertPlainText(qstr1);

                QString qstr = QString::fromStdString(t[a]);
                int type = x->categorize(t[a]);
              //  int dtype = x->categorize()
               // int delimType= x->categorize(delims[a]);
                if(a==0&&type==11)
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
                        ui->textBrowser->setTextColor("Mediumvioletred");
                        break;
                    case 3:
                        ui->textBrowser->setTextColor("Mediumvioletred");
                        break;
                    case 4:
                        ui->textBrowser->setTextColor("red");
                        break;
                    case 5:
                        ui->textBrowser->setTextColor("red");
                        break;
                    case 6:
                        ui->textBrowser->setTextColor("Dodgerblue");
                        break;
                    case 7:
                        ui->textBrowser->setTextColor("Mediumvioletred");
                        break;
                    case 8:
                        ui->textBrowser->setTextColor("Mediumvioletred");
                        break;
                    case 9:
                        ui->textBrowser->setTextColor("green");
                        break;
                    case 10:
                        ui->textBrowser->setTextColor("green");
                        break;
                    case 11:
                        ui->textBrowser->setTextColor("green");
                        break;
                    case 12:
                        tabCounter++;
                        bracket=true;
                        break;
                    case 13:
                        tabCounter--;
                        break;
                    case 0:
                        ui->textBrowser->setTextColor("black");
                        break;
                    default:
                        ui->textBrowser->setTextColor("black");
                        break;
                    }

                    if(comment||lineComment)
                    {
                        ui->textBrowser->setTextColor("green");

                    }

                    if(a==0){
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

                       // }
                    }

//                else{
//                    switch(delimType)
//                    {
//                    case 9:
//                        ui->textBrowser->setTextColor("green");
//                        break;
//                    case 0:
//                        ui->textBrowser->setTextColor("black");
//                        break;
//                    default:
//                        ui->textBrowser->setTextColor("black");
//                        break;
//                    }
//                }

                    // ui->textBrowser->moveCursor(QTextCursor::End);
                    // ui->textBrowser::moveCursor(  ui->textBrowser::End);
                    ui->textBrowser->insertPlainText(qstr);
                    //  ui->textBrowser->append(qstr);
                   // cout << "Testing" << endl;
                }
                ui->textBrowser->append("");
            }
        }
    }

    void textView::on_comboBox_activated(const QString &arg1)
    {
        if(arg1=="Drew")
        {
            student="Drew";
        }

    }

    void textView::on_comboBox_2_activated(const QString &arg1)
    {
        if(student=="Drew"&&arg1=="Student")
        {

            this->updateCode(1);

          //  ui->textBrowser->cursor().pos()

            //int para= ui->textBrowser->paragraphAt(QCursor::pos());     // te is the textEdit object
           //  QString line=ui->textBrowser->text(para);
            // cerr<<line;
        }

    }


