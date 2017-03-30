#include "rubrics.h"
#include "ui_rubrics.h"

Rubrics::Rubrics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rubrics)
{
    ui->setupUi(this);
}

Rubrics::~Rubrics()
{
    delete ui;
}

void Rubrics::on_pushButton_2_clicked()
{
    DataView *dv= new DataView();

    dv->show();
    this->hide();
}
