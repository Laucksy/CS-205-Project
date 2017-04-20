#ifndef SUDENTSUBDIRECTORY_H
#define SUDENTSUBDIRECTORY_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class sudentSubDirectory;
}

class sudentSubDirectory : public QWidget
{
    Q_OBJECT

public:
    explicit sudentSubDirectory(QWidget *parent = 0);
    ~sudentSubDirectory();
    void set_integ(Integration* integ);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sudentSubDirectory *ui;
    Integration* integ;
};

#endif // SUDENTSUBDIRECTORY_H
