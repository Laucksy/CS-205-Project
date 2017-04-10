#ifndef NEWUSER_H
#define NEWUSER_H
#include "mainwindow.h"
#include "../Integration/integration.h"

#include <QWidget>

namespace Ui {
class NewUser;
}

class NewUser : public QWidget
{
    Q_OBJECT

public:
    explicit NewUser(QWidget *parent = 0);
    ~NewUser();
    void set_integ(Integration* integ);

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewUser *ui;
    Integration* integ;
};


#endif // NEWUSER_H
