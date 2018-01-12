/********************************************************************************
** Form generated from reading UI file 'deleteuser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEUSER_H
#define UI_DELETEUSER_H

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

class Ui_deleteuser
{
public:
    QFrame *frame;
    QLabel *label_2;
    QPushButton *confirmBtn;
    QPushButton *concleBtn;

    void setupUi(QWidget *deleteuser)
    {
        if (deleteuser->objectName().isEmpty())
            deleteuser->setObjectName(QStringLiteral("deleteuser"));
        deleteuser->resize(370, 202);
        deleteuser->setStyleSheet(QString::fromUtf8("#deleteuser{\n"
"background-image: url(:/userManage/image/userManage/pop/\345\274\271\345\207\272\346\241\206.png);\n"
"}"));
        frame = new QFrame(deleteuser);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 370, 202));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"border-image: url(:/userManage/image/userManage/cd.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 52, 111, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        confirmBtn = new QPushButton(frame);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setGeometry(QRect(34, 114, 116, 39));
        confirmBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/userManage/image/userManage/btn_delete_normal_green.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border-image: url(:/userManage/image/userManage/btn_delete_press_green.png);\n"
"}\n"
""));
        concleBtn = new QPushButton(frame);
        concleBtn->setObjectName(QStringLiteral("concleBtn"));
        concleBtn->setGeometry(QRect(218, 114, 116, 39));
        concleBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/userManage/image/userManage/btn_cancel_normal.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/userManage/image/userManage/btn_cancel_press.png);\n"
"}\n"
"\n"
""));

        retranslateUi(deleteuser);

        QMetaObject::connectSlotsByName(deleteuser);
    } // setupUi

    void retranslateUi(QWidget *deleteuser)
    {
        deleteuser->setWindowTitle(QApplication::translate("deleteuser", "deleteuser", 0));
        label_2->setText(QApplication::translate("deleteuser", "  \347\241\256\350\256\244\345\210\240\351\231\244\357\274\237", 0));
        confirmBtn->setText(QString());
        concleBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class deleteuser: public Ui_deleteuser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEUSER_H
