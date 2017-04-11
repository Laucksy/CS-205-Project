#ifndef NEWSUBMISSION_H
#define NEWSUBMISSION_H

#include <QWidget>

namespace Ui {
class newSubmission;
}

class newSubmission : public QWidget
{
    Q_OBJECT

public:
    explicit newSubmission(QWidget *parent = 0);
    ~newSubmission();

private:
    Ui::newSubmission *ui;
};

#endif // NEWSUBMISSION_H
