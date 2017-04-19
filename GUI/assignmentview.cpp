#include "assignmentview.h"
#include "ui_assignmentview.h"
#include "dataview.h"
#include "newsubmission.h"

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
    integ = i;

    ui->comboBox->clear();

    QString qstra;
    string text;
    for (int i=0; i <integ->activeAssignemnt->list.size(); i++) {
        text += integ->activeAssignemnt->list[i]->stu->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    QString qstrb =  QString::fromStdString(integ->activeAssignemnt->name);

    ui->label_2->setText(qstrb);

    submit = nullptr;

    ui->comboBox->addItem("None");

    for (Assignment* k : integ->activeAssignemnt->list) {
        ui->comboBox->addItem(QString::fromStdString(k->stu->name));
    }
}
void assignmentView::on_pushButton_2_clicked()
{
    integ->set_active_assignment(integ->activeAssignemnt);
    DataView *dv= new DataView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void assignmentView::on_pushButton_clicked()
{
    newSubmission*dv= new newSubmission();
    dv->set_integ(integ);

    dv->show();
    this->hide();
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
