#include "newassignment.h"
#include "ui_newassignment.h"

newAssignment::newAssignment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newAssignment)
{
    ui->setupUi(this);
}

newAssignment::~newAssignment()
{
    delete ui;
}
