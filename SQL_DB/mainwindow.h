#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <databasehelper.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_createTable_clicked();
    void on_dropTable_clicked();


private:
    Ui::MainWindow *ui;
        QSqlDatabase db;
        DatabaseHelper dBH;

};

#endif // MAINWINDOW_H
