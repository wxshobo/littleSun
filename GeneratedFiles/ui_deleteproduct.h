/********************************************************************************
** Form generated from reading UI file 'deleteproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPRODUCT_H
#define UI_DELETEPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteproduct
{
public:
    QFrame *frame;
    QPushButton *cancelBtn;
    QPushButton *comfirmBtn;
    QLabel *label;

    void setupUi(QWidget *deleteproduct)
    {
        if (deleteproduct->objectName().isEmpty())
            deleteproduct->setObjectName(QStringLiteral("deleteproduct"));
        deleteproduct->resize(371, 221);
        deleteproduct->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        frame = new QFrame(deleteproduct);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 534, 324));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{border-image: url(:/productManage/image/productManage/ab.png);}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        cancelBtn = new QPushButton(deleteproduct);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(218, 130, 116, 39));
        cancelBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{border-image: url(:/userManage/image/userManage/btn_cancel_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/userManage/image/userManage/btn_cancel_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/userManage/image/userManage/btn_cancel_press.png);}\n"
"\n"
""));
        comfirmBtn = new QPushButton(deleteproduct);
        comfirmBtn->setObjectName(QStringLiteral("comfirmBtn"));
        comfirmBtn->setGeometry(QRect(36, 130, 116, 39));
        comfirmBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{border-image: url(:/userManage/image/userManage/btn_delete_normal_green.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/userManage/image/userManage/btn_delete_press_green.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/userManage/image/userManage/btn_delete_press_green.png);}\n"
""));
        label = new QLabel(deleteproduct);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 62, 101, 51));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        QWidget::setTabOrder(comfirmBtn, cancelBtn);

        retranslateUi(deleteproduct);

        QMetaObject::connectSlotsByName(deleteproduct);
    } // setupUi

    void retranslateUi(QWidget *deleteproduct)
    {
        deleteproduct->setWindowTitle(QApplication::translate("deleteproduct", "deleteproduct", 0));
        cancelBtn->setText(QString());
        comfirmBtn->setText(QString());
        label->setText(QApplication::translate("deleteproduct", "\347\241\256\350\256\244\345\210\240\351\231\244\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class deleteproduct: public Ui_deleteproduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPRODUCT_H
