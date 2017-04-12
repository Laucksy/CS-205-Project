#ifndef NEWASSIGNMENT_H
#define NEWASSIGNMENT_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class newAssignment;
}

class newAssignment : public QWidget
{
    Q_OBJECT

public:
    explicit newAssignment(QWidget *parent = 0);
    ~newAssignment();
    void set_integ(Integration* integ);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newAssignment *ui;
    Integration* integ;
};

#endif // NEWASSIGNMENT_H
