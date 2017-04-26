#ifndef CLASSVIEW_H
#define CLASSVIEW_H
#include "../Integration/integration.h"

#include <QWidget>

namespace Ui {
class classView;
}

class classView : public QWidget
{
    Q_OBJECT

public:
    explicit classView(QWidget *parent = 0);
    ~classView();
    void set_integ(Integration* integ);
    void set_integ(Integration* integ, Students* s);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_textBrowser_anchorClicked(const QUrl &arg1);

private:
    Ui::classView *ui;
    Integration *integ;
    Students* sec;
    Student* stu;
    bool edit;
};

#endif // CLASSVIEW_H
