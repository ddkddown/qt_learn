#ifndef COLORMAKER_H
#define COLORMAKER_H
#include <QObject>
#include <QColor>
#include <QDateTime>
#include <QTimerEvent>

class ColorMaker : public QObject {
    Q_OBJECT
    Q_ENUMS(GenerateAlgorithm)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor timeColor READ timeColor)

public:
    ColorMaker(QObject *parent = 0):QObject(parent),
                                    m_algorithm(RandomRGB),
                                    m_currentColor(Qt::black),
                                    m_nColorTimer(0){
        qsrand(QDateTime::currentDateTime().toTime_t());
    }

    ~ColorMaker(){}

    enum GenerateAlgorithm {
        RandomRGB,
        RandomRed,
        RandomGreen,
        RandomBlue,
        LinearIncrease
    };

    QColor color() const {
        return m_currentColor;
    }

    void setColor(const QColor &color) {
        m_currentColor = color;
        emit colorChanged(m_currentColor);
    }
    QColor timeColor() const {
        QTime time = QTime::currentTime();
        int r = time.hour();
        int g = time.minute()*2;
        int b = time.second()*4;

        return QColor::fromRgb(r,g,b);
    }

    Q_INVOKABLE int getInt() {
        return 1;
    }

    Q_INVOKABLE GenerateAlgorithm algorithm() const {
        return m_algorithm;
    }

    Q_INVOKABLE void setAlgorithm(GenerateAlgorithm algorithm) {
        m_algorithm = algorithm;
    }

signals:
    void colorChanged(const QColor &color);
    void currentTime(const QString &strTime);

public slots:
    void start() {
        if(0 == m_nColorTimer) {
            m_nColorTimer = startTimer(1000);
        }
    }
    void stop() {
        if(0 < m_nColorTimer) {
            killTimer(m_nColorTimer);
            m_nColorTimer = 0;
        }
    }

protected:
    void timerEvent(QTimerEvent *e) {
        if(e->timerId() == m_nColorTimer) {
            switch (m_algorithm) {
                case RandomRGB:
                    m_currentColor.setRgb(qrand()%255, qrand()%255, qrand()%255);
                break;
            }

            emit colorChanged(m_currentColor);
            emit currentTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        } else {
            QObject::timerEvent(e);
        }
    }

private:
    GenerateAlgorithm m_algorithm;
    QColor m_currentColor;
    int m_nColorTimer;

};

#endif // COLORMAKER_H
