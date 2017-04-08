#ifndef RUBRICTITLE_H
#define RUBRICTITLE_H

#include <QWidget>

namespace Ui {
class RubricTitle;
}

class RubricTitle : public QWidget
{
    Q_OBJECT

public:
    explicit RubricTitle(QWidget *parent = 0);
    ~RubricTitle();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::RubricTitle *ui;
};

#endif // RUBRICTITLE_H
