#include "addpair.h"
#include "ui_addpair.h"

AddPair::AddPair(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPair)
{
    ui->setupUi(this);
}

AddPair::~AddPair()
{
    delete ui;
}
