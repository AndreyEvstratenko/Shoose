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

    /*QSqlQuery q("INSERT INTO shoose (name, brand, size, count) VALUES ('Air', 'Nike', 38, 11)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Air', 'Nike', 39, 10)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Air', 'Nike', 40, 14)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Air', 'Nike', 41, 3)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Air', 'Nike', 42, 8)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Air', 'Nike', 43, 4)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Air', 'Nike', 44, 2)");
    
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Jordan', 'Nike', 38, 3)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Jordan', 'Nike', 39, 5)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Jordan', 'Nike', 40, 16)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Jordan', 'Nike', 41, 11)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Jordan', 'Nike', 42, 13)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Jordan', 'Nike', 43, 6)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Jordan', 'Nike', 44, 1)");
    
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Campus', 'Adidas', 38, 23)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Campus', 'Adidas', 39, 14)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Campus', 'Adidas', 40, 10)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Campus', 'Adidas', 41, 9)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Campus', 'Adidas', 42, 10)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Campus', 'Adidas', 43, 7)");
    QSqlQuery ("INSERT INTO shoose (name, brand, size, count) VALUES ('Campus', 'Adidas', 44, 5)");
    
    QSqlQuery z("INSERT INTO shoose (name, brand, size, count) VALUES ('Gazel', 'Adidas', 38, 11)");*/
    
    
    QSqlQuery v("SELECT * FROM shoose");
    while(v.next())
    {
        qDebug()<<v.value(0).toString()<<v.value(1).toString()<<v.value(2).toString();
    }


    //db.close();

    return a.exec();
}
