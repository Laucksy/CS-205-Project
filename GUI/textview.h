#ifndef TEXTVIEW_H
#define TEXTVIEW_H
#include "../project/code.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <QWidget>

namespace Ui {
class textView;
}

class textView : public QWidget
{
    Q_OBJECT

public:
    explicit textView(QWidget *parent = 0);
    ~textView();
    void updateCode(int);

    std::string student;



private slots:




    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);



private:
    Ui::textView *ui;
};

#endif // TEXTVIEW_H
