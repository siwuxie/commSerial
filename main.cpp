#include <QCoreApplication>
#include <QSerialPort>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSerialPort test;
    return a.exec();
}
