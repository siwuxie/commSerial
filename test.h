#ifndef TEST_H
#define TEST_H
#include <QObject>

class test: public QObject
{
    Q_OBJECT
public:
    test();
    ~test();
signals:
    void datasend(QByteArray &data);
public slots:
    void readData(QByteArray &data);
};

#endif // TEST_H
