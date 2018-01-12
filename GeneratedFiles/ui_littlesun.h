/********************************************************************************
** Form generated from reading UI file 'littlesun.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LITTLESUN_H
#define UI_LITTLESUN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LittleSunClass
{
public:
    QFrame *frame;
    QLabel *passWordLabel;
    QLineEdit *passWordEdit;
    QLineEdit *userNameEdit;
    QLabel *userNameLabel;
    QPushButton *loginBtn;
    QPushButton *narrowBtn;
    QPushButton *closeBtn;
    QPushButton *test;

    void setupUi(QWidget *LittleSunClass)
    {
        if (LittleSunClass->objectName().isEmpty())
            LittleSunClass->setObjectName(QStringLiteral("LittleSunClass"));
        LittleSunClass->resize(450, 338);
        LittleSunClass->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(LittleSunClass);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 450, 338));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"border-image: url(:/login/image/login/background_a.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        passWordLabel = new QLabel(frame);
        passWordLabel->setObjectName(QStringLiteral("passWordLabel"));
        passWordLabel->setGeometry(QRect(100, 176, 54, 14));
        passWordLabel->setStyleSheet(QStringLiteral("border-image: url(:/login/image/login/password.png);"));
        passWordEdit = new QLineEdit(frame);
        passWordEdit->setObjectName(QStringLiteral("passWordEdit"));
        passWordEdit->setGeometry(QRect(172, 169, 164, 28));
        passWordEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/login/image/login/input_box_a.png);\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        userNameEdit = new QLineEdit(frame);
        userNameEdit->setObjectName(QStringLiteral("userNameEdit"));
        userNameEdit->setGeometry(QRect(172, 123, 164, 28));
        userNameEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/login/image/login/input_box_a.png);\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        userNameLabel = new QLabel(frame);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));
        userNameLabel->setGeometry(QRect(100, 130, 54, 14));
        userNameLabel->setStyleSheet(QStringLiteral("border-image: url(:/login/image/login/username.png);"));
        loginBtn = new QPushButton(frame);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(158, 220, 133, 34));
        loginBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/login/image/login/land.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/login/image/login/landing.png);\n"
"}"));
        narrowBtn = new QPushButton(frame);
        narrowBtn->setObjectName(QStringLiteral("narrowBtn"));
        narrowBtn->setGeometry(QRect(396, 0, 24, 16));
        narrowBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/login/image/login/j.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/login/image/login/j_a.png);\n"
"}\n"
""));
        closeBtn = new QPushButton(frame);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(420, 0, 24, 16));
        closeBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/login/image/login/x.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/login/image/login/x_a.png);\n"
"}"));
        test = new QPushButton(frame);
        test->setObjectName(QStringLiteral("test"));
        test->setGeometry(QRect(200, 270, 75, 23));
        QWidget::setTabOrder(userNameEdit, passWordEdit);
        QWidget::setTabOrder(passWordEdit, loginBtn);

        retranslateUi(LittleSunClass);

        QMetaObject::connectSlotsByName(LittleSunClass);
    } // setupUi

    void retranslateUi(QWidget *LittleSunClass)
    {
        LittleSunClass->setWindowTitle(QApplication::translate("LittleSunClass", "LittleSun", 0));
        passWordLabel->setText(QString());
        passWordEdit->setText(QString());
        userNameLabel->setText(QString());
        loginBtn->setText(QString());
        narrowBtn->setText(QString());
        closeBtn->setText(QString());
        test->setText(QApplication::translate("LittleSunClass", "test", 0));
    } // retranslateUi

};

namespace Ui {
    class LittleSunClass: public Ui_LittleSunClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITTLESUN_H
