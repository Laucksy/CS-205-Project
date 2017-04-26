#include "importrubric.h"
#include "ui_importrubric.h"
#include "selectrubric.h"
#include <QFileDialog>

importRubric::importRubric(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::importRubric)
{
    ui->setupUi(this);
}

importRubric::~importRubric()
{
    delete ui;
}

void importRubric::set_integ(Integration *i)
{
    integ = i;
}

void importRubric::import_rubric()
{
    integ->import_rubric(path);
}



void importRubric::on_pushButton_2_clicked()
{
    selectRubric *sc= new selectRubric();

    import_rubric();

    sc->set_integ(integ);

    sc->show();
    this->hide();
}

void importRubric::on_pushButton_clicked()
{
    selectRubric *sc= new selectRubric();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}

void importRubric::on_lineEdit_textChanged(const QString &arg1)
{
    path = arg1.toStdString();
}

void importRubric::on_importRubricButton_clicked()
{
    QString importRubric = QFileDialog::getOpenFileName(this,tr("Open Rubric to Import"),"C://",tr("Txt (*.txt)"));
    integ->import_rubric(importRubric.toStdString());

}
