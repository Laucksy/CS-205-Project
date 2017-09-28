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
    void set_integ(Integration* integ, Students* s);
//    void set_integ(Integration* integ, Student* stu);
//    void set_integ(Integration* integ, Students* s, Student* stu);
    void get_data();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newStudent *ui;
    Integration* integ;
    Students* sec;
//    Student* stu;
    string n;
    bool classEdit;
//    bool edit;
};

#endif // NEWSTUDENT_H
