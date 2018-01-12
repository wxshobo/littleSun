#pragma execution_character_set("utf-8")
#include "tabstartsell.h"
#include "getUUID.cpp"
#include<QMessageBox>
TabStartSell::TabStartSell(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.stabuyEdit, SIGNAL(returnPressed()), this, SLOT(savestabuyEditinfo()));    //��ȡ����λ
	connect(ui.stabuyEdit, SIGNAL(editingFinished()), this, SLOT(savestabuyEditinfo()));    //��ȡ����λ
	//connect(ui.stasortComBox, SIGNAL(activated(QString)), this, SLOT(savestasortComBoxinfo()));   //��ȡ��ǰ��Ʒ����
	connect(ui.stasortComBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(savestasortComBoxinfo(QString)));
	connect(ui.stanameComBox, SIGNAL(activated(QString)), this, SLOT(savestanameComBoxinfo()));  //��ȡ��ǰ��Ʒ����
	//connect(ui.stanameComBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(savestanameComBoxinfo()));
	connect(ui.stalengthEdit, SIGNAL(returnPressed()), this, SLOT(savestalengthEditinfo()));   //��ȡ����
	connect(ui.stalengthEdit, SIGNAL(editingFinished()), this, SLOT(savestalengthEditinfo()));
	connect(ui.stawidthEdit, SIGNAL(returnPressed()), this, SLOT(savestawidthEditinfo()));   //��ȡ���
	connect(ui.stawidthEdit, SIGNAL(editingFinished()), this, SLOT(savestawidthEditinfo()));
	connect(ui.staflatCheBox, SIGNAL(stateChanged(int)), this, SLOT(savestateChanged(int)));  //����ѡ��״̬�����ı�ʱ�����ۺ���
   	connect(ui.staphoneEdit, SIGNAL(returnPressed()), this, SLOT(savestaphoneEditinfo()));     //��ȡ�ֻ���
	connect(ui.staphoneEdit, SIGNAL(editingFinished()), this, SLOT(savestaphoneEditinfo()));
	connect(ui.statelephoneEdit, SIGNAL(returnPressed()), this, SLOT(savestatelephoneEditinfo()));    //��ȡ�绰����
	connect(ui.statelephoneEdit, SIGNAL(editingFinished()), this, SLOT(savestatelephoneEditinfo()));
	ui.staflatsingleEdit->setEnabled(false);   //��ʼʱƽ�ӵ����޷�ѡ��
	ui.staflatpriceEdit->setEnabled(false);    //��ʼ��ƽ�Ӽ۸��޷�ѡ��
	connect(ui.stamodulusEdit, SIGNAL(returnPressed()), this, SLOT(savestamodulusEditinfo()));
	connect(ui.stamodulusEdit, SIGNAL(editingFinished()), this, SLOT(savestamodulusEditinfo()));
	connect(ui.staterminalEdit, SIGNAL(returnPressed()), this, SLOT(savestaterminalEditinfo()));
	connect(ui.staterminalEdit, SIGNAL(editingFinished()), this, SLOT(savestaterminalEditinfo()));
	connect(ui.staclearbutton, SIGNAL(clicked()), this, SLOT(ClearScreen()));    //����
	connect(ui.stafinishbutton, SIGNAL(clicked()), this, SLOT(Finish()));     //���
	ui.stasortComBox->addItem(tr("С̫��ɰ��"));   //��ʼ����Ʒ����������
	ui.stasortComBox->addItem(tr("����ɰ��"));
	ui.stasortComBox->addItem(tr("��ţɰ��"));
	ui.stasortComBox->addItem(tr("����ɰ��"));
	ui.stasortComBox->addItem(tr("Բ��ɰ"));
	ui.stasortComBox->addItem(tr("������Ʒ"));
	for (int i = 0; i < 6; i++)
	{
		ui.stasortComBox->model()->setData(ui.stasortComBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	ui.stabasisEdit->setEnabled(false);
	ui.stacostEdit->setEnabled(false);
	ui.stasingleEdit->setEnabled(false);    //��Ʒ�ĵ��۲��ܸı�
}

TabStartSell::~TabStartSell()
{

}
void TabStartSell::Refresh()
{
	ui.stanameComBox->clear();
	QString m_vSort = ui.stasortComBox->currentText();   //��ȡ��ǰѡ��Ĳ�Ʒ����
	if (m_vSort.indexOf("С") == 0)
		Sort = "1";
	else if (m_vSort.indexOf("��") == 0)
		Sort = "2";
	else if (m_vSort.indexOf("��") == 0)
		Sort = "3";
	else if (m_vSort.indexOf("��") == 0)
	{
		if (m_vSort.indexOf("ɰ") == 2)
			Sort = "4";
		else Sort = "6";
	}
	else Sort = "5";
	QString searchProductName = "select ProductName from ProductInfo where ProductType=?";
	//�����ݿ��в�ѯ��Ӧ�Ĳ�Ʒ����
	QVector<QVector<QString>> NameResult;   //������Ų�ѯ���
	QVector<QString> bindValue;
	bindValue.append(Sort);
	NameResult = SqlOp::SelectQuery(searchProductName, 1, bindValue);  //��ȡ��Ʒ����Ӧ�Ĳ�Ʒ����
	for (int i = 0; i < NameResult.size(); i++)
	{
		QString ProductName = NameResult[i][0];
		ui.stanameComBox->addItem(ProductName);  //�����еĲ�Ʒ������ӵ���������
		ui.stanameComBox->model()->setData(ui.stanameComBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	QString m_vProductName = ui.stanameComBox->currentText();  //��ȡ��ǰѡ��Ĳ�Ʒ����
	if (!m_vProductName.isEmpty())
	{
		QString searchUnitPrice = "select ProductID,Price from ProductInfo where ProductType=? and ProductName=? ";
		QVector<QVector<QString> > PriceResult;    //��ѯ��Ʒ��Ӧ�ĵ���
		QVector<QString> bindValue1;
		bindValue1.append(Sort);
		bindValue1.append(m_vProductName);
		PriceResult = SqlOp::SelectQuery(searchUnitPrice, 2, bindValue1);
		QString m_vUnitPrice = PriceResult[0][1];   //��ȡ��Ʒ����
		m_vProductId = PriceResult[0][0];    //��ȡ��ƷID
		ui.stasingleEdit->setText(m_vUnitPrice);   //����Ʒ�ĵ���ֱ����ʾ����
	}
	else ui.stasingleEdit->clear();
}
int TabStartSell::isDigitStr(QString str)  //�ж��������ֵ�Ƿ�Ϊ��ȷ��С��
{
	QByteArray ba = str.toLatin1();//QString ת��Ϊ char*  
	const char *s = ba.data();
	int point = 1;    //С�����������ֻ��1��
	int num = 0;     //���ֵĸ���
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 && s[i] == 0)
		{
			if ((str.size()>2 && s[i + 1] != '.') || str.size() == 1)
				//�������ֵΪ0�����ж�Ϊ�����ʽ������������һ������Ϊ0��0���治��С����Ҳ�ж�Ϊ��ʽ����
				return 0;
		}
		if (s[i] == '.')
		{
			point--;
			if (i == str.size() - 1 || i == 0)   //���С�������û�����֣�˵���������ֵ��ʽ����
				return 0;
		}
		if (point < 0)
			return 0;   //���С������������1����˵���������ֵ��ʽ����
		if (s[i] >= '0' && s[i] <= '9')
			num = num + 1;
	}
	if (point == 1)
	{
		if (num == str.size())
			return 1;
		else return 0;
	}
	else if (point == 0)
	{
		if (num + 1 == str.size())
			return 1;
		else return 0;
	}
}


int TabStartSell::isDigital(QString str)   //�ж��Ƿ�Ϊ������
{
	QByteArray ba = str.toLatin1();//QString ת��Ϊ char*  
	const char *s = ba.data();
	while (*s && *s >= '0' && *s <= '9') s++;
	if (*s)
	{ //���Ǵ�����  
		return 0;
	}
	else
	{ //������  
		return 1;
	}
}
void TabStartSell::savestabuyEditinfo()    //��ȡ����λ����
{
	if (ui.stabuyEdit->text().isEmpty())
	{
		ui.stabuyEdit->setPlaceholderText(tr("�����빺��λ"));
		//ui.stabuyEdit->setFocus();
	}
	else
	{
		QString m_vPurchaseUnit = ui.stabuyEdit->text();   //��ȡ�û�����Ĺ���λ����
		m_vCompanyName = m_vPurchaseUnit;
		QString searchPurchaseUnit = "select phone1,phone2,ContactMan from CompanyInfo where CompanyName=?";
		QVector<QString> bindValue;
		bindValue.append(m_vPurchaseUnit);
		QVector<QVector<QString> > result;  //������Ž��
		result = SqlOp::SelectQuery(searchPurchaseUnit, 3, bindValue);
		if (result.size() > 0)   //�������λ�����ݿ����Ѿ����ڣ���ô��ϵ�ˣ���ϵ�绰���ֻ��ſ����Զ���ʾ
		{
			m_vFlag = 1;   //�������λ�����ݿ����Ѿ�������m_vFlag��Ϊ1
			QString Telephone = result[0][0];   //��ȡ���ݿ�����Ӧ����ϵ�绰
			QString Phone = result[0][1];        // ��ȡ���ݿ�����Ӧ���ֻ���
			QString ContactMan = result[0][2];   //��ȡ���ݿ�����Ӧ��ϵ��
			ui.statelephoneEdit->setText(Telephone);   //����ϵ�绰��ӡ����ϵ�绰�༭����
			ui.staphoneEdit->setText(Phone);      // ���ֻ��Ŵ�ӡ���ֻ��ű༭����
			ui.stamanEdit->setText(ContactMan);   //����ϵ�˴�ӡ����ϵ�˱༭����
			m_vtelephone = Telephone;
			m_vphone = Phone;
			m_vContactPerson = ContactMan;
		}
	}
}
void TabStartSell::savestatelephoneEditinfo()   //��ȡ��ϵ�绰����
{
	if (isDigital(ui.statelephoneEdit->text()) == 0)
	{
		ui.statelephoneEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("��������ȷ����ֵ"));
		w->show();
	}
}
void TabStartSell::savestaphoneEditinfo()   //��ȡ�ֻ���
{
	if (isDigital(ui.staphoneEdit->text()) == 0)
	{
		ui.staphoneEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("��������ȷ����ֵ"));
		w->show();
	}
}
void TabStartSell::savestasortComBoxinfo(QString m_vSort)   //��ȡ��ǰ��Ʒ���
{
	ui.stanameComBox->clear();
	//QString m_vSort = ui.stasortComBox->currentText();   //��ȡ��ǰѡ��Ĳ�Ʒ����
	if (m_vSort.indexOf("С") == 0)
		Sort = "1";
	else if (m_vSort.indexOf("��") == 0)
		Sort = "2";
	else if (m_vSort.indexOf("��") == 0)
		Sort = "3";
	else if (m_vSort.indexOf("��") == 0)
	{
		if (m_vSort.indexOf("ɰ") == 2)
			Sort = "4";
		else Sort = "6";
	}
	else Sort = "5";
	QString searchProductName = "select ProductName from ProductInfo where ProductType=?";
	//�����ݿ��в�ѯ��Ӧ�Ĳ�Ʒ����
	QVector<QVector<QString>> NameResult;   //������Ų�ѯ���
	QVector<QString> bindValue;
	bindValue.append(Sort);
	NameResult = SqlOp::SelectQuery(searchProductName, 1, bindValue);  //��ȡ��Ʒ����Ӧ�Ĳ�Ʒ����
	for (int i = 0; i < NameResult.size(); i++)
	{
		QString ProductName = NameResult[i][0];
		ui.stanameComBox->addItem(ProductName);  //�����еĲ�Ʒ������ӵ���������
		ui.stanameComBox->model()->setData(ui.stanameComBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	QString m_vProductName = ui.stanameComBox->currentText();  //��ȡ��ǰѡ��Ĳ�Ʒ����
	if (!m_vProductName.isEmpty())
	{
		QString searchUnitPrice = "select ProductID,Price from ProductInfo where ProductType=? and ProductName=? ";
		QVector<QVector<QString> > PriceResult;    //��ѯ��Ʒ��Ӧ�ĵ���
		QVector<QString> bindValue1;
		bindValue1.append(Sort);
		bindValue1.append(m_vProductName);
		PriceResult = SqlOp::SelectQuery(searchUnitPrice, 2, bindValue1);
		QString m_vUnitPrice = PriceResult[0][1];   //��ȡ��Ʒ����
		m_vProductId = PriceResult[0][0];    //��ȡ��ƷID
		ui.stasingleEdit->setText(m_vUnitPrice);   //����Ʒ�ĵ���ֱ����ʾ����
	}
	else ui.stasingleEdit->clear();
}
void TabStartSell::savestanameComBoxinfo()   //��ȡ��ǰѡ��Ĳ�Ʒ����
{
	QString m_vProductName = ui.stanameComBox->currentText();  //��ȡ��ǰѡ��Ĳ�Ʒ����
	QString searchUnitPrice = "select ProductID,Price from ProductInfo where ProductType=? and ProductName=? ";
	QVector<QVector<QString> > result;    //��ѯ��Ʒ��Ӧ�ĵ���
	QVector<QString> bindValue;
	bindValue.append(Sort);
	bindValue.append(m_vProductName);
	result = SqlOp::SelectQuery(searchUnitPrice, 2, bindValue);
	QString m_vUnitPrice = result[0][1];   //��ȡ��Ʒ����
	m_vProductId = result[0][0];    //��ȡ��ƷID
	ui.stasingleEdit->setText(m_vUnitPrice);   //����Ʒ�ĵ���ֱ����ʾ����
}
void TabStartSell::savestalengthEditinfo()   //��ȡ����
{
	if (ui.stalengthEdit->text().isEmpty())
	{
		ui.stalengthEdit->setPlaceholderText(tr("�����볤��"));
		//ui.stalengthEdit->setFocus();
	}
	else
	{
		if (isDigitStr(ui.stalengthEdit->text()) == 0)
		{
			ui.stalengthEdit->clear();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("��������ȷ����ֵ"));
			w->show();
		}
		else
		{
			float Width = ui.stawidthEdit->text().toFloat();      //��QString�͵Ŀ�ȱ�Ϊfloat��
			float Length = ui.stalengthEdit->text().toFloat();    //��QString�͵ĳ��ȱ�Ϊfloat��
			float Price = ui.stasingleEdit->text().toFloat();  //��QString�͵ĵ��۱�Ϊfloat��
			float BasePrice = Width*Length*Price;    //�����۸�=����*���*����
			//QString m_vBasePrice = QString("%1").arg(BasePrice);   //��float�͵Ļ����۸��ΪQString��
			QString m_vBasePrice = QString::number(BasePrice, 'f', 2);
			ui.stabasisEdit->setText(m_vBasePrice);
			ui.stacostEdit->setText(m_vBasePrice);
			if (ui.stamodulusEdit->text().isEmpty())    //�������ϵ��Ϊ��
			{
				ui.stamodulusEdit->setText(tr("1.1"));   //��ʼʱ����ϵ��Ĭ��Ϊ1.1
				float terminalprice = BasePrice * 1.1;      //�ն˼۸�=�ɱ���*����ϵ��
				//QString m_vTerminalPrice = QString("%1").arg(terminalprice);   //��Float�͵��ն˼۸��ΪQString��
				QString m_vTerminalPrice = QString::number(terminalprice, 'f', 2);
				ui.staterminalEdit->setText(m_vTerminalPrice);
				ui.stawidthEdit->clearFocus();     //������ȱ༭���еĹ��
			}
			else
			{
				float coefficient = ui.stamodulusEdit->text().toFloat(); //��QString�͵ı���ϵ��תΪFloat��
				float terminalprice = BasePrice * coefficient;   //�ն˼۸�=�ɱ���*����ϵ��
				ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
			}
			ui.stawidthEdit->setFocus();
		}
	}
}
void TabStartSell::savestawidthEditinfo()    //��ȡ���
{
	if (ui.stawidthEdit->text().isEmpty())
	{
		ui.stawidthEdit->setPlaceholderText(tr("��������"));
		//ui.stawidthEdit->setFocus();
	}
	else
	{
		if (isDigitStr(ui.stawidthEdit->text()) == 0)
		{
			ui.stawidthEdit->clear();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("��������ȷ����ֵ"));
			w->show();
		}
		else
		{
			QString m_vWidth = ui.stawidthEdit->text();
			float Width = m_vWidth.toFloat();      //��QString�͵Ŀ�ȱ�Ϊfloat��
			float Length = ui.stalengthEdit->text().toFloat();    //��QString�͵ĳ��ȱ�Ϊfloat��
			float Price = ui.stasingleEdit->text().toFloat();  //��QString�͵ĵ��۱�Ϊfloat��
			float BasePrice = Width*Length*Price;    //�����۸�=����*���*����
			//QString m_vBasePrice = QString("%1").arg(BasePrice);   //��float�͵Ļ������۱�ΪQString��
			QString m_vBasePrice = QString::number(BasePrice, 'f', 2);
			ui.stabasisEdit->setText(m_vBasePrice);
			ui.stacostEdit->setText(m_vBasePrice);
			if (ui.stamodulusEdit->text().isEmpty())    //�������ϵ��Ϊ��
			{
				ui.stamodulusEdit->setText(tr("1.1"));   //��ʼʱ����ϵ��Ĭ��Ϊ1.1
				float terminalprice = BasePrice * 1.1;      //�ն˼۸�=�ɱ���*����ϵ��
				//QString m_vTerminalPrice = QString("%1").arg(terminalprice);   //��Float�͵��ն˼۸��ΪQString��
				QString m_vTerminalPrice = QString::number(terminalprice, 'f', 2);
				ui.staterminalEdit->setText(m_vTerminalPrice);
				ui.stawidthEdit->clearFocus();     //������ȱ༭���еĹ��
			}
			else
			{
				float coefficient = ui.stamodulusEdit->text().toFloat(); //��QString�͵ı���ϵ��תΪFloat��
				float terminalprice = BasePrice * coefficient;   //�ն˼۸�=�ɱ���*����ϵ��
				ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
			}
		}
	}
}
void TabStartSell::savestateChanged(int state)     //ѡ��ƽ��
{
	if (state == Qt::Unchecked)
	{
		float CostPrice = ui.stacostEdit->text().toFloat() - FlatPrice;
		QString m_vCostPrice = QString::number(CostPrice, 'f', 2);   //��Float�͵ĳɱ��۱�ΪQString��
		float coefficient = ui.stamodulusEdit->text().toFloat();   //��QString�͵ı���ϵ��תΪFloat��
		float terminalprice = CostPrice * coefficient;   //�ն˼۸�=�ɱ���*����ϵ��
		ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
		ui.stacostEdit->setText(m_vCostPrice);
		ui.staflatsingleEdit->clear();
		ui.staflatpriceEdit->clear();
		ui.staflatsingleEdit->setEnabled(false);   //��ʼʱƽ�ӵ����޷�ѡ��
		ui.staflatpriceEdit->setEnabled(false);    //��ʼ��ƽ�Ӽ۸��޷�ѡ��
	}
	else if (state == Qt::Checked)
	{
		m_vTemp = 1;   //���ѡ��ƽ����m_vTemp��1
		ui.staflatsingleEdit->setEnabled(true);
		ui.staflatsingleEdit->setText(tr("4"));
		//ui.staflatsingleEdit->setFocus();
	    FlatPrice = 4 * ui.stawidthEdit->text().toFloat();   //ƽ�Ӽ۸�=ƽ�ӵ���*���
		ui.staflatpriceEdit->setText(QString::number(FlatPrice, 'f', 2));
		float BasePrice = ui.stabasisEdit->text().toFloat();   //��QString�͵Ļ����۸��Ϊfloat��
		float CostPrice = BasePrice + FlatPrice;     //�ɱ���=�����۸�+ƽ�Ӽ۸�
		float coefficient = ui.stamodulusEdit->text().toFloat();   //��QString�͵ı���ϵ��תΪFloat��
		float terminalprice = CostPrice * coefficient;   //�ն˼۸�=�ɱ���*����ϵ��
		ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
		ui.stacostEdit->setText(QString::number(CostPrice, 'f', 2));
		connect(ui.staflatsingleEdit, SIGNAL(returnPressed()), this, SLOT(savestaflatsingleEditinfo()));
		connect(ui.staflatsingleEdit, SIGNAL(editingFinished()), this, SLOT(savestaflatsingleEditinfo()));
	}
}
void TabStartSell::savestaflatsingleEditinfo()   //��¼ƽ�ӵ��۵���Ϣ
{
	float FlatSinglePrice = ui.staflatsingleEdit->text().toFloat();    //��QString�͵�ƽ�ӵ��۱�ΪFloat
	float Width = ui.stawidthEdit->text().toFloat();      //��QString�͵Ŀ�ȱ�Ϊfloat��
	FlatPrice = FlatSinglePrice*Width;   //ƽ�Ӽ۸�=ƽ�ӵ���*���
	float BasePrice = ui.stabasisEdit->text().toFloat();   //��QString�͵Ļ����۸��Ϊfloat��
	float CostPrice = BasePrice + FlatPrice;     //�ɱ���=�����۸�+ƽ�Ӽ۸�
	float coefficient = ui.stamodulusEdit->text().toFloat();   //��QString�͵ı���ϵ��תΪFloat��
	float terminalprice = CostPrice * coefficient;   //�ն˼۸�=�ɱ���*����ϵ��
	ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
	ui.staflatpriceEdit->setText(QString::number(FlatPrice, 'f', 2));
	ui.stacostEdit->setText(QString::number(CostPrice, 'f', 2));
	ui.stacostEdit->setEnabled(false);
	ui.staflatpriceEdit->setEnabled(false);
	//ui.stamodulusEdit->setFocus();
}

