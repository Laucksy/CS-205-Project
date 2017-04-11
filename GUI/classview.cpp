#include "classview.h"
#include "ui_classview.h"

classView::classView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::classView)
{
    ui->setupUi(this);
}

classView::~classView()
{
    delete ui;
}

void classView::set_integ(Integration *i)
{
    integ = i;
}
