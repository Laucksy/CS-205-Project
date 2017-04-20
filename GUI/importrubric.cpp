#include "importrubric.h"
#include "ui_importrubric.h"
#include "selectrubric.h"

importRubric::importRubric(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::importRubric)
{
    ui->setupUi(this);
}

importRubric::~importRubric()
{
    delete ui;
}

void importRubric::set_integ(Integration *i)
{
    integ = i;
}
void importRubric::on_pushButton_2_clicked()
{
    selectRubric *sc= new selectRubric();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}

void importRubric::on_pushButton_clicked()
{
    selectRubric *sc= new selectRubric();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}
