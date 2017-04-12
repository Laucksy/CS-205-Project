#include "newfile.h"
#include "ui_newfile.h"
#include "submissionview.h"
newFile::newFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newFile)
{
    ui->setupUi(this);
}

newFile::~newFile()
{
    delete ui;
}

void newFile::set_integ(Integration *i)
{
    integ = i;
}

void newFile::on_pushButton_2_clicked()
{
    submissionView *dv= new submissionView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void newFile::on_pushButton_clicked()
{
    submissionView *dv= new submissionView();
    dv->set_integ(integ);

    dv->show();
    this->hide();

}