void TabStartSell::savestamodulusEditinfo()   //��¼����ϵ��
{
	if (ui.stamodulusEdit->text().isEmpty())
	{
		ui.stamodulusEdit->setText(tr("1.1"));
		ui.staterminalEdit->setText(tr("0"));
	}
	if (ui.staterminalEdit->text() == "0")
		return;
	else
	{
		QString m_vQuotationCoefficient = ui.stamodulusEdit->text();   //��ȡ����ϵ��
		float coefficient = m_vQuotationCoefficient.toFloat();   //��QString�͵ı���ϵ��תΪFloat��
		float costprice = ui.stacostEdit->text().toFloat();     //��QString�͵ĳɱ���תΪFloat��
		float terminalprice = costprice * coefficient;      //�ն˼۸�=�ɱ���*����ϵ��
		QString m_vTerminalPrice = QString::number(terminalprice, 'f', 2);   //��Float�͵��ն˼۸��ΪQString��
		ui.staterminalEdit->setText(m_vTerminalPrice);
	}
}
void TabStartSell::savestaterminalEditinfo()    //��¼�ն˼۸�
{
	if (ui.staterminalEdit->text().isEmpty())
	{
		ui.stamodulusEdit->setText(tr("1.1"));
		ui.staterminalEdit->setText(tr("0"));
	}
	if (ui.staterminalEdit->text() == "0")
		return;
	else
	{
		QString m_vTerminalPrice = ui.staterminalEdit->text();   //��ȡ�ն˼۸�
		float terminalprice = m_vTerminalPrice.toFloat();    //��QString�͵��ն˼۸�תΪFloat��
		float costprice = ui.stacostEdit->text().toFloat();     //��QString�͵ĳɱ���תΪFloat��
		float coefficient = terminalprice / costprice;   //����ϵ��=�ն˼۸�/�ɱ���
		QString m_vQuotationCoefficient = QString("%1").arg(coefficient);     //��Float�͵ı���ϵ����ΪQString��
		ui.stamodulusEdit->setText(m_vQuotationCoefficient);
	}
}
void TabStartSell::Finish()
{
	if (!ui.stabuyEdit->text().isEmpty() && !ui.stasortComBox->currentText().isEmpty() && !ui.stanameComBox->currentText().isEmpty() &&
		!ui.stalengthEdit->text().isEmpty() && !ui.stawidthEdit->text().isEmpty() && !ui.stamodulusEdit->text().isEmpty())
	{
		QString m_vUserName = Parameter::getInstance()->m_vUserName;   //��ȡ����Ա
		QString m_vRecordID = UUid::getUUid();   //ϵͳ�Զ����ɼ�¼ID
		QString CompanyName = ui.stabuyEdit->text();   //��ȡ����λ������
		QString Length = ui.stalengthEdit->text();//��ȡ����
		QString Width = ui.stawidthEdit->text();   //��ȡ���
		QString SinglePrice = ui.stasingleEdit->text();  //��ȡ����
		QString BasePrice = ui.stabasisEdit->text();    //��ȡ�����۸�
		QString QuotationCoefficient = ui.stamodulusEdit->text();    //��ȡ����ϵ��
		QString TerminalPrice = ui.staterminalEdit->text();   //��ȡ�ն˼۸�
		QString CompanyId;
		if (m_vFlag)   //�������λ�����ݿ����Ѿ�����
		{
			QString searchCompanyId = "select CompanyID from CompanyInfo where CompanyName=?";
			QVector<QString> bindValue;
			bindValue.append(CompanyName);
			QVector<QVector<QString> > result;  //������Ž��
			result = SqlOp::SelectQuery(searchCompanyId, 1, bindValue);
			CompanyId = result[0][0];   //��ȡ��˾ID
			if (QString::compare(m_vtelephone, ui.statelephoneEdit->text()) != 0 || QString::compare(m_vphone, ui.staphoneEdit->text()) != 0
				|| QString::compare(m_vContactPerson, ui.stamanEdit->text()) != 0 || QString::compare(m_vCompanyName, ui.stabuyEdit->text()) != 0)
				//�Ƚϲ鿴��˾��Ϣ��û�з����ı䣬����оͽ���˾��Ϣ���и���
			{
				QString updateQuery = "update CompanyInfo set CompanyName=?,phone1=?,phone2=?,ContactMan=? where CompanyID=?";
				QVector<QVariant> bindValue1;
				bindValue1.append(ui.stabuyEdit->text());
				bindValue1.append(ui.statelephoneEdit->text());
				bindValue1.append(ui.staphoneEdit->text());
				bindValue1.append(ui.stamanEdit->text());
				bindValue1.append(CompanyId);
				bool updateResult = SqlOp::Delete_UpdateQuery(updateQuery, bindValue1);
			}
		}
		else
		{
			CompanyId = UUid::getUUid();     //�������λ�����ݿ��в�������˾ID�Զ�����
			m_vtelephone = ui.statelephoneEdit->text();
			m_vphone = ui.staphoneEdit->text();
			m_vContactPerson = ui.stamanEdit->text();
			QString insertQuery = "insert into CompanyInfo(CompanyID,CompanyName,phone1,phone2,ContactMan) values(?,?,?,?,?)";
			QVector<QVariant>bindvalue;
			bindvalue.append(CompanyId);
			bindvalue.append(CompanyName);
			bindvalue.append(ui.statelephoneEdit->text());
			bindvalue.append(ui.staphoneEdit->text());
			bindvalue.append(ui.stamanEdit->text());
			bool result = SqlOp::InsertQuery(insertQuery, bindvalue);
		}
		if (m_vTemp)   //���ѡ��ƽ��
		{
			QString FlatSinglePrice = ui.staflatsingleEdit->text();   //��ȡƽ�ӵ���
			QString FlatPrice = ui.staflatpriceEdit->text();      //��ȡƽ�Ӽ۸�
			QString insertQuery = "insert into BJRecord(RecordID,CompanyID,ProductID,BJMan,BJTime,Length,Width,Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice) values(?,?,?,?,datetime('now','localtime'),?,?,?,?,?,?,?,?,?)";
			QVector<QVariant> bindvalue;
			bindvalue.append(m_vRecordID);
			bindvalue.append(CompanyId);
			bindvalue.append(m_vProductId);
			bindvalue.append(m_vUserName);
			bindvalue.append(Length);
			bindvalue.append(Width);
			bindvalue.append(SinglePrice);
			bindvalue.append(BasePrice);
			bindvalue.append(m_vTemp);
			bindvalue.append(FlatSinglePrice);
			bindvalue.append(FlatPrice);
			bindvalue.append(QuotationCoefficient);
			bindvalue.append(TerminalPrice);
			bool result = SqlOp::InsertQuery(insertQuery, bindvalue);
			if (result)    //�����ӳɹ�
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("��ӳɹ�"));
				w->show();
				m_vFlag = 0;
				m_vTemp = 0;
				ui.stabuyEdit->clear();
				ui.statelephoneEdit->clear();
				ui.stamanEdit->clear();
				ui.staphoneEdit->clear();
				ui.stalengthEdit->clear();
				ui.stawidthEdit->clear();
				ui.stabasisEdit->clear();
				ui.staflatsingleEdit->clear();
				ui.staflatpriceEdit->clear();
				ui.staflatCheBox->setChecked(false);
				ui.stacostEdit->clear();
				ui.stamodulusEdit->clear();
				ui.staterminalEdit->clear();
			}
			else
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("���ʧ�ܣ��������������"));
				w->show();
			}
		}
		else
		{
			QString insertQuery = "insert into BJRecord(RecordID,CompanyID,ProductID,BJMan,BJTime,Length,Width,Price,BasicPrice,IsContact,BJCoefficient,TotalPrice) values(?,?,?,?,datetime('now','localtime'),?,?,?,?,?,?,?)";
			QVector<QVariant> bindvalue;
			bindvalue.append(m_vRecordID);
			bindvalue.append(CompanyId);
			bindvalue.append(m_vProductId);
			bindvalue.append(m_vUserName);
			bindvalue.append(Length);
			bindvalue.append(Width);
			bindvalue.append(SinglePrice);
			bindvalue.append(BasePrice);
			bindvalue.append(m_vTemp);
			bindvalue.append(QuotationCoefficient);
			bindvalue.append(TerminalPrice);
			bool result = SqlOp::InsertQuery(insertQuery, bindvalue);
			if (result)    //�����ӳɹ�
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("��ӳɹ�"));
				w->show();
				m_vFlag = 0;
				m_vTemp = 0;
				ui.stabuyEdit->clear();
				ui.statelephoneEdit->clear();
				ui.stamanEdit->clear();
				ui.staphoneEdit->clear();
				ui.stalengthEdit->clear();
				ui.stawidthEdit->clear();
				ui.stabasisEdit->clear();
				ui.staflatsingleEdit->clear();
				ui.staflatpriceEdit->clear();
				ui.staflatCheBox->setChecked(false);
				ui.stacostEdit->clear();
				ui.stamodulusEdit->clear();
				ui.staterminalEdit->clear();
			}
			else
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("���ʧ�ܣ��������������"));
				w->show();
			}
		}
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("���ʧ�ܣ��������������"));
		w->show();
	}
}
void TabStartSell::ClearScreen()   //����
{
	m_vFlag = 0;
	m_vTemp = 0;
	ui.stabuyEdit->clear();
	ui.statelephoneEdit->clear();
	ui.stamanEdit->clear();
	ui.staphoneEdit->clear();
	ui.stalengthEdit->clear();
	ui.stawidthEdit->clear();
	ui.stabasisEdit->clear();
	ui.staflatsingleEdit->clear();
	ui.staflatpriceEdit->clear();
	ui.staflatCheBox->setChecked(false);
	ui.stacostEdit->clear();
	ui.stamodulusEdit->clear();
	ui.staterminalEdit->clear();
	ui.stabuyEdit->setPlaceholderText(tr(""));
	ui.stalengthEdit->setPlaceholderText(tr(""));
	ui.stawidthEdit->setPlaceholderText(tr(""));
}
