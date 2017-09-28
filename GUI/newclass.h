#ifndef NEWCLASS_H
#define NEWCLASS_H
#include "../Integration/integration.h"

#include <QWidget>

namespace Ui {
class newClass;
}

class newClass : public QWidget
{
    Q_OBJECT

public:
    explicit newClass(QWidget *parent = 0);
    ~newClass();
    void set_integ(Integration* integ);
    void get_data();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newClass *ui;
    Integration *integ;
    string name;
};

#endif // NEWCLASS_H
