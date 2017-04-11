#ifndef DATAVIEW_H
#define DATAVIEW_H
#include "textview.h"
#include "rubrics.h"
#include "../Integration/integration.h"

#include <QWidget>

namespace Ui {
class DataView;
}

class DataView : public QWidget
{
    Q_OBJECT

public:
    explicit DataView(QWidget *parent = 0);
    ~DataView();
    void set_integ(Integration* i);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::DataView *ui;
    Integration* integ;
};

#endif // DATAVIEW_H
