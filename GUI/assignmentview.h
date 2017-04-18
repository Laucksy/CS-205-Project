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
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::assignmentView *ui;
    Integration* integ;
    Assignment* submit;
};

#endif // ASSIGNMENTVIEW_H
