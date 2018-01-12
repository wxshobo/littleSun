#pragma execution_character_set("utf-8")
#include "reviseproduct.h"
#include<typeinfo>
reviseProduct::reviseProduct(QVector<QVector<QString>> tempInfo,int current,int number,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	result = 0;
	this->setWindowFlags(Qt::SplashScreen);						        //û�в˵���
	connect(ui.comfirmBtn, SIGNAL(clicked()), this, SLOT(confirmSlot()));
	connect(ui.cancelBtn, SIGNAL(clicked()), this, SLOT(concleSlot()));

	ui.productTypeBox->addItem(tr("С̫��ɰ��"));//��ʼ����Ʒ����������
	ui.productTypeBox->addItem(tr("����ɰ��"));
	ui.productTypeBox->addItem(tr("��ţɰ��"));
	ui.productTypeBox->addItem(tr("����ɰ��"));
	ui.productTypeBox->addItem(tr("԰��ɰ"));
	ui.productTypeBox->addItem(tr("������Ʒ"));
	for (int i = 0; i < 6; i++)
	{
		ui.productTypeBox->model()->setData(ui.productTypeBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}

	sel = tempInfo;														//�洢��ǰ��ѯ�������ݿ��е���Ϣ
	cur = current;														//���޸ĵĵ�ǰҳ
	num = number;														//���޸ĵĵ�ǰ��
	allPage = sel.size() / 7;
	if (sel.size() % 7 != 0)
		allPage++;
	/*��ѡ��Ҫ�޸ĵĵ���һ�е�������ʾ����*/
	ui.productNameEdit->setText(sel[(cur - 1) * 7 + num][1]);
	ui.productPriceEdit->setText(sel[(cur - 1) * 7 + num][3]);
	ui.productTypeBox->setCurrentText(sel[(cur - 1) * 7 + num][4]);		//��ʾ��ǰ�������������
}
/********************************************************************************************/
/*ʹaddproduct���ڿ��ƶ�*/
void reviseProduct::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
		offset = event->pos();
}

void reviseProduct::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - offset);
	}
}
void reviseProduct::mouseReleaseEvent(QMouseEvent *event)
{
	event->accept();
}
/******************************************************************************************/
void reviseProduct::confirmSlot()
{
	int i;
	int index;
	m_vProductId = sel[(cur-1) * 7 + num][0];
	m_vProductNameEdit = ui.productNameEdit->text().simplified();
	m_vProductPriceEdit = ui.productPriceEdit->text().toFloat();
	if (m_vProductNameEdit == "" || m_vProductPriceEdit == 0)		//�ж����Ӳ�Ʒ�����ƻ򵥼��Ƿ�Ϊ��
	{
		if (ui.productPriceEdit->text().isEmpty() || m_vProductNameEdit == "")
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
			ui.productPriceEdit->clear();
		}
	}
	else
	{
		index = ui.productTypeBox->currentIndex();		//currentIndex��ǰ��ʾ���б������
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
		QString updateQuery = "update ProductInfo set ProductName=?,ProductType=?,Price=?,Notes=? where ProductID = ?";//�������
		QVector<QVariant> bindValue;

		bindValue.append(m_vProductNameEdit);
		bindValue.append(m_vProductTypeEdit);
		bindValue.append(m_vProductPriceEdit);
		bindValue.append(m_vProductMarkEdit);
		bindValue.append(m_vProductId);
		result = SqlOp::Delete_UpdateQuery(updateQuery, bindValue);
		if (result == 1)
		{
			this->close();
			emit reviseSuccess();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("�޸Ĳ�Ʒ�ɹ�"));
			w->show();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("�޸Ĳ�Ʒʧ��"));
			w->show();
			if (typeid(m_vProductNameEdit) != typeid(QString))//�ж����뵽proNameLineEdit�е��Ƿ�ΪQString����
				ui.productNameEdit->clear();
			if (typeid(m_vProductPriceEdit) != typeid(float))//�ж����뵽proPriceLineEdit�е��Ƿ�Ϊfloat����
				ui.productPriceEdit->clear();
		}
	}
}

void reviseProduct::concleSlot()
{
	this->close();
}
reviseProduct::~reviseProduct()
{

}
void reviseProduct::keyPressEvent(QKeyEvent  *event)
{
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)          //�س�����С���̵�Enter��
	{
		confirmSlot();//��ť�ۺ���
	}
}