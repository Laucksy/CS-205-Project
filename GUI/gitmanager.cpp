#include "gitmanager.h"
#include "ui_gitmanager.h"

gitManager::gitManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gitManager)
{
    ui->setupUi(this);
}

gitManager::~gitManager()
{
    delete ui;
}

void gitManager::set_integ(Integration *i)
{
    integ = i;
}

void gitManager::on_local_clicked()
{
   Git::push();
   Git::pull();

    DataView *dv= new DataView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void gitManager::on_pushButton_2_clicked()
{
    Git::reset();

    DataView *dv= new DataView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}
