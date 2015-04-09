#ifndef TEST_H
#define TEST_H
#include <QObject>

class test: public QObject
{
    Q_OBJECT
public:
    test();
    ~test();

public slots:
    void getdata(QByteArray &data);
};

#endif // TEST_H
