#include "forgotpassword.h"
#include "ui_forgotpassword.h"

ForgotPassword::ForgotPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);
}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}

void ForgotPassword::set_integ(Integration *i)
{
    integ = i;
}

void ForgotPassword::on_pushButton_clicked()
{
    MainWindow *mv= new MainWindow();
    mv->set_integ(integ);

    mv->show();
    this->hide();

}
