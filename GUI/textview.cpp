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

    QString code1="hi";
    QString code2="there";
    switch(index){
    case 0 :
         ui->textBrowser->setTextColor("red");
        ui->textBrowser->setText(code1);

        break;
    case 1 :
    {

        Code *c1= new Code();

        lines=c1->parse("Student.java");


    }
       //  ui->textBrowser->setTextColor("cyan");
       // ui->textBrowser->setText(code2);
        break;

    }


}



void textView::on_tabWidget_tabBarClicked(int index)
{

        this->updateCode(index);


}
