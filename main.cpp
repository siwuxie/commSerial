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
    test *t= new test();
    serialThread *comunicator = \
            new serialThread("/dev/ttyUSB0", 115200, t);

    comunicator->start();
    return a.exec();
}
