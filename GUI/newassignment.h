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
    void get_data();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

private:
    Ui::newAssignment *ui;
    Integration* integ;
    Rubric* rubric;
    Students* stu;
    string name;
};

#endif // NEWASSIGNMENT_H
