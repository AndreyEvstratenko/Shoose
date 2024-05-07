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
    model->setQuery("SELECT * FROM shoose");
}

FindPair::~FindPair()
{
    delete ui;
}
