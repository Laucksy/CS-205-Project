#ifndef TEXTVIEW_H
#define TEXTVIEW_H
#include "../project/code.h"
#include "../Integration/integration.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QMouseEvent>

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
    void set_integ(Integration* integ);

    void update_rubric();

    bool writing=false;
    Code* updateCode(Code*);
     void makeComment(Code*);
    string newFeedback;
    string tag;
    int categoryIndex;
     Code* myCode=nullptr;
     int commentLoc=0;

    std::string student;

    QString clickedAnchor;

private slots:




   // void on_comboBox_activated(const QString &arg1);

   // void on_comboBox_2_activated(const QString &arg1);



   // void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();



    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();




    void on_textBrowser_anchorClicked(const QUrl &arg1);

    void mousePressEvent(QMouseEvent *e);

    bool eventFilter(QObject *watched, QEvent *event);

    void on_textBrowser_cursorPositionChanged();
    void clickComment(int pos, Code* myCode);

    void on_pushButton_4_clicked();

private:
    Ui::textView *ui;
    Integration* integ;
};

#endif // TEXTVIEW_H
