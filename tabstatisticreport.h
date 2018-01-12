#ifndef TABSTATISTICREPORT_H
#define TABSTATISTICREPORT_H

#include <QWidget>
#include "ui_tabstatisticreport.h"

class TabStatisticReport : public QWidget
{
	Q_OBJECT

public:
	TabStatisticReport(QWidget *parent = 0);
	~TabStatisticReport();

private:
	Ui::TabStatisticReport ui;
};

#endif // TABSTATISTICREPORT_H
