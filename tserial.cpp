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

void Tserial::dataSend(QByteArray &data)
{
    if (data.length()!=0)
        com->write(data);
}
