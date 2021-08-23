#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("fuck me!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog *dlg = new Dialog(this);
    dlg->show();
}
