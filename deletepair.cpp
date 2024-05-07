#include "deletepair.h"
#include "ui_deletepair.h"

DeletePair::DeletePair(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeletePair)
{
    ui->setupUi(this);
}

DeletePair::~DeletePair()
{
    delete ui;
}
