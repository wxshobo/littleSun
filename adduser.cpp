#pragma execution_character_set("utf-8")
#include "adduser.h"
#include "getUUID.cpp"
adduser::adduser(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.confirm, SIGNAL(clicked()), this, SLOT(confirmSlot()));              //ȷ�ϲۺ���	
	connect(ui.concle, SIGNAL(clicked()), this, SLOT(concleSlot()));                //ȡ���ۺ���
	this->setWindowFlags(Qt::SplashScreen);                                         //û�в˵���

	ui.usertypeBox->addItem(tr("��ͨ�û�"));//��ʼ����Ʒ����������
	ui.usertypeBox->addItem(tr("����Ա"));
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

	m_vUserEdit = UUid::getUUid();                                                //��ȡ���ID
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

	}
	else
	{

		QString selectuser = "select UserName from UserInfo where UserName=?";                   //�ж����ӵ��û��Ƿ��Ѿ�����
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
			w->setContent(tr("�û��Ѵ��ڣ�����������!"));
			w->show();
			ui.usernameEdit->clear();
			ui.userpasswordEdit->clear();
		}
		else
		{
			index = ui.usertypeBox->currentIndex();
			if (index == 0)                                        //���ѡ����ͨ�û������û�����Ϊ1
			{
				m_vUsertypeEdit = QString::number(1);
			}
			else
			{
				m_vUsertypeEdit = QString::number(2);
			}
			QString insert = "insert into UserInfo(UserID,UserName,UserPWD,UserType) values(?,?,?,?)";     //�����ݿ��м�������
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
				w->setContent(tr("�����û��ɹ�"));
				w->show();
				//QMessageBox::information(NULL, "��ʾ", "�����û��ɹ�");
				emit adduserfresh();                                     //�����û��ɹ�����ˢ�����ݣ��������ָ���¼ӵ����ݣ����
			}
			else
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("�����û�ʧ��"));
				w->show();
				//QMessageBox::information(NULL, "��ʾ", "�����û�ʧ��");
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
	if (event-> key()== Qt::Key_Enter || event->key() == Qt::Key_Return)          //�س�����С���̵�Enter��
	{
		confirmSlot();//��ť�ۺ���
	}
}