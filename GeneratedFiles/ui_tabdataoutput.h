/********************************************************************************
** Form generated from reading UI file 'tabdataoutput.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABDATAOUTPUT_H
#define UI_TABDATAOUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabDataOutput
{
public:
    QTableWidget *dataTabWid;
    QPushButton *datfirstpageButton;
    QPushButton *datprepageButton;
    QPushButton *datnextpageButton;
    QPushButton *datlastpageButton;
    QPushButton *datexportButton;
    QLabel *label1;
    QLabel *label2;
    QComboBox *datSortComBox;
    QComboBox *datNameComBox;
    QComboBox *datcompanyComBox;
    QComboBox *datmanComBox;
    QPushButton *datinquireButton;
    QDateEdit *datstartDateEdit;
    QDateEdit *datendDateEdit;
    QLabel *label;

    void setupUi(QWidget *TabDataOutput)
    {
        if (TabDataOutput->objectName().isEmpty())
            TabDataOutput->setObjectName(QStringLiteral("TabDataOutput"));
        TabDataOutput->resize(1024, 699);
        dataTabWid = new QTableWidget(TabDataOutput);
        if (dataTabWid->columnCount() < 13)
            dataTabWid->setColumnCount(13);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        dataTabWid->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        if (dataTabWid->rowCount() < 6)
            dataTabWid->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        dataTabWid->setVerticalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        dataTabWid->setVerticalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        dataTabWid->setVerticalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        dataTabWid->setVerticalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        dataTabWid->setVerticalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        dataTabWid->setVerticalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        dataTabWid->setItem(0, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        dataTabWid->setItem(0, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        dataTabWid->setItem(0, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        dataTabWid->setItem(0, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        dataTabWid->setItem(0, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        dataTabWid->setItem(0, 5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        dataTabWid->setItem(0, 6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        dataTabWid->setItem(0, 7, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        dataTabWid->setItem(0, 8, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        dataTabWid->setItem(0, 9, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        dataTabWid->setItem(0, 10, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        dataTabWid->setItem(0, 11, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        dataTabWid->setItem(0, 12, __qtablewidgetitem31);
        dataTabWid->setObjectName(QStringLiteral("dataTabWid"));
        dataTabWid->setGeometry(QRect(30, 176, 964, 332));
        dataTabWid->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei UI\";\n"
"color:#212222;\n"
"gridline-color:#212222;\n"
"\n"
""));
        datfirstpageButton = new QPushButton(TabDataOutput);
        datfirstpageButton->setObjectName(QStringLiteral("datfirstpageButton"));
        datfirstpageButton->setGeometry(QRect(184, 535, 114, 41));
        datfirstpageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_firstpage_normal.png);\n"
"}\n"
"QPushButton::hover {\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_firstpage_press.png);\n"
"}\n"
"QPushButton:disabled{\n"
"border-image: url(:/dataoutput/image/dataoutput/btn_firstpage_down.png);\n"
"}"));
        datprepageButton = new QPushButton(TabDataOutput);
        datprepageButton->setObjectName(QStringLiteral("datprepageButton"));
        datprepageButton->setGeometry(QRect(318, 535, 114, 41));
        datprepageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_prpage_normal.png);\n"
"}\n"
"QPushButton::hover {\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_prpage_press.png);\n"
"}\n"
"QPushButton:disabled{\n"
"border-image: url(:/dataoutput/image/dataoutput/btn_prpage_down.png);\n"
"}\n"
"	"));
        datnextpageButton = new QPushButton(TabDataOutput);
        datnextpageButton->setObjectName(QStringLiteral("datnextpageButton"));
        datnextpageButton->setGeometry(QRect(452, 535, 114, 41));
        datnextpageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_nextpage_normal.png);\n"
"}\n"
"QPushButton::hover {\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_nextpage_press.png);\n"
"}\n"
"QPushButton:disabled{\n"
"border-image: url(:/dataoutput/image/dataoutput/btn_nextpage_down.png);\n"
"}\n"
"	"));
        datlastpageButton = new QPushButton(TabDataOutput);
        datlastpageButton->setObjectName(QStringLiteral("datlastpageButton"));
        datlastpageButton->setGeometry(QRect(586, 535, 114, 41));
        datlastpageButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_lastpage.normal.png);\n"
"}\n"
"QPushButton::hover {\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_lastpage_press.png);\n"
"}\n"
"QPushButton:disabled{\n"
"border-image: url(:/dataoutput/image/dataoutput/btn_lastpage_down.png);\n"
"}\n"
"	"));
        datexportButton = new QPushButton(TabDataOutput);
        datexportButton->setObjectName(QStringLiteral("datexportButton"));
        datexportButton->setGeometry(QRect(720, 535, 114, 41));
        datexportButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_export_normal.png);\n"
"}\n"
"QPushButton::hover {\n"
"	border-image: url(:/dataoutput/image/dataoutput/btn_export_press.png);\n"
"}\n"
"	"));
        label1 = new QLabel(TabDataOutput);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(86, 62, 20, 20));
        label1->setStyleSheet(QStringLiteral("font: 14pt \"Microsoft YaHei UI\";"));
        label2 = new QLabel(TabDataOutput);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(325, 62, 20, 20));
        label2->setStyleSheet(QStringLiteral("font: 14pt \"Microsoft YaHei UI\";"));
        datSortComBox = new QComboBox(TabDataOutput);
        datSortComBox->setObjectName(QStringLiteral("datSortComBox"));
        datSortComBox->setGeometry(QRect(120, 110, 196, 43));
        datSortComBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(66, 66, 66);\n"
"	border-image: url(:/dataoutput/image/dataoutput/\344\270\213\346\213\211\346\241\206_normal.png);\n"
"}\n"
"\n"
"QComboBox:pressed{\n"
"border-image: url(:/dataoutput/image/dataoutput/\344\270\213\346\213\211\346\241\206_pressed.png);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 30px;\n"
"border-left-width: 0px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
""));
        datSortComBox->setEditable(false);
        datNameComBox = new QComboBox(TabDataOutput);
        datNameComBox->setObjectName(QStringLiteral("datNameComBox"));
        datNameComBox->setGeometry(QRect(358, 110, 196, 43));
        datNameComBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(66, 66, 66);\n"
"	border-image: url(:/dataoutput/image/dataoutput/\344\270\213\346\213\211\346\241\206_normal.png);\n"
"}\n"
"\n"
"QComboBox:pressed{\n"
"border-image: url(:/dataoutput/image/dataoutput/\344\270\213\346\213\211\346\241\206_pressed.png);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 30px;\n"
"border-left-width: 0px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
""));
        datNameComBox->setEditable(false);
        datcompanyComBox = new QComboBox(TabDataOutput);
        datcompanyComBox->setObjectName(QStringLiteral("datcompanyComBox"));
        datcompanyComBox->setGeometry(QRect(596, 50, 196, 43));
        datcompanyComBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(66, 66, 66);\n"
"	border-image: url(:/dataoutput/image/dataoutput/\344\270\213\346\213\211\346\241\206_normal.png);\n"
"}\n"
"\n"
"QComboBox:pressed{\n"
"border-image: url(:/dataoutput/image/dataoutput/\344\270\213\346\213\211\346\241\206_pressed.png);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 30px;\n"
"border-left-width: 0px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"}\n"
""));
        datcompanyComBox->setEditable(false);
        datmanComBox = new QComboBox(TabDataOutput);
        datmanComBox->setObjectName(QStringLiteral("datmanComBox"));
        datmanComBox->setGeometry(QRect(596, 110, 196, 43));
        datmanComBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(66, 66, 66);\n"
"	border-image: url(:/dataoutput/image/dataoutput/\344\270\213\346\213\211\346\241\206_normal.png);\n"
"}\n"
"\n"
"QComboBox:pressed{\n"
"border-image: url(:/dataoutput/image/dataoutput/\344\270\213\346\213\211\346\241\206_pressed.png);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"width: 30px;\n"
"border-left-width: 0px;\n"
"border-left-color: gray;\n"
"border-left-style: solid;\n"
"border-top-right-radius: 3px;\n"
"border-bottom-right-radius: 3px;\n"
"}\n"
""));
        datmanComBox->setEditable(false);
        datinquireButton = new QPushButton(TabDataOutput);
        datinquireButton->setObjectName(QStringLiteral("datinquireButton"));
        datinquireButton->setGeometry(QRect(820, 110, 114, 41));
        datinquireButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/dataoutput/image/dataoutput/btn_inquire_normal.png);}\n"
"\n"
"QPushButton::hover{\n"
"border-image: url(:/dataoutput/image/dataoutput/btn_inquire_press.png);}"));
        datstartDateEdit = new QDateEdit(TabDataOutput);
        datstartDateEdit->setObjectName(QStringLiteral("datstartDateEdit"));
        datstartDateEdit->setGeometry(QRect(120, 50, 196, 43));
        datstartDateEdit->setStyleSheet(QLatin1String("\n"
" font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(66, 66, 66);\n"
""));
        datendDateEdit = new QDateEdit(TabDataOutput);
        datendDateEdit->setObjectName(QStringLiteral("datendDateEdit"));
        datendDateEdit->setGeometry(QRect(358, 50, 196, 43));
        datendDateEdit->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(66, 66, 66);"));
        label = new QLabel(TabDataOutput);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(407, 605, 210, 31));
        label->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(0, 0, 0);"));
        QWidget::setTabOrder(datstartDateEdit, datendDateEdit);
        QWidget::setTabOrder(datendDateEdit, datcompanyComBox);
        QWidget::setTabOrder(datcompanyComBox, datSortComBox);
        QWidget::setTabOrder(datSortComBox, datNameComBox);
        QWidget::setTabOrder(datNameComBox, datmanComBox);
        QWidget::setTabOrder(datmanComBox, datinquireButton);
        QWidget::setTabOrder(datinquireButton, dataTabWid);
        QWidget::setTabOrder(dataTabWid, datfirstpageButton);
        QWidget::setTabOrder(datfirstpageButton, datprepageButton);
        QWidget::setTabOrder(datprepageButton, datnextpageButton);
        QWidget::setTabOrder(datnextpageButton, datlastpageButton);
        QWidget::setTabOrder(datlastpageButton, datexportButton);

        retranslateUi(TabDataOutput);

        QMetaObject::connectSlotsByName(TabDataOutput);
    } // setupUi

    void retranslateUi(QWidget *TabDataOutput)
    {
        TabDataOutput->setWindowTitle(QApplication::translate("TabDataOutput", "TabDataOutput", 0));
        QTableWidgetItem *___qtablewidgetitem = dataTabWid->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TabDataOutput", "\346\212\245\344\273\267\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem1 = dataTabWid->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TabDataOutput", "\344\272\247\345\223\201\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = dataTabWid->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TabDataOutput", "\344\272\247\345\223\201\347\261\273\345\210\253", 0));
        QTableWidgetItem *___qtablewidgetitem3 = dataTabWid->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TabDataOutput", "\351\225\277\345\272\246", 0));
        QTableWidgetItem *___qtablewidgetitem4 = dataTabWid->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("TabDataOutput", "\345\256\275\345\272\246", 0));
        QTableWidgetItem *___qtablewidgetitem5 = dataTabWid->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("TabDataOutput", "\345\215\225\344\273\267(\345\205\203)", 0));
        QTableWidgetItem *___qtablewidgetitem6 = dataTabWid->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("TabDataOutput", "\345\237\272\347\241\200\344\273\267\346\240\274", 0));
        QTableWidgetItem *___qtablewidgetitem7 = dataTabWid->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("TabDataOutput", "\345\271\263\346\216\245", 0));
        QTableWidgetItem *___qtablewidgetitem8 = dataTabWid->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("TabDataOutput", "\345\271\263\346\216\245\345\215\225\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem9 = dataTabWid->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("TabDataOutput", "\345\271\263\346\216\245\344\273\267\346\240\274", 0));
        QTableWidgetItem *___qtablewidgetitem10 = dataTabWid->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("TabDataOutput", "\346\212\245\344\273\267\347\263\273\346\225\260", 0));
        QTableWidgetItem *___qtablewidgetitem11 = dataTabWid->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("TabDataOutput", "\347\273\210\347\253\257\346\212\245\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem12 = dataTabWid->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("TabDataOutput", "\346\212\245\344\273\267\345\221\230", 0));

        const bool __sortingEnabled = dataTabWid->isSortingEnabled();
        dataTabWid->setSortingEnabled(false);
        dataTabWid->setSortingEnabled(__sortingEnabled);

        datfirstpageButton->setText(QString());
        datprepageButton->setText(QString());
        datnextpageButton->setText(QString());
        datlastpageButton->setText(QString());
        datexportButton->setText(QString());
        label1->setText(QApplication::translate("TabDataOutput", "\344\273\216", 0));
        label2->setText(QApplication::translate("TabDataOutput", "\345\210\260", 0));
        datNameComBox->clear();
        datNameComBox->insertItems(0, QStringList()
         << QApplication::translate("TabDataOutput", "\346\211\200\346\234\211\344\272\247\345\223\201", 0)
        );
        datinquireButton->setText(QString());
        label->setText(QApplication::translate("TabDataOutput", "\350\245\277\347\272\242\346\237\277\347\247\221\346\212\200\357\274\210\346\255\246\346\261\211\357\274\211\346\234\211\351\231\220\345\205\254\345\217\270", 0));
    } // retranslateUi

};

namespace Ui {
    class TabDataOutput: public Ui_TabDataOutput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABDATAOUTPUT_H
