#include "selectclass.h"
#include "ui_selectclass.h"
#include "newclass.h"
#include "dataview.h"

selectClass::selectClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectClass)
{
    ui->setupUi(this);
}

selectClass::~selectClass()
{
    delete ui;
}

void selectClass::set_integ(Integration *i)
{
    integ = i;
}

void selectClass::on_pushButton_4_clicked()
{
    newClass *sc= new newClass();
   sc->set_integ(integ);

   sc->show();
   this->hide();
}

void selectClass::on_pushButton_5_clicked()
{
    DataView *sc= new DataView();
   sc->set_integ(integ);

   sc->show();
   this->hide();
}
