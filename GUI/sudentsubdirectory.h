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
    void set_integ(Integration* integ, Assignment* assign);
    void set_integ(Integration* integ, Assignment* assign, Assignments* assignments);
    void import_dir();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::sudentSubDirectory *ui;
    Integration* integ;
    Assignment* assign;
    bool assignEdit;
    Assignments* assignment;
    string path;
};

#endif // SUDENTSUBDIRECTORY_H
