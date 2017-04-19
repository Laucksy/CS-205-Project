#ifndef ASSIGNMENTVIEW_H
#define ASSIGNMENTVIEW_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class assignmentView;
}

class assignmentView : public QWidget
{
    Q_OBJECT

public:
    explicit assignmentView(QWidget *parent = 0);
    ~assignmentView();
    void set_integ(Integration* integ);
    void set_integ(Integration* integ, Assignments* a);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::assignmentView *ui;
    Integration* integ;
    Assignment* submit;
    Assignments* assign;
    bool edit;
};

#endif // ASSIGNMENTVIEW_H
