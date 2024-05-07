#ifndef DELETEPAIR_H
#define DELETEPAIR_H

#include <QDialog>

namespace Ui {
class DeletePair;
}

class DeletePair : public QDialog
{
    Q_OBJECT

public:
    explicit DeletePair(QWidget *parent = nullptr);
    ~DeletePair();

private:
    Ui::DeletePair *ui;
};

#endif // DELETEPAIR_H
