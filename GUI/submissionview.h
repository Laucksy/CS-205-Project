#ifndef SUBMISSIONVIEW_H
#define SUBMISSIONVIEW_H

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

private:
    Ui::submissionView *ui;
};

#endif // SUBMISSIONVIEW_H
