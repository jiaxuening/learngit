#include "worker.h"
#include <QDebug>
#include <QEventLoop>
#include <QTimer>
int num_one1 = 0;
int num_one2 = 0;
int num_one3 = 0;
int num_one4 = 0;
int num_one5 = 0;
int num_one6 = 0;
int num_one7 = 0;
int num_one8 = 0;


Worker::Worker(QObject *parent) : QObject(parent)
{
    flag1 = false;
    isHex1 = false;
    flag2 = false;
    isHex2 = false;
    flag3 = false;
    isHex3 = false;
    flag4 = false;
    isHex4 = false;
    flag5 = false;
    isHex5 = false;
    flag6 = false;
    isHex6 = false;
    flag7 = false;
    isHex7 = false;
    flag8 = false;
    isHex8 = false;
}

Worker::~Worker()
{

}

void Worker::doWork_open1(QString portName,long  localBaudData )
 {

    port1 = new QSerialPort(portName);

    port1->setBaudRate(  localBaudData);
    port1->setDataBits(QSerialPort::Data8);
    port1->setParity(QSerialPort::NoParity);
    port1->setStopBits(QSerialPort::OneStop);
    port1->setFlowControl(QSerialPort::NoFlowControl);
    if(port1->open(QIODevice::ReadWrite))
    {
        qDebug() << "on";
        connect(port1, SIGNAL(readyRead()),this , SLOT(doWork_read1()));
        //   connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
        emit result_open1();}
    else {
           emit result_open1_false();
       }


 }
void Worker::doWork_open2(QString portName,long  localBaudData )
 {


    port2 = new QSerialPort(portName);

    port2->setBaudRate(  localBaudData);
    port2->setDataBits(QSerialPort::Data8);
    port2->setParity(QSerialPort::NoParity);
    port2->setStopBits(QSerialPort::OneStop);
    port2->setFlowControl(QSerialPort::NoFlowControl);
    if(port2->open(QIODevice::ReadWrite))
    {
        connect(port2, SIGNAL(readyRead()),this , SLOT(doWork_read2()));
        //   connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
        emit result_open2();
        qDebug() << "on";

    } else {
        emit result_open2_false();
    }

 }
void Worker::doWork_open3(QString portName,long  localBaudData )
 {

       port3 = new QSerialPort(portName);

       port3->setBaudRate(  localBaudData);
       port3->setDataBits(QSerialPort::Data8);
       port3->setParity(QSerialPort::NoParity);
       port3->setStopBits(QSerialPort::OneStop);
       port3->setFlowControl(QSerialPort::NoFlowControl);
       if(port3->open(QIODevice::ReadWrite))
         {  qDebug() << "on";
            connect(port3, SIGNAL(readyRead()),this , SLOT(doWork_read3()));
         //   connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
            emit result_open3();}
       else {
              emit result_open3_false();
          }


 }
void Worker::doWork_open4(QString portName,long  localBaudData )
 {

       port4 = new QSerialPort(portName);

       port4->setBaudRate(  localBaudData);
       port4->setDataBits(QSerialPort::Data8);
       port4->setParity(QSerialPort::NoParity);
       port4->setStopBits(QSerialPort::OneStop);
       port4->setFlowControl(QSerialPort::NoFlowControl);
       if(port4->open(QIODevice::ReadWrite))
         {  qDebug() << "on";
            connect(port4, SIGNAL(readyRead()),this , SLOT(doWork_read4()));
         //   connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
            emit result_open4();}
       else {
              emit result_open4_false();
          }


 }
void Worker::doWork_open5(QString portName,long  localBaudData )
 {

       port5 = new QSerialPort(portName);

       port5->setBaudRate(  localBaudData);
       port5->setDataBits(QSerialPort::Data8);
       port5->setParity(QSerialPort::NoParity);
       port5->setStopBits(QSerialPort::OneStop);
       port5->setFlowControl(QSerialPort::NoFlowControl);
       if(port5->open(QIODevice::ReadWrite))
         {  qDebug() << "on";
            connect(port5, SIGNAL(readyRead()),this , SLOT(doWork_read5()));
         //   connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
            emit result_open5();}
       else {
              emit result_open5_false();
          }


 }
