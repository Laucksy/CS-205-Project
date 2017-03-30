#include "dataview.h"
#include "ui_dataview.h"

DataView::DataView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataView)
{
    ui->setupUi(this);
}

DataView::~DataView()
{
    delete ui;
}

void DataView::on_pushButton_clicked()
{
    textView *tv= new textView();

    tv->show();
    this->hide();
}

void DataView::on_pushButton_2_clicked()
{
    Rubrics *rv= new Rubrics();

    rv->show();
    this->hide();
}
