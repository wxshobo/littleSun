#pragma execution_character_set("utf-8")
#include "reviseuser.h"

reviseuser::reviseuser(QVector<QVector <QString>> select, int current, int number, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::SplashScreen);                    //û�в˵���
	connect(ui.confirm, SIGNAL(clicked()), this, SLOT(confirmSlot()));
	connect(ui.concle, SIGNAL(clicked()), this, SLOT(concleSlot()));
	ui.comboBox->addItem(tr("��ͨ�û�"));
	ui.comboBox->addItem(tr("����Ա"));
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
	ui.usernameEdit->setText(QString(sel[cur * 7 + num][1]));                 //��Ҫɾ���û�����Ϣ��ʾ��LineEdit��
	ui.userpasswordEdit->setText(QString(sel[cur * 7 + num][3]));
	m_vusername = ui.usernameEdit->text();                                    //���浱ǰ�û���Ϣ
	m_vuserpassword = ui.userpasswordEdit->text();

	if (sel[cur * 7 + num][2] == QString::number(1))         //���Ҫɾ���û�����Ϊ1����combox �е�������Ϊ��ͨ�û�
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

	if (m_vUsernameEdit == "" || m_vUserpasswordEdit == "")                      //�ж������û����û����������Ƿ�Ϊ��
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("�û���������Ϊ�գ�����������!"));
		w->show();
		//	QMessageBox::warning(this, "��ʾ", "�û���������Ϊ�գ�����������", QMessageBox::Yes);
		ui.usernameEdit->clear();
		ui.userpasswordEdit->clear();
		ui.usernameEdit->setText(QString(sel[cur * 7 + num][1]));                 //��Ҫɾ���û�����Ϣ��ʾ��LineEdit��
		ui.userpasswordEdit->setText(QString(sel[cur * 7 + num][3]));
	}
	else
	{
		if (m_vusername == m_vUsernameEdit)
		{
			index = ui.comboBox->currentIndex();
			if (index == 0)                               //���ѡ����ͨ�û����򽫸��û���������Ϊ1���������ݿ���
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
				w->setContent(tr("�޸��û���Ϣ�ɹ�"));
				w->show();
				//QMessageBox::information(NULL, "��ʾ", "�޸��û���Ϣ�ɹ�");
				emit reviseuserfresh();               //ˢ�����ݣ�������Ƶ��޸ĵ�������
			}
		}
		else
		{

			QString selectuser = "select UserName from UserInfo where UserName=?";                   //�ж����ӵ��û��Ƿ��Ѿ�����
			QVector<QString >  bindValue1;
			bindValue1.append(m_vUsernameEdit);
			QVector<QVector<QString> > result;
			result = SqlOp::SelectQuery(selectuser, 1, bindValue1);
			if (result.size() > 0)
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("���û��Ѿ����ڣ�����������"));
				w->show();
				ui.usernameEdit->clear();
				ui.userpasswordEdit->clear();
				ui.usernameEdit->setText(QString(sel[cur * 7 + num][1]));                 //��Ҫɾ���û�����Ϣ��ʾ��LineEdit��
				ui.userpasswordEdit->setText(QString(sel[cur * 7 + num][3]));
			}
			else
			{
				index = ui.comboBox->currentIndex();
				if (index == 0)                               //���ѡ����ͨ�û����򽫸��û���������Ϊ1���������ݿ���
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
					w->setContent(tr("�޸��û���Ϣ�ɹ�"));
					w->show();
					emit reviseuserfresh();               //ˢ�����ݣ�������Ƶ��޸ĵ�������
				}
			}


		}
	}
}



void reviseuser::concleSlot()
{
	this->close();
}



