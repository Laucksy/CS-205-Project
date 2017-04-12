#include "newsubmission.h"
#include "ui_newsubmission.h"
#include "assignmentview.h"
#include "submissionview.h"
newSubmission::newSubmission(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newSubmission)
{
    ui->setupUi(this);
}

newSubmission::~newSubmission()
{
    delete ui;
}

void newSubmission::set_integ(Integration *i)
{
    integ = i;
}
void newSubmission::on_pushButton_clicked()
{
    assignmentView *dv= new assignmentView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void newSubmission::on_pushButton_2_clicked()
{
    submissionView *dv= new submissionView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}
