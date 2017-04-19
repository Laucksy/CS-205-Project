#ifndef SELECTASSIGNMENT_H
#define SELECTASSIGNMENT_H
#include "../Integration/integration.h"
#include "../export/exporthtml.h"
#include <QWidget>

namespace Ui {
class selectAssignment;
}

class selectAssignment : public QWidget
{
    Q_OBJECT

public:
    explicit selectAssignment(QWidget *parent = 0);
    ~selectAssignment();
    void set_integ(Integration* integ);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();



    void on_export_2_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::selectAssignment *ui;
    Integration* integ;
    Assignments* assign;
};

#endif // SELECTASSIGNMENT_H
