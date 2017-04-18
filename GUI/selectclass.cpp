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
    QString qstra;
    string text;
    for (int i=0; i <integ->students.size(); i++) {
        Students* temp = integ->students.at(i);
        text+= temp->name+ "\n";
       // text += integ->activeClass->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    section = nullptr;

    ui->comboBox->addItem("None");

    for (Students* k : integ->students) {
        ui->comboBox->addItem(QString::fromStdString(k->name));
    }

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



void selectClass::on_export_2_clicked()
{
   if(section!=nullptr){
    ExportHTML::export_csv_section(section);
   }
}

void selectClass::on_comboBox_activated(const QString &arg1)
{
    for (Students* k : integ->students) {
        if (arg1.toStdString() == k->name) {
            section = k;
        }
    }

    if (arg1.toStdString() == "None") {
        section = nullptr;
    }
}
