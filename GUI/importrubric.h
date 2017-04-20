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

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::importRubric *ui;
    Integration* integ;
};

#endif // IMPORTRUBRIC_H
