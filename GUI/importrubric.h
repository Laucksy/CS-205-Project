#ifndef IMPORTRUBRIC_H
#define IMPORTRUBRIC_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class importRubric;
}

class importRubric : public QWidget
{
    Q_OBJECT

public:
    explicit importRubric(QWidget *parent = 0);
    ~importRubric();
    void set_integ(Integration* integ);

    void import_rubric();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::importRubric *ui;
    Integration* integ;
    string path;
};

#endif // IMPORTRUBRIC_H
