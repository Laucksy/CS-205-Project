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
    void set_integ(Integration* integ, Assignment* assign, Assignments* assignments);

private slots:
    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_addDirectoryButton_clicked();

    void on_addFileButton_clicked();

private:
    Ui::submissionView *ui;
    Integration* integ;
    Assignment* assign;
    Code* code;
    bool assignEdit;
    Assignments* assignment;
};

#endif // SUBMISSIONVIEW_H
