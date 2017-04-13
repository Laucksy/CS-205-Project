#ifndef NEWFILE_H
#define NEWFILE_H
#include "../Integration/integration.h"
#include <QWidget>

namespace Ui {
class newFile;
}

class newFile : public QWidget
{
    Q_OBJECT

public:
    explicit newFile(QWidget *parent = 0);
    ~newFile();
    void set_integ(Integration* integ, Assignment* assign);
    void get_data();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::newFile *ui;
    Integration* integ;
    Assignment* assign;
    string fn;
};

#endif // NEWFILE_H
