#ifndef FINDPAIR_H
#define FINDPAIR_H

#include <QDialog>

namespace Ui {
class FindPair;
}

class FindPair : public QDialog
{
    Q_OBJECT

public:
    explicit FindPair(QWidget *parent = nullptr);
    ~FindPair();

private:
    Ui::FindPair *ui;
};

#endif // FINDPAIR_H
