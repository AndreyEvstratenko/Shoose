#include "deletepair.h"
#include "qsqlerror.h"
#include "ui_deletepair.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStandardItemModel>

DeletePair::DeletePair(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeletePair)
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

DeletePair::~DeletePair()
{
    delete ui;
}

void DeletePair::on_buttonBox_accepted()
{
    QString q = "DELETE FROM shoose WHERE true";
    for (int i = 0; i < headerModel->columnCount(); ++i) {
        auto index = headerModel->index(0,i);
        auto str = headerModel->data(index).toString();
        if (str.isEmpty()) continue;
        auto header = headerModel->headerData(i, Qt::Horizontal).toString();
        q += (" AND "+header+" = '"+str+"'");
    }
    QSqlQuery query;
    if (!query.exec(q))
    {
        QMessageBox::critical(nullptr,"Не удалось отправить запрос на удаление", query.lastError().text());
        return;
    }

    if (query.numRowsAffected()==0)
    {
        QMessageBox::warning(nullptr, "Нет удаленных строк", query.lastQuery());
        return;
    }
    QMessageBox::information(nullptr, "Успех", "Было удалено " +QString::number(query.numRowsAffected())+ " записей");
}


