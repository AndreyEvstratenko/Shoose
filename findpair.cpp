#include "findpair.h"
#include "qsqlrecord.h"
#include "ui_findpair.h"

#include <QSqlQuery>
#include <QSqlQueryModel>

FindPair::FindPair(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindPair)
{
    ui->setupUi(this);
    auto model = new QSqlQueryModel;
    ui->tableView->setModel(model);
    model->setQuery("SELECT * FROM shoose WHERE FALSE");
    model->insertRow(model->rowCount());
    auto index = model->index(model->rowCount(),0);
    qDebug()<<model->setData(index, QVariant(), Qt::EditRole);

}

FindPair::~FindPair()
{
    delete ui;
}
