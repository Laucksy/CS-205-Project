#ifndef NEWSUBMISSION_H
#define NEWSUBMISSION_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class newSubmission;
}

class newSubmission : public QWidget
{
    Q_OBJECT

public:
    explicit newSubmission(QWidget *parent = 0);
    ~newSubmission();
    void set_integ(Integration* integ);
    void set_integ(Integration* integ, Assignments* a);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::newSubmission *ui;
    Integration* integ;
    Student* student;
    Assignments* assign;
    Students* stu;
    bool assignEdit;
};

#endif // NEWSUBMISSION_H
