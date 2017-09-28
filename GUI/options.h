#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>
#include "../git/git.h"
#include "mainwindow.h"

namespace Ui {
class Options;
}

class Options : public QWidget
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();
    void set_integ(Integration* i);

private slots:
    void on_submitButton_clicked();

private:
    Ui::Options *ui;
    Integration* integ;
};

#endif // OPTIONS_H
