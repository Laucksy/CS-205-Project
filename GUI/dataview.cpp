#include "dataview.h"
#include "ui_dataview.h"
#include "rubrictitle.h"
#include "mainwindow.h"
#include "newclass.h"
#include "newassignment.h"
#include "selectclass.h"
#include "selectrubric.h"
#include "selectassignment.h"

DataView::DataView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataView)
{
    ui->setupUi(this);
    ui->label->setText("");
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
    if (integ->activeSubmission == nullptr) {
        ui->label->setText("Please create an assignment and submissions");
        return;
    }
    textView *tv= new textView();
    tv->set_integ(integ);

    tv->show();
    this->hide();
}

void DataView::on_pushButton_2_clicked()
{
    selectRubric *rv= new selectRubric();
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
    selectClass *sc= new selectClass();
   sc->set_integ(integ);

   sc->show();
   this->hide();
}

void DataView::on_pushButton_3_clicked()
{
    if (integ->activeClass == nullptr) {
        ui->label->setText("Please create a class before creating an assignemnt");
        return;
    }
    if (integ->activeClass->list[0] == nullptr) {
        ui->label->setText("Please create a student before creating an assignemnt");
        return;
    }
    selectAssignment *dv= new selectAssignment();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}
