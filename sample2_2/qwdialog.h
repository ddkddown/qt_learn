#ifndef QWDIALOG_H
#define QWDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QWDialog; }
QT_END_NAMESPACE

class QWDialog : public QDialog
{
    Q_OBJECT

public:
    QWDialog(QWidget *parent = nullptr);
    ~QWDialog();
public Q_SLOTS:
    void test(){
        this->close();
    }

private:
    Ui::QWDialog *ui;

private Q_SLOTS:
    void setTest();
};
#endif // QWDIALOG_H
