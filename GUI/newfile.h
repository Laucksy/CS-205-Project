#ifndef NEWFILE_H
#define NEWFILE_H

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

private:
    Ui::newFile *ui;
};

#endif // NEWFILE_H
