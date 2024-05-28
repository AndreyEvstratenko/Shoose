#ifndef ADDPAIR_H
#define ADDPAIR_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class AddPair;
}

class AddPair : public QDialog
{
    Q_OBJECT

public:
    explicit AddPair(QWidget *parent = nullptr);
    ~AddPair();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddPair *ui;
    QStandardItemModel *headerModel;
    bool success() const;
};

#endif // ADDPAIR_H
