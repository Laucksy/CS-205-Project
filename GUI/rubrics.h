#ifndef RUBRICS_H
#define RUBRICS_H
#include "dataview.h"
#include <vector>
#include <QWidget>
using namespace std;

namespace Ui {
class Rubrics;
}

class Rubrics : public QWidget
{
    Q_OBJECT

public:
    explicit Rubrics(QWidget *parent = 0);
    ~Rubrics();
    vector<string> rubricData;
private slots:
    void on_pushButton_2_clicked();


    void getData();

    void on_checkBox_clicked(bool checked);

private:
    Ui::Rubrics *ui;
};

#endif // RUBRICS_H
