#include "classview.h"
#include "ui_classview.h"
#include "newclass.h"
#include "newstudent.h"
#include "dataview.h"
#include "importclass.h"
#include <QFileDialog>

/*ClassView is a view of the all the classes.
 * */

classView::classView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::classView)
{
    ui->setupUi(this);

    stu = nullptr;

}

classView::~classView()
{
    delete ui;
}

void classView::set_integ(Integration *i)
{
    integ = i;
    sec = integ->activeClass;
    edit = false;

    ui->comboBox->clear();

    QString qstra;
    /*string text;
    for (int i=0; i <integ->activeClass->list.size(); i++) {
        text += integ->activeClass->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);*/

    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (unsigned i=0; i < sec->list.size(); i++) {
        Student* temp = sec->list.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(temp == stu) {
            text += "<span style='background-color:aqua;'>";
        } else {
            text += "<span>";
        }
        text += "<a href='" + temp->name + "'>" + temp->name + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);

    QString qstrb =  QString::fromStdString(integ->activeClass->name);

    ui->classTitle->setText(qstrb);

    ui->comboBox->addItem("None");

    for (Student* k : integ->activeClass->list) {
        ui->comboBox->addItem(QString::fromStdString(k->name));
    }
}

void classView::set_integ(Integration *i, Students* s)
{
    integ = i;
    sec = s;
    edit = true;

    ui->comboBox->clear();

    QString qstra;
    /*string text;
    for (int i=0; i <sec->list.size(); i++) {
        text += sec->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);*/

    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (unsigned i=0; i < sec->list.size(); i++) {
        Student* temp = sec->list.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(temp == stu) {
            text += "<span style='background-color:aqua;'>";
        } else {
            text += "<span>";
        }
        text += "<a href='" + temp->name + "'>" + temp->name + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);

    QString qstrb =  QString::fromStdString(sec->name);

    ui->classTitle->setText(qstrb);

    ui->comboBox->addItem("None");

    for (Student* k : sec->list) {
        ui->comboBox->addItem(QString::fromStdString(k->name));
    }
}

void classView::on_pushButton_2_clicked()
{
    DataView *mv= new DataView();
    mv->set_integ(integ);

    mv->show();
    this->hide();
}

void classView::on_pushButton_clicked()
{
    newStudent *dv= new newStudent();
    if (edit) {
        dv->set_integ(integ, sec);
    } else {
        dv->set_integ(integ);
    }

    dv->show();
    this->hide();
}


void classView::on_comboBox_activated(const QString &arg1)
{
    for (Student* k : sec->list) {
        if (arg1.toStdString() == k->name) {
            stu = k;
        }
    }

    if (arg1.toStdString() == "None") {
        stu = nullptr;
    }

    if (edit) {
        set_integ(integ, sec);
    } else {
        set_integ(integ);
    }
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(arg1));
}

void classView::on_pushButton_3_clicked()
{
    if (stu != nullptr) {
        integ->delete_student(stu);
        if (edit) {
            set_integ(integ, sec);
        } else {
            set_integ(integ);
        }
    }
}

void classView::on_pushButton_5_clicked()
{
    /*importClass *mv= new importClass();

    if (edit) {
        mv->set_integ(integ, sec);
    } else {
        mv->set_integ(integ);
    }

    mv->show();
    this->hide();*/

    QString path = QFileDialog::getOpenFileName(this,tr("Open Rubric to Import"),"C://",tr("Csv (*.csv)"));
    //cout << fn.toStdString() << endl;
    integ->import_students(path.toStdString(), sec);
    if (edit) {
        this->set_integ(integ, sec);
    } else {
        this->set_integ(integ);
    }
}

void classView::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    string url = arg1.url().toStdString();
    //cout << "URL" << url << endl;
    for(unsigned i = 0; i < sec->list.size(); i++) {
        Student* temp = sec->list.at(i);
        if(temp->name == url) {
            stu = temp;
        }
    }
    if (edit) {
        set_integ(integ, sec);
    } else {
        set_integ(integ);
    }
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(QString::fromStdString(url)));
}
