#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../Integration/integration.h"
#include <QMainWindow>
#include "textview.h"
#include "dataview.h"

#include "options.h"

#include "../git/git.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set_integ(Integration* integ);
    //fills in the inegration slot
    //void set_integ(Integration* i);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_optionsButton_clicked();

private:
    Ui::MainWindow *ui;
    Integration* integ;

};

#endif // MAINWINDOW_H
