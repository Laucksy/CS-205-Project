#ifndef SELECTRUBRIC_H
#define SELECTRUBRIC_H
#include "../Integration/integration.h"

#include <QWidget>

namespace Ui {
class selectRubric;
}

class selectRubric : public QWidget
{
    Q_OBJECT

public:
    explicit selectRubric(QWidget *parent = 0);
    ~selectRubric();
void set_integ(Integration* integ);
private slots:
void on_pushButton_5_clicked();

void on_pushButton_4_clicked();

private:
    Ui::selectRubric *ui;
    Integration* integ;
};

#endif // SELECTRUBRIC_H
