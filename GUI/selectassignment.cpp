#include "selectassignment.h"
#include "ui_selectassignment.h"
#include "newassignment.h"
#include "dataview.h"
#include "assignmentview.h"

selectAssignment::selectAssignment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selectAssignment)
{
    ui->setupUi(this);
}

selectAssignment::~selectAssignment()
{
    delete ui;

    assign = nullptr;
}

void selectAssignment::set_integ(Integration *i)
{
    integ = i;

    ui->comboBox->clear();

    QString qstra;
    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (unsigned i=0; i <integ->assignments.size(); i++) {
        Assignments* temp = integ->assignments.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(integ->activeAssignemnt != nullptr && temp == integ->activeAssignemnt) {
            text += "<span style='background-color:aqua;'>";
            assign = integ->activeAssignemnt;
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

    for (Assignments* k : integ->assignments) {
        ui->comboBox->addItem(QString::fromStdString(k->name));
    }

    cout << "here in assignment" << endl;
    if(integ->activeAssignemnt != nullptr) {
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(QString::fromStdString(integ->activeAssignemnt->name)));
    }


}

void selectAssignment::on_pushButton_4_clicked()
{
    newAssignment *dv= new newAssignment();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void selectAssignment::on_pushButton_5_clicked()
{
    DataView *dv= new DataView();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}



void selectAssignment::on_export_2_clicked()
{
    if(assign != nullptr){
        ExportHTML::export_csv_assignment(assign);
    }
}

void selectAssignment::on_comboBox_activated(const QString &arg1)
{
    for (Assignments* k : integ->assignments) {
        if (arg1.toStdString() == k->name) {
            assign = k;
            integ->set_active_assignment(k);
        }
    }

    if (arg1.toStdString() == "None") {
        assign = nullptr;
    }

    set_integ(integ);
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(arg1));
}

void selectAssignment::on_pushButton_2_clicked()
{
    if (assign != nullptr) {
        integ->delete_assignment(assign);
        set_integ(integ);
    }
}

void selectAssignment::on_pushButton_3_clicked()
{
    if (assign != nullptr) {
        integ->set_active_assignment(assign);
    }
}

void selectAssignment::on_pushButton_clicked()
{
    if (assign != nullptr) {
        cout << "Crash edit" << endl;
        integ->set_active_assignment(assign);
        cout << "Here 1" << endl;
        assignmentView *dv= new assignmentView();
        cout << "Here 2" << endl;
        dv->set_integ(integ, assign);
        cout << "Here 3" << endl;
        integ->set_active_assignment(assign);

        cout << "Didn't crash edit" << endl;
        dv->show();
        this->hide();
    }
}

/*void selectAssignment::on_textBrowser_cursorPositionChanged()
{
    int line = ui->textBrowser->textCursor().blockNumber();
}

void selectAssignment::on_textBrowser_mousePressEvent(QMouseEvent* e) {
    if (e->button() == Qt::LeftButton) {
        cout << ui->textBrowser->textCursor().blockNumber() << "AAAA" << endl;
    }
}*/

void selectAssignment::on_textBrowser_anchorClicked(const QUrl &arg1) {
    string url = arg1.url().toStdString();
    //cout << "URL" << url << endl;
    for(unsigned i = 0; i < integ->assignments.size(); i++) {
        Assignments* temp = integ->assignments.at(i);
        if(temp->name == url) {
            integ->set_active_assignment(temp);
            assign = temp;
        }
    }
    this->set_integ(integ);
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(QString::fromStdString(url)));
}
