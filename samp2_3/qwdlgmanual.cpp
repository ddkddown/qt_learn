#include "qwdlgmanual.h"

QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("hello world!");
}

QWDlgManual::~QWDlgManual()
{
}

void QWDlgManual::on_chkBoxUnder(bool checked)
{
    auto font=txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxItalic(bool checked)
{
    auto font=txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxBold(bool checked)
{
    auto font=txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::iniUI()
{
    chkBoxUnder = new QCheckBox(tr("underline"));
    chkBoxBold = new QCheckBox(tr("bold"));
    chkBoxItalic = new QCheckBox(tr("italic"));

    QHBoxLayout *hLay1 = new QHBoxLayout;
    hLay1->addWidget(chkBoxUnder);
    hLay1->addWidget(chkBoxBold);
    hLay1->addWidget(chkBoxItalic);

    rBtnBlack = new QRadioButton(tr("black"));
    rBtnBlack->setChecked(true);
    rBtnRed = new QRadioButton(tr("red"));
    rBtnBlue = new QRadioButton(tr("blue"));

    QHBoxLayout *hLay2 = new QHBoxLayout;
    hLay2->addWidget(rBtnBlack);
    hLay2->addWidget(rBtnBlue);
    hLay2->addWidget(rBtnRed);

    btnOK = new QPushButton(tr("confirm"));
    btnCancel = new QPushButton(tr("cancel"));
    btnClose = new QPushButton(tr("close"));

    QHBoxLayout *hLay3 = new QHBoxLayout;
    hLay3->addWidget(btnOK);
    hLay3->addWidget(btnClose);
    hLay3->addWidget(btnCancel);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("hello world");
    auto font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addLayout(hLay1);
    vLay->addLayout(hLay2);
    vLay->addLayout(hLay3);
    vLay->addWidget(txtEdit);
    setLayout(vLay);
}


void QWDlgManual::iniSignalSlots()
{
    connect(chkBoxUnder, SIGNAL(clicked()), this, SLOT(on_chkBoxUnder));
    connect(chkBoxItalic, SIGNAL(clicked()), this, SLOT(on_chkBoxItalic));
    connect(chkBoxBold, SIGNAL(clicked()), this, SLOT(on_chkBoxBold));
}
