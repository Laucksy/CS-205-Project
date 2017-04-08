#include "addcategory.h"
#include "ui_addcategory.h"
#include "rubrics.h"
#include "dataview.h"

AddCategory::AddCategory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCategory)
{
    ui->setupUi(this);
}

AddCategory::~AddCategory()
{
    delete ui;
}

void AddCategory::on_pushButton_clicked()
{
    Rubrics *rv= new Rubrics();

    rv->show();
    this->hide();
}

void AddCategory::on_pushButton_2_clicked()
{
    DataView *rv= new DataView();

    rv->show();
    this->hide();
}