void Worker::doWork_open6(QString portName,long  localBaudData )
 {

       port6 = new QSerialPort(portName);

       port6->setBaudRate(  localBaudData);
       port6->setDataBits(QSerialPort::Data8);
       port6->setParity(QSerialPort::NoParity);
       port6->setStopBits(QSerialPort::OneStop);
       port6->setFlowControl(QSerialPort::NoFlowControl);
       if(port6->open(QIODevice::ReadWrite))
         {  qDebug() << "on";
            connect(port6, SIGNAL(readyRead()),this , SLOT(doWork_read6()));
         //   connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
            emit result_open6();}
       else {
              emit result_open6_false();
          }


 }
void Worker::doWork_open7(QString portName,long  localBaudData )
 {

       port7 = new QSerialPort(portName);

       port7->setBaudRate(  localBaudData);
       port7->setDataBits(QSerialPort::Data8);
       port7->setParity(QSerialPort::NoParity);
       port7->setStopBits(QSerialPort::OneStop);
       port7->setFlowControl(QSerialPort::NoFlowControl);
       if(port7->open(QIODevice::ReadWrite))
         {  qDebug() << "on";
            connect(port7, SIGNAL(readyRead()),this , SLOT(doWork_read7()));
         //   connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
            emit result_open7();}
       else {
              emit result_open7_false();
          }


 }
void Worker::doWork_open8(QString portName,long  localBaudData )
 {

       port8 = new QSerialPort(portName);

       port8->setBaudRate(  localBaudData);
       port8->setDataBits(QSerialPort::Data8);
       port8->setParity(QSerialPort::NoParity);
       port8->setStopBits(QSerialPort::OneStop);
       port8->setFlowControl(QSerialPort::NoFlowControl);
       if(port8->open(QIODevice::ReadWrite))
         {  qDebug() << "on";
            connect(port8, SIGNAL(readyRead()),this , SLOT(doWork_read8()));
         //   connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
            emit result_open8();}
       else {
              emit result_open8_false();
          }


 }
void Worker::doWork_close1()
{
       port1->close();
       num_one1 = 0;
       emit result_close1(num_one1);

       qDebug() << "off";

}

