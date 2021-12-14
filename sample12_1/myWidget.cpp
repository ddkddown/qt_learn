#include "myWidget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    battery = new QmyBattery;
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

