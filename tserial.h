#ifndef TSERIAL_H
#define TSERIAL_H
#include <QSerialPort>
#include <QThread>
#include "test.h"
/*
 * 这个类实现了最基本的串口通信结构。该类不会对数据做任何处理。这也是为了加快接收与发送
 * 响应速度。
 */
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
    void dataTransition(QByteArray data);

public slots:
    void readData();
    void dataSend(QByteArray data);
};

/*
 * 该类继承于QThread，旨在将串口的读写操作放到单独的线程中。通过信号与槽的机制进行数据的传递
 *
 */

class serialThread:public QThread
{
    Q_OBJECT
public:
    serialThread(QString portname, int baud, test* objlist);
    ~serialThread();

    void run();

    Tserial *serialPort;
    void signalDispatcher(test* obj);
    QString portname;
    int baud;
    test *objlist;
};



#endif // TSERIAL_H
