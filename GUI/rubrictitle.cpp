#include "rubrictitle.h"
#include "ui_rubrictitle.h"
#include "rubrics.h"
#include "addcategory.h"

RubricTitle::RubricTitle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RubricTitle)
{
    ui->setupUi(this);
}

RubricTitle::~RubricTitle()
{
    delete ui;
}

void RubricTitle::set_integ(Integration *i)
{
    integ = i;
}

void RubricTitle::on_pushButton_2_clicked()
{
    AddCategory *rv= new AddCategory();
    get_data();
    Rubric* r = integ->add_new_rubric(d, n);
    rv->set_integ(integ, r);

    rv->show();
    this->hide();
}

void RubricTitle::get_data()
{
    n = ui->lineEdit->text().toStdString();
}

void RubricTitle::on_checkBox_clicked(bool checked)
{
    d = checked;
}

void RubricTitle::on_pushButton_clicked()
{
    DataView *dv= new DataView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}
