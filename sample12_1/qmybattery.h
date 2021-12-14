#ifndef QMYBATTERY_H
#define QMYBATTERY_H

#include <QWidget>
#include <QColor>

class QmyBattery : public QWidget
{
    Q_OBJECT

signals:

private:
    QColor  mColorBack=Qt::white;
    QColor  mColorBorder=Qt::black;
    QColor  mColorPower=Qt::green;
    QColor  mColorWarning=Qt::red;
    int mPowerLevel=60;
    int mWarnLevel=20;

protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE; //override func
public:
    explicit QmyBattery(QWidget *parent = 0);
    void setPowerLevel(int pow);
    int powerLevel();
    void setWarnLevel(int warn);
    int warnLevel();
    QSize sizeHint();
signals:
    void powerLevelChanged(int);
public slots:
};

#endif // QMYBATTERY_H
