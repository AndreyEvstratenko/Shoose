#include "findpair.h"
#include "qsqlrecord.h"
#include "qtimer.h"
#include "ui_findpair.h"
#include <QSqlQueryModel>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStandardItemModel>

FindPair::FindPair(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindPair)
{
    ui->setupUi(this);
    QSqlQueryModel queryModel;
    queryModel.setQuery("SELECT * FROM shoose");
    QStandardItemModel *headerModel = new QStandardItemModel(1, queryModel.columnCount());
    for (int i = 0; i < queryModel.columnCount(); ++i) {
        headerModel->setHeaderData(i, Qt::Horizontal, queryModel.headerData(i, Qt::Horizontal).toString());
    }
    ui->tableView->setModel(headerModel);
}

FindPair::~FindPair()
{
    delete ui;
}
