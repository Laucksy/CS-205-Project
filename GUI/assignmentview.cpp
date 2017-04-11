#include "assignmentview.h"
#include "ui_assignmentview.h"

assignmentView::assignmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::assignmentView)
{
    ui->setupUi(this);
}

assignmentView::~assignmentView()
{
    delete ui;
}
