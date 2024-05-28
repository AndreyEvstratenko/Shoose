#ifndef CHART_H
#define CHART_H

#include <QDialog>
#include <QWidget>

class Chart : public QDialog
{
    Q_OBJECT
public:
    explicit Chart(QWidget *parent = nullptr);

signals:
};

#endif // CHART_H
