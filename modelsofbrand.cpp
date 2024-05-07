#include "modelsofbrand.h"
#include "ui_modelsofbrand.h"

ModelsOfBrand::ModelsOfBrand(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModelsOfBrand)
{
    ui->setupUi(this);
}

ModelsOfBrand::~ModelsOfBrand()
{
    delete ui;
}
