#include "importclass.h"
#include "ui_importclass.h"
#include "selectclass.h"

importClass::importClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::importClass)
{
    ui->setupUi(this);
}

importClass::~importClass()
{
    delete ui;
}


void importClass::set_integ(Integration *i)
{
    integ = i;
}

void importClass::on_pushButton_clicked()
{
    selectClass *sc= new selectClass();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}

void importClass::on_pushButton_2_clicked()
{
    selectClass *sc= new selectClass();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}
