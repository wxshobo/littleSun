/********************************************************************************
** Form generated from reading UI file 'tabproductmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABPRODUCTMANAGE_H
#define UI_TABPRODUCTMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabProductManage
{
public:
    QPushButton *proAddBtn;
    QPushButton *proPreBtn;
    QPushButton *proNextBtn;
    QPushButton *proDelBtn;
    QPushButton *proFirstBtn;
    QPushButton *proLastBtn;
    QTableWidget *proTableWidget;
    QPushButton *proUpdateBtn;
    QLabel *label;

    void setupUi(QWidget *TabProductManage)
    {
        if (TabProductManage->objectName().isEmpty())
            TabProductManage->setObjectName(QStringLiteral("TabProductManage"));
        TabProductManage->resize(1024, 699);
        TabProductManage->setStyleSheet(QStringLiteral(""));
        proAddBtn = new QPushButton(TabProductManage);
        proAddBtn->setObjectName(QStringLiteral("proAddBtn"));
        proAddBtn->setGeometry(QRect(580, 515, 114, 41));
        proAddBtn->setStyleSheet(QLatin1String("\n"
"QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_add_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_add_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_add_normal.png);}"));
        proPreBtn = new QPushButton(TabProductManage);
        proPreBtn->setObjectName(QStringLiteral("proPreBtn"));
        proPreBtn->setGeometry(QRect(190, 515, 114, 41));
        proPreBtn->setStyleSheet(QLatin1String("\n"
"QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_prpage_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_prpage_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_prpage_normal.png);}\n"
"\n"
"QPushButton:disabled{\n"
"   border-image: url(:/productManage/image/productManage/btn_prpage_down.png);\n"
"}"));
        proNextBtn = new QPushButton(TabProductManage);
        proNextBtn->setObjectName(QStringLiteral("proNextBtn"));
        proNextBtn->setGeometry(QRect(320, 515, 114, 41));
        proNextBtn->setStyleSheet(QLatin1String("\n"
"QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_nextpage_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_nextpage_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_nextpage_normal.png);}\n"
"\n"
"QPushButton:disabled{\n"
"   border-image: url(:/productManage/image/productManage/btn_nextpage_down.png);\n"
"}"));
        proDelBtn = new QPushButton(TabProductManage);
        proDelBtn->setObjectName(QStringLiteral("proDelBtn"));
        proDelBtn->setGeometry(QRect(710, 515, 114, 41));
        proDelBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_delete_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_delete_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_delete_normal.png);}\n"
"\n"
"QPushButton:disabled{\n"
"   border-image: url(:/productManage/image/productManage/btn_delete_down.png);\n"
"}\n"
"\n"
""));
        proFirstBtn = new QPushButton(TabProductManage);
        proFirstBtn->setObjectName(QStringLiteral("proFirstBtn"));
        proFirstBtn->setGeometry(QRect(60, 515, 114, 41));
        proFirstBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_firstpage_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_firstpage_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_firstpage_normal.png);}\n"
"\n"
"QPushButton:disabled{\n"
"   border-image: url(:/productManage/image/productManage/btn_firstpage_down.png);\n"
"}\n"
"\n"
""));
        proLastBtn = new QPushButton(TabProductManage);
        proLastBtn->setObjectName(QStringLiteral("proLastBtn"));
        proLastBtn->setGeometry(QRect(450, 515, 114, 41));
        proLastBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_lastpage.normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_lastpage_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_lastpage.normal.png);}\n"
"\n"
"QPushButton:disabled{\n"
"   border-image: url(:/productManage/image/productManage/btn_lastpage_down.png);\n"
"}\n"
"\n"
""));
        proTableWidget = new QTableWidget(TabProductManage);
        if (proTableWidget->columnCount() < 4)
            proTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        proTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        proTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        proTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        proTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (proTableWidget->rowCount() < 7)
            proTableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        proTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        proTableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        proTableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        proTableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        proTableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        proTableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        proTableWidget->setVerticalHeaderItem(6, __qtablewidgetitem10);
        proTableWidget->setObjectName(QStringLiteral("proTableWidget"));
        proTableWidget->setGeometry(QRect(56, 60, 904, 418));
        proTableWidget->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei UI\";\n"
"color:#212222;\n"
"gridline-color:#212222;\n"
"\n"
""));
        proUpdateBtn = new QPushButton(TabProductManage);
        proUpdateBtn->setObjectName(QStringLiteral("proUpdateBtn"));
        proUpdateBtn->setGeometry(QRect(840, 515, 114, 41));
        proUpdateBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_alter_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_alter_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_alter_normal.png);}\n"
"\n"
"QPushButton:disabled{\n"
"   border-image: url(:/productManage/image/productManage/btn_alter_down.png);\n"
"}\n"
"\n"
""));
        label = new QLabel(TabProductManage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(407, 605, 210, 31));
        label->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(0, 0, 0);"));
        QWidget::setTabOrder(proFirstBtn, proPreBtn);
        QWidget::setTabOrder(proPreBtn, proNextBtn);
        QWidget::setTabOrder(proNextBtn, proLastBtn);
        QWidget::setTabOrder(proLastBtn, proAddBtn);
        QWidget::setTabOrder(proAddBtn, proDelBtn);
        QWidget::setTabOrder(proDelBtn, proUpdateBtn);
        QWidget::setTabOrder(proUpdateBtn, proTableWidget);

        retranslateUi(TabProductManage);

        QMetaObject::connectSlotsByName(TabProductManage);
    } // setupUi

    void retranslateUi(QWidget *TabProductManage)
    {
        TabProductManage->setWindowTitle(QApplication::translate("TabProductManage", "TabProductManage", 0));
        proAddBtn->setText(QString());
        proPreBtn->setText(QString());
        proNextBtn->setText(QString());
        proDelBtn->setText(QString());
        proFirstBtn->setText(QString());
        proLastBtn->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = proTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("TabProductManage", "\344\272\247\345\223\201\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = proTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("TabProductManage", "\344\272\247\345\223\201\347\261\273\345\210\253", 0));
        QTableWidgetItem *___qtablewidgetitem2 = proTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("TabProductManage", "\345\215\225\344\273\267\357\274\210\345\205\203\357\274\211", 0));
        proUpdateBtn->setText(QString());
        label->setText(QApplication::translate("TabProductManage", "\350\245\277\347\272\242\346\237\277\347\247\221\346\212\200\357\274\210\346\255\246\346\261\211\357\274\211\346\234\211\351\231\220\345\205\254\345\217\270", 0));
    } // retranslateUi

};

namespace Ui {
    class TabProductManage: public Ui_TabProductManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABPRODUCTMANAGE_H
