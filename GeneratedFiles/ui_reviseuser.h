/********************************************************************************
** Form generated from reading UI file 'reviseuser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVISEUSER_H
#define UI_REVISEUSER_H

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

class Ui_reviseuser
{
public:
    QFrame *frame;
    QPushButton *confirm;
    QLabel *label_4;
    QComboBox *comboBox;
    QPushButton *concle;
    QLabel *label_2;
    QLineEdit *usernameEdit;
    QLineEdit *userpasswordEdit;
    QLabel *label_3;

    void setupUi(QWidget *reviseuser)
    {
        if (reviseuser->objectName().isEmpty())
            reviseuser->setObjectName(QStringLiteral("reviseuser"));
        reviseuser->resize(522, 312);
        frame = new QFrame(reviseuser);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 522, 312));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"border-image: url(:/userManage/image/userManage/ab.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        confirm = new QPushButton(frame);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(102, 234, 116, 39));
        confirm->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/userManage/image/userManage/_alter_normal.png);\n"
"}\n"
"\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/userManage/image/userManage/_alter_pressed.png);\n"
"}"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(102, 180, 81, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(42, 42, 42);"));
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(196, 180, 218, 32));
        comboBox->setStyleSheet(QString::fromUtf8("\n"
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
""));
        concle = new QPushButton(frame);
        concle->setObjectName(QStringLiteral("concle"));
        concle->setGeometry(QRect(300, 234, 116, 39));
        concle->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/userManage/image/userManage/btn_cancel_normal.png);\n"
"}\n"
"QPushButton:hover{\n"
"border-image: url(:/userManage/image/userManage/btn_cancel_press.png);\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(102, 72, 81, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(42, 42, 42);"));
        usernameEdit = new QLineEdit(frame);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));
        usernameEdit->setGeometry(QRect(196, 72, 218, 32));
        usernameEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/userManage/image/userManage/\346\226\207\346\234\254\346\241\206.png);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(66, 66, 66);"));
        userpasswordEdit = new QLineEdit(frame);
        userpasswordEdit->setObjectName(QStringLiteral("userpasswordEdit"));
        userpasswordEdit->setGeometry(QRect(196, 126, 218, 32));
        userpasswordEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(66, 66, 66);\n"
"border-image: url(:/userManage/image/userManage/\346\226\207\346\234\254\346\241\206.png);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(102, 126, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(42, 42, 42);"));
        QWidget::setTabOrder(usernameEdit, userpasswordEdit);
        QWidget::setTabOrder(userpasswordEdit, comboBox);
        QWidget::setTabOrder(comboBox, confirm);
        QWidget::setTabOrder(confirm, concle);

        retranslateUi(reviseuser);

        QMetaObject::connectSlotsByName(reviseuser);
    } // setupUi

    void retranslateUi(QWidget *reviseuser)
    {
        reviseuser->setWindowTitle(QApplication::translate("reviseuser", "reviseuser", 0));
        confirm->setText(QString());
        label_4->setText(QApplication::translate("reviseuser", "\347\224\250\346\210\267\347\261\273\345\236\213\357\274\232", 0));
        concle->setText(QString());
        label_2->setText(QApplication::translate("reviseuser", "\347\224\250\346\210\267\345\220\215\347\247\260\357\274\232", 0));
        label_3->setText(QApplication::translate("reviseuser", "\345\257\206      \347\240\201\357\274\232 ", 0));
    } // retranslateUi

};

namespace Ui {
    class reviseuser: public Ui_reviseuser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVISEUSER_H
