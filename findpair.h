#ifndef FINDPAIR_H
#define FINDPAIR_H

#include <QDialog>
#include <QStandardItemModel>
#include <QAbstractButton>

namespace Ui {
class FindPair;
}

class FindPair : public QDialog
{
    Q_OBJECT

public:
    explicit FindPair(QWidget *parent = nullptr);
    ~FindPair();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::FindPair *ui;
    QStandardItemModel *headerModel;
};

#endif // FINDPAIR_H
