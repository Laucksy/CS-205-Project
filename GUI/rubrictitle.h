#ifndef RUBRICTITLE_H
#define RUBRICTITLE_H

#include <QWidget>
#include "../Integration/integration.h"

namespace Ui {
class RubricTitle;
}

class RubricTitle : public QWidget
{
    Q_OBJECT

public:
    explicit RubricTitle(QWidget *parent = 0);
    ~RubricTitle();

    //fills in the inegration slot
    void set_integ(Integration* i);

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_clicked(bool checked);

private:
    void get_data();

    Ui::RubricTitle *ui;
    Integration* integ;

    bool d;
    string n;
};

#endif // RUBRICTITLE_H
