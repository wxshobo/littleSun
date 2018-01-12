#pragma execution_character_set("utf-8")
#include "reviseuser.h"

reviseuser::reviseuser(QVector<QVector <QString>> select, int current, int number, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::SplashScreen);                    //没有菜单栏
	connect(ui.confirm, SIGNAL(clicked()), this, SLOT(confirmSlot()));
	connect(ui.concle, SIGNAL(clicked()), this, SLOT(concleSlot()));
	ui.comboBox->addItem(tr("普通用户"));
	ui.comboBox->addItem(tr("管理员"));
	for (int i = 0; i < 2; i++)
	{
		ui.comboBox->model()->setData(ui.comboBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}

	sel = select;
	cur = current;
	num = number;
	allPage = sel.size() / 7;

	/*ui.usernameEdit->setPlaceholderText(QString(sel[cur * 7 + num][1]));
	ui.userpasswordEdit->setPlaceholderText(QString(sel[cur * 7 + num][3]));*/
	ui.usernameEdit->setText(QString(sel[cur * 7 + num][1]));                 //将要删除用户的信息显示在LineEdit中
	ui.userpasswordEdit->setText(QString(sel[cur * 7 + num][3]));
	m_vusername = ui.usernameEdit->text();                                    //保存当前用户信息
	m_vuserpassword = ui.userpasswordEdit->text();

	if (sel[cur * 7 + num][2] == QString::number(1))         //如果要删除用户类型为1，则将combox 中的数据设为普通用户
	{
		ui.comboBox->setCurrentIndex(0);
	}
	else
		ui.comboBox->setCurrentIndex(1);



}



reviseuser::~reviseuser()
{

}


void reviseuser::confirmSlot()
{
	int i;
	int index;
	m_vUserId = sel[cur * 7 + num][0];
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
		ui.usernameEdit->setText(QString(sel[cur * 7 + num][1]));                 //将要删除用户的信息显示在LineEdit中
		ui.userpasswordEdit->setText(QString(sel[cur * 7 + num][3]));
	}
	else
	{
		if (m_vusername == m_vUsernameEdit)
		{
			index = ui.comboBox->currentIndex();
			if (index == 0)                               //如果选择普通用户，则将该用户的类型设为1，存入数据库中
			{
				m_vUsertypeEdit = QString::number(1);
			}
			else
			{
				m_vUsertypeEdit = QString::number(2);
			}

			QString update = "update UserInfo set UserName=?,UserPWD=?,UserType=? where UserID=?";
			QVector<QVariant> bindValue;
			bindValue.append(m_vUsernameEdit);
			bindValue.append(m_vUserpasswordEdit);
			bindValue.append(m_vUsertypeEdit);
			bindValue.append(m_vUserId);
			int result = SqlOp::Delete_UpdateQuery(update, bindValue);
			if (result == 1)
			{
				this->close();
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("修改用户信息成功"));
				w->show();
				//QMessageBox::information(NULL, "提示", "修改用户信息成功");
				emit reviseuserfresh();               //刷新数据，将光标移到修改的数据上
			}
		}
		else
		{

			QString selectuser = "select UserName from UserInfo where UserName=?";                   //判断增加的用户是否已经存在
			QVector<QString >  bindValue1;
			bindValue1.append(m_vUsernameEdit);
			QVector<QVector<QString> > result;
			result = SqlOp::SelectQuery(selectuser, 1, bindValue1);
			if (result.size() > 0)
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("该用户已经存在，请重新输入"));
				w->show();
				ui.usernameEdit->clear();
				ui.userpasswordEdit->clear();
				ui.usernameEdit->setText(QString(sel[cur * 7 + num][1]));                 //将要删除用户的信息显示在LineEdit中
				ui.userpasswordEdit->setText(QString(sel[cur * 7 + num][3]));
			}
			else
			{
				index = ui.comboBox->currentIndex();
				if (index == 0)                               //如果选择普通用户，则将该用户的类型设为1，存入数据库中
				{
					m_vUsertypeEdit = QString::number(1);
				}
				else
				{
					m_vUsertypeEdit = QString::number(2);
				}

				QString update = "update UserInfo set UserName=?,UserPWD=?,UserType=? where UserID=?";
				QVector<QVariant> bindValue;
				bindValue.append(m_vUsernameEdit);
				bindValue.append(m_vUserpasswordEdit);
				bindValue.append(m_vUsertypeEdit);
				bindValue.append(m_vUserId);
				int result = SqlOp::Delete_UpdateQuery(update, bindValue);
				if (result == 1)
				{
					this->close();
					TipDialog *w = new TipDialog("okButtonOnly");
					w->setContent(tr("修改用户信息成功"));
					w->show();
					emit reviseuserfresh();               //刷新数据，将光标移到修改的数据上
				}
			}


		}
	}
}



void reviseuser::concleSlot()
{
	this->close();
}



