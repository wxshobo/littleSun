#pragma execution_character_set("utf-8")
#include<typeinfo>
#include "addproduct.h"
#include "tabproductmanage.h"
#include "getUUID.cpp"

AddProduct::AddProduct(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.proCancelBtn, SIGNAL(clicked()), this, SLOT(closeButtonClicked()));
	connect(ui.proFinishBtn, SIGNAL(clicked()), this, SLOT(finishButtonClicked()));
	this->setWindowFlags(Qt::SplashScreen);                                         //û�в˵���
	ui.proTypeBox->addItem(tr("С̫��ɰ��"));//��ʼ����Ʒ����������
	ui.proTypeBox->addItem(tr("����ɰ��"));
	ui.proTypeBox->addItem(tr("��ţɰ��"));
	ui.proTypeBox->addItem(tr("����ɰ��"));
	ui.proTypeBox->addItem(tr("԰��ɰ"));
	ui.proTypeBox->addItem(tr("������Ʒ"));
	for (int i = 0; i < 6; i++)
	{
		ui.proTypeBox->model()->setData(ui.proTypeBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
}
/********************************************************************************************/
/*ʹaddproduct���ڿ��ƶ�*/
void AddProduct::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
		offset = event->pos();
}

void AddProduct::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - offset);
	}
}
void AddProduct::mouseReleaseEvent(QMouseEvent *event)
{
	event->accept();
}
/******************************************************************************************/
void AddProduct::closeButtonClicked()
{
	close();
}
void AddProduct::finishButtonClicked()
{
	int index = 0;
	m_vProductNameEdit = ui.proNameLineEdit->text().simplified();   //simplified()��һ���ַ�����β�Ŀո�ȫ�����
	m_vProductPriceEdit = ui.proPriceLineEdit->text().toFloat();
	m_vProductID = UUid::getUUid();									//ϵͳ�Զ����ɵ�ID
	if (m_vProductNameEdit == "" || m_vProductPriceEdit == 0)		//�ж����Ӳ�Ʒ�����ƻ򵥼��Ƿ�Ϊ��
	{
		if (ui.proPriceLineEdit->text().isEmpty() || m_vProductNameEdit == "")
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("��Ʒ���򵥼�Ϊ�գ�������!"));
			w->show();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("��Ʒ���۸�ʽ��������������!"));
			w->show();
			ui.proPriceLineEdit->clear();
		}
	}
	else
	{
		index = ui.proTypeBox->currentIndex();  //������������ʾ������
		if (index == 0)
		{
			m_vProductTypeEdit = QString::number(1);
			m_vProductMarkEdit = "С̫��ɰ��";
		}
		else if (index == 1)
		{
			m_vProductTypeEdit = QString::number(2);
			m_vProductMarkEdit = "����ɰ��";
		}
		else if (index == 2)
		{
			m_vProductTypeEdit = QString::number(3);
			m_vProductMarkEdit = "��ţɰ��";
		}
		else if (index == 3)
		{
			m_vProductTypeEdit = QString::number(4);
			m_vProductMarkEdit = "����ɰ��";
		}
		else if (index == 4)
		{
			m_vProductTypeEdit = QString::number(5);
			m_vProductMarkEdit = "԰��ɰ";
		}
		else{
			m_vProductTypeEdit = QString::number(6);
			m_vProductMarkEdit = "������Ʒ";
		}
		QString query = "insert into ProductInfo(ProductID,ProductName,ProductType,Price,Notes) values(?,?,?,?,?)";//�������
		QVector<QVariant> bindvalue;
		bindvalue.append(m_vProductID);
		bindvalue.append(m_vProductNameEdit);
		bindvalue.append(m_vProductTypeEdit);
		bindvalue.append(m_vProductPriceEdit);
		bindvalue.append(m_vProductMarkEdit);
		bool result = SqlOp::InsertQuery(query, bindvalue);
	
		if (result)//��ʾ��ӳɹ�
		{
			this->close();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("��Ӳ�Ʒ�ɹ�"));
			w->show();
			emit addSuccess();//������ӳɹ����ź�
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("��Ӳ�Ʒʧ��"));
			w->show();
			if (typeid(m_vProductNameEdit) != typeid(QString))	 //�ж����뵽proNameLineEdit�е��Ƿ�ΪQString����
				ui.proNameLineEdit->clear();							
			if (typeid(m_vProductPriceEdit) != typeid(float))	 //�ж����뵽proPriceLineEdit�е��Ƿ�Ϊfloat����
				ui.proPriceLineEdit->clear();
		}
	}
}
AddProduct::~AddProduct()
{

}
void AddProduct::keyPressEvent(QKeyEvent  *event)
{
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)          //�س�����С���̵�Enter��
	{
		finishButtonClicked();//��ť�ۺ���
	}
}