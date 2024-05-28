#include "addpair.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include "ui_addpair.h"

#include <QSqlQueryModel>
#include <QStandardItemModel>
#include <QMessageBox>

AddPair::AddPair(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPair)
{
    ui->setupUi(this);
    QSqlQueryModel queryModel;
    queryModel.setQuery("SELECT * FROM shoose");
    headerModel = new QStandardItemModel(1, queryModel.columnCount()-1);
    for (int i = 0; i < queryModel.columnCount()-1; ++i) {
        headerModel->setHeaderData(i, Qt::Horizontal, queryModel.headerData(i+1, Qt::Horizontal).toString());
    }
    ui->tableView->setModel(headerModel);
}

AddPair::~AddPair()
{
    delete ui;
}

void AddPair::on_buttonBox_accepted()
{
    if (!success())
    {
        QMessageBox::critical(nullptr,"Заголовок", "Таблица не заполнена");
        return;
    }

    QStringList headers;
    QStringList values;
    for(int i = 0; i < headerModel->columnCount(); i++)
    {
        headers << headerModel->headerData(i, Qt::Horizontal).toString();
        values << headerModel->item(0, i)->text();
    }
    QString q = "INSERT INTO shoose ("+headers.join(", ")+") VALUES ("+values.join(", ")+")";
    QSqlQuery query;
    if (!query.exec(q))
    {
        qDebug() << query.lastError().text() << query.lastQuery();
    }
    else QMessageBox::information(nullptr, "Title", "Text");
}

bool AddPair::success() const
{
    for(int i = 0; i< headerModel->columnCount(); i++)
    {
        auto index = headerModel->index(0,i);
        auto str = headerModel->data(index).toString();
        if (str.isEmpty()) return false;
    }
    return true;
}

