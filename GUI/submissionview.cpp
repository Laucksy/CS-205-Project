#include "submissionview.h"
#include "ui_submissionview.h"
#include "newsubmission.h"
#include "newfile.h"

submissionView::submissionView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::submissionView)
{
    ui->setupUi(this);
}

submissionView::~submissionView()
{
    delete ui;
}

void submissionView::set_integ(Integration *i)
{
    integ = i;
}

void submissionView::on_pushButton_2_clicked()
{
    newSubmission *dv= new newSubmission();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void submissionView::on_pushButton_clicked()
{
    newFile *dv= new newFile();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}
