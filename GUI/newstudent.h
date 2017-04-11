#ifndef NEWSTUDENT_H
#define NEWSTUDENT_H

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

private:
    Ui::newStudent *ui;
};

#endif // NEWSTUDENT_H
