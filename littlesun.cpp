#pragma execution_character_set("utf-8")
#include "littlesun.h"
#include "sqlOp.h"
#include <QDebug>
#include"Parameter.h"
LittleSun::LittleSun(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setFixedSize(504, 378);                                  //固定大小
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground);            //背景透明化

	QDesktopWidget* pDw = QApplication::desktop();                 //获得桌面窗体
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);      //居中显示

	ui.userNameEdit->setPlaceholderText("请输入用户名");
	ui.passWordEdit->setPlaceholderText("请输入密码");
	ui.passWordEdit->setEchoMode(QLineEdit::Password);             //设置密码格式

	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(loginBtnSlot()));      //登录槽函数
	connect(ui.narrowBtn, SIGNAL(clicked()), this, SLOT(narrowBtnSlot()));    //缩小槽函数
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(closeBtnSlot()));      //关闭槽函数
	
	connect(ui.test, SIGNAL(clicked()), this, SLOT(opentest()));
	//ui.loginBtn->setShortcut(Qt::Key_Enter);
	

}



LittleSun::~LittleSun()
{


}

void LittleSun::loginBtnSlot()
{

	//QDateTime time;
	//time = time.currentDateTime();
	//qDebug() << time;
	m_vUserName = ui.userNameEdit->text();               //将输入的用户名赋值给变量
	m_vUserPWD = ui.passWordEdit->text();
	Parameter::getInstance()->m_vUserName = m_vUserName;
	
	if (m_vUserName == "" || m_vUserPWD == "")           //判断用户名彧密码是否为空
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("用户名或密码为空，请重新输入"));
		w->show();
	//	QMessageBox::warning(this, "提示", "用户名或密码为空，请重新输入", QMessageBox::Yes);
		ui.userNameEdit->clear();
		ui.passWordEdit->clear();
	}
	else
	{
		QString searchUser = "select UserName, UserPWD from UserInfo where UserName = ? and UserPWD = ?";       //查询语句
		QVector<QString > bindValue; 
		bindValue.append(m_vUserName);
		bindValue.append(m_vUserPWD);

		QVector<QVector<QString> > result;
		result = SqlOp::SelectQuery(searchUser, 2, bindValue);
		if (result.size() > 0)
		{
			//HomePage * homepage = new HomePage();                    //登录成功，则跳转到homepage
			//homepage->show();
			this->hide();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("用户名或密码错误，请重新输入"));
			w->show();
			//QMessageBox::warning(this, "提示", "用户名或密码错误，请重新输入", QMessageBox::Yes);
			ui.userNameEdit->clear();
			ui.passWordEdit->clear();
			return;
		}
	}
}


void LittleSun::narrowBtnSlot()                            //最小化
{

	QWidget::showMinimized();
}


void LittleSun::closeBtnSlot()                             //关闭
{
	QApplication *app;
	app->exit();

}



void LittleSun::keyPressEvent(QKeyEvent  *event)           //回车键和小键盘的Enter键
{
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)          
	{
		loginBtnSlot();
	}
}


void LittleSun::opentest()
{
	HomePage::exitapp();
}