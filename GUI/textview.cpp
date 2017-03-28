#include "textview.h"
#include "ui_textview.h"
#include <iostream>



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
    vector<string> lines;


    // ui->textBrowser->setSizePolicy();
    QString code1="hi";
    QString code2="there";
    switch(index){
    case 0 :
        ui->textBrowser->setTextColor("red");
        ui->textBrowser->setText(code1);

        break;
    case 1 :
    {

        Code x;

        //vector<string> v;
        vector<string> v = x.parse("/Users/drewcarleton/Project205/axolotl/GUI/Student.java");
        cerr<<v.size();
        ui->textBrowser->setText("");
        for(int i=0; i<v.size(); i++){
            vector<string> t = x.tokenize(v[i]);
            for(int a=0; a<t.size();a++){

                QString qstr = QString::fromStdString(t[a]);
                int type = x.categorize(t[a]);
                switch(type)
                {
                case 1:
                {
                    ui->textBrowser->setTextColor("red");
                }
                    break;
                case 2:
                {
                    ui->textBrowser->setTextColor("cyan");
                }
                    break;
                case 3:
                {
                    ui->textBrowser->setTextColor("aqua");
                }
                    break;
                case 4:
                {
                    ui->textBrowser->setTextColor("green");
                }
                    break;
                case 5:
                {
                    ui->textBrowser->setTextColor("yellow");
                }
                    break;
                case 6:
                {
                    ui->textBrowser->setTextColor("orange");
                }
                    break;
                case 7:
                {
                    ui->textBrowser->setTextColor("blue");
                }
                    break;
                case 8:
                {
                    ui->textBrowser->setTextColor("pink");
                }
                    break;
                case 0:
                {
                    ui->textBrowser->setTextColor("black");
                }
                    break;

                default:{


                    ui->textBrowser->setTextColor("black");
                }
                    break;
                }


                // ui->textBrowser->moveCursor(QTextCursor::End);
                // ui->textBrowser::moveCursor(  ui->textBrowser::End);
                ui->textBrowser->insertPlainText(qstr+" ");
                //  ui->textBrowser->append(qstr);
            }
            ui->textBrowser->append("");
        }
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
    }

}
