/********************************************************************************
** Form generated from reading UI file 'tabusermanage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABUSERMANAGE_H
#define UI_TABUSERMANAGE_H

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

class Ui_TabUserManage
{
public:
    QTableWidget *usertableWidget;
    QPushButton *userdeleteBtn;
    QPushButton *userpreviousBtn;
    QPushButton *userlastBtn;
    QPushButton *userreviseBtn;
    QPushButton *useraddBtn;
    QPushButton *usernextBtn;
    QPushButton *userfirstBtn;
    QLabel *label;

    void setupUi(QWidget *TabUserManage)
    {
        if (TabUserManage->objectName().isEmpty())
            TabUserManage->setObjectName(QStringLiteral("TabUserManage"));
        TabUserManage->resize(1024, 699);
        usertableWidget = new QTableWidget(TabUserManage);
        if (usertableWidget->columnCount() < 4)
            usertableWidget->setColumnCount(4);
        QFont font;
        font.setUnderline(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        usertableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usertableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        usertableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        usertableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (usertableWidget->rowCount() < 7)
            usertableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        usertableWidget->setVerticalHeaderItem(6, __qtablewidgetitem10);
        usertableWidget->setObjectName(QStringLiteral("usertableWidget"));
        usertableWidget->setGeometry(QRect(56, 60, 904, 418));
        usertableWidget->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei UI\";\n"
"color:#212222;\n"
"gridline-color:#212222;\n"
"\n"
""));
        userdeleteBtn = new QPushButton(TabUserManage);
        userdeleteBtn->setObjectName(QStringLiteral("userdeleteBtn"));
        userdeleteBtn->setGeometry(QRect(710, 515, 114, 41));
        userdeleteBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"		border-image: url(:/userManage/image/userManage/btn_delete_normal_blue.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-image: url(:/userManage/image/userManage/btn_delete_press_blue.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/userManage/image/userManage/btn_delete_down.png);\n"
"}\n"
""));
        userpreviousBtn = new QPushButton(TabUserManage);
        userpreviousBtn->setObjectName(QStringLiteral("userpreviousBtn"));
        userpreviousBtn->setGeometry(QRect(190, 515, 114, 41));
        userpreviousBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/userManage/image/userManage/btn_prpage_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-image: url(:/userManage/image/userManage/btn_prpage_press.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/userManage/image/userManage/btn_prpage_down.png);\n"
"}\n"
""));
        userlastBtn = new QPushButton(TabUserManage);
        userlastBtn->setObjectName(QStringLiteral("userlastBtn"));
        userlastBtn->setGeometry(QRect(450, 515, 114, 41));
        userlastBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"		border-image: url(:/userManage/image/userManage/btn_lastpage.normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-image: url(:/userManage/image/userManage/btn_lastpage_press.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/userManage/image/userManage/btn_lastpage_down.png);\n"
"}\n"
""));
        userreviseBtn = new QPushButton(TabUserManage);
        userreviseBtn->setObjectName(QStringLiteral("userreviseBtn"));
        userreviseBtn->setGeometry(QRect(840, 515, 114, 41));
        userreviseBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"		border-image: url(:/userManage/image/userManage/btn_alter_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-image: url(:/userManage/image/userManage/btn_alter_press.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/userManage/image/userManage/btn_alter_down.png);\n"
"}\n"
"	"));
        useraddBtn = new QPushButton(TabUserManage);
        useraddBtn->setObjectName(QStringLiteral("useraddBtn"));
        useraddBtn->setGeometry(QRect(580, 515, 114, 41));
        useraddBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"		border-image: url(:/userManage/image/userManage/btn_add_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-image: url(:/userManage/image/userManage/btn_add_press.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/userManage/image/userManage/btn_add_down.png);\n"
"}\n"
""));
        usernextBtn = new QPushButton(TabUserManage);
        usernextBtn->setObjectName(QStringLiteral("usernextBtn"));
        usernextBtn->setGeometry(QRect(320, 515, 114, 41));
        usernextBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/userManage/image/userManage/btn_nextpage_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border-image: url(:/userManage/image/userManage/btn_nextpage_press.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled{\n"
"	border-image: url(:/userManage/image/userManage/btn_nextpage_down.png);\n"
"}\n"
""));
        userfirstBtn = new QPushButton(TabUserManage);
        userfirstBtn->setObjectName(QStringLiteral("userfirstBtn"));
        userfirstBtn->setGeometry(QRect(60, 515, 114, 41));
        userfirstBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/userManage/image/userManage/btn_firstpage_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border-image: url(:/userManage/image/userManage/btn_firstpage_press.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled{\n"
"   border-image: url(:/userManage/image/userManage/btn_firstpage_down.png);\n"
"}\n"
"\n"
""));
        label = new QLabel(TabUserManage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(407, 605, 210, 31));
        label->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(0, 0, 0);"));
        QWidget::setTabOrder(userfirstBtn, userpreviousBtn);
        QWidget::setTabOrder(userpreviousBtn, usernextBtn);
        QWidget::setTabOrder(usernextBtn, userlastBtn);
        QWidget::setTabOrder(userlastBtn, useraddBtn);
        QWidget::setTabOrder(useraddBtn, userdeleteBtn);
        QWidget::setTabOrder(userdeleteBtn, userreviseBtn);
        QWidget::setTabOrder(userreviseBtn, usertableWidget);

        retranslateUi(TabUserManage);

        QMetaObject::connectSlotsByName(TabUserManage);
    } // setupUi

    void retranslateUi(QWidget *TabUserManage)
    {
        TabUserManage->setWindowTitle(QApplication::translate("TabUserManage", "TabUserManage", 0));
        QTableWidgetItem *___qtablewidgetitem = usertableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("TabUserManage", "\347\224\250\346\210\267\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = usertableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("TabUserManage", "\347\224\250\346\210\267\347\261\273\345\210\253", 0));
        QTableWidgetItem *___qtablewidgetitem2 = usertableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("TabUserManage", "\345\257\206\347\240\201", 0));
        userdeleteBtn->setText(QString());
        userpreviousBtn->setText(QString());
        userlastBtn->setText(QString());
        userreviseBtn->setText(QString());
        useraddBtn->setText(QString());
        usernextBtn->setText(QString());
        userfirstBtn->setText(QString());
        label->setText(QApplication::translate("TabUserManage", "\350\245\277\347\272\242\346\237\277\347\247\221\346\212\200\357\274\210\346\255\246\346\261\211\357\274\211\346\234\211\351\231\220\345\205\254\345\217\270", 0));
    } // retranslateUi

};

namespace Ui {
    class TabUserManage: public Ui_TabUserManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABUSERMANAGE_H