void Worker::doWork_close2()
{
    port2->close();
    num_one2 = 0;
    emit result_close2(num_one2);

    qDebug() << "off";


}
void Worker::doWork_close3()
{
       port3->close();
       num_one3 = 0;
       emit result_close3(num_one3);

       qDebug() << "off";

}
void Worker::doWork_close4()
{
       port4->close();
       num_one4 = 0;
       emit result_close4(num_one4);

       qDebug() << "off";

}
void Worker::doWork_close5()
{
       port5->close();
       num_one5 = 0;
       emit result_close5(num_one5);

       qDebug() << "off";

}
void Worker::doWork_close6()
{
       port6->close();
       num_one6 = 0;
       emit result_close6(num_one6);

       qDebug() << "off";

}
void Worker::doWork_close7()
{
       port7->close();
       num_one7 = 0;
       emit result_close7(num_one7);

       qDebug() << "off";

}
void Worker::doWork_close8()
{
       port8->close();
       num_one8 = 0;
       emit result_close8(num_one8);

       qDebug() << "off";

}
void Worker::doWork_one1(QString str,int ascii_11_2,int* cnt)
{

    if(ascii_11_2==0)
       {
        QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
        port1->write(text);
        *cnt+=str.size();

       }
       if(ascii_11_2==1)
       {
           port1->write(str.toLocal8Bit());
          // qDebug() << "send";
           *cnt+=str.size();
       }
       //emit result_num_one(*cnt);
       qDebug() << *cnt;

}
void Worker::doWork_one2(QString str,int ascii_22_2,int* cnt)
{

    if(ascii_22_2==0)
       {
        QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
        port2->write(text);
        *cnt+=str.size();

       }
       if(ascii_22_2==1)
       {
           port2->write(str.toLocal8Bit());
          // qDebug() << "send";
           *cnt+=str.size();
       }
       //emit result_num_one(*cnt);
       qDebug() << *cnt;



}
void Worker::doWork_one3(QString str,int ascii_33_2,int* cnt)
{

    if(ascii_33_2==0)
       {
        QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
        port3->write(text);
        *cnt+=str.size();

       }
       if(ascii_33_2==1)
       {
           port3->write(str.toLocal8Bit());
          // qDebug() << "send";
           *cnt+=str.size();
       }
       //emit result_num_one(*cnt);
       qDebug() << *cnt;



}
void Worker::doWork_one4(QString str,int ascii_44_2,int* cnt)
{

    if(ascii_44_2==0)
       {
        QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
        port4->write(text);
        *cnt+=str.size();

       }
       if(ascii_44_2==1)
       {
           port4->write(str.toLocal8Bit());
          // qDebug() << "send";
           *cnt+=str.size();
       }
       //emit result_num_one(*cnt);
       qDebug() << *cnt;
}
void Worker::doWork_one5(QString str,int ascii_55_2,int* cnt)
{

    if(ascii_55_2==0)
       {
        QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
        port5->write(text);
        *cnt+=str.size();

       }
       if(ascii_55_2==1)
       {
           port5->write(str.toLocal8Bit());
          // qDebug() << "send";
           *cnt+=str.size();
       }
       //emit result_num_one(*cnt);
       qDebug() << *cnt;
}
void Worker::doWork_one6(QString str,int ascii_66_2,int* cnt)
{

    if(ascii_66_2==0)
       {
        QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
        port6->write(text);
        *cnt+=str.size();

       }
       if(ascii_66_2==1)
       {
           port6->write(str.toLocal8Bit());
          // qDebug() << "send";
           *cnt+=str.size();
       }
       //emit result_num_one(*cnt);
       qDebug() << *cnt;
}
void Worker::doWork_one7(QString str,int ascii_77_2,int* cnt)
{

    if(ascii_77_2==0)
       {
        QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
        port7->write(text);
        *cnt+=str.size();

       }
       if(ascii_77_2==1)
       {
           port7->write(str.toLocal8Bit());
          // qDebug() << "send";
           *cnt+=str.size();
       }
       //emit result_num_one(*cnt);
       qDebug() << *cnt;
}
void Worker::doWork_one8(QString str,int ascii_88_2,int* cnt)
{

    if(ascii_88_2==0)
       {
        QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
        port8->write(text);
        *cnt+=str.size();

       }
       if(ascii_88_2==1)
       {
           port8->write(str.toLocal8Bit());
          // qDebug() << "send";
           *cnt+=str.size();
       }
       //emit result_num_one(*cnt);
       qDebug() << *cnt;
}
void Worker::doWork_read1()
{
    int num=0;
    QByteArray readData = port1->readAll();
    num=readData.size();
    emit result_read1(readData,num);
   // qDebug() << "rec";
}
void Worker::doWork_read2()
{
    int num=0;
    QByteArray readData = port2->readAll();
    num=readData.size();
    emit result_read2(readData,num);
   // qDebug() << "rec";
}
void Worker::doWork_read3()
{
    int num=0;
    QByteArray readData = port3->readAll();
    num=readData.size();
    emit result_read3(readData,num);
   // qDebug() << "rec";
}
void Worker::doWork_read4()
{
    int num=0;
    QByteArray readData = port4->readAll();
    num=readData.size();
    emit result_read4(readData,num);
   // qDebug() << "rec";
}
void Worker::doWork_read5()
{
    int num=0;
    QByteArray readData = port5->readAll();
    num=readData.size();
    emit result_read5(readData,num);
   // qDebug() << "rec";
}
void Worker::doWork_read6()
{
    int num=0;
    QByteArray readData = port6->readAll();
    num=readData.size();
    emit result_read6(readData,num);
   // qDebug() << "rec";
}
void Worker::doWork_read7()
{
    int num=0;
    QByteArray readData = port7->readAll();
    num=readData.size();
    emit result_read7(readData,num);
   // qDebug() << "rec";
}
void Worker::doWork_read8()
{
    int num=0;
    QByteArray readData = port8->readAll();
    num=readData.size();
    emit result_read8(readData,num);
   // qDebug() << "rec";
}
void Worker::doWork_cycle1(QString str, int interval, int *cnt)
{
    while (flag1)
    {
        if(!isHex1) {

            port1->write(str.toLocal8Bit());
            *cnt = *cnt + str.size();
            qDebug() << "Ascii";
            qDebug() << "cycle1";

            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);

        } else {

            QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
            port1->write(text);
            *cnt = *cnt + str.size();
            qDebug() << "Hex";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        }
        intervalGen(interval);
    }
}

