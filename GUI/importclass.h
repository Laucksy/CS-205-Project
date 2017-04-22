#ifndef IMPORTCLASS_H
#define IMPORTCLASS_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class importClass;
}

class importClass : public QWidget
{
    Q_OBJECT

public:
    explicit importClass(QWidget *parent = 0);
    ~importClass();
    void set_integ(Integration* integ);
    void set_integ(Integration* integ, Students* s);

    void import_students();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::importClass *ui;
    Integration* integ;
    Students* section;
    bool edit;
    string path;
};

#endif // IMPORTCLASS_H
