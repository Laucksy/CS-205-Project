#ifndef SELECTASSIGNMENT_H
#define SELECTASSIGNMENT_H
#include "../Integration/integration.h"

#include <QWidget>

namespace Ui {
class selectAssignment;
}

class selectAssignment : public QWidget
{
    Q_OBJECT

public:
    explicit selectAssignment(QWidget *parent = 0);
    ~selectAssignment();
    void set_integ(Integration* integ);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::selectAssignment *ui;
    Integration* integ;
};

#endif // SELECTASSIGNMENT_H
