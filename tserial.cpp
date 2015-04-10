#include "tserial.h"

Tserial::Tserial(QString portname, int baud):QObject()
{
    com = new QSerialPort();
    com->setBaudRate(baud);
    com->setPortName(portname);
    com->setDataBits(QSerialPort::Data8);
    com->setStopBits(QSerialPort::OneStop);
    com->setParity(QSerialPort::NoParity);
    com->setFlowControl(QSerialPort::NoFlowControl);

    connect(com, SIGNAL(readyRead()), this, SLOT(readData()));
}

Tserial::~Tserial()
{
    com->close();
}

void Tserial::openPort()
{
    if (!com->isOpen())
    {
        int err = com->open(QIODevice::ReadWrite);
        if (!err)
        {
            while(1);
        }
    }
}

void Tserial::closePort()
{
    if (com->isOpen())
    {
        com->close();
    }
}

void Tserial::readData()
{
    QByteArray temp;
    temp = com->readAll();
    if (temp.length()!=0)
        emit dataTransition(temp);
}

void Tserial::dataSend(QByteArray data)
{
    if (data.length()!=0)
        com->write(data);
}


serialThread::serialThread(QString portname, int baud,
                           test *objlist):
    QThread()
{
    this->portname = portname;
    this->baud = baud;
    this->objlist = objlist;
}

serialThread::~serialThread()
{
}

void serialThread::run()
{
    serialPort = new Tserial(portname, baud);
    signalDispatcher(objlist);
    serialPort->openPort();
    this->exec();
}


/*
 * 改方法用于实现信号与槽的链接。串口线程发送信号为dataTransition
 */

void serialThread::signalDispatcher(test *obj)
{
    connect(obj, SIGNAL(datasend(QByteArray)),
            serialPort, SLOT(dataSend(QByteArray)),Qt::QueuedConnection);
    connect(serialPort, SIGNAL(dataTransition(QByteArray)),
            obj, SLOT(readData(QByteArray)),Qt::QueuedConnection);
}









