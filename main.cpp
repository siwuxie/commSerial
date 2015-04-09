#include <QCoreApplication>
#include <QSerialPort>
#include "tserial.h"
#include <QObject>
#include <iostream>
#include "test.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Tserial *comunicator = new Tserial("/dev/ttyUSB0", 115200);
    comunicator->openPort();
    test *t = new test();
    Tserial::connect(comunicator, SIGNAL(dataTransition(QByteArray&)), t, SLOT(getdata(QByteArray&)));
    return a.exec();
}
