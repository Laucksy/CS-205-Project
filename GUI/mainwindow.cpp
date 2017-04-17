#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gitmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    //it::reset();

    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    Git::push();
    delete ui;
}

void MainWindow::set_integ(Integration *i)
{
    integ = i;
}

void MainWindow::on_pushButton_clicked()
{

    bool pulled = Git::pull();
    if(!pulled||true) {
        gitManager *dv= new gitManager();
        dv->set_integ(integ);

        dv->show();
        this->hide();
    }
    else
    {
        DataView *dv= new DataView();
        dv->set_integ(integ);

        dv->show();
        this->hide();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    NewUser *nv= new NewUser();
    nv->set_integ(integ);

    nv->show();
    this->hide();
}

void MainWindow::on_pushButton_3_clicked()
{
    ForgotPassword *fv= new ForgotPassword();
    fv->set_integ(integ);

    fv->show();
    this->hide();
}


