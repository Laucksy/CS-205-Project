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

void RubricTitle::on_pushButton_2_clicked()
{
    AddCategory *rv= new AddCategory();

    rv->show();
    this->hide();
}
