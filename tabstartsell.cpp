#pragma execution_character_set("utf-8")
#include "tabstartsell.h"
#include "getUUID.cpp"
#include<QMessageBox>
TabStartSell::TabStartSell(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.stabuyEdit, SIGNAL(returnPressed()), this, SLOT(savestabuyEditinfo()));    //获取购买单位
	connect(ui.stabuyEdit, SIGNAL(editingFinished()), this, SLOT(savestabuyEditinfo()));    //获取购买单位
	//connect(ui.stasortComBox, SIGNAL(activated(QString)), this, SLOT(savestasortComBoxinfo()));   //获取当前产品类型
	connect(ui.stasortComBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(savestasortComBoxinfo(QString)));
	connect(ui.stanameComBox, SIGNAL(activated(QString)), this, SLOT(savestanameComBoxinfo()));  //获取当前产品名称
	//connect(ui.stanameComBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(savestanameComBoxinfo()));
	connect(ui.stalengthEdit, SIGNAL(returnPressed()), this, SLOT(savestalengthEditinfo()));   //获取长度
	connect(ui.stalengthEdit, SIGNAL(editingFinished()), this, SLOT(savestalengthEditinfo()));
	connect(ui.stawidthEdit, SIGNAL(returnPressed()), this, SLOT(savestawidthEditinfo()));   //获取宽度
	connect(ui.stawidthEdit, SIGNAL(editingFinished()), this, SLOT(savestawidthEditinfo()));
	connect(ui.staflatCheBox, SIGNAL(stateChanged(int)), this, SLOT(savestateChanged(int)));  //当复选框状态发生改变时触发槽函数
   	connect(ui.staphoneEdit, SIGNAL(returnPressed()), this, SLOT(savestaphoneEditinfo()));     //获取手机号
	connect(ui.staphoneEdit, SIGNAL(editingFinished()), this, SLOT(savestaphoneEditinfo()));
	connect(ui.statelephoneEdit, SIGNAL(returnPressed()), this, SLOT(savestatelephoneEditinfo()));    //获取电话号码
	connect(ui.statelephoneEdit, SIGNAL(editingFinished()), this, SLOT(savestatelephoneEditinfo()));
	ui.staflatsingleEdit->setEnabled(false);   //开始时平接单价无法选择
	ui.staflatpriceEdit->setEnabled(false);    //开始是平接价格无法选择
	connect(ui.stamodulusEdit, SIGNAL(returnPressed()), this, SLOT(savestamodulusEditinfo()));
	connect(ui.stamodulusEdit, SIGNAL(editingFinished()), this, SLOT(savestamodulusEditinfo()));
	connect(ui.staterminalEdit, SIGNAL(returnPressed()), this, SLOT(savestaterminalEditinfo()));
	connect(ui.staterminalEdit, SIGNAL(editingFinished()), this, SLOT(savestaterminalEditinfo()));
	connect(ui.staclearbutton, SIGNAL(clicked()), this, SLOT(ClearScreen()));    //清屏
	connect(ui.stafinishbutton, SIGNAL(clicked()), this, SLOT(Finish()));     //完成
	ui.stasortComBox->addItem(tr("小太阳砂带"));   //初始化产品类型下拉框
	ui.stasortComBox->addItem(tr("三菱砂带"));
	ui.stasortComBox->addItem(tr("金牛砂带"));
	ui.stasortComBox->addItem(tr("其他砂带"));
	ui.stasortComBox->addItem(tr("圆盘砂"));
	ui.stasortComBox->addItem(tr("其他产品"));
	for (int i = 0; i < 6; i++)
	{
		ui.stasortComBox->model()->setData(ui.stasortComBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	ui.stabasisEdit->setEnabled(false);
	ui.stacostEdit->setEnabled(false);
	ui.stasingleEdit->setEnabled(false);    //产品的单价不能改变
}

TabStartSell::~TabStartSell()
{

}
void TabStartSell::Refresh()
{
	ui.stanameComBox->clear();
	QString m_vSort = ui.stasortComBox->currentText();   //获取当前选择的产品类型
	if (m_vSort.indexOf("小") == 0)
		Sort = "1";
	else if (m_vSort.indexOf("三") == 0)
		Sort = "2";
	else if (m_vSort.indexOf("金") == 0)
		Sort = "3";
	else if (m_vSort.indexOf("其") == 0)
	{
		if (m_vSort.indexOf("砂") == 2)
			Sort = "4";
		else Sort = "6";
	}
	else Sort = "5";
	QString searchProductName = "select ProductName from ProductInfo where ProductType=?";
	//从数据库中查询相应的产品名称
	QVector<QVector<QString>> NameResult;   //用来存放查询结果
	QVector<QString> bindValue;
	bindValue.append(Sort);
	NameResult = SqlOp::SelectQuery(searchProductName, 1, bindValue);  //获取产品类别对应的产品名称
	for (int i = 0; i < NameResult.size(); i++)
	{
		QString ProductName = NameResult[i][0];
		ui.stanameComBox->addItem(ProductName);  //将所有的产品名称添加到下拉框中
		ui.stanameComBox->model()->setData(ui.stanameComBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	QString m_vProductName = ui.stanameComBox->currentText();  //获取当前选择的产品名称
	if (!m_vProductName.isEmpty())
	{
		QString searchUnitPrice = "select ProductID,Price from ProductInfo where ProductType=? and ProductName=? ";
		QVector<QVector<QString> > PriceResult;    //查询产品对应的单价
		QVector<QString> bindValue1;
		bindValue1.append(Sort);
		bindValue1.append(m_vProductName);
		PriceResult = SqlOp::SelectQuery(searchUnitPrice, 2, bindValue1);
		QString m_vUnitPrice = PriceResult[0][1];   //获取产品单价
		m_vProductId = PriceResult[0][0];    //获取产品ID
		ui.stasingleEdit->setText(m_vUnitPrice);   //将产品的单价直接显示出来
	}
	else ui.stasingleEdit->clear();
}
int TabStartSell::isDigitStr(QString str)  //判断输入的数值是否为正确的小数
{
	QByteArray ba = str.toLatin1();//QString 转换为 char*  
	const char *s = ba.data();
	int point = 1;    //小数点数量最多只有1个
	int num = 0;     //数字的个数
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 && s[i] == 0)
		{
			if ((str.size()>2 && s[i + 1] != '.') || str.size() == 1)
				//如果输入值为0，则判断为输入格式错误。如果输入第一个数字为0，0后面不是小数点也判断为格式错误。
				return 0;
		}
		if (s[i] == '.')
		{
			point--;
			if (i == str.size() - 1 || i == 0)   //如果小数点后面没有数字，说明输入的数值格式错误
				return 0;
		}
		if (point < 0)
			return 0;   //如果小数点数量大于1个，说明输入的数值格式错误
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


int TabStartSell::isDigital(QString str)   //判断是否为纯数字
{
	QByteArray ba = str.toLatin1();//QString 转换为 char*  
	const char *s = ba.data();
	while (*s && *s >= '0' && *s <= '9') s++;
	if (*s)
	{ //不是纯数字  
		return 0;
	}
	else
	{ //纯数字  
		return 1;
	}
}
void TabStartSell::savestabuyEditinfo()    //获取购买单位名称
{
	if (ui.stabuyEdit->text().isEmpty())
	{
		ui.stabuyEdit->setPlaceholderText(tr("请输入购买单位"));
		//ui.stabuyEdit->setFocus();
	}
	else
	{
		QString m_vPurchaseUnit = ui.stabuyEdit->text();   //获取用户输入的购买单位名称
		m_vCompanyName = m_vPurchaseUnit;
		QString searchPurchaseUnit = "select phone1,phone2,ContactMan from CompanyInfo where CompanyName=?";
		QVector<QString> bindValue;
		bindValue.append(m_vPurchaseUnit);
		QVector<QVector<QString> > result;  //用来存放结果
		result = SqlOp::SelectQuery(searchPurchaseUnit, 3, bindValue);
		if (result.size() > 0)   //如果购买单位在数据库中已经存在，那么联系人，联系电话，手机号可以自动显示
		{
			m_vFlag = 1;   //如果购买单位在数据库中已经存在则将m_vFlag置为1
			QString Telephone = result[0][0];   //获取数据库中相应的联系电话
			QString Phone = result[0][1];        // 获取数据库中相应的手机号
			QString ContactMan = result[0][2];   //获取数据库中相应联系人
			ui.statelephoneEdit->setText(Telephone);   //将联系电话打印到联系电话编辑器中
			ui.staphoneEdit->setText(Phone);      // 将手机号打印到手机号编辑器中
			ui.stamanEdit->setText(ContactMan);   //将联系人打印到联系人编辑器中
			m_vtelephone = Telephone;
			m_vphone = Phone;
			m_vContactPerson = ContactMan;
		}
	}
}
void TabStartSell::savestatelephoneEditinfo()   //获取联系电话名称
{
	if (isDigital(ui.statelephoneEdit->text()) == 0)
	{
		ui.statelephoneEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请输入正确的数值"));
		w->show();
	}
}
void TabStartSell::savestaphoneEditinfo()   //获取手机号
{
	if (isDigital(ui.staphoneEdit->text()) == 0)
	{
		ui.staphoneEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请输入正确的数值"));
		w->show();
	}
}
void TabStartSell::savestasortComBoxinfo(QString m_vSort)   //获取当前产品类别
{
	ui.stanameComBox->clear();
	//QString m_vSort = ui.stasortComBox->currentText();   //获取当前选择的产品类型
	if (m_vSort.indexOf("小") == 0)
		Sort = "1";
	else if (m_vSort.indexOf("三") == 0)
		Sort = "2";
	else if (m_vSort.indexOf("金") == 0)
		Sort = "3";
	else if (m_vSort.indexOf("其") == 0)
	{
		if (m_vSort.indexOf("砂") == 2)
			Sort = "4";
		else Sort = "6";
	}
	else Sort = "5";
	QString searchProductName = "select ProductName from ProductInfo where ProductType=?";
	//从数据库中查询相应的产品名称
	QVector<QVector<QString>> NameResult;   //用来存放查询结果
	QVector<QString> bindValue;
	bindValue.append(Sort);
	NameResult = SqlOp::SelectQuery(searchProductName, 1, bindValue);  //获取产品类别对应的产品名称
	for (int i = 0; i < NameResult.size(); i++)
	{
		QString ProductName = NameResult[i][0];
		ui.stanameComBox->addItem(ProductName);  //将所有的产品名称添加到下拉框中
		ui.stanameComBox->model()->setData(ui.stanameComBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	QString m_vProductName = ui.stanameComBox->currentText();  //获取当前选择的产品名称
	if (!m_vProductName.isEmpty())
	{
		QString searchUnitPrice = "select ProductID,Price from ProductInfo where ProductType=? and ProductName=? ";
		QVector<QVector<QString> > PriceResult;    //查询产品对应的单价
		QVector<QString> bindValue1;
		bindValue1.append(Sort);
		bindValue1.append(m_vProductName);
		PriceResult = SqlOp::SelectQuery(searchUnitPrice, 2, bindValue1);
		QString m_vUnitPrice = PriceResult[0][1];   //获取产品单价
		m_vProductId = PriceResult[0][0];    //获取产品ID
		ui.stasingleEdit->setText(m_vUnitPrice);   //将产品的单价直接显示出来
	}
	else ui.stasingleEdit->clear();
}
void TabStartSell::savestanameComBoxinfo()   //获取当前选择的产品名称
{
	QString m_vProductName = ui.stanameComBox->currentText();  //获取当前选择的产品名称
	QString searchUnitPrice = "select ProductID,Price from ProductInfo where ProductType=? and ProductName=? ";
	QVector<QVector<QString> > result;    //查询产品对应的单价
	QVector<QString> bindValue;
	bindValue.append(Sort);
	bindValue.append(m_vProductName);
	result = SqlOp::SelectQuery(searchUnitPrice, 2, bindValue);
	QString m_vUnitPrice = result[0][1];   //获取产品单价
	m_vProductId = result[0][0];    //获取产品ID
	ui.stasingleEdit->setText(m_vUnitPrice);   //将产品的单价直接显示出来
}
void TabStartSell::savestalengthEditinfo()   //获取长度
{
	if (ui.stalengthEdit->text().isEmpty())
	{
		ui.stalengthEdit->setPlaceholderText(tr("请输入长度"));
		//ui.stalengthEdit->setFocus();
	}
	else
	{
		if (isDigitStr(ui.stalengthEdit->text()) == 0)
		{
			ui.stalengthEdit->clear();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("请输入正确的数值"));
			w->show();
		}
		else
		{
			float Width = ui.stawidthEdit->text().toFloat();      //将QString型的宽度变为float型
			float Length = ui.stalengthEdit->text().toFloat();    //将QString型的长度变为float型
			float Price = ui.stasingleEdit->text().toFloat();  //将QString型的单价变为float型
			float BasePrice = Width*Length*Price;    //基础价格=长度*宽度*单价
			//QString m_vBasePrice = QString("%1").arg(BasePrice);   //将float型的基础价格变为QString型
			QString m_vBasePrice = QString::number(BasePrice, 'f', 2);
			ui.stabasisEdit->setText(m_vBasePrice);
			ui.stacostEdit->setText(m_vBasePrice);
			if (ui.stamodulusEdit->text().isEmpty())    //如果报价系数为空
			{
				ui.stamodulusEdit->setText(tr("1.1"));   //开始时报价系数默认为1.1
				float terminalprice = BasePrice * 1.1;      //终端价格=成本价*报价系数
				//QString m_vTerminalPrice = QString("%1").arg(terminalprice);   //将Float型的终端价格变为QString型
				QString m_vTerminalPrice = QString::number(terminalprice, 'f', 2);
				ui.staterminalEdit->setText(m_vTerminalPrice);
				ui.stawidthEdit->clearFocus();     //消除宽度编辑框中的光标
			}
			else
			{
				float coefficient = ui.stamodulusEdit->text().toFloat(); //将QString型的报价系数转为Float型
				float terminalprice = BasePrice * coefficient;   //终端价格=成本价*报价系数
				ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
			}
			ui.stawidthEdit->setFocus();
		}
	}
}
void TabStartSell::savestawidthEditinfo()    //获取宽度
{
	if (ui.stawidthEdit->text().isEmpty())
	{
		ui.stawidthEdit->setPlaceholderText(tr("请输入宽度"));
		//ui.stawidthEdit->setFocus();
	}
	else
	{
		if (isDigitStr(ui.stawidthEdit->text()) == 0)
		{
			ui.stawidthEdit->clear();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("请输入正确的数值"));
			w->show();
		}
		else
		{
			QString m_vWidth = ui.stawidthEdit->text();
			float Width = m_vWidth.toFloat();      //将QString型的宽度变为float型
			float Length = ui.stalengthEdit->text().toFloat();    //将QString型的长度变为float型
			float Price = ui.stasingleEdit->text().toFloat();  //将QString型的单价变为float型
			float BasePrice = Width*Length*Price;    //基础价格=长度*宽度*单价
			//QString m_vBasePrice = QString("%1").arg(BasePrice);   //将float型的基础单价变为QString型
			QString m_vBasePrice = QString::number(BasePrice, 'f', 2);
			ui.stabasisEdit->setText(m_vBasePrice);
			ui.stacostEdit->setText(m_vBasePrice);
			if (ui.stamodulusEdit->text().isEmpty())    //如果报价系数为空
			{
				ui.stamodulusEdit->setText(tr("1.1"));   //开始时报价系数默认为1.1
				float terminalprice = BasePrice * 1.1;      //终端价格=成本价*报价系数
				//QString m_vTerminalPrice = QString("%1").arg(terminalprice);   //将Float型的终端价格变为QString型
				QString m_vTerminalPrice = QString::number(terminalprice, 'f', 2);
				ui.staterminalEdit->setText(m_vTerminalPrice);
				ui.stawidthEdit->clearFocus();     //消除宽度编辑框中的光标
			}
			else
			{
				float coefficient = ui.stamodulusEdit->text().toFloat(); //将QString型的报价系数转为Float型
				float terminalprice = BasePrice * coefficient;   //终端价格=成本价*报价系数
				ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
			}
		}
	}
}
void TabStartSell::savestateChanged(int state)     //选择平接
{
	if (state == Qt::Unchecked)
	{
		float CostPrice = ui.stacostEdit->text().toFloat() - FlatPrice;
		QString m_vCostPrice = QString::number(CostPrice, 'f', 2);   //将Float型的成本价变为QString型
		float coefficient = ui.stamodulusEdit->text().toFloat();   //将QString型的报价系数转为Float型
		float terminalprice = CostPrice * coefficient;   //终端价格=成本价*报价系数
		ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
		ui.stacostEdit->setText(m_vCostPrice);
		ui.staflatsingleEdit->clear();
		ui.staflatpriceEdit->clear();
		ui.staflatsingleEdit->setEnabled(false);   //开始时平接单价无法选择
		ui.staflatpriceEdit->setEnabled(false);    //开始是平接价格无法选择
	}
	else if (state == Qt::Checked)
	{
		m_vTemp = 1;   //如果选择平接则m_vTemp置1
		ui.staflatsingleEdit->setEnabled(true);
		ui.staflatsingleEdit->setText(tr("4"));
		//ui.staflatsingleEdit->setFocus();
	    FlatPrice = 4 * ui.stawidthEdit->text().toFloat();   //平接价格=平接单价*宽度
		ui.staflatpriceEdit->setText(QString::number(FlatPrice, 'f', 2));
		float BasePrice = ui.stabasisEdit->text().toFloat();   //将QString型的基础价格变为float型
		float CostPrice = BasePrice + FlatPrice;     //成本价=基础价格+平接价格
		float coefficient = ui.stamodulusEdit->text().toFloat();   //将QString型的报价系数转为Float型
		float terminalprice = CostPrice * coefficient;   //终端价格=成本价*报价系数
		ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
		ui.stacostEdit->setText(QString::number(CostPrice, 'f', 2));
		connect(ui.staflatsingleEdit, SIGNAL(returnPressed()), this, SLOT(savestaflatsingleEditinfo()));
		connect(ui.staflatsingleEdit, SIGNAL(editingFinished()), this, SLOT(savestaflatsingleEditinfo()));
	}
}
void TabStartSell::savestaflatsingleEditinfo()   //记录平接单价的信息
{
	float FlatSinglePrice = ui.staflatsingleEdit->text().toFloat();    //将QString型的平接单价变为Float
	float Width = ui.stawidthEdit->text().toFloat();      //将QString型的宽度变为float型
	FlatPrice = FlatSinglePrice*Width;   //平接价格=平接单价*宽度
	float BasePrice = ui.stabasisEdit->text().toFloat();   //将QString型的基础价格变为float型
	float CostPrice = BasePrice + FlatPrice;     //成本价=基础价格+平接价格
	float coefficient = ui.stamodulusEdit->text().toFloat();   //将QString型的报价系数转为Float型
	float terminalprice = CostPrice * coefficient;   //终端价格=成本价*报价系数
	ui.staterminalEdit->setText(QString::number(terminalprice, 'f', 2));
	ui.staflatpriceEdit->setText(QString::number(FlatPrice, 'f', 2));
	ui.stacostEdit->setText(QString::number(CostPrice, 'f', 2));
	ui.stacostEdit->setEnabled(false);
	ui.staflatpriceEdit->setEnabled(false);
	//ui.stamodulusEdit->setFocus();
}

void TabStartSell::savestamodulusEditinfo()   //记录报价系数
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
		QString m_vQuotationCoefficient = ui.stamodulusEdit->text();   //获取报价系数
		float coefficient = m_vQuotationCoefficient.toFloat();   //将QString型的报价系数转为Float型
		float costprice = ui.stacostEdit->text().toFloat();     //将QString型的成本价转为Float型
		float terminalprice = costprice * coefficient;      //终端价格=成本价*报价系数
		QString m_vTerminalPrice = QString::number(terminalprice, 'f', 2);   //将Float型的终端价格变为QString型
		ui.staterminalEdit->setText(m_vTerminalPrice);
	}
}
void TabStartSell::savestaterminalEditinfo()    //记录终端价格
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
		QString m_vTerminalPrice = ui.staterminalEdit->text();   //获取终端价格
		float terminalprice = m_vTerminalPrice.toFloat();    //将QString型的终端价格转为Float型
		float costprice = ui.stacostEdit->text().toFloat();     //将QString型的成本价转为Float型
		float coefficient = terminalprice / costprice;   //报价系数=终端价格/成本价
		QString m_vQuotationCoefficient = QString("%1").arg(coefficient);     //将Float型的报价系数变为QString型
		ui.stamodulusEdit->setText(m_vQuotationCoefficient);
	}
}
void TabStartSell::Finish()
{
	if (!ui.stabuyEdit->text().isEmpty() && !ui.stasortComBox->currentText().isEmpty() && !ui.stanameComBox->currentText().isEmpty() &&
		!ui.stalengthEdit->text().isEmpty() && !ui.stawidthEdit->text().isEmpty() && !ui.stamodulusEdit->text().isEmpty())
	{
		QString m_vUserName = Parameter::getInstance()->m_vUserName;   //获取报价员
		QString m_vRecordID = UUid::getUUid();   //系统自动生成记录ID
		QString CompanyName = ui.stabuyEdit->text();   //获取购买单位的名称
		QString Length = ui.stalengthEdit->text();//获取长度
		QString Width = ui.stawidthEdit->text();   //获取宽度
		QString SinglePrice = ui.stasingleEdit->text();  //获取单价
		QString BasePrice = ui.stabasisEdit->text();    //获取基础价格
		QString QuotationCoefficient = ui.stamodulusEdit->text();    //获取报价系数
		QString TerminalPrice = ui.staterminalEdit->text();   //获取终端价格
		QString CompanyId;
		if (m_vFlag)   //如果购买单位在数据库中已经存在
		{
			QString searchCompanyId = "select CompanyID from CompanyInfo where CompanyName=?";
			QVector<QString> bindValue;
			bindValue.append(CompanyName);
			QVector<QVector<QString> > result;  //用来存放结果
			result = SqlOp::SelectQuery(searchCompanyId, 1, bindValue);
			CompanyId = result[0][0];   //获取公司ID
			if (QString::compare(m_vtelephone, ui.statelephoneEdit->text()) != 0 || QString::compare(m_vphone, ui.staphoneEdit->text()) != 0
				|| QString::compare(m_vContactPerson, ui.stamanEdit->text()) != 0 || QString::compare(m_vCompanyName, ui.stabuyEdit->text()) != 0)
				//比较查看公司信息有没有发生改变，如果有就将公司信息进行更新
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
			CompanyId = UUid::getUUid();     //如果购买单位在数据库中不存在则公司ID自动生成
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
		if (m_vTemp)   //如果选择平接
		{
			QString FlatSinglePrice = ui.staflatsingleEdit->text();   //获取平接单价
			QString FlatPrice = ui.staflatpriceEdit->text();      //获取平接价格
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
			if (result)    //如果添加成功
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("添加成功"));
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
				w->setContent(tr("添加失败，请检查后重新输入"));
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
			if (result)    //如果添加成功
			{
				TipDialog *w = new TipDialog("okButtonOnly");
				w->setContent(tr("添加成功"));
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
				w->setContent(tr("添加失败，请检查后重新输入"));
				w->show();
			}
		}
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("添加失败，请检查后重新输入"));
		w->show();
	}
}
void TabStartSell::ClearScreen()   //清屏
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
