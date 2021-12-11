#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("test");
}

MainWindow::~MainWindow()
{
}

void MainWindow::iniUI()
{
    chkBoxBold = new QCheckBox(tr("Bold"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    chkBoxUnder = new QCheckBox(tr("Under"));
    QHBoxLayout *HLayl = new QHBoxLayout;
    HLayl->addWidget(chkBoxUnder);
    HLayl->addWidget(chkBoxBold);
    HLayl->addWidget(chkBoxItalic);

    rBtnBlack = new QRadioButton(tr("Black"));
    rBtnBlack->setChecked(true);
    rBtnRed = new QRadioButton(tr("Red"));
    rBtnBlue = new QRadioButton(tr("Blue"));
    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(rBtnBlack);
    HLay2->addWidget(rBtnRed);
    HLay2->addWidget(rBtnBlue);

    btnOK = new QPushButton(tr("ok"));
    btnCancel = new QPushButton(tr("cancel"));
    btnClose = new QPushButton(tr("close"));
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("show test");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);
    QVBoxLayout *VLay=new QVBoxLayout;
    VLay->addLayout(HLayl);
    VLay->addLayout(HLay2);
    VLay->addLayout(HLay3);
    VLay->addWidget(txtEdit);
    setLayout(VLay);
}

void MainWindow::iniSignalSlots()
{
    connect(chkBoxUnder, SIGNAL(clicked()), this, SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxBold, SIGNAL(clicked()), this, SLOT(on_chkBoxBold(bool)));
    connect(chkBoxItalic, SIGNAL(clicked()), this, SLOT(on_chkBoxItalic(bool)));

    connect(rBtnBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));

    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

void MainWindow::setTextFontColor()
{
    auto font = txtEdit->font();
    do{
        if(rBtnBlue->isChecked()) {
            font.setPixelSize(10);
            break;
        }

        if(rBtnRed->isChecked()) {
            font.setPixelSize(20);
            break;
        }

        if(rBtnBlack->isChecked()) {
            font.setPixelSize(30);
            break;
        }

    }while(0);

    txtEdit->setFont(font);
}

void MainWindow::on_chkBoxUnder(bool checked)
{
    QFont font=txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void MainWindow::on_chkBoxBold(bool checked)
{
    QFont font=txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void MainWindow::on_chkBoxItalic(bool checked)
{
    QFont font=txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}
