#include "importclass.h"
#include "ui_importclass.h"
#include "classview.h"

importClass::importClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::importClass)
{
    ui->setupUi(this);
}

importClass::~importClass()
{
    delete ui;
}


void importClass::set_integ(Integration *i)
{
    integ = i;
    section = integ->activeClass;
    edit = false;
}

void importClass::set_integ(Integration* i, Students *s)
{
    integ = i;
    section = s;
    edit = true;
}

void importClass::import_students()
{
    integ->import_students(path);
}

void importClass::on_pushButton_clicked()
{
    classView *sc= new classView();

    import_students();

    if (edit) {
        sc->set_integ(integ, section);
    } else {
        sc->set_integ(integ);
    }

    sc->show();
    this->hide();
}

void importClass::on_pushButton_2_clicked()
{
    classView *sc= new classView();

    if (edit) {
        sc->set_integ(integ, section);
    } else {
        sc->set_integ(integ);
    }

    sc->show();
    this->hide();
}

void importClass::on_lineEdit_textChanged(const QString &arg1)
{
    path = arg1.toStdString();
}
