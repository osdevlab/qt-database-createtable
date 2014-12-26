#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    if (dBH.setDataBasePath("database")) {
        ui->label_status->setText("Connected");
    } else {
        ui->label_status->setText("Failed");
    }

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_createTable_clicked() {

    bool isTableCreated = dBH.createTable();

    if (isTableCreated) {
        ui->status_tableCreated->setText("Table Created");
    }

    else {
        ui->status_tableCreated->setText("Failed to create table");
    }

}

void MainWindow::on_dropTable_clicked() {

    bool isTableDropped = dBH.dropTable();
    if (isTableDropped) {
        ui->status_tableCreated->setText("Table Dropped");
    }

    else {
        ui->status_tableCreated->setText("Failed to drop the table");
    }
}

