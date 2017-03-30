#include "newuser.h"
#include "ui_newuser.h"

NewUser::NewUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUser)
{
    ui->setupUi(this);
}

NewUser::~NewUser()
{
    delete ui;
}

void NewUser::on_pushButton_clicked()
{
    MainWindow *mv= new MainWindow();

    mv->show();
    this->hide();
}
