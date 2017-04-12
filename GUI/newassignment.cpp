#include "newassignment.h"
#include "ui_newassignment.h"
#include "dataview.h"
#include "assignmentview.h"

newAssignment::newAssignment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newAssignment)
{
    ui->setupUi(this);
}

newAssignment::~newAssignment()
{
    delete ui;
}

void newAssignment::set_integ(Integration *i)
{
    integ = i;
}

void newAssignment::on_pushButton_clicked()
{
    DataView *dv= new DataView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void newAssignment::on_pushButton_2_clicked()
{

    assignmentView *dv= new assignmentView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}
