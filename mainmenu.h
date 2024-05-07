#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_addPair_clicked();

    void on_findPair_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
