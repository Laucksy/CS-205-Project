#include "addcategory.h"
#include "ui_addcategory.h"
#include "rubrics.h"
#include "dataview.h"

AddCategory::AddCategory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCategory)
{
    ui->setupUi(this);

}

AddCategory::~AddCategory()
{
    delete ui;
}

void AddCategory::set_integ(Integration *i, Rubric* r)
{
    integ = i;
    rubric = r;

    QString qstr;
    string text;
    for (int i=0; i <rubric->name.size(); i++) {
        text += rubric->name[i] + " | " + to_string(rubric->cat[i]->pts) + "\n";
    }
    qstr = QString::fromStdString(text);

    ui->textBrowser->setText(qstr);

    cat = nullptr;

    ui->comboBox->addItem("None");

    for (string k : r->name) {
        ui->comboBox->addItem(QString::fromStdString(k));
    }

}

void AddCategory::on_pushButton_clicked()
{
    Rubrics *rv= new Rubrics();
    rv->set_integ(integ, rubric);

    rv->show();
    this->hide();
}

void AddCategory::on_pushButton_2_clicked()
{
    DataView *rv= new DataView();
    rv->set_integ(integ);

    rv->show();
    this->hide();
}


void AddCategory::on_comboBox_activated(const QString &arg1)
{
    int ind = -1;
    for (int i = 0; i < rubric->name.size(); i++) {
        if (arg1.toStdString() == rubric->name[i]) {
            ind = i;
        }
    }

    if (ind != -1) {
        cat = rubric->cat[ind];
    } else {
        cat = nullptr;
    }
}
