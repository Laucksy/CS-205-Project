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

    Students* temp = integ->activeClass;
    integ->set_active_class(sec);

    get_data();
    integ->add_new_student(n);

    integ->set_active_class(temp);

    if (classEdit) {
        dv->set_integ(integ, sec);
    } else {
        dv->set_integ(integ);
    }

    dv->show();
    this->hide();
}

void newStudent::set_integ(Integration *i)
{
    integ = i;
    sec = integ->activeClass;
    classEdit = false;
}

void newStudent::set_integ(Integration *i, Students* s)
{
    integ = i;
    sec = s;
    classEdit= true;
}
void newStudent::on_pushButton_2_clicked()
{
    classView *dv= new classView();
    if (classEdit) {
        dv->set_integ(integ, sec);
    } else {
        dv->set_integ(integ);
    }

    dv->show();
    this->hide();
}

void newStudent::get_data()
{
    n = ui->lineEdit->text().toStdString() + " " + ui->lineEdit_2->text().toStdString();
}
