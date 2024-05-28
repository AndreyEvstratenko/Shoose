#ifndef DELETEPAIR_H
#define DELETEPAIR_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class DeletePair;
}

class DeletePair : public QDialog
{
    Q_OBJECT

public:
    explicit DeletePair(QWidget *parent = nullptr);
    ~DeletePair();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DeletePair *ui;
    QStandardItemModel *headerModel;
    bool success() const;
};

#endif // DELETEPAIR_H
