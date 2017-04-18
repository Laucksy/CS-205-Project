#include "selectassignment.h"
#include "ui_selectassignment.h"
#include "newassignment.h"
#include "dataview.h"

selectAssignment::selectAssignment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectAssignment)
{
    ui->setupUi(this);
}

selectAssignment::~selectAssignment()
{
    delete ui;
}

void selectAssignment::set_integ(Integration *i)
{
    integ = i;
    QString qstra;
    string text;
    for (int i=0; i <integ->assignments.size(); i++) {
      Assignments* temp = integ->assignments.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        text+= temp->name+ "\n";
       // text += integ->activeClass->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);
}

void selectAssignment::on_pushButton_4_clicked()
{
    newAssignment *dv= new newAssignment();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void selectAssignment::on_pushButton_5_clicked()
{
    DataView *dv= new DataView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}



void selectAssignment::on_export_2_clicked()
{

}

void selectAssignment::on_comboBox_activated(const QString &arg1)
{

}
