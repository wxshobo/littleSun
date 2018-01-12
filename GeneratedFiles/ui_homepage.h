/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QFrame *frame;
    QTabWidget *tabWidget;
    QPushButton *narrowbutton;
    QPushButton *closebutton;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QStringLiteral("HomePage"));
        HomePage->resize(1024, 766);
        HomePage->setMaximumSize(QSize(1024, 768));
        HomePage->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(HomePage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 1024, 768));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"\n"
"border-image: url(:/homepage/image/userinterface/\350\203\214\346\231\257.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 69, 1028, 699));
        tabWidget->setMaximumSize(QSize(1030, 768));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar {  	\n"
"   /* left: 2px; */\n"
"      left:12px;\n"
"} \n"
"QTabBar::tab{\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"		width:200px;\n"
"		    height:50px; \n"
"color: rgb(66, 66, 66);\n"
"}\n"
"\n"
"QTabBar::tab:selected{\n"
"background-image: url(:/homepage/image/userinterface/\347\224\250\346\210\267\347\256\241\347\220\206--\351\200\211\344\270\255\347\212\266\346\200\201.png);\n"
"}\n"
"\n"
"\n"
"QTabBar::tab:!selected {  \n"
"background-image: url(:/homepage/image/userinterface/\346\234\252\351\200\211\347\212\266\346\200\201.png);\n"
"}\n"
"\n"
"\n"
""));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        narrowbutton = new QPushButton(frame);
        narrowbutton->setObjectName(QStringLiteral("narrowbutton"));
        narrowbutton->setGeometry(QRect(890, 0, 61, 28));
        narrowbutton->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	border-image: url(:/homepage/image/userinterface/narrow.png);\n"
"}\n"
"QPushButton::hover {\n"
"    \n"
"	border-image: url(:/homepage/image/userinterface/narrow_ed.png);\n"
"}\n"
""));
        closebutton = new QPushButton(frame);
        closebutton->setObjectName(QStringLiteral("closebutton"));
        closebutton->setGeometry(QRect(950, 0, 61, 28));
        closebutton->setStyleSheet(QLatin1String("\n"
"QPushButton{\n"
"	\n"
"	border-image: url(:/homepage/image/userinterface/close.png);\n"
"}\n"
"QPushButton::hover {\n"
"   \n"
"	border-image: url(:/homepage/image/userinterface/close_ed.png);\n"
"}\n"
""));

        retranslateUi(HomePage);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "HomePage", 0));
        narrowbutton->setText(QString());
        closebutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
