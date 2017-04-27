#include "addcategory.h"
#include "ui_addcategory.h"
#include "rubrics.h"
#include "dataview.h"

/*AddCategory adds a category to a Rubric within the GUI.
 * */

//constructor sets up UI
AddCategory::AddCategory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCategory)
{
    ui->setupUi(this);
    cat = nullptr;

}

//destructor deletes UI
AddCategory::~AddCategory()
{
    delete ui;
}

void AddCategory::set_integ(Integration *i, Rubric* r)
{
    integ = i;
    rubric = r;

    ui->comboBox->clear();

    QString qstra;
    /*string text;
    for (int i=0; i <rubric->name.size(); i++) {
        text += rubric->name[i] + " | " + to_string(rubric->cat[i]->pts) + "\n";
    }
    qstr = QString::fromStdString(text);

    ui->textBrowser->setText(qstr);*/

    string text = "<html><head><style>a {text-decoration: none; color: black;}</style></head><body>";
    // ui->comboBox->addItem("None");
    for (int i=0; i < rubric->cat.size(); i++) {
        Category* temp = rubric->cat.at(i);
        // Rubric* temp = integ->rubrics.at(i);
        if(temp == cat) {
            text += "<span style='background-color:aqua;'>";
        } else {
            text += "<span>";
        }
        text += "<a href='" + rubric->name.at(i) + "'>" + rubric->name[i] + " | " + to_string(rubric->cat[i]->pts) + "</a></span><br/>";
        // text += integ->activeClass->list[i]->name + "\n";
    }
    text += "</body></html>";
    qstra = QString::fromStdString(text);
    ui->textBrowser->setHtml(qstra);

    //cat = nullptr;

    ui->comboBox->addItem("None");

    for (string k : r->name) {
        ui->comboBox->addItem(QString::fromStdString(k));
    }

}

void AddCategory::on_pushButton_clicked()
{
    Rubrics *rv= new Rubrics();
    rv->set_integ(integ, rubric);

    rv->show();
    this->hide();
}

void AddCategory::on_pushButton_2_clicked()
{
    DataView *rv= new DataView();
    rv->set_integ(integ);

    rv->show();
    this->hide();
}


void AddCategory::on_comboBox_activated(const QString &arg1)
{
    int ind = -1;
    for (int i = 0; i < rubric->name.size(); i++) {
        if (arg1.toStdString() == rubric->name[i]) {
            ind = i;
        }
    }

    if (ind != -1) {
        cat = rubric->cat[ind];
    } else {
        cat = nullptr;
    }

    set_integ(integ, rubric);
}

void AddCategory::on_pushButton_4_clicked()
{
    if (cat != nullptr) {
        integ->delete_category(cat);
        set_integ(integ, rubric);
    }
}

void AddCategory::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    string url = arg1.url().toStdString();
    //cout << "URL" << url << endl;
    for(unsigned i = 0; i < rubric->cat.size(); i++) {
        Category* temp = rubric->cat.at(i);
        if(rubric->name.at(i) == url) {
            cat = temp;
        }
    }
    this->set_integ(integ, rubric);
}
