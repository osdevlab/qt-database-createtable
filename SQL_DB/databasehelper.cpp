#include "databasehelper.h"
#include <QDebug>

DatabaseHelper::DatabaseHelper() //default constructor
{
    //needed it in constructor otherwise, database can't be opened from other function call; werid
    myDataBase = QSqlDatabase::addDatabase("QSQLITE"); //QSLITE must be exact
}

bool DatabaseHelper::setDataBasePath(QString filename) {

//another file *.db will be created if the file is not presented on the system
    QString dbPath = QCoreApplication::applicationDirPath() + "/" + filename
            + ".db";
    myDataBase.setDatabaseName(dbPath);
    if (myDataBase.open()) {

        qDebug() << "databased is opened sucessfully ";
        return true;
    } else {
        qDebug() << "failed to open databased";
        return false;
    }
}

bool DatabaseHelper::createTable() {
    if (myDataBase.isOpen()) {

        QSqlQuery query(myDataBase);
        //you can use "create table if not exists" but it will be always
        //successful to execute this following command

        //Name of table cannot be variable//
        //so have to hard code it//
        //it is just sqlite way//
        bool ret = query.exec("create table studentTable"
                "(id integer primary key, "
                "firstname varchar(20), "
                "lastname varchar(30), "
                "age integer)");

        if (ret) {
            qDebug() << "table created";
            return true;
        } else {
            qDebug() << "faied to crate table";
            return false;
        }
    } else {
        return false;
    }
}

bool DatabaseHelper::dropTable() {

    if (myDataBase.isOpen()) {
        QSqlQuery query(myDataBase);
        bool ret = query.exec("drop table studentTable");

        if (ret) {
            qDebug() << "table dropped";
            return true;
        } else {
            qDebug() << "faied to drop the table";
            return false;
        }
    } else {
        return false; //return false if failed to open database
    }
}

DatabaseHelper::~DatabaseHelper() //default deconstructor
{

}

