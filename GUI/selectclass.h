#ifndef SELECTCLASS_H
#define SELECTCLASS_H
#include "../Integration/integration.h"
#include "../export/exporthtml.h"
#include <QWidget>

namespace Ui {
class selectClass;
}

class selectClass : public QWidget
{
    Q_OBJECT

public:
    explicit selectClass(QWidget *parent = 0);
    ~selectClass();
void set_integ(Integration* integ);
private slots:
void on_pushButton_4_clicked();

void on_pushButton_5_clicked();



void on_export_2_clicked();

void on_comboBox_activated(const QString &arg1);

private:
    Ui::selectClass *ui;
    Integration* integ;
    Students* section;
};

#endif // SELECTCLASS_H
