#ifndef ADDCATEGORY_H
#define ADDCATEGORY_H

#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class AddCategory;
}

class AddCategory : public QWidget
{
    Q_OBJECT

public:
    explicit AddCategory(QWidget *parent = 0);
    ~AddCategory();
    void set_integ(Integration* integ, Rubric* r);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::AddCategory *ui;
    Integration* integ;
    Rubric* rubric;
    Category* cat;
};

#endif // ADDCATEGORY_H
