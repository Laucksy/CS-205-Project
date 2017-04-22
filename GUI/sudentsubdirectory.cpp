#include "sudentsubdirectory.h"
#include "ui_sudentsubdirectory.h"
#include "submissionview.h"


sudentSubDirectory::sudentSubDirectory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sudentSubDirectory)
{
    ui->setupUi(this);
}

sudentSubDirectory::~sudentSubDirectory()
{
    delete ui;
}


void sudentSubDirectory::set_integ(Integration *i, Assignment* a)
{
    integ = i;
    assign = a;
    assignment= nullptr;
    assignEdit = false;
}

void sudentSubDirectory::set_integ(Integration *i, Assignment* a, Assignments* as)
{
    integ = i;
    assign = a;
    assignment= as;
    assignEdit = true;
}

void sudentSubDirectory::import_dir()
{
    integ->add_directory(assign, path);
}

void sudentSubDirectory::on_pushButton_clicked()
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

void sudentSubDirectory::on_pushButton_2_clicked()
{
    submissionView *dv= new submissionView();

    import_dir();

    if (assignEdit) {
        dv->set_integ(integ, assign, assignment);
    } else {
        dv->set_integ(integ, assign);
    }

    dv->show();
    this->hide();
}

void sudentSubDirectory::on_lineEdit_textChanged(const QString &arg1)
{
    path = arg1.toStdString();
}
