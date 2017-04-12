#ifndef NEWSUBMISSION_H
#define NEWSUBMISSION_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class newSubmission;
}

class newSubmission : public QWidget
{
    Q_OBJECT

public:
    explicit newSubmission(QWidget *parent = 0);
    ~newSubmission();
    void set_integ(Integration* integ);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::newSubmission *ui;
    Integration* integ;
};

#endif // NEWSUBMISSION_H
