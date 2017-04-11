#ifndef ASSIGNMENTVIEW_H
#define ASSIGNMENTVIEW_H

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

private:
    Ui::assignmentView *ui;
};

#endif // ASSIGNMENTVIEW_H
