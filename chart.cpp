#include "chart.h"
#include "qsqlerror.h"

#include <QBarCategoryAxis>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QChartView>
#include <QLineEdit>
#include <QPushButton>
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QValueAxis>

Chart::Chart(QWidget *parent)
    : QDialog{parent}
{
    QBarSeries *series = new QBarSeries();
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple bar chart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);


    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 30);
    axisY->setTickCount(16);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    auto l = new QVBoxLayout;
    setLayout(l);
    l->addWidget(chartView);

    auto brand = new QLineEdit;
    auto model = new QLineEdit;
    auto push = new QPushButton("Построить");
    l->addWidget(brand);
    l->addWidget(model);
    l->addWidget(push);

    connect(push, &QPushButton::clicked, [brand, model, this, series, axisX](){
        QSqlQuery q;
        q.prepare("SELECT size, count FROM shoose WHERE brand = ? AND name = ? ORDER BY size ASC");
        q.addBindValue(brand->text());
        q.addBindValue(model->text());
        if (!q.exec())
        {
            qDebug() << q.lastError().text()<<q.lastQuery();
            return;
        }
        QBarSet *set = new QBarSet(brand->text());
        QStringList categories;
        while(q.next())
        {
            *set << q.value(1).toInt();
            categories << QString::number(q.value(0).toInt());
        }
        series->append(set);
        axisX->append(categories);
    });

}
