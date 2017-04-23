#include "assignmentview.h"
#include "ui_assignmentview.h"
#include "dataview.h"
#include "newsubmission.h"
#include "submissionview.h"
#include "selectassignment.h"

/*AssignmentView is a ciew of the submission being graded.
 * */

assignmentView::assignmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::assignmentView)
{
    ui->setupUi(this);
}

assignmentView::~assignmentView()
{
    delete ui;
}

void assignmentView::set_integ(Integration *i)
{
    edit = false;
    integ = i;
    assign = integ->activeAssignemnt;

    ui->comboBox->clear();

    QString qstra;
    string text;
    for (int i=0; i <assign->list.size(); i++) {
        text += assign->list[i]->stu->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    QString qstrb =  QString::fromStdString(assign->name);

    ui->label_2->setText(qstrb);

    submit = nullptr;

    ui->comboBox->addItem("None");

    for (Assignment* k : assign->list) {
        ui->comboBox->addItem(QString::fromStdString(k->stu->name));
    }
}

void assignmentView::set_integ(Integration *i, Assignments* a)
{
    edit = true;
    integ = i;
    assign = a;

    ui->comboBox->clear();

    QString qstra;
    string text;
    for (int i=0; i <assign->list.size(); i++) {
        text += assign->list[i]->stu->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    QString qstrb =  QString::fromStdString(assign->name);

    ui->label_2->setText(qstrb);

    submit = nullptr;

    ui->comboBox->addItem("None");

    for (Assignment* k : assign->list) {
        ui->comboBox->addItem(QString::fromStdString(k->stu->name));
    }
}
void assignmentView::on_pushButton_2_clicked()
{
    integ->set_active_assignment(assign);
    selectAssignment *dv= new selectAssignment();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void assignmentView::on_pushButton_clicked()
{
    if (edit) {
        newSubmission*dv= new newSubmission();
        dv->set_integ(integ, assign);

        dv->show();
        this->hide();
    } else {
        newSubmission*dv= new newSubmission();
        dv->set_integ(integ);

        dv->show();
        this->hide();
    }
}

void assignmentView::on_comboBox_activated(const QString &arg1)
{
    for (Assignment* k : integ->activeAssignemnt->list) {
        if (arg1.toStdString() == k->stu->name) {
            submit = k;
        }
    }

    if (arg1.toStdString() == "None") {
        submit = nullptr;
    }
}

void assignmentView::on_pushButton_3_clicked()
{
    if(submit != nullptr) {
        integ->delete_submission(submit);
        set_integ(integ);
    }
}

void assignmentView::on_pushButton_4_clicked()
{
    if (submit != nullptr) {
        if (edit) {
            submissionView *dv= new submissionView();
            dv->set_integ(integ, submit, assign);

            dv->show();
            this->hide();
        } else {
            submissionView *dv= new submissionView();
            dv->set_integ(integ, submit);

            dv->show();
            this->hide();
        }
    }
}
