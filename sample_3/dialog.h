#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
public slots:
    void on_leftClick();
    void on_rightClick();
private slots:
    void on_TextChange(int i);

private: signals:
    void setTextLR(int i);
private:
    Ui::Dialog *ui;
    enum LR {
        LEFT = 0,
        RIGHT
    };

};
#endif // DIALOG_H
