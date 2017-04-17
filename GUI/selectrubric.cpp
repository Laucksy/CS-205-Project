#include "selectrubric.h"
#include "ui_selectrubric.h"
#include "dataview.h"
#include "../DataStructure/rubric.h"
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

    QString qstra;
    string text;
    for (int i=0; i <integ->rubrics.size(); i++) {
        Rubric* temp = integ->rubrics.at(i);
        text+= temp->title+ "\n";
       // text += integ->activeClass->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

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
