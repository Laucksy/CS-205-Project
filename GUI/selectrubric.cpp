#include "selectrubric.h"
#include "ui_selectrubric.h"
#include "dataview.h"
#include "rubrictitle.h"

selectRubric::selectRubric(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectRubric)
{
    ui->setupUi(this);
}

selectRubric::~selectRubric()
{
    delete ui;
}

void selectRubric::set_integ(Integration *i)
{
    integ = i;
}

void selectRubric::on_pushButton_5_clicked()
{
    DataView *sc= new DataView();
   sc->set_integ(integ);

   sc->show();
   this->hide();
}

void selectRubric::on_pushButton_4_clicked()
{
    RubricTitle *sc= new RubricTitle();
   sc->set_integ(integ);

   sc->show();
   this->hide();
}
