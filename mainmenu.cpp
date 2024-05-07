#include "mainmenu.h"
#include "ui_mainmenu.h"

#include "addpair.h"
#include "findpair.h"

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

