#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  DataView *dv= new DataView();

  dv->show();
  this->hide();
}


void MainWindow::on_pushButton_2_clicked()
{
    NewUser *nv= new NewUser();

    nv->show();
    this->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    ForgotPassword *fv= new ForgotPassword();

    fv->show();
    this->hide();
}


