#include "newstudent.h"
#include "ui_newstudent.h"
#include "classview.h"

newStudent::newStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newStudent)
{
    ui->setupUi(this);
}

newStudent::~newStudent()
{
    delete ui;
}

void newStudent::on_pushButton_clicked()
{
    classView *dv= new classView();

    get_data();
    integ->add_new_student(fn, ln);
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void newStudent::set_integ(Integration *i)
{
    integ = i;
}
void newStudent::on_pushButton_2_clicked()
{
    classView *dv= new classView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void newStudent::get_data()
{
    fn = ui->lineEdit->text().toStdString();
    ln = ui->lineEdit_2->text().toStdString();
}
