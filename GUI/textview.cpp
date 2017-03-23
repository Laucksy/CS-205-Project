#include "textview.h"
#include "ui_textview.h"

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
    QString code1="hi";
    QString code2="there";
    switch(index){
    case 0 :
         ui->textBrowser->setTextColor("red");
        ui->textBrowser->setText(code1);

        break;
    case 1 :
         ui->textBrowser->setTextColor("cyan");
        ui->textBrowser->setText(code2);
        break;

    }


}



void textView::on_tabWidget_tabBarClicked(int index)
{

        this->updateCode(index);


}
