#include "test.h"

#include <iostream>
using namespace std;

test::test():QObject()
{

}

test::~test()
{

}

void test::readData(QByteArray data)
{
    cout<<data.toStdString()<<endl;
}
