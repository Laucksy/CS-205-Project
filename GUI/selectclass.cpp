#include "selectclass.h"
#include "ui_selectclass.h"
#include "newclass.h"
#include "dataview.h"
#include "classview.h"

selectClass::selectClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectClass)
{
    ui->setupUi(this);
}

selectClass::~selectClass()
{
    delete ui;
    section = nullptr;
}

void selectClass::set_integ(Integration *i)
{
    /*integ = i;

    ui->comboBox->clear();

    QString qstra;
    string text;
    for (int i=0; i <integ->students.size(); i++) {
        Students* temp = integ->students.at(i);
        text+= temp->name+ "\n";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

    section = nullptr;

    ui->comboBox->addItem("None");

    for (Students* k : integ->students) {
        ui->comboBox->addItem(QString::fromStdString(k->name));
    }*/

    cout << "begin class set integ" << endl;
    integ = i;

    ui->comboBox->clear();

    QString qstra;
    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (unsigned i=0; i <integ->students.size(); i++) {
        Students* temp = integ->students.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(integ->activeClass != nullptr && temp == integ->activeClass) {
            text += "<span style='background-color:aqua;'>";
            section = integ->activeClass;
        } else {
            text += "<span>";
        }
        text += "<a href='" + temp->name + "'>" + temp->name + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);
    //ui->textBrowser->setText(qstra);

    ui->comboBox->addItem("None");

    cout << "here in class set integ" << endl;
    for (Students* k : integ->students) {
        cout << k << endl;
        ui->comboBox->addItem(QString::fromStdString(k->name));
    }
    cout << "here" << integ->activeClass << endl;
    if(integ->activeClass == nullptr) {
        //cout << "nullptr" << sizeof(integ->activeClass) << endl;
        cout << "test" << endl;
    }

    if(integ->activeClass != nullptr) {
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(QString::fromStdString(integ->activeClass->name)));
    }
    cout << "end class set integ" << endl;
}



void selectClass::on_pushButton_4_clicked()
{
    newClass *sc= new newClass();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}

void selectClass::on_pushButton_5_clicked()
{
    DataView *sc= new DataView();
    sc->set_integ(integ);

    sc->show();
    this->hide();
}



void selectClass::on_export_2_clicked()
{
    if(section != nullptr){
        ExportHTML::export_csv_section(section);
    }
}

void selectClass::on_comboBox_activated(const QString &arg1)
{
    for (Students* k : integ->students) {
        if (arg1.toStdString() == k->name) {
            section = k;
        }
    }

    if (arg1.toStdString() == "None") {
        section = nullptr;
    }

    set_integ(integ);
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(arg1));
}

void selectClass::on_pushButton_clicked()
{
    if (section != nullptr) {
        integ->set_active_class(section);
        classView *sc= new classView();
        sc->set_integ(integ, section);

        sc->show();
        this->hide();
    }
}

void selectClass::on_pushButton_2_clicked()
{
    if (section != nullptr) {
        integ->delete_class(section);
        set_integ(integ);
    }
}

void selectClass::on_pushButton_3_clicked()
{
    if (section != nullptr) {
        integ->set_active_class(section);
        set_integ(integ);
    }
}

void selectClass::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    string url = arg1.url().toStdString();
    //cout << "URL" << url << endl;
    for(unsigned i = 0; i < integ->students.size(); i++) {
        Students* temp = integ->students.at(i);
        if(temp->name == url) {
            integ->set_active_class(temp);
            section = temp;
        }
    }
    this->set_integ(integ);
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(QString::fromStdString(url)));
}
