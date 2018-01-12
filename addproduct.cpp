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
	this->setWindowFlags(Qt::SplashScreen);                                         //没有菜单栏
	ui.proTypeBox->addItem(tr("小太阳砂带"));//初始化产品类型下拉框
	ui.proTypeBox->addItem(tr("三菱砂带"));
	ui.proTypeBox->addItem(tr("金牛砂带"));
	ui.proTypeBox->addItem(tr("其他砂带"));
	ui.proTypeBox->addItem(tr("园盘砂"));
	ui.proTypeBox->addItem(tr("其它产品"));
	for (int i = 0; i < 6; i++)
	{
		ui.proTypeBox->model()->setData(ui.proTypeBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
}
/********************************************************************************************/
/*使addproduct窗口可移动*/
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
	m_vProductNameEdit = ui.proNameLineEdit->text().simplified();   //simplified()把一个字符串首尾的空格全部清除
	m_vProductPriceEdit = ui.proPriceLineEdit->text().toFloat();
	m_vProductID = UUid::getUUid();									//系统自动生成的ID
	if (m_vProductNameEdit == "" || m_vProductPriceEdit == 0)		//判断增加产品的名称或单价是否为空
	{
		if (ui.proPriceLineEdit->text().isEmpty() || m_vProductNameEdit == "")
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("产品名或单价为空，请输入!"));
			w->show();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("产品单价格式有误，请重新输入!"));
			w->show();
			ui.proPriceLineEdit->clear();
		}
	}
	else
	{
		index = ui.proTypeBox->currentIndex();  //在下拉框中显示的类型
		if (index == 0)
		{
			m_vProductTypeEdit = QString::number(1);
			m_vProductMarkEdit = "小太阳砂带";
		}
		else if (index == 1)
		{
			m_vProductTypeEdit = QString::number(2);
			m_vProductMarkEdit = "三菱砂带";
		}
		else if (index == 2)
		{
			m_vProductTypeEdit = QString::number(3);
			m_vProductMarkEdit = "金牛砂带";
		}
		else if (index == 3)
		{
			m_vProductTypeEdit = QString::number(4);
			m_vProductMarkEdit = "其他砂带";
		}
		else if (index == 4)
		{
			m_vProductTypeEdit = QString::number(5);
			m_vProductMarkEdit = "园盘砂";
		}
		else{
			m_vProductTypeEdit = QString::number(6);
			m_vProductMarkEdit = "其它产品";
		}
		QString query = "insert into ProductInfo(ProductID,ProductName,ProductType,Price,Notes) values(?,?,?,?,?)";//插入语句
		QVector<QVariant> bindvalue;
		bindvalue.append(m_vProductID);
		bindvalue.append(m_vProductNameEdit);
		bindvalue.append(m_vProductTypeEdit);
		bindvalue.append(m_vProductPriceEdit);
		bindvalue.append(m_vProductMarkEdit);
		bool result = SqlOp::InsertQuery(query, bindvalue);
	
		if (result)//表示添加成功
		{
			this->close();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("添加产品成功"));
			w->show();
			emit addSuccess();//发送添加成功的信号
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("添加产品失败"));
			w->show();
			if (typeid(m_vProductNameEdit) != typeid(QString))	 //判断输入到proNameLineEdit中的是否为QString类型
				ui.proNameLineEdit->clear();							
			if (typeid(m_vProductPriceEdit) != typeid(float))	 //判断输入到proPriceLineEdit中的是否为float类型
				ui.proPriceLineEdit->clear();
		}
	}
}
AddProduct::~AddProduct()
{

}
void AddProduct::keyPressEvent(QKeyEvent  *event)
{
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)          //回车键和小键盘的Enter键
	{
		finishButtonClicked();//按钮槽函数
	}
}