void Worker::doWork_cycle2(QString str, int interval, int *cnt)
{
    while (flag2)
    {
        if(!isHex2) {
            qDebug() << "cycle1";
            port2->write(str.toLocal8Bit());
            *cnt = *cnt + str.size();
            qDebug() << "cycle1";
            qDebug() << "Ascii";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);

        } else {

            QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
            port2->write(text);
            *cnt = *cnt + str.size();
            qDebug() << "Hex";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        }
        intervalGen(interval);
    }
}
void Worker::doWork_cycle3(QString str, int interval, int *cnt)
{
    while (flag3)
    {
        if(!isHex3) {
            port3->write(str.toLocal8Bit());
            *cnt = *cnt + str.size();
            qDebug() << "cycle1";
            qDebug() << "Ascii";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);

        } else {

            QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
            port3->write(text);
            *cnt = *cnt + str.size();
            qDebug() << "Hex";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        }
        intervalGen(interval);
    }
}
void Worker::doWork_cycle4(QString str, int interval, int *cnt)
{
    while (flag4)
    {
        if(!isHex4) {
            port4->write(str.toLocal8Bit());
            *cnt = *cnt + str.size();
            qDebug() << "cycle1";
            qDebug() << "Ascii";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        } else {
            QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
            port4->write(text);
            *cnt = *cnt + str.size();
            qDebug() << "Hex";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        }
        intervalGen(interval);
    }
}
void Worker::doWork_cycle5(QString str, int interval, int *cnt)
{
    while (flag5)
    {
        if(!isHex5) {
            port5->write(str.toLocal8Bit());
            *cnt = *cnt + str.size();
            qDebug() << "cycle1";
            qDebug() << "Ascii";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        } else {
            QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
            port5->write(text);
            *cnt = *cnt + str.size();
            qDebug() << "Hex";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        }
        intervalGen(interval);
    }
}
void Worker::doWork_cycle6(QString str, int interval, int *cnt)
{
    while (flag6)
    {
        if(!isHex6) {
            port6->write(str.toLocal8Bit());
            *cnt = *cnt + str.size();
            qDebug() << "cycle1";
            qDebug() << "Ascii";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        } else {
            QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
            port6->write(text);
            *cnt = *cnt + str.size();
            qDebug() << "Hex";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        }
        intervalGen(interval);
    }
}
void Worker::doWork_cycle7(QString str, int interval, int *cnt)
{
    while (flag7)
    {
        if(!isHex7) {
            port7->write(str.toLocal8Bit());
            *cnt = *cnt + str.size();
            qDebug() << "cycle1";
            qDebug() << "Ascii";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        } else {
            QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
            port7->write(text);
            *cnt = *cnt + str.size();
            qDebug() << "Hex";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        }
        intervalGen(interval);
    }
}
void Worker::doWork_cycle8(QString str, int interval, int *cnt)
{
    while (flag8)
    {
        if(!isHex8) {
            port8->write(str.toLocal8Bit());
            *cnt = *cnt + str.size();
            qDebug() << "cycle1";
            qDebug() << "Ascii";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        } else {
            QByteArray text = QByteArray::fromHex(str.toLocal8Bit());
            port8->write(text);
            *cnt = *cnt + str.size();
            qDebug() << "Hex";
            qDebug() << *cnt;
            //emit result_num_cycle1(cnt);
        }
        intervalGen(interval);
    }
}
void Worker::intervalGen(int interval)
{
    QEventLoop loop;
    QTimer::singleShot(interval, &loop, SLOT(quit()));
    loop.exec();
}
