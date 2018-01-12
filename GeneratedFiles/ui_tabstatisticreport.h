/********************************************************************************
** Form generated from reading UI file 'tabstatisticreport.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABSTATISTICREPORT_H
#define UI_TABSTATISTICREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabStatisticReport
{
public:

    void setupUi(QWidget *TabStatisticReport)
    {
        if (TabStatisticReport->objectName().isEmpty())
            TabStatisticReport->setObjectName(QStringLiteral("TabStatisticReport"));
        TabStatisticReport->setEnabled(true);
        TabStatisticReport->resize(94, 16);

        retranslateUi(TabStatisticReport);

        QMetaObject::connectSlotsByName(TabStatisticReport);
    } // setupUi

    void retranslateUi(QWidget *TabStatisticReport)
    {
        TabStatisticReport->setWindowTitle(QApplication::translate("TabStatisticReport", "TabStatisticReport", 0));
    } // retranslateUi

};

namespace Ui {
    class TabStatisticReport: public Ui_TabStatisticReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABSTATISTICREPORT_H
