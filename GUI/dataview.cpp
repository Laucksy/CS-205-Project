#include "dataview.h"
#include "ui_dataview.h"
#include "rubrictitle.h"
#include "mainwindow.h"
#include "newclass.h"

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

void DataView::set_integ(Integration *i)
{
    integ = i;
}

void DataView::on_pushButton_clicked()
{
    textView *tv= new textView();
    tv->set_integ(integ);

    tv->show();
    this->hide();
}

void DataView::on_pushButton_2_clicked()
{
    RubricTitle *rv= new RubricTitle();
    rv->set_integ(integ);

    rv->show();
    this->hide();
}

void DataView::on_pushButton_4_clicked()
{
     MainWindow *rv= new MainWindow();
    rv->set_integ(integ);

    rv->show();
    this->hide();

}

void DataView::on_pushButton_5_clicked()
{
    newClass *rv= new newClass();
   rv->set_integ(integ);

   rv->show();
   this->hide();
}
