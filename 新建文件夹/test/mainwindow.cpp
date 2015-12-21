#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configdialog.h"
#include <QSerialPort>
#include <QEventLoop>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <qlabel.h>
#include <QTextCodec>
#include <QThread>
#include "worker.h"
int  symbol=0;
int  symbol_3=0;
int  symbol_write=0;
int  symbol_read=0;
int  symbol_11_ascii_2=1;
int  symbol_11_ascii=1;
int  symbol_22_ascii_2=1;
int  symbol_22_ascii=1;
int  symbol_33_ascii_2=1;
int  symbol_33_ascii=1;
int  symbol_44_ascii_2=1;
int  symbol_44_ascii=1;
int  symbol_55_ascii_2=1;
int  symbol_55_ascii=1;
int  symbol_66_ascii_2=1;
int  symbol_66_ascii=1;
int  symbol_77_ascii_2=1;
int  symbol_77_ascii=1;
int  symbol_88_ascii_2=1;
int  symbol_88_ascii=1;
QThread *workerThread_open1;
QThread *workerThread_open2;
QThread *workerThread_open3;
QThread *workerThread_open4;
QThread *workerThread_open5;
QThread *workerThread_open6;
QThread *workerThread_open7;
QThread *workerThread_open8;
Worker *worker_open1 ;
Worker *worker_open2 ;
Worker *worker_open3 ;
Worker *worker_open4 ;
Worker *worker_open5 ;
Worker *worker_open6 ;
Worker *worker_open7 ;
Worker *worker_open8 ;
extern QByteArray config;
extern QStringList config_read;
extern QStringList Baud_read;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)   //初始化
{
    ui->setupUi(this);

    for (int i=0; i<8; i++) {
        sendCnt[i] = 0;
        recvCnt[i] = 0;
    }
    //  QTimer *time_clear = new QTimer(this);

    data1.clear();    //缓冲区
    data2.clear();
    data3.clear();
    data4.clear();
    data5.clear();
    data6.clear();
    data7.clear();
    data8.clear();

    ui->tab->setCurrentIndex(0);

    ui->radioButton_11_ascii_2->setChecked(true);
    ui->radioButton_11_ascii->setChecked(true);
    ui->radioButton_22_ascii_2->setChecked(true);
    ui->radioButton_22_ascii->setChecked(true);
    ui->radioButton_33_ascii_2->setChecked(true);
    ui->radioButton_33_ascii->setChecked(true);
    ui->radioButton_44_ascii_2->setChecked(true);
    ui->radioButton_44_ascii->setChecked(true);
    ui->radioButton_55_ascii_2->setChecked(true);
    ui->radioButton_55_ascii->setChecked(true);
    ui->radioButton_66_ascii_2->setChecked(true);
    ui->radioButton_66_ascii->setChecked(true);
    ui->radioButton_77_ascii_2->setChecked(true);
    ui->radioButton_77_ascii->setChecked(true);
    ui->radioButton_88_ascii_2->setChecked(true);
    ui->radioButton_88_ascii->setChecked(true);


    ui->radioButton_11_hex_2->setEnabled(false);
    ui->radioButton_11_hex->setEnabled(false);
    ui->radioButton_22_hex_2->setEnabled(false);
    ui->radioButton_22_hex->setEnabled(false);
    ui->radioButton_33_hex_2->setEnabled(false);
    ui->radioButton_33_hex->setEnabled(false);
    ui->radioButton_44_hex_2->setEnabled(false);
    ui->radioButton_44_hex->setEnabled(false);
    ui->radioButton_55_hex_2->setEnabled(false);
    ui->radioButton_55_hex->setEnabled(false);
    ui->radioButton_66_hex_2->setEnabled(false);
    ui->radioButton_66_hex->setEnabled(false);
    ui->radioButton_77_hex_2->setEnabled(false);
    ui->radioButton_77_hex->setEnabled(false);
    ui->radioButton_88_hex_2->setEnabled(false);
    ui->radioButton_88_hex->setEnabled(false);
    ui->btn_open_1->setDisabled(false);
    ui->btn_close_1->setEnabled(false);
    ui->checkBox_12->setEnabled(false);
    ui->btn_send_1->setEnabled(false);
    ui->spinBox_11->setMinimum(10);
    ui->spinBox_11->setMaximum(10000);
    ui->spinBox_11->setSingleStep(1);
    ui->spinBox_11->setValue(100);

    ui->btn_open_2->setDisabled(false);
    ui->btn_close_2->setEnabled(false);
    ui->checkBox_22->setEnabled(false);
    ui->btn_send_2->setEnabled(false);
    ui->spinBox_21->setMinimum(10);
    ui->spinBox_21->setMaximum(10000);
    ui->spinBox_21->setSingleStep(1);
    ui->spinBox_21->setValue(100);



    ui->btn_open_3->setDisabled(false);
    ui->btn_close_3->setEnabled(false);
    ui->checkBox_32->setEnabled(false);
    ui->btn_send_3->setEnabled(false);
    ui->spinBox_31->setMinimum(10);
    ui->spinBox_31->setMaximum(10000);
    ui->spinBox_31->setSingleStep(1);
    ui->spinBox_31->setValue(100);



    ui->btn_open_4->setDisabled(false);
    ui->btn_close_4->setEnabled(false);
    ui->checkBox_42->setEnabled(false);
    ui->btn_send_4->setEnabled(false);
    ui->spinBox_41->setMinimum(10);
    ui->spinBox_41->setMaximum(10000);
    ui->spinBox_41->setSingleStep(1);
    ui->spinBox_41->setValue(100);

    ui->btn_open_5->setDisabled(false);
    ui->btn_close_5->setEnabled(false);
    ui->checkBox_52->setEnabled(false);
    ui->btn_send_5->setEnabled(false);
    ui->spinBox_51->setMinimum(10);
    ui->spinBox_51->setMaximum(10000);
    ui->spinBox_51->setSingleStep(1);
    ui->spinBox_51->setValue(100);


    ui->btn_open_6->setDisabled(false);
    ui->btn_close_6->setEnabled(false);
    ui->checkBox_62->setEnabled(false);
    ui->btn_send_6->setEnabled(false);
    ui->spinBox_61->setMinimum(10);
    ui->spinBox_61->setMaximum(10000);
    ui->spinBox_61->setSingleStep(1);
    ui->spinBox_61->setValue(100);



    ui->btn_open_7->setDisabled(false);
    ui->btn_close_7->setEnabled(false);
    ui->checkBox_72->setEnabled(false);
    ui->btn_send_7->setEnabled(false);
    ui->spinBox_71->setMinimum(10);
    ui->spinBox_71->setMaximum(10000);
    ui->spinBox_71->setSingleStep(1);
    ui->spinBox_71->setValue(100);

    ui->btn_open_8->setDisabled(false);
    ui->btn_close_8->setEnabled(false);
    ui->checkBox_82->setEnabled(false);
    ui->btn_send_8->setEnabled(false);
    ui->spinBox_81->setMinimum(10);
    ui->spinBox_81->setMaximum(10000);
    ui->spinBox_81->setSingleStep(1);
    ui->spinBox_81->setValue(100);

    ui->textEdit_12->setDisabled(true);
    ui->textEdit_22->setDisabled(true);
    ui->textEdit_32->setDisabled(true);
    ui->textEdit_42->setDisabled(true);
    ui->textEdit_52->setDisabled(true);
    ui->textEdit_62->setDisabled(true);
    ui->textEdit_72->setDisabled(true);
    ui->textEdit_82->setDisabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timerUpDate1()
{

    if (data1.count()) {

        ui->textEdit_11->moveCursor(QTextCursor::End);
        if(symbol_11_ascii==1)
        {
            ui->textEdit_11->insertPlainText(data1);
            //   ui->label_15->setText(QString::number(sendCnt[0]));
        }
        if(symbol_11_ascii==0)
        {
            QByteArray text = data1.toHex();
            ui->textEdit_11->insertPlainText(text);
            //   ui->label_15->setText(QString::number(sendCnt[0]));
        }

        ui->label_15->setText(QString::number(recvCnt[0]));
        limitCharsInTextEdit(ui->textEdit_11, 10000);
        data1.clear();
    }
    ui->label_16->setText(QString::number(sendCnt[0]));

}
void MainWindow::timerUpDate2()
{

    if (data2.count()) {

        ui->textEdit_21->moveCursor(QTextCursor::End);
        if(symbol_22_ascii==1)
        {
            ui->textEdit_21->insertPlainText(data2);
            //   ui->label_15->setText(QString::number(sendCnt[0]));
        }
        if(symbol_22_ascii==0)
        {
            QByteArray text = data2.toHex();
            ui->textEdit_21->insertPlainText(text);
            //   ui->label_15->setText(QString::number(sendCnt[0]));
        }
        limitCharsInTextEdit(ui->textEdit_21, 10000);
        ui->label_25->setText(QString::number(recvCnt[1]));
        data2.clear();
    }
    ui->label_26->setText(QString::number(sendCnt[1]));

}
void MainWindow::timerUpDate3()
{

    if (data3.count()) {

        ui->textEdit_31->moveCursor(QTextCursor::End);
        if(symbol_33_ascii==1)
        {
            ui->textEdit_31->insertPlainText(data3);
            //   ui->label_15->setText(QString::number(sendCnt[0]));
        }
        if(symbol_33_ascii==0)
        {
            QByteArray text = data3.toHex();
            ui->textEdit_31->insertPlainText(text);
            //   ui->label_15->setText(QString::number(sendCnt[0]));
        }
        limitCharsInTextEdit(ui->textEdit_31, 10000);
        ui->label_35->setText(QString::number(recvCnt[2]));
        data3.clear();
    }
    ui->label_36->setText(QString::number(sendCnt[2]));

}
void MainWindow::timerUpDate4()
{

    if (data4.count()) {

        ui->textEdit_41->moveCursor(QTextCursor::End);
        if(symbol_44_ascii==1)
        {
            ui->textEdit_41->insertPlainText(data4);
            //   ui->label_15->setText(QString::number(sendCnt[0]));
        }
        if(symbol_44_ascii==0)
        {
            QByteArray text = data4.toHex();
            ui->textEdit_41->insertPlainText(text);
            //   ui->label_15->setText(QString::number(sendCnt[0]));
        }
        limitCharsInTextEdit(ui->textEdit_41, 10000);
        ui->label_45->setText(QString::number(recvCnt[3]));
        data4.clear();
    }
    ui->label_46->setText(QString::number(sendCnt[3]));

}
void MainWindow::timerUpDate5()
{
    if (data5.count()) {

        ui->textEdit_51->moveCursor(QTextCursor::End);
        if(symbol_55_ascii==1)
        {
            ui->textEdit_51->insertPlainText(data5);

        }
        if(symbol_55_ascii==0)
        {
            QByteArray text = data5.toHex();
            ui->textEdit_51->insertPlainText(text);

        }
        limitCharsInTextEdit(ui->textEdit_51, 10000);
        ui->label_55->setText(QString::number(recvCnt[4]));
        data5.clear();
    }
    ui->label_56->setText(QString::number(sendCnt[4]));
}
void MainWindow::timerUpDate6()
{
    if (data6.count()) {

        ui->textEdit_61->moveCursor(QTextCursor::End);
        if(symbol_66_ascii==1)
        {
            ui->textEdit_61->insertPlainText(data6);

        }
        if(symbol_66_ascii==0)
        {
            QByteArray text = data6.toHex();
            ui->textEdit_61->insertPlainText(text);

        }
        limitCharsInTextEdit(ui->textEdit_61, 10000);
        ui->label_65->setText(QString::number(recvCnt[5]));
        data6.clear();
    }
    ui->label_66->setText(QString::number(sendCnt[5]));
}
void MainWindow::timerUpDate7()
{
    if (data7.count()) {

        ui->textEdit_71->moveCursor(QTextCursor::End);
        if(symbol_77_ascii==1)
        {
            ui->textEdit_71->insertPlainText(data7);

        }
        if(symbol_77_ascii==0)
        {
            QByteArray text = data7.toHex();
            ui->textEdit_71->insertPlainText(text);

        }
        limitCharsInTextEdit(ui->textEdit_71, 10000);
        ui->label_75->setText(QString::number(recvCnt[6]));
        data7.clear();
    }
    ui->label_76->setText(QString::number(sendCnt[6]));
}
void MainWindow::timerUpDate8()
{
    if (data8.count()) {

        ui->textEdit_81->moveCursor(QTextCursor::End);
        if(symbol_88_ascii==1)
        {
            ui->textEdit_81->insertPlainText(data8);

        }
        if(symbol_88_ascii==0)
        {
            QByteArray text = data8.toHex();
            ui->textEdit_81->insertPlainText(text);

        }
        limitCharsInTextEdit(ui->textEdit_81, 10000);
        ui->label_85->setText(QString::number(recvCnt[7]));
        data8.clear();
    }
    ui->label_86->setText(QString::number(sendCnt[7]));
}
void MainWindow::on_btn_config_clicked()    //按下配置按键
{

    ConfigDialog *dlg = new ConfigDialog(this);
    connect(dlg, SIGNAL(sendConfigData(QStringList)), this, SLOT(recvConfigData(QStringList)));
    connect(dlg, SIGNAL(sendBaudData(QStringList)), this, SLOT(recvBaudData(QStringList)));
    dlg->exec();

}

void MainWindow::recvConfigData(QStringList configData)
{


    if(symbol_write==1)
    {
        symbol_write=0;
        localConfigData = configData;
        ui->groupBox_11->setTitle(localConfigData[0]);//显示目前的串口号
        ui->groupBox_21->setTitle(localConfigData[1]);
        ui->groupBox_31->setTitle(localConfigData[2]);
        ui->groupBox_41->setTitle(localConfigData[3]);
        ui->groupBox_51->setTitle(localConfigData[4]);
        ui->groupBox_61->setTitle(localConfigData[5]);
        ui->groupBox_71->setTitle(localConfigData[6]);
        ui->groupBox_81->setTitle(localConfigData[7]);
    }
    else
    {
        localConfigData=config_read;
        ui->groupBox_11->setTitle(localConfigData[0]);//显示目前的串口号
        ui->groupBox_21->setTitle(localConfigData[1]);
        ui->groupBox_31->setTitle(localConfigData[2]);
        ui->groupBox_41->setTitle(localConfigData[3]);
        ui->groupBox_51->setTitle(localConfigData[4]);
        ui->groupBox_61->setTitle(localConfigData[5]);
        ui->groupBox_71->setTitle(localConfigData[6]);
        ui->groupBox_81->setTitle(localConfigData[7]);
    }

}
void MainWindow::recvBaudData(QStringList BaudData)  //接收波特率
{

    if(symbol_read==1)
    { BaudData=Baud_read;symbol_read=0;}
    localBaudData[0]=BaudData[0].toLong();
    localBaudData[1]=BaudData[1].toLong();
    localBaudData[2]=BaudData[2].toLong();
    localBaudData[3]=BaudData[3].toLong();
    localBaudData[4]=BaudData[4].toLong();
    localBaudData[5]=BaudData[5].toLong();
    localBaudData[6]=BaudData[6].toLong();
    localBaudData[7]=BaudData[7].toLong();
    ui->label_111->setText(QString::number(localBaudData[0]));
    ui->label_222->setText(QString::number(localBaudData[1]));
    ui->label_333->setText(QString::number(localBaudData[2]));
    ui->label_444->setText(QString::number(localBaudData[3]));
    ui->label_555->setText(QString::number(localBaudData[4]));
    ui->label_666->setText(QString::number(localBaudData[5]));
    ui->label_777->setText(QString::number(localBaudData[6]));
    ui->label_888->setText(QString::number(localBaudData[7]));
}




void MainWindow::on_btn_send_1_clicked()   //1单次发送被按下
{

    QString str = ui->textEdit_12->toPlainText();


    emit one1(str,symbol_11_ascii_2, &sendCnt[0]);

}
void MainWindow::on_btn_send_2_clicked()   //2单次发送被按下
{
    QString str = ui->textEdit_22->toPlainText();


    emit one2(str,symbol_22_ascii_2, &sendCnt[1]);

}
void MainWindow::on_btn_send_3_clicked()   //3单次发送被按下
{

    QString str = ui->textEdit_32->toPlainText();


    emit one3(str,symbol_33_ascii_2, &sendCnt[2]);

}
void MainWindow::on_btn_send_4_clicked()   //4单次发送被按下
{


    QString str = ui->textEdit_42->toPlainText();


    emit one4(str,symbol_44_ascii_2, &sendCnt[3]);

}
void MainWindow::on_btn_send_5_clicked()   //5单次发送被按下
{

    QString str = ui->textEdit_52->toPlainText();


    emit one5(str,symbol_55_ascii_2, &sendCnt[4]);
}
void MainWindow::on_btn_send_6_clicked()   //6单次发送被按下
{

    QString str = ui->textEdit_62->toPlainText();


    emit one6(str,symbol_66_ascii_2, &sendCnt[5]);
}
void MainWindow::on_btn_send_7_clicked()   //7单次发送被按下
{


    QString str = ui->textEdit_72->toPlainText();


    emit one7(str,symbol_77_ascii_2, &sendCnt[6]);

}
void MainWindow::on_btn_send_8_clicked()   //8单次发送被按下
{

    QString str = ui->textEdit_82->toPlainText();


    emit one8(str,symbol_88_ascii_2, &sendCnt[7]);


}

void MainWindow::on_btn_open_1_clicked()    //打开1串口按键
{


    if(symbol!=1)
    {
        QMessageBox::about(NULL, "警告", "请先配置串口");
        return;
    }
    time_clear1 = new QTimer(this);
    worker_open1 = new Worker;
    workerThread_open1 = new QThread;
    worker_open1->moveToThread(workerThread_open1);

    connect(this, SIGNAL(open1(QString,long)), worker_open1, SLOT(doWork_open1(QString,long)));
    connect(worker_open1,SIGNAL(result_open1()),this,SLOT(handleResults_open1()));   //打开
    connect(worker_open1,SIGNAL(result_open1_false()),this,SLOT(handleResults_open1_false()));//打开失败
    emit open1(localConfigData[0],localBaudData[0]);
    workerThread_open1->start();

    connect(worker_open1,SIGNAL(result_read1(QByteArray,int)),this,SLOT(handleResults_read1(QByteArray,int))); //读
    connect(workerThread_open1, &QThread::finished, worker_open1, &QObject::deleteLater);
    connect(this, SIGNAL(one1(QString,int,int*)), worker_open1, SLOT(doWork_one1(QString,int,int*)));//单次发送
    connect(this, SIGNAL(cycle1(QString,int,int*)), worker_open1, SLOT(doWork_cycle1(QString,int,int*))); //循环
    //connect(worker_open1,SIGNAL(result_num_cycle1(int*)),this,SLOT(handleResults_num_cycle1(int*)));

    connect(time_clear1,SIGNAL(timeout()),this,SLOT(timerUpDate1()));//定时
    time_clear1->start(500);
    connect(this, SIGNAL(close1()), worker_open1, SLOT(doWork_close1()));  //关闭
    connect(worker_open1,SIGNAL(result_close1(int)),this,SLOT(handleResults_close1()));

}



void MainWindow::handleResults_open1()
{
    ui->btn_open_1->setDisabled(true);
    ui->btn_close_1->setEnabled(true);
    ui->checkBox_12->setEnabled(true);
    ui->btn_send_1->setEnabled(true);
    ui->textEdit_12->setEnabled(true);

    ui->radioButton_11_hex_2->setEnabled(true);
    ui->radioButton_11_hex->setEnabled(true);

    connect(ui->textEdit_11, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
}
void MainWindow::handleResults_open1_false()
{
    time_clear1->stop();
    worker_open1->flag1 = false;
    intervalGen(100);
    workerThread_open1->quit();
    workerThread_open1->wait();
    QMessageBox::about(NULL, "警告", "串口打开失败");
}

void MainWindow::on_btn_open_2_clicked()    //打开2串口按键
{

    if(symbol!=1)
    {
        QMessageBox::about(NULL, "警告", "请先配置串口");
        return;
    }
    time_clear2 = new QTimer(this);
    worker_open2 = new Worker;
    workerThread_open2 = new QThread;
    worker_open2->moveToThread(workerThread_open2);
    qDebug() << "new";

    connect(this, SIGNAL(open2(QString,long)), worker_open2, SLOT(doWork_open2(QString,long)));
    connect(worker_open2,SIGNAL(result_open2()),this,SLOT(handleResults_open2()));   //打开
    connect(worker_open2,SIGNAL(result_open2_false()),this,SLOT(handleResults_open2_false()));//打开失败
    workerThread_open2->start();
    emit open2(localConfigData[1],localBaudData[1]);
    connect(worker_open2,SIGNAL(result_read2(QByteArray,int)),this,SLOT(handleResults_read2(QByteArray,int))); //读
    connect(workerThread_open2, &QThread::finished, worker_open2, &QObject::deleteLater);
    connect(this, SIGNAL(one2(QString,int,int*)), worker_open2, SLOT(doWork_one2(QString,int,int*)));//单次发送
    connect(this, SIGNAL(cycle2(QString,int,int*)), worker_open2, SLOT(doWork_cycle2(QString,int,int*))); //循环
    //connect(worker_open1,SIGNAL(result_num_cycle1(int*)),this,SLOT(handleResults_num_cycle1(int*)));

    connect(time_clear2,SIGNAL(timeout()),this,SLOT(timerUpDate2()));//定时
    time_clear2->start(500);

    connect(this, SIGNAL(close2()), worker_open2, SLOT(doWork_close2()));   //关闭
    connect(worker_open2,SIGNAL(result_close2(int)),this,SLOT(handleResults_close2()));


}
void MainWindow::handleResults_open2()
{


    ui->btn_open_2->setDisabled(true);
    ui->btn_close_2->setEnabled(true);
    ui->checkBox_22->setEnabled(true);
    ui->btn_send_2->setEnabled(true);
    ui->textEdit_22->setEnabled(true);
    ui->radioButton_22_hex_2->setEnabled(true);
    ui->radioButton_22_hex->setEnabled(true);


    connect(ui->textEdit_21, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));


}
void MainWindow::handleResults_open2_false()
{
    time_clear2->stop();
    worker_open2->flag2 = false;
    intervalGen(100);
    workerThread_open2->quit();
    workerThread_open2->wait();
    QMessageBox::about(NULL, "警告", "串口打开失败");
}

void MainWindow::on_btn_open_3_clicked()    //打开3串口按键
{


    //  ui->textEdit_32->setEnabled(true);
    if(symbol!=1)
    {
        QMessageBox::about(NULL, "警告", "请先配置串口");
        return;
    }
    time_clear3 = new QTimer(this);
    worker_open3 = new Worker;
    workerThread_open3 = new QThread;
    worker_open3->moveToThread(workerThread_open3);

    connect(this, SIGNAL(open3(QString,long)), worker_open3, SLOT(doWork_open3(QString,long)));
    connect(worker_open3,SIGNAL(result_open3()),this,SLOT(handleResults_open3()));   //打开
    connect(worker_open3,SIGNAL(result_open3_false()),this,SLOT(handleResults_open3_false()));//打开失败
    //connect(worker_open1,SIGNAL(result_num_one(int*)),this,SLOT(handleResults_num_one1(int*)));  //返回字数
    workerThread_open3->start();
    emit open3(localConfigData[2],localBaudData[2]);
    connect(worker_open3,SIGNAL(result_read3(QByteArray,int)),this,SLOT(handleResults_read3(QByteArray,int))); //读
    connect(workerThread_open3, &QThread::finished, worker_open3, &QObject::deleteLater);
    connect(this, SIGNAL(one3(QString,int,int*)), worker_open3, SLOT(doWork_one3(QString,int,int*)));//单次发送
    connect(this, SIGNAL(cycle3(QString,int,int*)), worker_open3, SLOT(doWork_cycle3(QString,int,int*))); //循环
    //connect(worker_open1,SIGNAL(result_num_cycle1(int*)),this,SLOT(handleResults_num_cycle1(int*)));

    connect(time_clear3,SIGNAL(timeout()),this,SLOT(timerUpDate3()));//定时
    time_clear3->start(500);
    connect(this, SIGNAL(close3()), worker_open3, SLOT(doWork_close3()));
    connect(worker_open3,SIGNAL(result_close3(int)),this,SLOT(handleResults_close3()));

}
void MainWindow::handleResults_open3()
{


    ui->btn_open_3->setDisabled(true);
    ui->btn_close_3->setEnabled(true);
    ui->checkBox_32->setEnabled(true);
    ui->btn_send_3->setEnabled(true);
    ui->textEdit_32->setEnabled(true);
    ui->radioButton_33_hex_2->setEnabled(true);
    ui->radioButton_33_hex->setEnabled(true);


    connect(ui->textEdit_31, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
}
void MainWindow::handleResults_open3_false()
{
    time_clear3->stop();
    worker_open3->flag3 = false;
    intervalGen(100);
    workerThread_open3->quit();
    workerThread_open3->wait();
    QMessageBox::about(NULL, "警告", "串口打开失败");
}
void MainWindow::on_btn_open_4_clicked()    //打开4串口按键
{

    if(symbol!=1)
    {
        QMessageBox::about(NULL, "警告", "请先配置串口");
        return;
    }
    time_clear4 = new QTimer(this);
    worker_open4 = new Worker;
    workerThread_open4 = new QThread;
    worker_open4->moveToThread(workerThread_open4);

    connect(this, SIGNAL(open4(QString,long)), worker_open4, SLOT(doWork_open4(QString,long)));
    connect(worker_open4,SIGNAL(result_open4()),this,SLOT(handleResults_open4()));   //打开
    connect(worker_open4,SIGNAL(result_open4_false()),this,SLOT(handleResults_open4_false()));//打开失败
    //connect(worker_open1,SIGNAL(result_num_one(int*)),this,SLOT(handleResults_num_one1(int*)));  //返回字数
    workerThread_open4->start();
    emit open4(localConfigData[3],localBaudData[3]);
    connect(worker_open4,SIGNAL(result_read4(QByteArray,int)),this,SLOT(handleResults_read4(QByteArray,int))); //读
    connect(workerThread_open4, &QThread::finished, worker_open4, &QObject::deleteLater);
    connect(this, SIGNAL(one4(QString,int,int*)), worker_open4, SLOT(doWork_one4(QString,int,int*)));//单次发送
    connect(this, SIGNAL(cycle4(QString,int,int*)), worker_open4, SLOT(doWork_cycle4(QString,int,int*))); //循环
    //connect(worker_open1,SIGNAL(result_num_cycle1(int*)),this,SLOT(handleResults_num_cycle1(int*)));

    connect(time_clear4,SIGNAL(timeout()),this,SLOT(timerUpDate4()));//定时
    time_clear4->start(500);

    connect(this, SIGNAL(close4()), worker_open4, SLOT(doWork_close4()));
    connect(worker_open4,SIGNAL(result_close4(int)),this,SLOT(handleResults_close4()));

}
void MainWindow::handleResults_open4()
{


    ui->btn_open_4->setDisabled(true);
    ui->btn_close_4->setEnabled(true);
    ui->checkBox_42->setEnabled(true);
    ui->btn_send_4->setEnabled(true);
    ui->textEdit_42->setEnabled(true);
    ui->radioButton_44_hex_2->setEnabled(true);
    ui->radioButton_44_hex->setEnabled(true);


    connect(ui->textEdit_41, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
}
void MainWindow::handleResults_open4_false()
{
    time_clear4->stop();
    worker_open4->flag4 = false;
    intervalGen(100);
    workerThread_open4->quit();
    workerThread_open4->wait();
    QMessageBox::about(NULL, "警告", "串口打开失败");
}

void MainWindow::on_btn_open_5_clicked()    //打开5串口按键
{


    // ui->textEdit_52->setEnabled(true);

    if(symbol!=1)
    {
        QMessageBox::about(NULL, "警告", "请先配置串口");
        return;
    }
    time_clear5 = new QTimer(this);
    worker_open5 = new Worker;
    workerThread_open5 = new QThread;
    worker_open5->moveToThread(workerThread_open5);

    connect(this, SIGNAL(open5(QString,long)), worker_open5, SLOT(doWork_open5(QString,long)));
    connect(worker_open5,SIGNAL(result_open5()),this,SLOT(handleResults_open5()));   //打开
    connect(worker_open5,SIGNAL(result_open5_false()),this,SLOT(handleResults_open5_false()));//打开失败

    workerThread_open5->start();
    emit open5(localConfigData[4],localBaudData[4]);
    connect(worker_open5,SIGNAL(result_read5(QByteArray,int)),this,SLOT(handleResults_read5(QByteArray,int))); //读
    connect(workerThread_open5, &QThread::finished, worker_open5, &QObject::deleteLater);
    connect(this, SIGNAL(one5(QString,int,int*)), worker_open5, SLOT(doWork_one5(QString,int,int*)));//单次发送
    connect(this, SIGNAL(cycle5(QString,int,int*)), worker_open5, SLOT(doWork_cycle5(QString,int,int*))); //循环
    //connect(worker_open1,SIGNAL(result_num_cycle1(int*)),this,SLOT(handleResults_num_cycle1(int*)));

    connect(time_clear5,SIGNAL(timeout()),this,SLOT(timerUpDate5()));//定时
    time_clear5->start(500);
    connect(this, SIGNAL(close5()), worker_open5, SLOT(doWork_close5()));
    connect(worker_open5,SIGNAL(result_close5(int)),this,SLOT(handleResults_close5()));

}
void MainWindow::handleResults_open5()
{
    ui->btn_open_5->setDisabled(true);
    ui->btn_close_5->setEnabled(true);
    ui->checkBox_52->setEnabled(true);
    ui->btn_send_5->setEnabled(true);
    ui->textEdit_52->setEnabled(true);
    ui->radioButton_55_hex_2->setEnabled(true);
    ui->radioButton_55_hex->setEnabled(true);
    connect(ui->textEdit_51, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
}
void MainWindow::handleResults_open5_false()
{
    time_clear5->stop();
    worker_open5->flag5 = false;
    intervalGen(100);
    workerThread_open5->quit();
    workerThread_open5->wait();
    QMessageBox::about(NULL, "警告", "串口打开失败");
}

void MainWindow::on_btn_open_6_clicked()    //打开6串口按键
{


    //ui->textEdit_62->setEnabled(true);

    if(symbol!=1)
    {
        QMessageBox::about(NULL, "警告", "请先配置串口");
        return;
    }
    time_clear6 = new QTimer(this);
    worker_open6 = new Worker;
    workerThread_open6 = new QThread;
    worker_open6->moveToThread(workerThread_open6);

    connect(this, SIGNAL(open6(QString,long)), worker_open6, SLOT(doWork_open6(QString,long)));
    connect(worker_open6,SIGNAL(result_open6()),this,SLOT(handleResults_open6()));   //打开
    connect(worker_open6,SIGNAL(result_open6_false()),this,SLOT(handleResults_open6_false()));//打开失败

    workerThread_open6->start();
    emit open6(localConfigData[5],localBaudData[5]);
    connect(worker_open6,SIGNAL(result_read6(QByteArray,int)),this,SLOT(handleResults_read6(QByteArray,int))); //读
    connect(workerThread_open6, &QThread::finished, worker_open6, &QObject::deleteLater);
    connect(this, SIGNAL(one6(QString,int,int*)), worker_open6, SLOT(doWork_one6(QString,int,int*)));//单次发送
    connect(this, SIGNAL(cycle6(QString,int,int*)), worker_open6, SLOT(doWork_cycle6(QString,int,int*))); //循环
    //connect(worker_open1,SIGNAL(result_num_cycle1(int*)),this,SLOT(handleResults_num_cycle1(int*)));

    connect(time_clear6,SIGNAL(timeout()),this,SLOT(timerUpDate6()));//定时
    time_clear6->start(500);
    connect(this, SIGNAL(close6()), worker_open6, SLOT(doWork_close6()));
    connect(worker_open6,SIGNAL(result_close6(int)),this,SLOT(handleResults_close6()));

    //workerThread_open1.start();
}

void MainWindow::handleResults_open6()
{
    ui->btn_open_6->setDisabled(true);
    ui->btn_close_6->setEnabled(true);
    ui->checkBox_62->setEnabled(true);
    ui->btn_send_6->setEnabled(true);
    ui->textEdit_62->setEnabled(true);
    ui->radioButton_66_hex_2->setEnabled(true);
    ui->radioButton_66_hex->setEnabled(true);
    connect(ui->textEdit_61, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
}
void MainWindow::handleResults_open6_false()
{
    time_clear6->stop();
    worker_open6->flag6 = false;
    intervalGen(100);
    workerThread_open6->quit();
    workerThread_open6->wait();
    QMessageBox::about(NULL, "警告", "串口打开失败");
}

void MainWindow::on_btn_open_7_clicked()    //打开6串口按键
{

    if(symbol!=1)
    {
        QMessageBox::about(NULL, "警告", "请先配置串口");
        return;
    }
    time_clear7 = new QTimer(this);
    worker_open7 = new Worker;
    workerThread_open7 = new QThread;
    worker_open7->moveToThread(workerThread_open7);

    connect(this, SIGNAL(open7(QString,long)), worker_open7, SLOT(doWork_open7(QString,long)));
    connect(worker_open7,SIGNAL(result_open7()),this,SLOT(handleResults_open7()));   //打开
    connect(worker_open7,SIGNAL(result_open7_false()),this,SLOT(handleResults_open7_false()));//打开失败

    workerThread_open7->start();
    emit open7(localConfigData[6],localBaudData[6]);
    connect(worker_open7,SIGNAL(result_read7(QByteArray,int)),this,SLOT(handleResults_read7(QByteArray,int))); //读
    connect(workerThread_open7, &QThread::finished, worker_open7, &QObject::deleteLater);
    connect(this, SIGNAL(one7(QString,int,int*)), worker_open7, SLOT(doWork_one7(QString,int,int*)));//单次发送
    connect(this, SIGNAL(cycle7(QString,int,int*)), worker_open7, SLOT(doWork_cycle7(QString,int,int*))); //循环
    //connect(worker_open1,SIGNAL(result_num_cycle1(int*)),this,SLOT(handleResults_num_cycle1(int*)));

    connect(time_clear7,SIGNAL(timeout()),this,SLOT(timerUpDate7()));//定时
    time_clear7->start(500);
    connect(this, SIGNAL(close7()), worker_open7, SLOT(doWork_close7()));
    connect(worker_open7,SIGNAL(result_close7(int)),this,SLOT(handleResults_close7()));

}

void MainWindow::handleResults_open7()
{
    ui->btn_open_7->setDisabled(true);
    ui->btn_close_7->setEnabled(true);
    ui->checkBox_72->setEnabled(true);
    ui->btn_send_7->setEnabled(true);
    ui->textEdit_72->setEnabled(true);
    ui->radioButton_77_hex_2->setEnabled(true);
    ui->radioButton_77_hex->setEnabled(true);
    connect(ui->textEdit_71, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
}
void MainWindow::handleResults_open7_false()
{
    time_clear7->stop();
    worker_open7->flag7 = false;
    intervalGen(100);
    workerThread_open7->quit();
    workerThread_open7->wait();
    QMessageBox::about(NULL, "警告", "串口打开失败");
}
void MainWindow::on_btn_open_8_clicked()    //打开8串口按键
{
    if(symbol!=1)
    {
        QMessageBox::about(NULL, "警告", "请先配置串口");
        return;
    }
    time_clear8 = new QTimer(this);
    worker_open8 = new Worker;
    workerThread_open8 = new QThread;
    worker_open8->moveToThread(workerThread_open8);

    connect(this, SIGNAL(open8(QString,long)), worker_open8, SLOT(doWork_open8(QString,long)));
    connect(worker_open8,SIGNAL(result_open8()),this,SLOT(handleResults_open8()));   //打开
    connect(worker_open8,SIGNAL(result_open8_false()),this,SLOT(handleResults_open8_false()));//打开失败

    workerThread_open8->start();
    emit open8(localConfigData[7],localBaudData[7]);
    connect(worker_open8,SIGNAL(result_read8(QByteArray,int)),this,SLOT(handleResults_read8(QByteArray,int))); //读
    connect(workerThread_open8, &QThread::finished, worker_open8, &QObject::deleteLater);
    connect(this, SIGNAL(one8(QString,int,int*)), worker_open8, SLOT(doWork_one8(QString,int,int*)));//单次发送
    connect(this, SIGNAL(cycle8(QString,int,int*)), worker_open8, SLOT(doWork_cycle8(QString,int,int*))); //循环
    //connect(worker_open1,SIGNAL(result_num_cycle1(int*)),this,SLOT(handleResults_num_cycle1(int*)));

    connect(time_clear8,SIGNAL(timeout()),this,SLOT(timerUpDate8()));//定时
    time_clear8->start(500);
    connect(this, SIGNAL(close8()), worker_open8, SLOT(doWork_close8()));
    connect(worker_open8,SIGNAL(result_close8(int)),this,SLOT(handleResults_close8()));

}

void MainWindow::handleResults_open8()
{
    ui->btn_open_8->setDisabled(true);
    ui->btn_close_8->setEnabled(true);
    ui->checkBox_82->setEnabled(true);
    ui->btn_send_8->setEnabled(true);
    ui->textEdit_82->setEnabled(true);
    ui->radioButton_88_hex_2->setEnabled(true);
    ui->radioButton_88_hex->setEnabled(true);
    connect(ui->textEdit_81, SIGNAL(cursorPositionChanged()), this, SLOT(updateVisibleArea()));
}
void MainWindow::handleResults_open8_false()
{
    time_clear8->stop();
    worker_open8->flag8 = false;
    intervalGen(100);
    workerThread_open8->quit();
    workerThread_open8->wait();
    QMessageBox::about(NULL, "警告", "串口打开失败");
}


void MainWindow::handleResults_read1(QByteArray readData, int num)
{
    qDebug() << "rec" << num;
    recvCnt[0] += num;
    data1.append(readData);
}

void MainWindow::handleResults_read2(QByteArray readData, int num)
{

    recvCnt[1] += num;
    data2.append(readData);
}

void MainWindow::handleResults_read3(QByteArray readData, int num)
{
    recvCnt[2] += num;
    data3.append(readData);
}

void MainWindow::handleResults_read4(QByteArray readData, int num)
{
    recvCnt[3] += num;
    data4.append(readData);

}
void MainWindow::handleResults_read5(QByteArray readData, int num)
{
    recvCnt[4] += num;
    data5.append(readData);

}
void MainWindow::handleResults_read6(QByteArray readData, int num)
{
    recvCnt[5] += num;
    data6.append(readData);

}

void MainWindow::handleResults_read7(QByteArray readData, int num)
{
    recvCnt[6] += num;
    data7.append(readData);

}
void MainWindow::handleResults_read8(QByteArray readData, int num)
{
    recvCnt[7] += num;
    data8.append(readData);

}
void MainWindow::on_btn_close_1_clicked()   //关闭1串口
{

    ui->radioButton_11_hex_2->setEnabled(false);
    ui->radioButton_11_hex->setEnabled(false);
    ui->textEdit_12->setDisabled(true);

    ui->checkBox_12->setCheckState(Qt::Unchecked);
    intervalGen(100);

    emit close1();
    worker_open1->flag1 = false;



}
void MainWindow::handleResults_close1()
{
    time_clear1->stop();
    worker_open1->flag1 = false;
    ui->btn_open_1->setDisabled(false);
    ui->btn_close_1->setEnabled(false);
    ui->checkBox_12->setDisabled(true);
    ui->btn_send_1->setDisabled(true);
    workerThread_open1->quit();
    workerThread_open1->wait();
    // ui->label_16->setText("0");
}

void MainWindow::on_btn_close_2_clicked()   //关闭2串口
{

    ui->radioButton_22_hex_2->setEnabled(false);
    ui->radioButton_22_hex->setEnabled(false);
    ui->textEdit_22->setDisabled(true);


    ui->checkBox_22->setCheckState(Qt::Unchecked);
    intervalGen(100);
    //   connect(this, SIGNAL(close2()), worker_open2, SLOT(doWork_close2()));
    //    connect(worker_open2,SIGNAL(result_close2(int)),this,SLOT(handleResults_close2()));
    //workerThread_open1.start();
    emit close2();
    worker_open2->flag2 = false;
}
void MainWindow::handleResults_close2()
{
    time_clear2->stop();
    worker_open2->flag2 = false;
    ui->btn_open_2->setDisabled(false);
    ui->btn_close_2->setEnabled(false);
    ui->checkBox_22->setDisabled(true);
    ui->btn_send_2->setDisabled(true);
    workerThread_open2->quit();
    workerThread_open2->wait();

}


void MainWindow::on_btn_close_3_clicked()   //关闭3串口
{

    ui->radioButton_33_hex_2->setEnabled(false);
    ui->radioButton_33_hex->setEnabled(false);
    ui->textEdit_32->setDisabled(true);

    ui->checkBox_32->setCheckState(Qt::Unchecked);
    intervalGen(100);
    emit close3();
    worker_open3->flag3 = false;
}
void MainWindow::handleResults_close3()
{
    ui->btn_open_3->setDisabled(false);
    ui->btn_close_3->setEnabled(false);
    ui->checkBox_32->setDisabled(true);
    ui->btn_send_3->setDisabled(true);
    workerThread_open3->quit();
    workerThread_open3->wait();
}
void MainWindow::on_btn_close_4_clicked()   //关闭4串口
{
    ui->radioButton_44_hex_2->setEnabled(false);
    ui->radioButton_44_hex->setEnabled(false);
    ui->textEdit_42->setDisabled(true);

    ui->checkBox_42->setCheckState(Qt::Unchecked);
    intervalGen(100);

    emit close4();
    worker_open4->flag4 = false;
}

void MainWindow::handleResults_close4()
{
    ui->btn_open_4->setDisabled(false);
    ui->btn_close_4->setEnabled(false);
    ui->checkBox_42->setDisabled(true);
    ui->btn_send_4->setDisabled(true);
    workerThread_open4->quit();
    workerThread_open4->wait();
}
void MainWindow::on_btn_close_5_clicked()   //关闭5串口
{

    ui->radioButton_55_hex_2->setEnabled(false);
    ui->radioButton_55_hex->setEnabled(false);
    ui->textEdit_52->setDisabled(true);

    ui->checkBox_52->setCheckState(Qt::Unchecked);
    intervalGen(100);
    emit close5();
    worker_open5->flag5 = false;
}
void MainWindow::handleResults_close5()
{
    ui->btn_open_5->setDisabled(false);
    ui->btn_close_5->setEnabled(false);
    ui->checkBox_52->setDisabled(true);
    ui->btn_send_5->setDisabled(true);
    workerThread_open5->quit();
    workerThread_open5->wait();

}

void MainWindow::on_btn_close_6_clicked()   //关闭5串口
{

    ui->radioButton_66_hex_2->setEnabled(false);
    ui->radioButton_66_hex->setEnabled(false);
    ui->textEdit_62->setDisabled(true);

    ui->checkBox_62->setCheckState(Qt::Unchecked);
    intervalGen(100);

    //workerThread_open1.start();
    emit close6();
    worker_open6->flag6 = false;
}
void MainWindow::handleResults_close6()
{
    ui->btn_open_6->setDisabled(false);
    ui->btn_close_6->setEnabled(false);
    ui->checkBox_62->setDisabled(true);
    ui->btn_send_6->setDisabled(true);
    workerThread_open6->quit();
    workerThread_open6->wait();

}
void MainWindow::on_btn_close_7_clicked()   //关闭5串口
{

    ui->radioButton_77_hex_2->setEnabled(false);
    ui->radioButton_77_hex->setEnabled(false);
    ui->textEdit_72->setDisabled(true);

    ui->checkBox_72->setCheckState(Qt::Unchecked);
    intervalGen(100);
    emit close7();
    worker_open7->flag7 = false;
}
void MainWindow::handleResults_close7()
{
    ui->btn_open_7->setDisabled(false);
    ui->btn_close_7->setEnabled(false);
    ui->checkBox_72->setDisabled(true);
    ui->btn_send_7->setDisabled(true);
    workerThread_open7->quit();
    workerThread_open7->wait();

}
void MainWindow::on_btn_close_8_clicked()   //关闭5串口
{

    ui->radioButton_88_hex_2->setEnabled(false);
    ui->radioButton_88_hex->setEnabled(false);
    ui->textEdit_82->setDisabled(true);

    ui->checkBox_82->setCheckState(Qt::Unchecked);
    intervalGen(100);
    emit close8();
    worker_open8->flag8 = false;
}
void MainWindow::handleResults_close8()
{
    ui->btn_open_8->setDisabled(false);
    ui->btn_close_8->setEnabled(false);
    ui->checkBox_82->setDisabled(true);
    ui->btn_send_8->setDisabled(true);
    workerThread_open8->quit();
    workerThread_open8->wait();

}
void MainWindow::on_checkBox_12_clicked()  //1循环发送
{

    QString str;

    if (ui->checkBox_12->isChecked() ) {//重复发被选上
        ui->btn_send_1->setDisabled(true);
        worker_open1->flag1 = true;
        ui->spinBox_11->setDisabled(true);
        ui->textEdit_12->setDisabled(true);
        ui->btn_clr_12->setDisabled(true);
        str = ui->textEdit_12->toPlainText();  //发送框
        emit cycle1(str,ui->spinBox_11->value(), &sendCnt[0]);
    } else {
        ui->textEdit_12->setDisabled(false);
        worker_open1->flag1 = false;
        ui->spinBox_11->setDisabled(false);
        ui->btn_send_1->setEnabled(true);
        ui->btn_clr_12->setEnabled(true);
    }
}
void MainWindow::on_checkBox_22_clicked()  //2循环发送
{

    QString str;
    if (ui->checkBox_22->isChecked() ) {//串口被打开而且重复发被选上
        ui->btn_send_2->setDisabled(true);
        worker_open2->flag2 = true;
        ui->spinBox_21->setDisabled(true);
        ui->textEdit_22->setDisabled(true);
        ui->btn_clr_22->setDisabled(true);
        str = ui->textEdit_22->toPlainText();  //发送框
        emit cycle2(str,ui->spinBox_21->value(), &sendCnt[1]);
    } else {
        worker_open2->flag2 = false;
        ui->textEdit_22->setDisabled(false);
        ui->spinBox_21->setDisabled(false);
        ui->btn_send_2->setEnabled(true);
        ui->btn_clr_22->setDisabled(false);
    }
}

void MainWindow::on_checkBox_32_clicked()
{
    QString str;
    //  int i = 0;
    if (ui->checkBox_32->isChecked() ) {//串口被打开而且重复发被选上
        ui->btn_send_3->setDisabled(true);
        worker_open3->flag3 = true;
        ui->spinBox_31->setDisabled(true);
        ui->textEdit_32->setDisabled(true);
        ui->btn_clr_32->setDisabled(true);
        str = ui->textEdit_32->toPlainText();  //发送框
        emit cycle3(str,ui->spinBox_31->value(), &sendCnt[2]);
    } else {
        worker_open3->flag3 = false;
        ui->textEdit_32->setDisabled(false);
        ui->spinBox_31->setDisabled(false);
        ui->btn_send_3->setEnabled(true);
        ui->btn_clr_32->setDisabled(false);
    }

}
void MainWindow::on_checkBox_42_clicked()
{
    QString str;
    if (ui->checkBox_42->isChecked() ) {//串口被打开而且重复发被选上
        ui->btn_send_4->setDisabled(true);
        worker_open4->flag4 = true;
        ui->spinBox_41->setDisabled(true);
        ui->textEdit_42->setDisabled(true);
        ui->btn_clr_42->setDisabled(true);
        str = ui->textEdit_42->toPlainText();  //发送框
        emit cycle4(str,ui->spinBox_41->value(), &sendCnt[3]);
    } else {
        worker_open4->flag4 = false;
        ui->textEdit_42->setDisabled(false);
        ui->spinBox_41->setDisabled(false);
        ui->btn_send_4->setEnabled(true);
        ui->btn_clr_42->setDisabled(false);
    }
}

void MainWindow::on_checkBox_52_clicked()  //5循环发送
{

    QString str;
    if (ui->checkBox_52->isChecked() ) {//串口被打开而且重复发被选上
        ui->btn_send_5->setDisabled(true);
        worker_open5->flag5 = true;
        ui->spinBox_51->setDisabled(true);
        ui->textEdit_52->setDisabled(true);
        ui->btn_clr_52->setDisabled(true);
        str = ui->textEdit_52->toPlainText();  //发送框
        emit cycle5(str,ui->spinBox_51->value(), &sendCnt[4]);
    } else {
        worker_open5->flag5 = false;
        ui->textEdit_52->setDisabled(false);
        ui->spinBox_51->setDisabled(false);
        ui->btn_send_5->setEnabled(true);
        ui->btn_clr_52->setDisabled(false);
    }

}


void MainWindow::on_checkBox_62_clicked()  //5循环发送
{

    QString str;
    if (ui->checkBox_62->isChecked() ) {//串口被打开而且重复发被选上
        ui->btn_send_6->setDisabled(true);
        worker_open6->flag6 = true;
        ui->textEdit_62->setDisabled(true);
        ui->spinBox_61->setDisabled(true);
        ui->btn_clr_62->setDisabled(true);
        str = ui->textEdit_62->toPlainText();  //发送框
        emit cycle6(str,ui->spinBox_61->value(), &sendCnt[5]);
    } else {
        worker_open6->flag6 = false;
        ui->textEdit_62->setDisabled(false);
        ui->spinBox_61->setDisabled(false);
        ui->btn_send_6->setEnabled(true);
        ui->btn_clr_62->setDisabled(false);
    }

}
void MainWindow::on_checkBox_72_clicked()  //7循环发送
{

    QString str;
    if (ui->checkBox_72->isChecked() ) {//串口被打开而且重复发被选上
        ui->btn_send_7->setDisabled(true);
        worker_open7->flag7 = true;
        ui->textEdit_72->setDisabled(true);
        ui->spinBox_71->setDisabled(true);
        ui->btn_clr_72->setDisabled(true);
        str = ui->textEdit_72->toPlainText();  //发送框
        emit cycle7(str,ui->spinBox_71->value(), &sendCnt[6]);
    } else {
        worker_open7->flag7 = false;
        ui->textEdit_72->setDisabled(false);
        ui->spinBox_71->setDisabled(false);
        ui->btn_send_7->setEnabled(true);
        ui->btn_clr_72->setDisabled(false);
    }

}


void MainWindow::on_checkBox_82_clicked()  //7循环发送
{
    QString str;
    if (ui->checkBox_82->isChecked() ) {//串口被打开而且重复发被选上
        ui->btn_send_8->setDisabled(true);
        worker_open8->flag8 = true;
        ui->spinBox_81->setDisabled(true);
        ui->textEdit_82->setDisabled(true);
        ui->btn_clr_82->setDisabled(true);
        str = ui->textEdit_82->toPlainText();  //发送框
        emit cycle8(str,ui->spinBox_81->value(), &sendCnt[7]);
    } else {
        worker_open8->flag8 = false;
        ui->textEdit_82->setDisabled(false);
        ui->spinBox_81->setDisabled(false);
        ui->btn_send_8->setEnabled(true);
        ui->btn_clr_82->setDisabled(false);
    }

}


void MainWindow::intervalGen(int interval)
{
    QEventLoop loop;
    QTimer::singleShot(interval, &loop, SLOT(quit()));
    loop.exec();
}
void MainWindow::on_btn_clr_12_clicked()
{
    ui->textEdit_12->clear();
    sendCnt[0]=0;
    ui->label_16->setText(QString::number(sendCnt[0]));
}
void MainWindow::on_btn_clr_22_clicked()
{
    ui->textEdit_22->clear();
    sendCnt[1]=0;
    ui->label_26->setText(QString::number(sendCnt[1]));
}

void MainWindow::on_btn_clr_32_clicked()
{
    ui->textEdit_32->clear();
    sendCnt[2]=0;
    ui->label_36->setText(QString::number(sendCnt[2]));
}

void MainWindow::on_btn_clr_42_clicked()
{
    ui->textEdit_42->clear();
    sendCnt[3]=0;
    ui->label_46->setText(QString::number(sendCnt[3]));
}

void MainWindow::on_btn_clr_52_clicked()
{
    ui->textEdit_52->clear();
    sendCnt[4]=0;
    ui->label_56->setText(QString::number(sendCnt[4]));
}

void MainWindow::on_btn_clr_62_clicked()
{
    ui->textEdit_62->clear();
    sendCnt[5]=0;
    ui->label_66->setText(QString::number(sendCnt[5]));
}

void MainWindow::on_btn_clr_72_clicked()
{
    ui->textEdit_72->clear();
    sendCnt[6]=0;
    ui->label_76->setText(QString::number(sendCnt[6]));
}

void MainWindow::on_btn_clr_82_clicked()
{
    ui->textEdit_82->clear();
    sendCnt[7]=0;
    ui->label_86->setText(QString::number(sendCnt[7]));
}


void MainWindow::on_btn_clr_11_clicked()
{
    ui->textEdit_11->clear();
    recvCnt[0]=0;
    ui->label_15->setText(QString::number(recvCnt[0]));


}

void MainWindow::on_btn_clr_21_clicked()
{
    ui->textEdit_21->clear();
    recvCnt[1]=0;
    ui->label_25->setText(QString::number(recvCnt[1]));

}


void MainWindow::on_btn_clr_31_clicked()
{
    ui->textEdit_31->clear();
    recvCnt[2]=0;
    ui->label_35->setText(QString::number(recvCnt[2]));
}



void MainWindow::on_btn_clr_41_clicked()
{
    ui->textEdit_41->clear();
    recvCnt[3]=0;
    ui->label_45->setText(QString::number(recvCnt[3]));
}
void MainWindow::on_btn_clr_51_clicked()
{
    ui->textEdit_51->clear();
    recvCnt[4]=0;
    ui->label_55->setText(QString::number(recvCnt[4]));
}
void MainWindow::on_btn_clr_61_clicked()
{
    ui->textEdit_61->clear();
    recvCnt[5]=0;
    ui->label_65->setText(QString::number(recvCnt[5]));
}
void MainWindow::on_btn_clr_71_clicked()
{
    ui->textEdit_71->clear();
    recvCnt[6]=0;
    ui->label_75->setText(QString::number(recvCnt[6]));
}
void MainWindow::on_btn_clr_81_clicked()
{
    ui->textEdit_81->clear();
    recvCnt[7]=0;
    ui->label_85->setText(QString::number(recvCnt[7]));
}
void MainWindow::updateVisibleArea()
{
    ui->textEdit_11->setTextCursor(ui->textEdit_11->textCursor());
    ui->textEdit_21->setTextCursor(ui->textEdit_21->textCursor());
    ui->textEdit_31->setTextCursor(ui->textEdit_31->textCursor());
    ui->textEdit_41->setTextCursor(ui->textEdit_41->textCursor());
    ui->textEdit_51->setTextCursor(ui->textEdit_51->textCursor());
    ui->textEdit_61->setTextCursor(ui->textEdit_61->textCursor());
    ui->textEdit_71->setTextCursor(ui->textEdit_71->textCursor());
    ui->textEdit_81->setTextCursor(ui->textEdit_81->textCursor());
}
void MainWindow::closeEvent(QCloseEvent*)
{


    if (worker_open1 != NULL && workerThread_open1 != NULL) {

        time_clear1->stop();
        worker_open1->flag1 = false;
        intervalGen(100);
        workerThread_open1->quit();
        workerThread_open1->wait();

    }

    if (worker_open2 != NULL && workerThread_open2 != NULL) {

        time_clear2->stop();
        worker_open2->flag2 = false;
        intervalGen(100);
        workerThread_open2->quit();
        workerThread_open2->wait();

    }
    if (worker_open3 != NULL && workerThread_open3 != NULL) {

        time_clear3->stop();
        worker_open3->flag3 = false;
        intervalGen(100);
        workerThread_open3->quit();
        workerThread_open3->wait();

    }
    if (worker_open4 != NULL && workerThread_open4 != NULL) {

        time_clear4->stop();
        worker_open4->flag4 = false;
        intervalGen(100);
        workerThread_open4->quit();
        workerThread_open4->wait();

    }
    if (worker_open5 != NULL && workerThread_open5 != NULL) {

        time_clear5->stop();
        worker_open5->flag5 = false;
        intervalGen(100);
        workerThread_open5->quit();
        workerThread_open5->wait();

    }
    if (worker_open6 != NULL && workerThread_open6 != NULL) {

        time_clear6->stop();
        worker_open6->flag6 = false;
        intervalGen(100);
        workerThread_open6->quit();
        workerThread_open6->wait();

    }
    if (worker_open7 != NULL && workerThread_open7 != NULL) {

        time_clear7->stop();
        worker_open7->flag7 = false;
        intervalGen(100);
        workerThread_open7->quit();
        workerThread_open7->wait();

    }
    if (worker_open8 != NULL && workerThread_open8 != NULL) {

        time_clear8->stop();
        worker_open8->flag8 = false;
        intervalGen(100);
        workerThread_open8->quit();
        workerThread_open8->wait();

    }

    /*   if ((port3 != NULL)&&port3->isOpen()) {

        ui->checkBox_32->setCheckState(Qt::Unchecked);
        intervalGen(100);

        port3->close();

    }
     if ((port4 != NULL)&&port4->isOpen()) {

        ui->checkBox_42->setCheckState(Qt::Unchecked);
        intervalGen(100);

        port4->close();

    }
  if ((port5 != NULL)&&port5->isOpen()) {

        ui->checkBox_52->setCheckState(Qt::Unchecked);
        intervalGen(100);

        port5->close();

    }
    if ((port6 != NULL)&&port6->isOpen()) {

        ui->checkBox_62->setCheckState(Qt::Unchecked);
        intervalGen(100);

        port6->close();

    }
    if ((port7 != NULL)&&port7->isOpen()) {

        ui->checkBox_72->setCheckState(Qt::Unchecked);
        intervalGen(100);

        port7->close();

    }
     if ((port8 != NULL)&&port8->isOpen()) {

        ui->checkBox_82->setCheckState(Qt::Unchecked);
        intervalGen(100);

        port8->close();

    }*/
}


void MainWindow::on_radioButton_11_ascii_2_clicked()
{
    symbol_11_ascii_2=1;
    worker_open1->isHex1 = false;
}

void MainWindow::on_radioButton_11_hex_2_clicked()
{
    symbol_11_ascii_2=0;
    worker_open1->isHex1 = true;
}

void MainWindow::on_radioButton_11_ascii_clicked()
{
    symbol_11_ascii=1;
}

void MainWindow::on_radioButton_11_hex_clicked()
{
    symbol_11_ascii=0;
}

void MainWindow::on_radioButton_22_ascii_2_clicked()
{
    symbol_22_ascii_2=1;
    worker_open2->isHex2 = false;
}

void MainWindow::on_radioButton_22_hex_2_clicked()
{
    symbol_22_ascii_2=0;
    worker_open2->isHex2 = true;
}

void MainWindow::on_radioButton_22_ascii_clicked()
{
    symbol_22_ascii=1;
}

void MainWindow::on_radioButton_22_hex_clicked()
{
    symbol_22_ascii=0;
}

void MainWindow::on_radioButton_33_ascii_2_clicked()
{
    symbol_33_ascii_2=1;
    worker_open3->isHex3 = false;
}

void MainWindow::on_radioButton_33_hex_2_clicked()
{
    symbol_33_ascii_2=0;
    worker_open3->isHex3 = true;
}

void MainWindow::on_radioButton_33_ascii_clicked()
{
    symbol_33_ascii=1;
}

void MainWindow::on_radioButton_33_hex_clicked()
{
    symbol_33_ascii=0;
}


void MainWindow::on_radioButton_44_ascii_2_clicked()
{
    symbol_44_ascii_2=1;
    worker_open4->isHex4 = false;
}

void MainWindow::on_radioButton_44_hex_2_clicked()
{
    symbol_44_ascii_2=0;
    worker_open4->isHex4 = true;
}

void MainWindow::on_radioButton_44_ascii_clicked()
{
    symbol_44_ascii=1;
}

void MainWindow::on_radioButton_44_hex_clicked()
{
    symbol_44_ascii=0;
}


void MainWindow::on_radioButton_55_ascii_2_clicked()
{
    symbol_55_ascii_2=1;
    worker_open5->isHex5 = false;
}

void MainWindow::on_radioButton_55_hex_2_clicked()
{
    symbol_55_ascii_2=0;
    worker_open5->isHex5 = true;
}

void MainWindow::on_radioButton_55_ascii_clicked()
{
    symbol_55_ascii=1;
}

void MainWindow::on_radioButton_55_hex_clicked()
{
    symbol_55_ascii=0;
}


void MainWindow::on_radioButton_66_ascii_2_clicked()
{
    symbol_66_ascii_2=1;
    worker_open6->isHex6 = false;
}

void MainWindow::on_radioButton_66_hex_2_clicked()
{
    symbol_66_ascii_2=0;
    worker_open6->isHex6 = true;
}

void MainWindow::on_radioButton_66_ascii_clicked()
{
    symbol_66_ascii=1;
}

void MainWindow::on_radioButton_66_hex_clicked()
{
    symbol_66_ascii=0;
}

void MainWindow::on_radioButton_77_ascii_2_clicked()
{
    symbol_77_ascii_2=1;
    worker_open7->isHex7 = false;
}

void MainWindow::on_radioButton_77_hex_2_clicked()
{
    symbol_77_ascii_2=0;
    worker_open7->isHex7 = true;
}

void MainWindow::on_radioButton_77_ascii_clicked()
{
    symbol_77_ascii=1;
}

void MainWindow::on_radioButton_77_hex_clicked()
{
    symbol_77_ascii=0;
}

void MainWindow::on_radioButton_88_ascii_2_clicked()
{
    symbol_88_ascii_2=1;
    worker_open8->isHex8 = false;
}

void MainWindow::on_radioButton_88_hex_2_clicked()
{
    symbol_88_ascii_2=0;
    worker_open8->isHex8 = true;
}

void MainWindow::on_radioButton_88_ascii_clicked()
{
    symbol_88_ascii=1;
}

void MainWindow::on_radioButton_88_hex_clicked()
{
    symbol_88_ascii=0;
}


void MainWindow::limitCharsInTextEdit(const QTextEdit* textEdit, const int maxChars)
{

    int currentCount = textEdit->document()->characterCount();

    if(currentCount > (maxChars + (maxChars / 5)))
    {
        QTextCursor tc = textEdit->textCursor();
        tc.setPosition(0);
        tc.setPosition(currentCount - (maxChars + 1), QTextCursor::KeepAnchor);
        tc.removeSelectedText();
        tc.movePosition( QTextCursor::End, QTextCursor::MoveAnchor );
    }
}

