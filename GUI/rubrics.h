#ifndef RUBRICS_H
#define RUBRICS_H
#include "dataview.h"

#include <QWidget>

namespace Ui {
class Rubrics;
}

class Rubrics : public QWidget
{
    Q_OBJECT

public:
    explicit Rubrics(QWidget *parent = 0);
    ~Rubrics();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Rubrics *ui;
};

#endif // RUBRICS_H
