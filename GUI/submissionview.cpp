#include "submissionview.h"
#include "ui_submissionview.h"
#include "newsubmission.h"
#include "newfile.h"
#include "assignmentview.h"
#include "sudentsubdirectory.h"
#include <QFileDialog>

submissionView::submissionView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::submissionView)
{
    ui->setupUi(this);
}

submissionView::~submissionView()
{
    delete ui;
}

void submissionView::set_integ(Integration *i, Assignment* a)
{
    integ = i;
    assign = a;
    assignment= nullptr;
    assignEdit = false;

    ui->comboBox->clear();

    QString qstra;
    /*string text;
    for (int i=0; i <assign->files.size(); i++) {
        text += assign->files[i]->fileName + "\n";
    }
    qstra = QString::fromStdString(text);*/

    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (int i=0; i < assign->files.size(); i++) {
        Code* temp = assign->files.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(temp == code) {
            text += "<span style='background-color:aqua;'>";
        } else {
            text += "<span>";
        }
        text += "<a href='" + temp->fileName + "'>" + temp->fileName + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);

    //ui->textBrowser->setText(qstra);

    code = nullptr;

    ui->comboBox->addItem("None");

    for (Code* k : a->files) {
        ui->comboBox->addItem(QString::fromStdString(k->fileName));
    }
}

void submissionView::set_integ(Integration *i, Assignment* a, Assignments* as)
{
    integ = i;
    assign = a;
    assignment= as;
    assignEdit = true;

    ui->comboBox->clear();

    QString qstra;
    /*string text;
    for (int i=0; i <assign->files.size(); i++) {
        text += assign->files[i]->fileName + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);*/

    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (int i=0; i < assign->files.size(); i++) {
        Code* temp = assign->files.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(temp == code) {
            text += "<span style='background-color:aqua;'>";
        } else {
            text += "<span>";
        }
        text += "<a href='" + temp->fileName + "'>" + temp->fileName + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);

    code = nullptr;

    ui->comboBox->addItem("None");

    for (Code* k : a->files) {
        ui->comboBox->addItem(QString::fromStdString(k->fileName));
    }
}

void submissionView::on_pushButton_2_clicked()
{
    if (assignEdit) {
        assignmentView *dv= new assignmentView();
        dv->set_integ(integ, assignment);

        dv->show();
        this->hide();
    } else {
        assignmentView *dv= new assignmentView();
        dv->set_integ(integ);

        dv->show();
        this->hide();
    }
}

void submissionView::on_comboBox_activated(const QString &arg1)
{
    for (Code* k : assign->files) {
        if (arg1.toStdString() == k->fileName) {
            code = k;
        }
    }

    if (arg1.toStdString() == "None") {
        code = nullptr;
    }
}

void submissionView::on_pushButton_3_clicked()
{
    if (code != nullptr) {
        integ->delete_file(code);
        if (!assignEdit) {
            set_integ(integ, assign);
        } else {
            set_integ(integ, assign, assignment);
        }
    }
}

void submissionView::on_addDirectoryButton_clicked()
{
    //Insert your code here
    //QString path = QFileDialog::getOpenFileName(this,tr("Open Rubric to Import"),"C://",tr("Txt (*.txt)");
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "C://",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    cout << dir.toStdString() << endl;
    integ->add_directory(assign, dir.toStdString()); //Replace path with the file name you get from the file picker
    if (!assignEdit) {
        set_integ(integ, assign);
    } else {
        set_integ(integ, assign, assignment);
    }

    //   sudentSubDirectory *dv= new sudentSubDirectory();
//    if (assignEdit) {
//        dv->set_integ(integ, assign,assignment);
//    } else {
//        dv->set_integ(integ, assign);
//    }

//    dv->show();
//    this->hide();
}

void submissionView::on_addFileButton_clicked()
{
    //Insert your code here
    QString fn = QFileDialog::getOpenFileName(this,tr("Select File to Add"),"C://",tr("Any files (*)"));
    cout << fn.toStdString() << endl;
    integ->add_new_file(assign, fn.toStdString()); //Replace fn with the file name you get from the file picker
    if (!assignEdit) {
        set_integ(integ, assign);
    } else {
        set_integ(integ, assign, assignment);
    }
    /*if (assignEdit) {
        newFile *dv= new newFile();
        dv->set_integ(integ, assign, assignment);

        dv->show();
        this->hide();
    } else {
        newFile *dv= new newFile();
        dv->set_integ(integ, assign);

        dv->show();
        this->hide();
    }*/
}

void submissionView::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    string url = arg1.url().toStdString();
    //cout << "URL" << url << endl;
    for(unsigned i = 0; i < assign->files.size(); i++) {
        Code* temp = assign->files.at(i);
        if(temp->fileName == url) {
            code = temp;
        }
    }
    this->set_integ(integ, assign);
}
