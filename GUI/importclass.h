#ifndef IMPORTCLASS_H
#define IMPORTCLASS_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class importClass;
}

class importClass : public QWidget
{
    Q_OBJECT

public:
    explicit importClass(QWidget *parent = 0);
    ~importClass();
    void set_integ(Integration* integ);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::importClass *ui;
    Integration* integ;
};

#endif // IMPORTCLASS_H
