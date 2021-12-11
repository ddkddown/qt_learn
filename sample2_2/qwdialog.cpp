#include "qwdialog.h"
#include "./ui_qwdialog.h"

QWDialog::QWDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QWDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(setTest()));
}

QWDialog::~QWDialog()
{
    delete ui;
}


void QWDialog::setTest()
{
    ui->textEdit->setText("damn!");
}
