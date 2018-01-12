#pragma execution_character_set("utf-8")
#include "homepage.h"

HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
{

	
	ui.setupUi(this);
	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setWindowFlags(Qt::FramelessWindowHint);  //消除运行边框
	m_pTabStartSell = new TabStartSell();
	m_pTabDataOutput = new TabDataOutput();
	m_pTabStatisticReport = new TabStatisticReport();
	m_pTabProductManage = new TabProductManage();
	m_pTabUserManage = new TabUserManage();
	ui.tabWidget->addTab(m_pTabStartSell, "开始报价");    //开始报价
	ui.tabWidget->addTab(m_pTabDataOutput, "数据导出");   //数据导出
	ui.tabWidget->addTab(m_pTabStatisticReport, "统计报表");    //统计报表
	ui.tabWidget->addTab(m_pTabProductManage, "产品管理");     //产品管理
	ui.tabWidget->addTab(m_pTabUserManage, "用户管理");         //用户管理
	ui.tabWidget->currentIndex();
	connect(ui.narrowbutton, SIGNAL(clicked()), this, SLOT(narrowbuttonclicked()));
	connect(ui.closebutton, SIGNAL(clicked()), this, SLOT(closebuttonclicked()));
	connect(ui.tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(tabBarclicked(int)));
	ui.tabWidget->setTabEnabled(2,false);

	QDesktopWidget* pDw = QApplication::desktop();                 //获得桌面窗体
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);      //居中显示
}
void HomePage::tabBarclicked(int index)
{
	if (index == 1)
	{
		m_pTabDataOutput->Update();
	}
	if (index == 0)
	{
		m_pTabStartSell->Refresh();
	}
}
void HomePage::narrowbuttonclicked()//最小化
{
	QWidget::showMinimized();
}
void HomePage::closebuttonclicked()//关闭窗口
{
	QApplication *a;
	a->exit();
	//close();
}
void HomePage::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		offset = QCursor::pos() - frameGeometry().topLeft();
	}
	QWidget::mousePressEvent(event);
}

void HomePage::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		QRect desktopRc = QApplication::desktop()->availableGeometry();
		QPoint curPoint = event->globalPos() - offset;
		if (event->globalY() > desktopRc.height())
		{
			curPoint.setY(desktopRc.height() - offset.y());
		}
		move(curPoint);
	}
	QWidget::mouseMoveEvent(event);
}
void HomePage::mouseReleaseEvent(QMouseEvent *event)
{
	event->accept();
}


HomePage::~HomePage()
{

}


void HomePage::exitapp()
{
	QApplication *app;
	app->exit();
}