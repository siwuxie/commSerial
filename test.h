#ifndef TEST_H
#define TEST_H
#include <QObject>

/*
 * test 类 用于项目测试
 * /


class test: public QObject
{
    Q_OBJECT
public:
    test();
    ~test();
signals:
    void datasend(QByteArray data);
public slots:
    void readData(QByteArray data);
};

#endif // TEST_H
