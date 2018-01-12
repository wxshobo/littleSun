/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adduser
{
public:
    QFrame *frame;
    QLabel *label_5;
    QLineEdit *usernameEdit;
    QLineEdit *userpasswordEdit;
    QLabel *label_6;
    QPushButton *confirm;
    QComboBox *usertypeBox;
    QPushButton *concle;
    QLabel *label_7;

    void setupUi(QWidget *adduser)
    {
        if (adduser->objectName().isEmpty())
            adduser->setObjectName(QStringLiteral("adduser"));
        adduser->resize(522, 312);
        adduser->setStyleSheet(QString::fromUtf8("#adduser{\n"
"background-image: url(:/userManage/image/userManage/pop/\345\274\271\345\207\272\346\241\206.png);\n"
"}\n"
""));
        frame = new QFrame(adduser);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 522, 312));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"border-image: url(:/userManage/image/userManage/ab.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(102, 180, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(42, 42, 42);\n"
"\n"
""));
        usernameEdit = new QLineEdit(frame);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));
        usernameEdit->setGeometry(QRect(196, 72, 218, 32));
        usernameEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(66, 66, 66);\n"
"\n"
"border-image: url(:/userManage/image/userManage/\346\226\207\346\234\254\346\241\206.png);"));
        userpasswordEdit = new QLineEdit(frame);
        userpasswordEdit->setObjectName(QStringLiteral("userpasswordEdit"));
        userpasswordEdit->setGeometry(QRect(196, 126, 218, 32));
        userpasswordEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(66, 66, 66);\n"
"border-image: url(:/userManage/image/userManage/\346\226\207\346\234\254\346\241\206.png);"));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(102, 126, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(42, 42, 42);\n"
"\n"
""));
        confirm = new QPushButton(frame);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(102, 234, 116, 39));
        confirm->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/userManage/image/userManage/_confirm_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/userManage/image/userManage/_confirm_pressed.png);\n"
"}"));
        usertypeBox = new QComboBox(frame);
        usertypeBox->setObjectName(QStringLiteral("usertypeBox"));
        usertypeBox->setGeometry(QRect(196, 180, 218, 33));
        usertypeBox->setAcceptDrops(false);
        usertypeBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox{\n"
"     font: 12pt \"Microsoft YaHei UI\";\n"
"color: rgb(66, 66, 66);\n"
"	border-image: url(:/userManage/W:/107/image/userManage/\345\274\271\345\207\272\346\241\206\345\210\207\345\233\276_\346\226\260\345\242\236\344\270\216\344\277\256\346\224\271/\344\270\213\346\213\211\346\241\206_normal.png);\n"
"}\n"
"\n"
"QComboBox:pressed{\n"
"border-image: url(:/userManage/W:/107/image/userManage/\345\274\271\345\207\272\346\241\206\345\210\207\345\233\276_\346\226\260\345\242\236\344\270\216\344\277\256\346\224\271/\344\270\213\346\213\211\346\241\206_pressed.png);\n"
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
        concle = new QPushButton(frame);
        concle->setObjectName(QStringLiteral("concle"));
        concle->setGeometry(QRect(300, 234, 116, 39));
        concle->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/userManage/image/userManage/btn_cancel_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/userManage/image/userManage/btn_cancel_press.png);\n"
"}"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(102, 72, 81, 31));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(42, 42, 42);\n"
"\n"
""));
        QWidget::setTabOrder(usernameEdit, userpasswordEdit);
        QWidget::setTabOrder(userpasswordEdit, usertypeBox);
        QWidget::setTabOrder(usertypeBox, confirm);
        QWidget::setTabOrder(confirm, concle);

        retranslateUi(adduser);

        QMetaObject::connectSlotsByName(adduser);
    } // setupUi

    void retranslateUi(QWidget *adduser)
    {
        adduser->setWindowTitle(QApplication::translate("adduser", "adduser", 0));
        label_5->setText(QApplication::translate("adduser", "\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232", 0));
        label_6->setText(QApplication::translate("adduser", "\345\257\206      \347\240\201\357\274\232 ", 0));
        confirm->setText(QString());
        concle->setText(QString());
        label_7->setText(QApplication::translate("adduser", "\347\224\250\346\210\267\345\220\215\347\247\260\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class adduser: public Ui_adduser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
