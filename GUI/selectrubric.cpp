#include "selectrubric.h"
#include "ui_selectrubric.h"
#include "dataview.h"
#include "../DataStructure/rubric.h"
#include "rubrictitle.h"
#include "addcategory.h"
#include "importrubric.h"
#include <QFileDialog>

selectRubric::selectRubric(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectRubric)
{
    ui->setupUi(this);
}

selectRubric::~selectRubric()
{
    delete ui;
}

void selectRubric::set_integ(Integration *i)
{
    /*integ = i;

    ui->comboBox->clear();

    QString qstra;
    string text;
    for (int i=0; i <integ->rubrics.size(); i++) {
        Rubric* temp = integ->rubrics.at(i);
        text+= temp->title+ "\n";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    grade = nullptr;

    ui->comboBox->addItem("None");

    for (Rubric* k : integ->rubrics) {
        ui->comboBox->addItem(QString::fromStdString(k->title));
    }*/

    integ = i;

    ui->comboBox->clear();

    QString qstra;
    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (unsigned i=0; i <integ->rubrics.size(); i++) {
        Rubric* temp = integ->rubrics.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(grade != nullptr && temp == grade) {
            text += "<span style='background-color:aqua;'>";
            grade = temp;

        } else {
            text += "<span>";
        }
        text += "<a href='" + temp->title + "'>" + temp->title + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);
    //ui->textBrowser->setText(qstra);

    //section = nullptr;

    ui->comboBox->addItem("None");

    for (Rubric* k : integ->rubrics) {
        ui->comboBox->addItem(QString::fromStdString(k->title));
    }
}

void selectRubric::on_pushButton_5_clicked()
{
    DataView *sc= new DataView();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}

void selectRubric::on_pushButton_4_clicked()
{
    RubricTitle *sc= new RubricTitle();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}

void selectRubric::on_comboBox_activated(const QString &arg1)
{
    for (Rubric* k : integ->rubrics) {
        if (arg1.toStdString() == k->title) {
            grade = k;
        }
    }

    if (arg1.toStdString() == "None") {
        grade = nullptr;
    }

    set_integ(integ);
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(arg1));
}

void selectRubric::on_pushButton_clicked()
{
    if (grade != nullptr) {
        AddCategory *sc= new AddCategory();
        sc->set_integ(integ, grade);

        sc->show();
        this->hide();
    }
}

void selectRubric::on_pushButton_2_clicked()
{
    if (grade != nullptr) {
        integ->delete_rubric(grade);
        set_integ(integ);
    }
}

void selectRubric::on_pushButton_3_clicked()
{
    importRubric *sc= new importRubric();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}

void selectRubric::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    string url = arg1.url().toStdString();
    //cout << "URL" << url << endl;
    for(unsigned i = 0; i < integ->rubrics.size(); i++) {
        Rubric* temp = integ->rubrics.at(i);
        if(temp->title == url) {
            grade = temp;
        }
    }
    this->set_integ(integ);
    //cout << ui->comboBox->findText(QString::fromStdString(url)) << "," << url << "," << endl;
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(QString::fromStdString(url)));
}
