#include "selectrubric.h"
#include "ui_selectrubric.h"
#include "dataview.h"
#include "../DataStructure/rubric.h"
#include "rubrictitle.h"
#include "addcategory.h"

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

    ui->comboBox->clear();

    QString qstra;
    string text;
    for (int i=0; i <integ->rubrics.size(); i++) {
        Rubric* temp = integ->rubrics.at(i);
        text+= temp->title+ "\n";
       // text += integ->activeClass->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    grade = nullptr;

    ui->comboBox->addItem("None");

    for (Rubric* k : integ->rubrics) {
        ui->comboBox->addItem(QString::fromStdString(k->title));
    }

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

void selectRubric::on_comboBox_activated(const QString &arg1)
{
    for (Rubric* k : integ->rubrics) {
        if (arg1.toStdString() == k->title) {
            grade = k;
        }
    }

    if (arg1.toStdString() == "None") {
        grade = nullptr;
    }
}

void selectRubric::on_pushButton_clicked()
{
   if (grade != nullptr) {
   AddCategory *sc= new AddCategory();
   sc->set_integ(integ, grade);

   sc->show();
   this->hide();
   }
}

void selectRubric::on_pushButton_2_clicked()
{
    if (grade != nullptr) {
        integ->delete_rubric(grade);
        set_integ(integ);
    }
}
