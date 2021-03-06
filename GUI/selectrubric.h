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

void on_comboBox_activated(const QString &arg1);

void on_pushButton_clicked();

void on_pushButton_2_clicked();

void on_pushButton_3_clicked();

void on_textBrowser_anchorClicked(const QUrl &arg1);

private:
    Ui::selectRubric *ui;
    Integration* integ;
    Rubric* grade;
};

#endif // SELECTRUBRIC_H
