#pragma execution_character_set("utf-8")
#include "deleteuser.h"

deleteuser::deleteuser(QVector<QVector <QString>> del, int current, int number,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::SplashScreen);                    //û�в˵���
	connect(ui.confirmBtn, SIGNAL(clicked()), this, SLOT(confirmBtnSlot()));     //ȷ�ϰ�ť�ۺ���
	connect(ui.concleBtn, SIGNAL(clicked()), this, SLOT(concleBtnSlot()));
	deleteTemp = del;
	cur = current;
	num = number;
	allPage = deleteTemp.size() / 7;

}

deleteuser::~deleteuser()
{

}

void deleteuser::concleBtnSlot()
{
	this->close();
}



void deleteuser::confirmBtnSlot()
{
	if (deleteTemp.size() <= 1)
	{
		this->close();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("������Ҫһ���û���ɾ��ʧ��"));
		w->show();
	}
	else
	{

		int i;
		QVector<QVariant> bindValue;
		bindValue.append(deleteTemp[cur * 7 + num][0]);                //num:ҳ���б�ѡ�еĵڼ���������֪����Ҫɾ�����û�ID
		QString del = "delete from UserInfo where UserId=?";
		int result = SqlOp::Delete_UpdateQuery(del, bindValue);
		if (result == 1)
		{
			this->close();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("ɾ���û��ɹ�"));
			w->show();
			//	QMessageBox::information(NULL, "��ʾ", "ɾ���û��ɹ�");

			emit deleteuserfresh();                                //���ɾ���ɹ�����ˢ�£���������Ƶ���ҳ��һ��λ��
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("ɾ���û�ʧ��"));
			w->show();
			//	QMessageBox::information(NULL, "��ʾ", "ɾ���û�ʧ��");
		}
	}
}
