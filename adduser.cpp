#pragma execution_character_set("utf-8")
#include "adduser.h"
#include "getUUID.cpp"
adduser::adduser(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.confirm, SIGNAL(clicked()), this, SLOT(confirmSlot()));              //确认槽函数	
	connect(ui.concle, SIGNAL(clicked()), this, SLOT(concleSlot()));                //取消槽函数
	this->setWindowFlags(Qt::SplashScreen);                                         //没有菜单栏

	ui.usertypeBox->addItem(tr("普通用户"));//初始化产品类型下拉框
	ui.usertypeBox->addItem(tr("管理员"));
	for (int i = 0; i < 2; i++)
	{
		ui.usertypeBox->model()->setData(ui.usertypeBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
}

adduser::~adduser()
{


}


void adduser::confirmSlot()
{
	int index;
	int flag = 0;
	/*QDateTime time = QDateTime::currentDateTime();
	QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
	m_vUserEdit =str;*/

	m_vUserEdit = UUid::getUUid();                                                //获取随机ID
	m_vUsernameEdit = ui.usernameEdit->text();
	m_vUserpasswordEdit = ui.userpasswordEdit->text();

	if (m_vUsernameEdit == "" || m_vUserpasswordEdit == "")                      //判断增加用户的用户名或密码是否为空
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("用户名或密码为空，请重新输入!"));
		w->show();
		//	QMessageBox::warning(this, "提示", "用户名或密码为空，请重新输入", QMessageBox::Yes);
		ui.usernameEdit->clear();
		ui.userpasswordEdit->clear();

	}
	else
	{

		QString selectuser = "select UserName from UserInfo where UserName=?";                   //判断增加的用户是否已经存在
		QVector<QString >  bindValue1;
		bindValue1.append(m_vUsernameEdit);
		QVector<QVector<QString> > result;
		result = SqlOp::SelectQuery(selectuser, 1, bindValue1);
		for (int i = 0; i < result.size(); i++)
		{
			if (m_vUsernameEdit == result[i][0])
				flag = 1;
		}

		if (flag == 1)
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("用户已存在，请重新输入!"));
			w->show();
			ui.usernameEdit->clear();
			ui.userpasswordEdit->clear();
		}
		else
		{
			index = ui.usertypeBox->currentIndex();
			if (index == 0)                                        //如果选择普通用户，则用户类型为1
			{
				m_vUsertypeEdit = QString::number(1);
			}
			else
			{
				m_vUsertypeEdit = QString::number(2);
			}
			QString insert = "insert into UserInfo(UserID,UserName,UserPWD,UserType) values(?,?,?,?)";     //向数据库中加入数据
			QVector<QVariant> bindValue;
			bindValue.append(m_vUserEdit);
			bindValue.append(m_vUsernameEdit);
			bindValue.append(m_vUserpasswordEdit);
			bindValue.append(m_vUsertypeEdit);
			int result = SqlOp::InsertQuery(insert, bindValue);
			if (result == 1)
			{
				this->close();
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("增加用户成功"));
				w->show();
				//QMessageBox::information(NULL, "提示", "增加用户成功");
				emit adduserfresh();                                     //增加用户成功，则刷新数据，并将光标指向新加的数据（最后）
			}
			else
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("增加用户失败"));
				w->show();
				//QMessageBox::information(NULL, "提示", "增加用户失败");
				ui.usernameEdit->clear();
				ui.userpasswordEdit->clear();
			}

		}
	}
}




void adduser::concleSlot()
{
	this->close();
}


void adduser::keyPressEvent(QKeyEvent  *event)
{
	if (event-> key()== Qt::Key_Enter || event->key() == Qt::Key_Return)          //回车键和小键盘的Enter键
	{
		confirmSlot();//按钮槽函数
	}
}