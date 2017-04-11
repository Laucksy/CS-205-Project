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

private:
    Ui::classView *ui;
    Integration *integ;
};

#endif // CLASSVIEW_H
