#include "findpair.h"
#include "qsqlerror.h"
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
    headerModel = new QStandardItemModel(1, queryModel.columnCount());
    for (int i = 0; i < queryModel.columnCount(); ++i) {
        headerModel->setHeaderData(i, Qt::Horizontal, queryModel.headerData(i, Qt::Horizontal).toString());
    }
    ui->tableView->setModel(headerModel);
}

FindPair::~FindPair()
{
    delete ui;
}

void FindPair::on_buttonBox_accepted()
{

}


void FindPair::on_buttonBox_clicked(QAbstractButton *button)
{
    QString q = "SELECT * FROM shoose WHERE true";
    for (int i = 0; i < headerModel->columnCount(); ++i) {
        auto index = headerModel->index(0,i);
        auto str = headerModel->data(index).toString();
        if (str.isEmpty()) continue;
        auto header = headerModel->headerData(i, Qt::Horizontal).toString();
        q += (" AND "+header+" = '"+str+"'");
    }
    QSqlQueryModel *query = new QSqlQueryModel;
    query->setQuery(q);
    ui->tableView->setModel(query);

}

