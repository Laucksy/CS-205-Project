#ifndef NEWASSIGNMENT_H
#define NEWASSIGNMENT_H

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

private:
    Ui::newAssignment *ui;
};

#endif // NEWASSIGNMENT_H
