#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H
#include <QtSql>

class DatabaseHelper : public QSqlDatabase //inheritance from QSqlDatabase
{
    //define public variable and acess function here
public:
    DatabaseHelper();
    ~DatabaseHelper();
    bool createTable();
    bool dropTable();
    bool setDataBasePath(QString filename);
    //define private variable and utility function here
private:
    QSqlDatabase myDataBase;
};

#endif // DATABASEHELPER_H
