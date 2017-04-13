#include "newclass.h"
#include "ui_newclass.h"
#include "dataview.h"
#include "classview.h"

newClass::newClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newClass)
{
    ui->setupUi(this);
}

newClass::~newClass()
{
    delete ui;
}

void newClass::on_pushButton_clicked()
{
    DataView *mv= new DataView();
    mv->set_integ(integ);

    mv->show();
    this->hide();
}

void newClass::on_pushButton_2_clicked()
{
    classView *mv= new classView();

    get_data();
    integ->add_new_class(name);
    mv->set_integ(integ);

    mv->show();
    this->hide();
}

void newClass::set_integ(Integration *i)
{
    integ = i;
}

void newClass::get_data()
{
    name = ui->lineEdit->text().toStdString();
}
