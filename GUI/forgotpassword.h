#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class ForgotPassword;
}

class ForgotPassword : public QWidget
{
    Q_OBJECT

public:
    explicit ForgotPassword(QWidget *parent = 0);
    ~ForgotPassword();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ForgotPassword *ui;
};

#endif // FORGOTPASSWORD_H
