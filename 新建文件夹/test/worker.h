#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QSerialPort>
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    ~Worker();
     QSerialPort* port1;
     QSerialPort* port2;
     QSerialPort* port3;
     QSerialPort* port4;
     QSerialPort* port5;
     QSerialPort* port6;
     QSerialPort* port7;
     QSerialPort* port8;
     bool flag1;
     bool flag2;
     bool flag3;
     bool flag4;
     bool flag5;
     bool flag6;
     bool flag7;
     bool flag8;
     bool isHex1;
     bool isHex2;
     bool isHex3;
     bool isHex4;
     bool isHex5;
     bool isHex6;
     bool isHex7;
     bool isHex8;
    void intervalGen(int interval);
signals:

     void result_open1();
     void result_open2();
     void result_open3();
     void result_open4();
     void result_open5();
     void result_open6();
     void result_open7();
     void result_open8();
     void result_close1(int);
     void result_close2(int);
     void result_close3(int);
     void result_close4(int);
     void result_close5(int);
     void result_close6(int);
     void result_close7(int);
     void result_close8(int);
     void result_read1(QByteArray,int);
     void result_read2(QByteArray,int);
     void result_read3(QByteArray,int);
     void result_read4(QByteArray,int);
     void result_read5(QByteArray,int);
     void result_read6(QByteArray,int);
     void result_read7(QByteArray,int);
     void result_read8(QByteArray,int);
     void result_open1_false();
     void result_open2_false();
     void result_open3_false();
     void result_open4_false();
     void result_open5_false();
     void result_open6_false();
     void result_open7_false();
     void result_open8_false();
     //void result_num_one(int);
     //void result_close1(int);
     //void result_num_cycle1(int*);
public slots:

     void doWork_open1(QString portName,long  localBaudData );
     void doWork_open2(QString portName,long  localBaudData );
     void doWork_open3(QString portName,long  localBaudData );
     void doWork_open4(QString portName,long  localBaudData );
     void doWork_open5(QString portName,long  localBaudData );
     void doWork_open6(QString portName,long  localBaudData );
     void doWork_open7(QString portName,long  localBaudData );
     void doWork_open8(QString portName,long  localBaudData );
   //  void doWork_cycle3(QString str,int ascii_33_2);
     void doWork_close1();
     void doWork_close2();
     void doWork_close3();
     void doWork_close4();
     void doWork_close5();
     void doWork_close6();
     void doWork_close7();
     void doWork_close8();
     void doWork_one1(QString str, int ascii_11_2, int *cnt);
     void doWork_one2(QString str, int ascii_22_2, int *cnt);
     void doWork_one3(QString str, int ascii_33_2, int *cnt);
     void doWork_one4(QString str, int ascii_44_2, int *cnt);
     void doWork_one5(QString str, int ascii_55_2, int *cnt);
     void doWork_one6(QString str, int ascii_66_2, int *cnt);
     void doWork_one7(QString str, int ascii_77_2, int *cnt);
     void doWork_one8(QString str, int ascii_88_2, int *cnt);
     void doWork_read1();
     void doWork_read2();
     void doWork_read3();
     void doWork_read4();
     void doWork_read5();
     void doWork_read6();
     void doWork_read7();
     void doWork_read8();
     void doWork_cycle1(QString str, int interval, int *cnt);
     void doWork_cycle2(QString str, int interval, int *cnt);
     void doWork_cycle3(QString str, int interval, int *cnt);
     void doWork_cycle4(QString str, int interval, int *cnt);
     void doWork_cycle5(QString str, int interval, int *cnt);
     void doWork_cycle6(QString str, int interval, int *cnt);
     void doWork_cycle7(QString str, int interval, int *cnt);
     void doWork_cycle8(QString str, int interval, int *cnt);
};

#endif // WORKER_H
