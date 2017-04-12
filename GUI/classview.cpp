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

