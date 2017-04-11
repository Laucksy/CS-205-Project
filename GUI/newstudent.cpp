#include "newstudent.h"
#include "ui_newstudent.h"

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
