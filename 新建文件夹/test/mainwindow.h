#ifndef MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTextEdit>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void limitCharsInTextEdit(const QTextEdit* textEdit, const int maxChars);
    void intervalGen(int interval);
    Ui::MainWindow *ui;
    QStringList localConfigData;
    long int localBaudData[8];
  /*  QSerialPort* port7;
    QSerialPort* port8;
    QSerialPort* port6;
    QSerialPort* port5;
    QSerialPort* port4;
    QSerialPort* port3;
    QSerialPort* port2;
    QSerialPort* port1;*/
    int sendCnt[8];
    int recvCnt[8];
    QByteArray data1;
    QByteArray data2;
    QByteArray data3;
    QByteArray data4;
    QByteArray data5;
    QByteArray data6;
    QByteArray data7;
    QByteArray data8;

    QTimer *time_clear1;
    QTimer *time_clear2;
    QTimer *time_clear3;
    QTimer *time_clear4;
    QTimer *time_clear5;
    QTimer *time_clear6;
    QTimer *time_clear7;
    QTimer *time_clear8;
    //QString send_str1;

private slots:
    void on_btn_config_clicked();
    void recvConfigData(QStringList configData);
    void recvBaudData(QStringList BaudData);


    void handleResults_open1();
    void handleResults_open2();
    void handleResults_open3();
    void handleResults_open4();
    void handleResults_open5();
    void handleResults_open6();
    void handleResults_open7();
    void handleResults_open8();
    void on_btn_send_1_clicked();

    void on_btn_open_1_clicked();

    void on_btn_close_1_clicked();
  //  void read1Port();

    void on_checkBox_12_clicked();

    void on_btn_clr_11_clicked();

    void on_btn_clr_12_clicked();



    void on_btn_send_2_clicked();

    void on_btn_open_2_clicked();

    void on_btn_close_2_clicked();
 //   void read2Port();

    void on_checkBox_22_clicked();

    void on_btn_clr_21_clicked();

    void on_btn_clr_22_clicked();



    void on_btn_send_3_clicked();

    void on_btn_open_3_clicked();

    void on_btn_close_3_clicked();
 //   void read3Port();

    void on_checkBox_32_clicked();

    void on_btn_clr_31_clicked();

    void on_btn_clr_32_clicked();





    void on_btn_send_4_clicked();

    void on_btn_open_4_clicked();

    void on_btn_close_4_clicked();
    //void read4Port();

    void on_checkBox_42_clicked();

    void on_btn_clr_41_clicked();

    void on_btn_clr_42_clicked();


    void on_btn_send_5_clicked();

    void on_btn_open_5_clicked();

    void on_btn_close_5_clicked();
    //void read5Port();

    void on_checkBox_52_clicked();

    void on_btn_clr_51_clicked();

    void on_btn_clr_52_clicked();



    void on_btn_send_6_clicked();

    void on_btn_open_6_clicked();

    void on_btn_close_6_clicked();
   // void read6Port();

    void on_checkBox_62_clicked();

    void on_btn_clr_61_clicked();

    void on_btn_clr_62_clicked();



    void on_btn_send_7_clicked();

    void on_btn_open_7_clicked();

    void on_btn_close_7_clicked();
    //void read7Port();

    void on_checkBox_72_clicked();

    void on_btn_clr_71_clicked();

    void on_btn_clr_72_clicked();






    void on_btn_send_8_clicked();

    void on_btn_open_8_clicked();

    void on_btn_close_8_clicked();
   // void read8Port();

    void on_checkBox_82_clicked();

    void on_btn_clr_81_clicked();

    void on_btn_clr_82_clicked();

    void updateVisibleArea();
    void closeEvent(QCloseEvent*);



    void on_radioButton_11_ascii_2_clicked();

    void on_radioButton_11_hex_2_clicked();

    void on_radioButton_11_ascii_clicked();

    void on_radioButton_11_hex_clicked();
    void on_radioButton_22_ascii_2_clicked();

    void on_radioButton_22_hex_2_clicked();

    void on_radioButton_22_ascii_clicked();

    void on_radioButton_22_hex_clicked();

    void on_radioButton_33_ascii_2_clicked();

    void on_radioButton_33_hex_2_clicked();

    void on_radioButton_33_ascii_clicked();

    void on_radioButton_33_hex_clicked();


    void on_radioButton_44_ascii_2_clicked();

    void on_radioButton_44_hex_2_clicked();

    void on_radioButton_44_ascii_clicked();

    void on_radioButton_44_hex_clicked();

    void on_radioButton_55_ascii_2_clicked();

    void on_radioButton_55_hex_2_clicked();

    void on_radioButton_55_ascii_clicked();

    void on_radioButton_55_hex_clicked();


    void on_radioButton_66_ascii_2_clicked();

    void on_radioButton_66_hex_2_clicked();

    void on_radioButton_66_ascii_clicked();

    void on_radioButton_66_hex_clicked();

    void on_radioButton_77_ascii_2_clicked();

    void on_radioButton_77_hex_2_clicked();

    void on_radioButton_77_ascii_clicked();

    void on_radioButton_77_hex_clicked();


    void on_radioButton_88_ascii_2_clicked();

    void on_radioButton_88_hex_2_clicked();

    void on_radioButton_88_ascii_clicked();

    void on_radioButton_88_hex_clicked();
  //  void on_pushButton_clicked();

    void handleResults_close1();
    void handleResults_close2();
    void handleResults_close3();
    void handleResults_close4();
    void handleResults_close5();
    void handleResults_close6();
    void handleResults_close7();
    void handleResults_close8();
    void handleResults_read1(QByteArray readData, int num);
    void handleResults_read2(QByteArray readData, int num);
    void handleResults_read3(QByteArray readData, int num);
    void handleResults_read4(QByteArray readData, int num);
    void handleResults_read5(QByteArray readData, int num);
    void handleResults_read6(QByteArray readData, int num);
    void handleResults_read7(QByteArray readData, int num);
    void handleResults_read8(QByteArray readData, int num);


    //void handleResults_num_one1(int *num);
    //void handleResults_num_cycle1(int*);
    void timerUpDate1();
    void timerUpDate2();
    void timerUpDate3();
    void timerUpDate4();
    void timerUpDate5();
    void timerUpDate6();
    void timerUpDate7();
    void timerUpDate8();
    void handleResults_open1_false();
    void handleResults_open2_false();
    void handleResults_open3_false();
    void handleResults_open4_false();
    void handleResults_open5_false();
    void handleResults_open6_false();
    void handleResults_open7_false();
    void handleResults_open8_false();

//    void on_tab_currentChanged(int index);

private:

signals:
    void open1(QString,long);
    void open2(QString,long);
    void open3(QString,long);
    void open4(QString,long);
    void open5(QString,long);
    void open6(QString,long);
    void open7(QString,long);
    void open8(QString,long);

    void close1();
    void close2();
    void close3();
    void close4();
    void close5();
    void close6();
    void close7();
    void close8();

    void one1(QString,int,int*);
    void one2(QString,int,int*);
    void one3(QString,int,int*);
    void one4(QString,int,int*);
    void one5(QString,int,int*);
    void one6(QString,int,int*);
    void one7(QString,int,int*);
    void one8(QString,int,int*);

    void read1();
    void read2();
    void read3();
    void read4();
    void read5();
    void read6();
    void read7();
    void read8();
    void cycle1(QString,int, int*);
    void cycle2(QString,int, int*);
    void cycle3(QString,int, int*);
    void cycle4(QString,int, int*);
    void cycle5(QString,int, int*);
    void cycle6(QString,int, int*);
    void cycle7(QString,int, int*);
    void cycle8(QString,int, int*);


};

#endif // MAINWINDOW_H
