#include "sudentsubdirectory.h"
#include "ui_sudentsubdirectory.h"
#include "submissionview.h"


sudentSubDirectory::sudentSubDirectory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sudentSubDirectory)
{
    ui->setupUi(this);
}

sudentSubDirectory::~sudentSubDirectory()
{
    delete ui;
}


void sudentSubDirectory::set_integ(Integration *i)
{
    integ = i;
}
void sudentSubDirectory::on_pushButton_clicked()
{
    submissionView *dv= new submissionView();
   // dv->set_integ(integ);

    dv->show();
    this->hide();
}

void sudentSubDirectory::on_pushButton_2_clicked()
{
    submissionView *dv= new submissionView();
    ////dv->set_integ(integ);

    dv->show();
    this->hide();
}
