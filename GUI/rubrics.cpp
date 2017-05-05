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
//    for(int i=0; i<rubricData.size();i++){
//    cerr<<rubricData.at(i);
//    }
// cerr<<"finished";

    vector<string> qual;
    vector<double> mark;
    for (unsigned i = 0; i < rubricData.size(); i = i+2) {
        qual.push_back(rubricData[i]);
        mark.push_back(atof(rubricData[i+1].c_str()));
    }

    integ->add_new_category(rubric, name, pts, mark, qual, matrix);

    AddCategory *dv= new AddCategory();
    dv->set_integ(integ, rubric);

    dv->show();
    this->hide();
}

void Rubrics::set_integ(Integration *i, Rubric *r)
{
    integ = i;
    rubric = r;
}

void Rubrics::getData(){
    for(int i=0; ui->tableWidget->item(i,1)->text()!="";i++){
        rubricData.push_back(ui->tableWidget->item(i,1)->text().toStdString());
        //cerr<<"this is the thing"<<ui->tableWidget->item(0,1)->text().toStdString();
    }
    name = ui->lineEdit->text().toStdString();
    pts = atof(ui->lineEdit_2->text().toStdString().c_str());

}

void Rubrics::on_checkBox_clicked(bool checked)
{
    matrix = checked;
    if(!checked){
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    else{
        ui->tableWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
    }
}
