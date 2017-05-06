#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    ui->repoLineEdit->setText(QString::fromStdString(Git::get_repo()));
}

Options::~Options()
{
    delete ui;
}

void Options::set_integ(Integration *i) {
    integ = i;
}

void Options::on_submitButton_clicked()
{
    Git::set_repo(ui->repoLineEdit->text().toStdString());

    MainWindow *dv = new MainWindow();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}
