#ifndef ADDPAIR_H
#define ADDPAIR_H

#include <QDialog>

namespace Ui {
class AddPair;
}

class AddPair : public QDialog
{
    Q_OBJECT

public:
    explicit AddPair(QWidget *parent = nullptr);
    ~AddPair();

private:
    Ui::AddPair *ui;
};

#endif // ADDPAIR_H
