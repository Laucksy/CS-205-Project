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
    string text;
    for (int i=0; i <assign->files.size(); i++) {
        text += assign->files[i]->fileName + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

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
    string text;
    for (int i=0; i <assign->files.size(); i++) {
        text += assign->files[i]->fileName + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);

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
        set_integ(integ, assign);
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
    integ->add_directory(assign, dir.toStdString()); //Replace path with the file name you get from the file picker
<<<<<<< HEAD
=======
    this->set_integ(integ, assign);
>>>>>>> da8a7533b793b69f1934447523161f003489be02
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
    integ->add_new_file(assign, fn.toStdString()); //Replace fn with the file name you get from the file picker
<<<<<<< HEAD
=======
    this->set_integ(integ, assign);
>>>>>>> da8a7533b793b69f1934447523161f003489be02
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
