#include "mainmenu.h"

#include <QApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a SQLite database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("file.db");

    // Check if the database can be opened
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return -1;
    }

    // Execute a SQL query to create a table
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS shoose (id INTEGER PRIMARY KEY, name TEXT, brand TEXT, size INTEGER, count INT)")) {
        qDebug() << "Error creating table:" << query.lastError().text();
        return -1;
    }
    MainMenu mainmenu;
    mainmenu.show();

    QSqlQuery q("INSERT INTO shoose (name, brand, size, count) VALUES ('Air', 'Nike', 38, 11)");



    //db.close();

    return a.exec();
}
