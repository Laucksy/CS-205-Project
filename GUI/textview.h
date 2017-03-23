#ifndef TEXTVIEW_H
#define TEXTVIEW_H

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



private slots:


    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::textView *ui;
};

#endif // TEXTVIEW_H
