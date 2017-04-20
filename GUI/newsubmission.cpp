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
    assign = integ->activeAssignemnt;
    assignEdit = false;

    vector<Student*> add;

    for (Student* k : integ->activeClass->list) {
        bool has;
        for (Assignment* l : k->list) {
            if (l->assignNum == assign->id) {
                has = true;
            }
        }

        if (!has) {
            ui->comboBox->addItem(QString::fromStdString(k->name));
            add.push_back(k);
        }
    }

    if (add.size() > 0) {
        student = add[0];
    }
}

void newSubmission::set_integ(Integration *i, Assignments* a)
{
    integ = i;
    assign = a;
    assignEdit = true;

    vector<Student*> add;

    for (Student* k : integ->activeClass->list) {
        bool has;
        for (Assignment* l : k->list) {
            if (l->assignNum == assign->id) {
                has = true;
            }
        }

        if (!has) {
            ui->comboBox->addItem(QString::fromStdString(k->name));
            add.push_back(k);
        }
    }

    if (add.size() > 0) {
        student = add[0];
    }
}

void newSubmission::on_pushButton_clicked()
{
    if (!assignEdit) {
        assignmentView *dv= new assignmentView();
        dv->set_integ(integ);

        dv->show();
        this->hide();
    } else {
        assignmentView *dv= new assignmentView();
        dv->set_integ(integ, assign);

        dv->show();
        this->hide();
    }
}

void newSubmission::on_pushButton_2_clicked()
{
    submissionView *dv= new submissionView();

    Assignments* temp = integ->activeAssignemnt;
    integ->activeAssignemnt = assign;

    Assignment* a = integ->add_new_submission(assign->rubric, student);
    integ->activeAssignemnt = temp;

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
