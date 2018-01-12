#pragma execution_character_set("utf-8")
#include "littlesun.h"
#include "sqlOp.h"
#include <QDebug>
#include"Parameter.h"
LittleSun::LittleSun(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->setFixedSize(504, 378);                                  //�̶���С
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	this->setAttribute(Qt::WA_TranslucentBackground);            //����͸����

	QDesktopWidget* pDw = QApplication::desktop();                 //������洰��
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);      //������ʾ

	ui.userNameEdit->setPlaceholderText("�������û���");
	ui.passWordEdit->setPlaceholderText("����������");
	ui.passWordEdit->setEchoMode(QLineEdit::Password);             //���������ʽ

	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(loginBtnSlot()));      //��¼�ۺ���
	connect(ui.narrowBtn, SIGNAL(clicked()), this, SLOT(narrowBtnSlot()));    //��С�ۺ���
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(closeBtnSlot()));      //�رղۺ���
	
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
	m_vUserName = ui.userNameEdit->text();               //��������û�����ֵ������
	m_vUserPWD = ui.passWordEdit->text();
	Parameter::getInstance()->m_vUserName = m_vUserName;
	
	if (m_vUserName == "" || m_vUserPWD == "")           //�ж��û����������Ƿ�Ϊ��
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("�û���������Ϊ�գ�����������"));
		w->show();
	//	QMessageBox::warning(this, "��ʾ", "�û���������Ϊ�գ�����������", QMessageBox::Yes);
		ui.userNameEdit->clear();
		ui.passWordEdit->clear();
	}
	else
	{
		QString searchUser = "select UserName, UserPWD from UserInfo where UserName = ? and UserPWD = ?";       //��ѯ���
		QVector<QString > bindValue; 
		bindValue.append(m_vUserName);
		bindValue.append(m_vUserPWD);

		QVector<QVector<QString> > result;
		result = SqlOp::SelectQuery(searchUser, 2, bindValue);
		if (result.size() > 0)
		{
			//HomePage * homepage = new HomePage();                    //��¼�ɹ�������ת��homepage
			//homepage->show();
			this->hide();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("�û����������������������"));
			w->show();
			//QMessageBox::warning(this, "��ʾ", "�û����������������������", QMessageBox::Yes);
			ui.userNameEdit->clear();
			ui.passWordEdit->clear();
			return;
		}
	}
}


void LittleSun::narrowBtnSlot()                            //��С��
{

	QWidget::showMinimized();
}


void LittleSun::closeBtnSlot()                             //�ر�
{
	QApplication *app;
	app->exit();

}



void LittleSun::keyPressEvent(QKeyEvent  *event)           //�س�����С���̵�Enter��
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