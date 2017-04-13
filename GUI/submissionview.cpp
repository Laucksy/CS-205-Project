#include "submissionview.h"
#include "ui_submissionview.h"
#include "newsubmission.h"
#include "newfile.h"

submissionView::submissionView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::submissionView)
{
    ui->setupUi(this);
}

submissionView::~submissionView()
{
    delete ui;
}

void submissionView::set_integ(Integration *i, Assignment* a)
{
    integ = i;
    assign = a;

    QString qstra;
    string text;
    for (int i=0; i <assign->files.size(); i++) {
        text += assign->files[i]->fileName + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);
}

void submissionView::on_pushButton_2_clicked()
{
    newSubmission *dv= new newSubmission();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void submissionView::on_pushButton_clicked()
{
    newFile *dv= new newFile();
    dv->set_integ(integ, assign);

    dv->show();
    this->hide();
}
