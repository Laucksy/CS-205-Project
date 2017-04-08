#ifndef ADDCATEGORY_H
#define ADDCATEGORY_H

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddCategory *ui;
};

#endif // ADDCATEGORY_H
