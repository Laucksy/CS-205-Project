#ifndef TEXTVIEW_H
#define TEXTVIEW_H
#include "../project/code.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <QWidget>
using namespace std;

namespace Ui {
class textView;
}

class textView : public QWidget
{
    Q_OBJECT

public:
    explicit textView(QWidget *parent = 0);
    ~textView();

    Code* updateCode(Code*);
     void makeComment(Code*);
    string newFeedback;
     Code* myCode=nullptr;
     int commentLoc=0;

    std::string student;



private slots:




    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);



    void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::textView *ui;
};

#endif // TEXTVIEW_H
