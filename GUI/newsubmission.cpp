#include "newsubmission.h"
#include "ui_newsubmission.h"

newSubmission::newSubmission(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newSubmission)
{
    ui->setupUi(this);
}

newSubmission::~newSubmission()
{
    delete ui;
}
