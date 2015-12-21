#include "configdialog.h"
#include "ui_configdialog.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QFile>
extern int  symbol;
extern int  symbol_write;
extern int  symbol_read;
QStringList config_read;
QStringList Baud_read;
ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDialog)
{

    ui->setupUi(this);

    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();

    foreach (const QSerialPortInfo &serialPortInfo, serialPortInfoList) {
        ui->comboBox11->addItem(serialPortInfo.portName());
        ui->comboBox21->addItem(serialPortInfo.portName());
        ui->comboBox31->addItem(serialPortInfo.portName());
        ui->comboBox41->addItem(serialPortInfo.portName());
        ui->comboBox51->addItem(serialPortInfo.portName());
        ui->comboBox61->addItem(serialPortInfo.portName());
        ui->comboBox71->addItem(serialPortInfo.portName());
        ui->comboBox81->addItem(serialPortInfo.portName());

    }


    InitBaudrateComboBox(ui->comboBox12);
    InitBaudrateComboBox(ui->comboBox22);
    InitBaudrateComboBox(ui->comboBox32);
    InitBaudrateComboBox(ui->comboBox42);
    InitBaudrateComboBox(ui->comboBox52);
    InitBaudrateComboBox(ui->comboBox62);
    InitBaudrateComboBox(ui->comboBox72);
    InitBaudrateComboBox(ui->comboBox82);

}

ConfigDialog::~ConfigDialog()
{
    delete ui;
}

void ConfigDialog::InitBaudrateComboBox(QComboBox* box)
{
    box->addItem("9600");
    box->addItem("19200");
    box->addItem("38400");
    box->addItem("57600");
    box->addItem("115200");
}

void ConfigDialog::on_btn_ok_clicked()
{
    QStringList configData;
    QStringList BaudData;
    int i=0;
    symbol_write=1;
    symbol=1;
    configData << ui->comboBox11->currentText();
    configData << ui->comboBox21->currentText();
    configData << ui->comboBox31->currentText();
    configData << ui->comboBox41->currentText();
    configData << ui->comboBox51->currentText();
    configData << ui->comboBox61->currentText();
    configData << ui->comboBox71->currentText();
    configData << ui->comboBox81->currentText();

    emit sendConfigData(configData);

    BaudData << ui->comboBox12->currentText();
    BaudData << ui->comboBox22->currentText();
    BaudData << ui->comboBox32->currentText();
    BaudData << ui->comboBox42->currentText();
    BaudData << ui->comboBox52->currentText();
    BaudData << ui->comboBox62->currentText();
    BaudData << ui->comboBox72->currentText();
    BaudData << ui->comboBox82->currentText();

    emit sendBaudData(BaudData);



    QFile file(QCoreApplication::applicationDirPath() + "/config.ini");  //当前路径
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    for(i=0;i<8;i++)
    {
        file.write(configData[i].toLocal8Bit() + "\n",          //向文本中写入串口号
                   configData[i].size()+1);
    }


    for(i=0;i<8;i++)
    {
        file.write(BaudData[i].toLocal8Bit() + "\n",          //向文本中写入波特率
                   BaudData[i].size()+1);
    }
    file.close();



    QDialog::accept();

}

void ConfigDialog::on_btn_old_clicked()
{
    int i=0;
    symbol=1;
    symbol_read=1;
    QFile file(QCoreApplication::applicationDirPath() + "/config.ini");  //当前路径
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    for(i=0;i<16;i++)
    {
        if(i<8)
        {
            QByteArray line = file.readLine().trimmed();    //trimeed()去除读上来的“回车”
            QString str(line);
            config_read << str;
        }
        else
        {
            QByteArray line1 = file.readLine();
            QString str1(line1);
            Baud_read << str1;
        }
    }

    emit sendBaudData(Baud_read);
    emit sendConfigData(config_read);
    QDialog::accept();

}
