#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(true);
    ui->textEdit_2->setVisible(false);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_leftClick()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_rightClick()));
    connect(this, SIGNAL(setTextLR(int)), this, SLOT(on_TextChange(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_leftClick()
{
    emit setTextLR(LEFT);
}
void Dialog::on_rightClick()
{
    emit setTextLR(RIGHT);
}

void Dialog::on_TextChange(int i)
{
    if(LEFT == i)
    {
        ui->textEdit->setVisible(true);
        ui->textEdit_2->setVisible(false);
    } else if(RIGHT == i)
    {
        ui->textEdit->setVisible(false);
        ui->textEdit_2->setVisible(true);
    }

}
