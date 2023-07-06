/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_file1;
    QToolButton *toolButton;
    QLabel *label;
    QPushButton *pushButton_v;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_d5;
    QRadioButton *radioButton_d8;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_inr;
    QRadioButton *radioButton_ybj;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_fast;
    QRadioButton *radioButton_slow;
    QComboBox *comboBox;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QRadioButton *radioButton_classic;
    QRadioButton *radioButton_ta;
    QLineEdit *lineEdit;
    QToolButton *toolButton_2;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_9;
    QComboBox *comboBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(781, 453);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(630, 190, 91, 51));
        lineEdit_file1 = new QLineEdit(centralwidget);
        lineEdit_file1->setObjectName(QString::fromUtf8("lineEdit_file1"));
        lineEdit_file1->setGeometry(QRect(120, 160, 311, 22));
        lineEdit_file1->setMaximumSize(QSize(16777215, 16777182));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(440, 160, 27, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 150, 91, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        pushButton_v = new QPushButton(centralwidget);
        pushButton_v->setObjectName(QString::fromUtf8("pushButton_v"));
        pushButton_v->setGeometry(QRect(500, 340, 91, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 61, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(450, 40, 121, 111));
        QFont font2;
        font2.setPointSize(10);
        groupBox->setFont(font2);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        radioButton_d5 = new QRadioButton(groupBox);
        radioButton_d5->setObjectName(QString::fromUtf8("radioButton_d5"));

        gridLayout_2->addWidget(radioButton_d5, 0, 0, 1, 1);

        radioButton_d8 = new QRadioButton(groupBox);
        radioButton_d8->setObjectName(QString::fromUtf8("radioButton_d8"));
        radioButton_d8->setChecked(true);

        gridLayout_2->addWidget(radioButton_d8, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(110, 40, 325, 111));
        groupBox_2->setFont(font2);
        radioButton_inr = new QRadioButton(groupBox_2);
        radioButton_inr->setObjectName(QString::fromUtf8("radioButton_inr"));
        radioButton_inr->setGeometry(QRect(10, 55, 131, 20));
        radioButton_inr->setChecked(false);
        radioButton_ybj = new QRadioButton(groupBox_2);
        radioButton_ybj->setObjectName(QString::fromUtf8("radioButton_ybj"));
        radioButton_ybj->setGeometry(QRect(150, 55, 131, 20));
        radioButton_ybj->setChecked(true);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(580, 40, 181, 111));
        groupBox_3->setFont(font2);
        radioButton_fast = new QRadioButton(groupBox_3);
        radioButton_fast->setObjectName(QString::fromUtf8("radioButton_fast"));
        radioButton_fast->setGeometry(QRect(10, 30, 171, 20));
        radioButton_fast->setChecked(true);
        radioButton_slow = new QRadioButton(groupBox_3);
        radioButton_slow->setObjectName(QString::fromUtf8("radioButton_slow"));
        radioButton_slow->setGeometry(QRect(10, 70, 161, 20));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 210, 201, 22));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 210, 101, 16));
        label_3->setFont(font2);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(410, 210, 42, 22));
        spinBox->setMinimum(10);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(340, 210, 71, 21));
        label_4->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 210, 131, 21));
        label_5->setFont(font2);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(110, 330, 371, 61));
        groupBox_4->setFont(font2);
        radioButton_classic = new QRadioButton(groupBox_4);
        radioButton_classic->setObjectName(QString::fromUtf8("radioButton_classic"));
        radioButton_classic->setGeometry(QRect(20, 20, 121, 31));
        radioButton_classic->setFont(font2);
        radioButton_classic->setChecked(true);
        radioButton_ta = new QRadioButton(groupBox_4);
        radioButton_ta->setObjectName(QString::fromUtf8("radioButton_ta"));
        radioButton_ta->setGeometry(QRect(160, 25, 101, 21));
        radioButton_ta->setFont(font2);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 300, 311, 22));
        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(440, 300, 27, 22));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 300, 81, 21));
        label_8->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 260, 211, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        label_6->setFont(font3);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 10, 231, 16));
        label_7->setFont(font3);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(480, 270, 101, 21));
        label_9->setFont(font2);
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(480, 300, 201, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 781, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Execute", nullptr));
        lineEdit_file1->setText(QString());
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose File", nullptr));
        pushButton_v->setText(QCoreApplication::translate("MainWindow", "Visualize", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Dinode", nullptr));
        radioButton_d5->setText(QCoreApplication::translate("MainWindow", "d5", nullptr));
        radioButton_d8->setText(QCoreApplication::translate("MainWindow", "d8", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Experiment", nullptr));
        radioButton_inr->setText(QCoreApplication::translate("MainWindow", "ENDA-INR", nullptr));
        radioButton_ybj->setText(QCoreApplication::translate("MainWindow", "ENDA-YBJ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Draw mode", nullptr));
        radioButton_fast->setText(QCoreApplication::translate("MainWindow", "Fast (scatter plot)", nullptr));
        radioButton_slow->setText(QCoreApplication::translate("MainWindow", "Slow (line plot)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Select event", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Filter >", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "neutrons in event", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Visualise style", nullptr));
        radioButton_classic->setText(QCoreApplication::translate("MainWindow", "Classic", nullptr));
        radioButton_ta->setText(QCoreApplication::translate("MainWindow", "TA", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "EAS file", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "2D VISUALIZER", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "OSCILLOGRAM VIEWER", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Select event", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
