#ifndef TSERIAL_H
#define TSERIAL_H
#include <QSerialPort>

class Tserial:public QObject
{
    Q_OBJECT
public:
    Tserial(QString portname, int baud);
    ~Tserial();

    QSerialPort *com;
    void openPort();
    void closePort();

signals:
    void dataTransition(QByteArray &data);

public slots:
    void dataSend(QByteArray &data);

private slots:
    void readData();

};

#endif // TSERIAL_H
