#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "ui_homepage.h"
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QTabWidget>
#include<QPushButton>
#include<QMouseEvent>
#include<QString>
#include<QKeyEvent>
#include <QDesktopWidget>
#include <QDebug>
#include "tabstartsell.h"
#include "tabproductmanage.h"
#include "tabusermanage.h"
#include"tabdataoutput.h"
#include "sqlOp.h"
#include "tabstatisticreport.h"

class HomePage : public QWidget
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = 0);
	~HomePage();



	private slots:
	void narrowbuttonclicked();
	void closebuttonclicked();
	void tabBarclicked(int a);


protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	
private:
	QPoint offset;
	Ui::HomePage ui;

	TabStartSell * m_pTabStartSell;
	TabDataOutput * m_pTabDataOutput;
	TabStatisticReport * m_pTabStatisticReport;
	TabProductManage * m_pTabProductManage;
	TabUserManage * m_pTabUserManage;

	static void exitapp();
};

#endif // HOMEPAGE_H
