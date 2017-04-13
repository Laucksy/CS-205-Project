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
