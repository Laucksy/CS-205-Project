#include "rubrics.h"
#include "ui_rubrics.h"
#include <iostream>
#include <vector>
#include "addcategory.h"
using namespace std;

Rubrics::Rubrics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rubrics)
{

    ui->setupUi(this);
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Rubrics::~Rubrics()
{
    delete ui;
}

void Rubrics::on_pushButton_2_clicked()
{
   this->getData();
    for(int i=0; i<rubricData.size();i++){
    cerr<<rubricData.at(i);
    }
 cerr<<"finished";

    AddCategory *dv= new AddCategory();

    dv->show();
    this->hide();
}



void Rubrics::getData(){
    for(int i=0; ui->tableWidget->item(i,1)->text()!="";i++){
        rubricData.push_back(ui->tableWidget->item(i,1)->text().toStdString());
        //cerr<<"this is the thing"<<ui->tableWidget->item(0,1)->text().toStdString();
    }
}

void Rubrics::on_checkBox_clicked(bool checked)
{
    if(!checked){
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    else{
        ui->tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
}
