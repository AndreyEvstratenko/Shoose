#include "modelsofbrand.h"
#include "ui_modelsofbrand.h"

#include <QSqlQueryModel>

ModelsOfBrand::ModelsOfBrand(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModelsOfBrand)
{
    ui->setupUi(this);
    QSqlQueryModel * model = new QSqlQueryModel;
    model->setQuery("SELECT brand, COUNT(DISTINCT name) AS name, SUM(count) AS count FROM shoose GROUP BY brand");
    ui->tableView->setModel(model);
}

ModelsOfBrand::~ModelsOfBrand()
{
    delete ui;
}
