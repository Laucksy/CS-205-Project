#include "classview.h"
#include "ui_classview.h"
#include "newclass.h"
#include "newstudent.h"
#include "dataview.h"

classView::classView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::classView)
{
    ui->setupUi(this);

}

classView::~classView()
{
    delete ui;
}

void classView::set_integ(Integration *i)
{
    integ = i;

    QString qstra;
    string text;
    for (int i=0; i <integ->activeClass->list.size(); i++) {
        text += integ->activeClass->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    QString qstrb =  QString::fromStdString(integ->activeClass->name);

    ui->classTitle->setText(qstrb);

    stu = nullptr;

    ui->comboBox->addItem("None");

    for (Student* k : integ->activeClass->list) {
        ui->comboBox->addItem(QString::fromStdString(k->name));
    }
}

void classView::on_pushButton_2_clicked()
{
    DataView *mv= new DataView();
    mv->set_integ(integ);

    mv->show();
    this->hide();
}

void classView::on_pushButton_clicked()
{
    newStudent *dv= new newStudent();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}


void classView::on_comboBox_activated(const QString &arg1)
{
    for (Student* k : integ->activeClass->list) {
        if (arg1.toStdString() == k->name) {
            stu = k;
        }
    }

    if (arg1.toStdString() == "None") {
        stu = nullptr;
    }
}
