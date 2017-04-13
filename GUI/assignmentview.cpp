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

    QString qstra;
    string text;
    for (int i=0; i <integ->activeAssignemnt->list.size(); i++) {
        text += integ->activeAssignemnt->list[i]->stu->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    QString qstrb =  QString::fromStdString(integ->activeAssignemnt->name);

    ui->label_2->setText(qstrb);
}
void assignmentView::on_pushButton_2_clicked()
{
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
