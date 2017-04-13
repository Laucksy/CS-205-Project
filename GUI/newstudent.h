#ifndef NEWSTUDENT_H
#define NEWSTUDENT_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class newStudent;
}

class newStudent : public QWidget
{
    Q_OBJECT

public:
    explicit newStudent(QWidget *parent = 0);
    ~newStudent();
    void set_integ(Integration* integ);
    void get_data();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newStudent *ui;
    Integration* integ;
    string fn;
    string ln;
};

#endif // NEWSTUDENT_H
