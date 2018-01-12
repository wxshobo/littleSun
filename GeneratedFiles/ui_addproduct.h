/********************************************************************************
** Form generated from reading UI file 'addproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPRODUCT_H
#define UI_ADDPRODUCT_H

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

class Ui_addProduct
{
public:
    QFrame *frame;
    QComboBox *proTypeBox;
    QLabel *proPriceLabel;
    QPushButton *proFinishBtn;
    QLabel *proTypeLabel;
    QLineEdit *proPriceLineEdit;
    QLineEdit *proNameLineEdit;
    QLabel *proNameLabel;
    QPushButton *proCancelBtn;

    void setupUi(QWidget *addProduct)
    {
        if (addProduct->objectName().isEmpty())
            addProduct->setObjectName(QStringLiteral("addProduct"));
        addProduct->resize(522, 318);
        addProduct->setStyleSheet(QString::fromUtf8("color: rgb(42, 42, 42);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        frame = new QFrame(addProduct);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 534, 324));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{border-image: url(:/productManage/image/productManage/ab.png);}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        proTypeBox = new QComboBox(frame);
        proTypeBox->setObjectName(QStringLiteral("proTypeBox"));
        proTypeBox->setGeometry(QRect(194, 120, 218, 32));
        proTypeBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox{\n"
"     font: 12pt \"Microsoft YaHei UI\";\n"
"\n"
"color: rgb(66, 66, 66);\n"
"	border-image: url(:/productManage/image/productManage/\344\270\213\346\213\211\346\241\206_normal.png);\n"
"}\n"
"\n"
"QComboBox:pressed{\n"
"border-image: url(:/productManage/image/productManage/\344\270\213\346\213\211\346\241\206_pressed.png);\n"
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
"}"));
        proTypeBox->setEditable(false);
        proPriceLabel = new QLabel(frame);
        proPriceLabel->setObjectName(QStringLiteral("proPriceLabel"));
        proPriceLabel->setGeometry(QRect(100, 190, 91, 20));
        proFinishBtn = new QPushButton(frame);
        proFinishBtn->setObjectName(QStringLiteral("proFinishBtn"));
        proFinishBtn->setGeometry(QRect(100, 250, 116, 39));
        proFinishBtn->setStyleSheet(QLatin1String("\n"
"QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_finish_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_finish_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_finish_normal.png);}"));
        proTypeLabel = new QLabel(frame);
        proTypeLabel->setObjectName(QStringLiteral("proTypeLabel"));
        proTypeLabel->setGeometry(QRect(100, 130, 81, 20));
        proPriceLineEdit = new QLineEdit(frame);
        proPriceLineEdit->setObjectName(QStringLiteral("proPriceLineEdit"));
        proPriceLineEdit->setGeometry(QRect(194, 180, 218, 32));
        proPriceLineEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/userManage/image/userManage/\346\226\207\346\234\254\346\241\206.png);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(66, 66, 66);"));
        proNameLineEdit = new QLineEdit(frame);
        proNameLineEdit->setObjectName(QStringLiteral("proNameLineEdit"));
        proNameLineEdit->setGeometry(QRect(190, 60, 218, 32));
        proNameLineEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/userManage/image/userManage/\346\226\207\346\234\254\346\241\206.png);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(66, 66, 66);"));
        proNameLabel = new QLabel(frame);
        proNameLabel->setObjectName(QStringLiteral("proNameLabel"));
        proNameLabel->setGeometry(QRect(100, 70, 81, 20));
        proNameLabel->setStyleSheet(QStringLiteral(""));
        proCancelBtn = new QPushButton(frame);
        proCancelBtn->setObjectName(QStringLiteral("proCancelBtn"));
        proCancelBtn->setGeometry(QRect(296, 250, 116, 39));
        proCancelBtn->setStyleSheet(QLatin1String("\n"
"QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_cancel_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_cancel_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_cancel_normal.png);}"));
        QWidget::setTabOrder(proNameLineEdit, proTypeBox);
        QWidget::setTabOrder(proTypeBox, proPriceLineEdit);
        QWidget::setTabOrder(proPriceLineEdit, proFinishBtn);
        QWidget::setTabOrder(proFinishBtn, proCancelBtn);

        retranslateUi(addProduct);

        QMetaObject::connectSlotsByName(addProduct);
    } // setupUi

    void retranslateUi(QWidget *addProduct)
    {
        addProduct->setWindowTitle(QApplication::translate("addProduct", "addproduct", 0));
        proPriceLabel->setText(QApplication::translate("addProduct", "\345\215\225\344\273\267(\345\205\203) \357\274\232", 0));
        proFinishBtn->setText(QString());
        proTypeLabel->setText(QApplication::translate("addProduct", "\344\272\247\345\223\201\347\261\273\345\210\253\357\274\232", 0));
        proNameLabel->setText(QApplication::translate("addProduct", "\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232", 0));
        proCancelBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addProduct: public Ui_addProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPRODUCT_H
