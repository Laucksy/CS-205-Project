#ifndef SUBMISSIONVIEW_H
#define SUBMISSIONVIEW_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class submissionView;
}

class submissionView : public QWidget
{
    Q_OBJECT

public:
    explicit submissionView(QWidget *parent = 0);
    ~submissionView();
    void set_integ(Integration* integ, Assignment* assign);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::submissionView *ui;
    Integration* integ;
    Assignment* assign;
};

#endif // SUBMISSIONVIEW_H
