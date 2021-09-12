#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(set_text_color()));
    connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(set_text_color()));
    connect(ui->radioButton_3, SIGNAL(clicked()), this, SLOT(set_text_color()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_clicked(bool checked)
{
    auto font = ui->label->font();
    font.setUnderline(checked);
    ui->label->setFont(font);
}

void MainWindow::on_checkBox_2_clicked(bool checked)
{
    auto font = ui->label->font();
    font.setItalic(checked);
    ui->label->setFont(font);
}

void MainWindow::on_checkBox_3_clicked(bool checked)
{
    auto font = ui->label->font();
    font.setBold(checked);
    ui->label->setFont(font);
}

void MainWindow::set_text_color()
{
    auto plet = ui->label->palette();
    if(ui->radioButton->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else if (ui->radioButton_2->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    else if(ui->radioButton_3->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    else
        plet.setColor(QPalette::Text, Qt::black);

    ui->label->setPalette(plet);

}

void MainWindow::on_radioButton_clicked()
{
    auto plet = ui->label->palette();
    if(ui->radioButton->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else if (ui->radioButton_2->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    else if(ui->radioButton_3->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    else
        plet.setColor(QPalette::Text, Qt::black);

    ui->label->setPalette(plet);
}

void MainWindow::on_radioButton_2_clicked()
{
    auto plet = ui->label->palette();
    if(ui->radioButton->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else if (ui->radioButton_2->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    else if(ui->radioButton_3->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    else
        plet.setColor(QPalette::Text, Qt::black);

    ui->label->setPalette(plet);
}

void MainWindow::on_radioButton_3_clicked()
{
    auto plet = ui->label->palette();
    if(ui->radioButton->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else if (ui->radioButton_2->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    else if(ui->radioButton_3->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    else
        plet.setColor(QPalette::Text, Qt::black);

    ui->label->setPalette(plet);
}
