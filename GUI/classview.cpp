#include "classview.h"
#include "ui_classview.h"
#include "newclass.h"
#include "newstudent.h"
#include "dataview.h"

classView::classView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::classView)
{
    ui->setupUi(this);

}

classView::~classView()
{
    delete ui;
}

void classView::set_integ(Integration *i)
{
    integ = i;

    QString qstra;
    string text;
    for (int i=0; i <integ->activeClass->list.size(); i++) {
        text += integ->activeClass->list[i]->firstName + " " + integ->activeClass->list[i]->lastName + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    QString qstrb =  QString::fromStdString(integ->activeClass->name);

    ui->classTitle->setText(qstrb);
}

void classView::on_pushButton_2_clicked()
{
    DataView *mv= new DataView();
    mv->set_integ(integ);

    mv->show();
    this->hide();
}

void classView::on_pushButton_clicked()
{
    newStudent *dv= new newStudent();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

