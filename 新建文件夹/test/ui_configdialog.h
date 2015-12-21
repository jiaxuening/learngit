/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QPushButton *btn_ok;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_1;
    QComboBox *comboBox11;
    QComboBox *comboBox12;
    QLabel *label_2;
    QComboBox *comboBox21;
    QComboBox *comboBox22;
    QLabel *label_3;
    QComboBox *comboBox31;
    QComboBox *comboBox32;
    QLabel *label_4;
    QComboBox *comboBox41;
    QComboBox *comboBox42;
    QLabel *label_5;
    QComboBox *comboBox51;
    QComboBox *comboBox52;
    QLabel *label_6;
    QComboBox *comboBox61;
    QComboBox *comboBox62;
    QLabel *label_7;
    QComboBox *comboBox71;
    QComboBox *comboBox72;
    QLabel *label_8;
    QComboBox *comboBox81;
    QComboBox *comboBox82;
    QPushButton *btn_old;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->setWindowModality(Qt::ApplicationModal);
        ConfigDialog->resize(257, 306);
        ConfigDialog->setMinimumSize(QSize(257, 306));
        ConfigDialog->setMaximumSize(QSize(257, 306));
        ConfigDialog->setModal(true);
        btn_ok = new QPushButton(ConfigDialog);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        btn_ok->setGeometry(QRect(140, 260, 75, 31));
        layoutWidget = new QWidget(ConfigDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 201, 241));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 1, 1, 1, Qt::AlignHCenter);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 2, 1, 1, Qt::AlignHCenter);

        label_1 = new QLabel(layoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));

        gridLayout->addWidget(label_1, 1, 0, 1, 1, Qt::AlignHCenter);

        comboBox11 = new QComboBox(layoutWidget);
        comboBox11->setObjectName(QStringLiteral("comboBox11"));
        comboBox11->setInsertPolicy(QComboBox::InsertAtBottom);

        gridLayout->addWidget(comboBox11, 1, 1, 1, 1);

        comboBox12 = new QComboBox(layoutWidget);
        comboBox12->setObjectName(QStringLiteral("comboBox12"));

        gridLayout->addWidget(comboBox12, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1, Qt::AlignHCenter);

        comboBox21 = new QComboBox(layoutWidget);
        comboBox21->setObjectName(QStringLiteral("comboBox21"));

        gridLayout->addWidget(comboBox21, 2, 1, 1, 1);

        comboBox22 = new QComboBox(layoutWidget);
        comboBox22->setObjectName(QStringLiteral("comboBox22"));

        gridLayout->addWidget(comboBox22, 2, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1, Qt::AlignHCenter);

        comboBox31 = new QComboBox(layoutWidget);
        comboBox31->setObjectName(QStringLiteral("comboBox31"));

        gridLayout->addWidget(comboBox31, 3, 1, 1, 1);

        comboBox32 = new QComboBox(layoutWidget);
        comboBox32->setObjectName(QStringLiteral("comboBox32"));

        gridLayout->addWidget(comboBox32, 3, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1, Qt::AlignHCenter);

        comboBox41 = new QComboBox(layoutWidget);
        comboBox41->setObjectName(QStringLiteral("comboBox41"));

        gridLayout->addWidget(comboBox41, 4, 1, 1, 1);

        comboBox42 = new QComboBox(layoutWidget);
        comboBox42->setObjectName(QStringLiteral("comboBox42"));

        gridLayout->addWidget(comboBox42, 4, 2, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1, Qt::AlignHCenter);

        comboBox51 = new QComboBox(layoutWidget);
        comboBox51->setObjectName(QStringLiteral("comboBox51"));

        gridLayout->addWidget(comboBox51, 5, 1, 1, 1);

        comboBox52 = new QComboBox(layoutWidget);
        comboBox52->setObjectName(QStringLiteral("comboBox52"));

        gridLayout->addWidget(comboBox52, 5, 2, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1, Qt::AlignHCenter);

        comboBox61 = new QComboBox(layoutWidget);
        comboBox61->setObjectName(QStringLiteral("comboBox61"));

        gridLayout->addWidget(comboBox61, 6, 1, 1, 1);

        comboBox62 = new QComboBox(layoutWidget);
        comboBox62->setObjectName(QStringLiteral("comboBox62"));

        gridLayout->addWidget(comboBox62, 6, 2, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1, Qt::AlignHCenter);

        comboBox71 = new QComboBox(layoutWidget);
        comboBox71->setObjectName(QStringLiteral("comboBox71"));

        gridLayout->addWidget(comboBox71, 7, 1, 1, 1);

        comboBox72 = new QComboBox(layoutWidget);
        comboBox72->setObjectName(QStringLiteral("comboBox72"));

        gridLayout->addWidget(comboBox72, 7, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1, Qt::AlignHCenter);

        comboBox81 = new QComboBox(layoutWidget);
        comboBox81->setObjectName(QStringLiteral("comboBox81"));

        gridLayout->addWidget(comboBox81, 8, 1, 1, 1);

        comboBox82 = new QComboBox(layoutWidget);
        comboBox82->setObjectName(QStringLiteral("comboBox82"));

        gridLayout->addWidget(comboBox82, 8, 2, 1, 1);

        btn_old = new QPushButton(ConfigDialog);
        btn_old->setObjectName(QStringLiteral("btn_old"));
        btn_old->setGeometry(QRect(50, 260, 71, 31));

        retranslateUi(ConfigDialog);

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "\351\205\215\347\275\256", 0));
#ifndef QT_NO_WHATSTHIS
        ConfigDialog->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        btn_ok->setText(QApplication::translate("ConfigDialog", "\347\241\256\345\256\232", 0));
        label_9->setText(QApplication::translate("ConfigDialog", "\347\253\257\345\217\243", 0));
        label_10->setText(QApplication::translate("ConfigDialog", "\346\263\242\347\211\271\347\216\207", 0));
        label_1->setText(QApplication::translate("ConfigDialog", "COM1", 0));
        label_2->setText(QApplication::translate("ConfigDialog", "COM2", 0));
        label_3->setText(QApplication::translate("ConfigDialog", "COM3", 0));
        label_4->setText(QApplication::translate("ConfigDialog", "COM4", 0));
        label_5->setText(QApplication::translate("ConfigDialog", "COM5", 0));
        label_6->setText(QApplication::translate("ConfigDialog", "COM6", 0));
        label_7->setText(QApplication::translate("ConfigDialog", "COM7", 0));
        label_8->setText(QApplication::translate("ConfigDialog", "COM8", 0));
        btn_old->setText(QApplication::translate("ConfigDialog", "\351\273\230\350\256\244\345\200\274", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
