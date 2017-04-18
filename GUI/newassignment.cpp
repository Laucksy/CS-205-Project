#include "newassignment.h"
#include "ui_newassignment.h"
#include "dataview.h"
#include "assignmentview.h"
#include "selectassignment.h"

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

void newAssignment::set_integ(Integration *i)
{
    integ = i;

    for (Rubric* k : integ->rubrics) {
        ui->comboBox->addItem(QString::fromStdString(k->title));
    }

    for (Students* k : integ->students) {
        ui->comboBox_2->addItem(QString::fromStdString(k->name));
    }

    if (integ->rubrics.size() > 0) {
        rubric = integ->rubrics[0];
    } else {
        rubric = nullptr;
    }
}

void newAssignment::on_pushButton_clicked()
{
    selectAssignment *dv= new selectAssignment();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void newAssignment::on_pushButton_2_clicked()
{

    assignmentView *dv= new assignmentView();

    get_data();
    integ->add_new_assignment(name, stu->id);
    integ->select_assignment_rubric(rubric);
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void newAssignment::get_data()
{
    name = ui->lineEdit->text().toStdString();

}

void newAssignment::on_comboBox_activated(const QString &arg1)
{
    for (Rubric* k : integ->rubrics) {
        if (k->title == arg1.toStdString()) {
            rubric = k;
        }
    }
}

void newAssignment::on_comboBox_2_activated(const QString &arg1)
{
    for (Students* k : integ->students) {
        if (k->name == arg1.toStdString()) {
            stu = k;
        }
    }
}
