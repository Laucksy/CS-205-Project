#include "newfile.h"
#include "ui_newfile.h"

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
