#ifndef GITMANAGER_H
#define GITMANAGER_H
#include "../Integration/integration.h"
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class gitManager;
}

class gitManager : public QWidget
{
    Q_OBJECT

public:
    explicit gitManager(QWidget *parent = 0);
    ~gitManager();
    void set_integ(Integration* i);

private slots:
    void on_local_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gitManager *ui;
    Integration* integ;
};

#endif // GITMANAGER_H
