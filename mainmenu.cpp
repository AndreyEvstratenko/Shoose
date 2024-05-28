#include "mainmenu.h"
#include "ui_mainmenu.h"

#include "addpair.h"
#include "chart.h"
#include "deletepair.h"
#include "findpair.h"
#include "modelsofbrand.h"



MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_addPair_clicked()
{
    auto dialog = new AddPair(this);
    dialog->exec();
}


void MainMenu::on_findPair_clicked()
{
    auto dialog = new FindPair(this);
    dialog->exec();
}


void MainMenu::on_deletPair_clicked()
{
    auto dialog = new DeletePair(this);
    dialog->exec();
}


void MainMenu::on_modelsOfBrand_clicked()
{
    auto dialog = new ModelsOfBrand(this);
    dialog->exec();
}


void MainMenu::on_chart_clicked()
{
    auto dialog = new Chart(this);
    dialog->exec();
}

