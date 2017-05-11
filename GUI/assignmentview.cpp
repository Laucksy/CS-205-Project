#include "assignmentview.h"
#include "ui_assignmentview.h"
#include "dataview.h"
#include "newsubmission.h"
#include "submissionview.h"
#include "selectassignment.h"

/*AssignmentView is a ciew of the submission being graded.
 * */

assignmentView::assignmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::assignmentView)
{
    ui->setupUi(this);
}

assignmentView::~assignmentView()
{
    delete ui;

    submit = nullptr;
}

void assignmentView::set_integ(Integration *i)
{
    cout << "set integ 1" << endl;
    edit = false;
    integ = i;
    assign = integ->activeAssignemnt;

    ui->comboBox->clear();

    QString qstra;
    /*string text;
    for (int i=0; i <assign->list.size(); i++) {
        text += assign->list[i]->stu->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);*/

    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (unsigned i=0; i < assign->list.size(); i++) {
        Assignment* temp = assign->list.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(temp == submit) {
            text += "<span style='background-color:aqua;'>";
        } else {
            text += "<span>";
        }
        text += "<a href='" + temp->stu->name + "'>" + temp->stu->name + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);

    QString qstrb =  QString::fromStdString(assign->name);

    ui->label_2->setText(qstrb);

    ui->comboBox->addItem("None");

    for (Assignment* k : assign->list) {
        ui->comboBox->addItem(QString::fromStdString(k->stu->name));
    }
}

void assignmentView::set_integ(Integration *i, Assignments* a)
{
    cout << "Start set integ" << endl;
    edit = true;
    integ = i;
    assign = a;

    ui->comboBox->clear();

    if(assign ==nullptr) {return;}

    QString qstra;
    /*string text;
    for (int i=0; i <assign->list.size(); i++) {
        text += assign->list[i]->stu->name + "\n";
    }
    qstra = QString::fromStdString(text);

    ui->textBrowser->setText(qstra);*/

    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (unsigned i=0; i < assign->list.size(); i++) {
        Assignment* temp = assign->list.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(temp == submit) {
            text += "<span style='background-color:aqua;'>";
        } else {
            text += "<span>";
        }
        text += "<a href='" + temp->stu->name + "'>" + temp->stu->name + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);

    QString qstrb =  QString::fromStdString(assign->name);

    ui->label_2->setText(qstrb);

    ui->comboBox->addItem("None");

    for (Assignment* k : assign->list) {
        ui->comboBox->addItem(QString::fromStdString(k->stu->name));
    }
    cout << "finished set integ" << endl;
}
void assignmentView::on_pushButton_2_clicked()
{
    integ->set_active_assignment(assign);
    selectAssignment *dv= new selectAssignment();
    dv->set_integ(integ);

    dv->show();
    this->hide();
}

void assignmentView::on_pushButton_clicked()
{
    if (edit) {
        newSubmission*dv= new newSubmission();
        dv->set_integ(integ, assign);

        dv->show();
        this->hide();
    } else {
        newSubmission*dv= new newSubmission();
        dv->set_integ(integ);

        dv->show();
        this->hide();
    }
}

void assignmentView::on_comboBox_activated(const QString &arg1)
{
    for (Assignment* k : integ->activeAssignemnt->list) {
        if (arg1.toStdString() == k->stu->name) {
            submit = k;
        }
    }

    if (arg1.toStdString() == "None") {
        submit = nullptr;
    }

    if (edit) {
        this->set_integ(integ, assign);
    } else {
        this->set_integ(integ);
    }
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(arg1));
}

void assignmentView::on_pushButton_3_clicked()
{
    if(submit != nullptr) {
        integ->delete_submission(submit);
        set_integ(integ);
    }
}

void assignmentView::on_pushButton_4_clicked()
{
    if (submit != nullptr) {
        if (edit) {
            submissionView *dv= new submissionView();
            dv->set_integ(integ, submit, assign);

            dv->show();
            this->hide();
        } else {
            submissionView *dv= new submissionView();
            dv->set_integ(integ, submit);

            dv->show();
            this->hide();
        }
    }
}

void assignmentView::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    string url = arg1.url().toStdString();
    //cout << "URL" << url << endl;
    for(unsigned i = 0; i < assign->list.size(); i++) {
        Assignment* temp = assign->list.at(i);
        if(temp->stu->name == url) {
            submit = temp;
        }
    }
    if (edit) {
        this->set_integ(integ, assign);
    } else {
        this->set_integ(integ);
    }
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(QString::fromStdString(url)));
}
