#include "newsubmission.h"
#include "ui_newsubmission.h"
#include "assignmentview.h"
#include "submissionview.h"
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

void newSubmission::set_integ(Integration *i)
{
    integ = i;

    for (Student* k : integ->activeClass->list) {
        ui->comboBox->addItem(QString::fromStdString(k->name));
    }

    if (integ->activeClass->list.size() > 0) {
        student = integ->activeClass->list[0];
    }
}
void newSubmission::on_pushButton_clicked()
{
    assignmentView *dv= new assignmentView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void newSubmission::on_pushButton_2_clicked()
{
    submissionView *dv= new submissionView();

    Assignment* a = integ->add_new_submission(integ->activeAssignemnt->rubric, student);
    dv->set_integ(integ, a);

    dv->show();
    this->hide();
}

void newSubmission::on_comboBox_activated(const QString &arg1)
{
    for (Student* k : integ->activeClass->list) {
        if (arg1.toStdString() == k->name) {
            student = k;
        }
    }
}
