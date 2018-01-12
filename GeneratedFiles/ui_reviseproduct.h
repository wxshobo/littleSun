/********************************************************************************
** Form generated from reading UI file 'reviseproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVISEPRODUCT_H
#define UI_REVISEPRODUCT_H

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

class Ui_reviseProduct
{
public:
    QFrame *frame;
    QComboBox *productTypeBox;
    QLabel *label_3;
    QLabel *label;
    QPushButton *cancelBtn;
    QPushButton *comfirmBtn;
    QLineEdit *productNameEdit;
    QLabel *label_2;
    QLineEdit *productPriceEdit;

    void setupUi(QWidget *reviseProduct)
    {
        if (reviseProduct->objectName().isEmpty())
            reviseProduct->setObjectName(QStringLiteral("reviseProduct"));
        reviseProduct->resize(522, 316);
        reviseProduct->setStyleSheet(QString::fromUtf8("color: rgb(42, 42, 42);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        frame = new QFrame(reviseProduct);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 534, 324));
        frame->setStyleSheet(QLatin1String("#frame\n"
"{border-image: url(:/productManage/image/productManage/ab.png);}\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        productTypeBox = new QComboBox(frame);
        productTypeBox->setObjectName(QStringLiteral("productTypeBox"));
        productTypeBox->setGeometry(QRect(200, 120, 218, 32));
        productTypeBox->setStyleSheet(QString::fromUtf8("\n"
"QComboBox{\n"
"     font: 12pt \"Microsoft YaHei UI\";\n"
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
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(106, 190, 81, 20));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(106, 70, 81, 20));
        cancelBtn = new QPushButton(frame);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(302, 250, 116, 39));
        cancelBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{border-image: url(:/productManage/image/productManage/btn_cancel_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/btn_cancel_press.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/btn_cancel_press.png);}\n"
""));
        comfirmBtn = new QPushButton(frame);
        comfirmBtn->setObjectName(QStringLiteral("comfirmBtn"));
        comfirmBtn->setGeometry(QRect(106, 250, 116, 39));
        comfirmBtn->setStyleSheet(QLatin1String("QPushButton\n"
"{border-image: url(:/productManage/image/productManage/_alter_normal.png);}\n"
"QPushButton:hover\n"
"{border-image: url(:/productManage/image/productManage/_alter_pressed.png);}\n"
"QPushButton:pressed\n"
"{border-image: url(:/productManage/image/productManage/_alter_pressed.png);}\n"
""));
        productNameEdit = new QLineEdit(frame);
        productNameEdit->setObjectName(QStringLiteral("productNameEdit"));
        productNameEdit->setGeometry(QRect(200, 60, 218, 32));
        productNameEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/userManage/image/userManage/\346\226\207\346\234\254\346\241\206.png);\n"
"color: rgb(66, 66, 66);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(106, 130, 81, 20));
        productPriceEdit = new QLineEdit(frame);
        productPriceEdit->setObjectName(QStringLiteral("productPriceEdit"));
        productPriceEdit->setGeometry(QRect(200, 190, 218, 32));
        productPriceEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/userManage/image/userManage/\346\226\207\346\234\254\346\241\206.png);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(66, 66, 66);"));
        QWidget::setTabOrder(productNameEdit, productTypeBox);
        QWidget::setTabOrder(productTypeBox, productPriceEdit);
        QWidget::setTabOrder(productPriceEdit, comfirmBtn);
        QWidget::setTabOrder(comfirmBtn, cancelBtn);

        retranslateUi(reviseProduct);

        QMetaObject::connectSlotsByName(reviseProduct);
    } // setupUi

    void retranslateUi(QWidget *reviseProduct)
    {
        reviseProduct->setWindowTitle(QApplication::translate("reviseProduct", "reviseProduct", 0));
        label_3->setText(QApplication::translate("reviseProduct", "\345\215\225\344\273\267(\345\205\203) \357\274\232", 0));
        label->setText(QApplication::translate("reviseProduct", "\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232", 0));
        cancelBtn->setText(QString());
        comfirmBtn->setText(QString());
        label_2->setText(QApplication::translate("reviseProduct", "\344\272\247\345\223\201\347\261\273\345\236\213\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class reviseProduct: public Ui_reviseProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVISEPRODUCT_H
