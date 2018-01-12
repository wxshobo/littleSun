#pragma execution_character_set("utf-8")
#include "deleteproduct.h"

deleteproduct::deleteproduct(QVector<QVector<QString>> tempIn,int cur,int number,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::SplashScreen);                                //û�в˵���
	result = 0;
	tempInformation = tempIn;
	currentPage = cur;//��ɾ������һҳ
	currentIndex = number;//��ɾ������һ��
	allPage = tempInformation.size() / 7;
	if (tempInformation.size() % 7 != 0)
		allPage++;
	connect(ui.comfirmBtn, SIGNAL(clicked()), this, SLOT(deleteButtonClicked()));
	connect(ui.cancelBtn, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
}
/********************************************************************************************/
/*ʹdeleteproduct���ڿ��ƶ�*/

void deleteproduct::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
		offset = event->pos();
}

void deleteproduct::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - offset);
	}
}
void deleteproduct::mouseReleaseEvent(QMouseEvent *event)
{
	event->accept();
}
/******************************************************************************************/

deleteproduct::~deleteproduct()
{

}
void deleteproduct::deleteButtonClicked()
{
	int flag = 0;
	QString query = "select ProductID from BJRecord";
	proInformation = SqlOp::SelectQuery(query, 1);
	for (int i = 0; i < proInformation.size(); i++)
	{
		if (proInformation[i][0] == tempInformation[7 * (currentPage - 1) + currentIndex][0])
			flag = 1;
	}
	if (flag == 0)
	{
		QVector<QVariant> bindValue;
		bindValue.append(tempInformation[7 * (currentPage - 1) + currentIndex][0]);
		QString deleteQuery = "delete from ProductInfo where ProductID = ?";
		result = SqlOp::Delete_UpdateQuery(deleteQuery, bindValue);
		if (result)
		{
			this->close();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("ɾ����Ʒ�ɹ�"));
			w->show();
			emit deleteSuccess();
		}
		else
		{
			this->close();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("ɾ����Ʒʧ��"));
			w->show();
		}
	}
	else
	{
		this->close();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("ɾ����Ʒʧ��"));
		w->show();
	}
}
void deleteproduct::cancelButtonClicked()
{
	this->close();
}
void deleteproduct::keyPressEvent(QKeyEvent  *event)
{
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)          //�س�����С���̵�Enter��
	{
		deleteButtonClicked();//��ť�ۺ���
	}
}