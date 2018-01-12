#pragma execution_character_set("utf-8")
#include "homepage.h"

HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
{

	
	ui.setupUi(this);
	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	setWindowFlags(Qt::FramelessWindowHint);  //�������б߿�
	m_pTabStartSell = new TabStartSell();
	m_pTabDataOutput = new TabDataOutput();
	m_pTabStatisticReport = new TabStatisticReport();
	m_pTabProductManage = new TabProductManage();
	m_pTabUserManage = new TabUserManage();
	ui.tabWidget->addTab(m_pTabStartSell, "��ʼ����");    //��ʼ����
	ui.tabWidget->addTab(m_pTabDataOutput, "���ݵ���");   //���ݵ���
	ui.tabWidget->addTab(m_pTabStatisticReport, "ͳ�Ʊ���");    //ͳ�Ʊ���
	ui.tabWidget->addTab(m_pTabProductManage, "��Ʒ����");     //��Ʒ����
	ui.tabWidget->addTab(m_pTabUserManage, "�û�����");         //�û�����
	ui.tabWidget->currentIndex();
	connect(ui.narrowbutton, SIGNAL(clicked()), this, SLOT(narrowbuttonclicked()));
	connect(ui.closebutton, SIGNAL(clicked()), this, SLOT(closebuttonclicked()));
	connect(ui.tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(tabBarclicked(int)));
	ui.tabWidget->setTabEnabled(2,false);

	QDesktopWidget* pDw = QApplication::desktop();                 //������洰��
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);      //������ʾ
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
void HomePage::narrowbuttonclicked()//��С��
{
	QWidget::showMinimized();
}
void HomePage::closebuttonclicked()//�رմ���
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