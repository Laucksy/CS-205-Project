#include "newfile.h"
#include "ui_newfile.h"
#include "submissionview.h"
newFile::newFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newFile)
{
    ui->setupUi(this);
}

newFile::~newFile()
{
    delete ui;
}

void newFile::set_integ(Integration *i, Assignment* a)
{
    integ = i;
    assign = a;
    assignment = nullptr;
    assignEdit = false;
}

void newFile::set_integ(Integration *i, Assignment* a, Assignments* as)
{
    integ = i;
    assign = a;
    assignment = as;
    assignEdit = true;
}

void newFile::on_pushButton_2_clicked()
{
    submissionView *dv= new submissionView();

    get_data();
    integ->add_new_file(assign, fn);

    if (assignEdit) {
        dv->set_integ(integ, assign, assignment);
    } else {
        dv->set_integ(integ, assign);
    }

    dv->show();
    this->hide();
}

void newFile::on_pushButton_clicked()
{
    submissionView *dv= new submissionView();

    if (assignEdit) {
        dv->set_integ(integ, assign, assignment);
    } else {
        dv->set_integ(integ, assign);
    }

    dv->show();
    this->hide();

}

void newFile::get_data()
{
    fn = ui->lineEdit->text().toStdString();
}
