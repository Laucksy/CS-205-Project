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
