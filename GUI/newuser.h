#ifndef NEWUSER_H
#define NEWUSER_H
#include "mainwindow.h"

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewUser *ui;
};

#endif // NEWUSER_H
