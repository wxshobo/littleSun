#pragma execution_character_set("utf-8")
#include "reviseproduct.h"
#include<typeinfo>
reviseProduct::reviseProduct(QVector<QVector<QString>> tempInfo,int current,int number,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	result = 0;
	this->setWindowFlags(Qt::SplashScreen);						        //没有菜单栏
	connect(ui.comfirmBtn, SIGNAL(clicked()), this, SLOT(confirmSlot()));
	connect(ui.cancelBtn, SIGNAL(clicked()), this, SLOT(concleSlot()));

	ui.productTypeBox->addItem(tr("小太阳砂带"));//初始化产品类型下拉框
	ui.productTypeBox->addItem(tr("三菱砂带"));
	ui.productTypeBox->addItem(tr("金牛砂带"));
	ui.productTypeBox->addItem(tr("其他砂带"));
	ui.productTypeBox->addItem(tr("园盘砂"));
	ui.productTypeBox->addItem(tr("其它产品"));
	for (int i = 0; i < 6; i++)
	{
		ui.productTypeBox->model()->setData(ui.productTypeBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}

	sel = tempInfo;														//存储当前查询到的数据库中的信息
	cur = current;														//被修改的当前页
	num = number;														//被修改的当前行
	allPage = sel.size() / 7;
	if (sel.size() % 7 != 0)
		allPage++;
	/*将选中要修改的的那一行的内容显示出来*/
	ui.productNameEdit->setText(sel[(cur - 1) * 7 + num][1]);
	ui.productPriceEdit->setText(sel[(cur - 1) * 7 + num][3]);
	ui.productTypeBox->setCurrentText(sel[(cur - 1) * 7 + num][4]);		//显示当前的下拉框的内容
}
/********************************************************************************************/
/*使addproduct窗口可移动*/
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
	if (m_vProductNameEdit == "" || m_vProductPriceEdit == 0)		//判断增加产品的名称或单价是否为空
	{
		if (ui.productPriceEdit->text().isEmpty() || m_vProductNameEdit == "")
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
			ui.productPriceEdit->clear();
		}
	}
	else
	{
		index = ui.productTypeBox->currentIndex();		//currentIndex当前显示的列表项序号
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
		QString updateQuery = "update ProductInfo set ProductName=?,ProductType=?,Price=?,Notes=? where ProductID = ?";//更新语句
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
			w->setContent(tr("修改产品成功"));
			w->show();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("修改产品失败"));
			w->show();
			if (typeid(m_vProductNameEdit) != typeid(QString))//判断输入到proNameLineEdit中的是否为QString类型
				ui.productNameEdit->clear();
			if (typeid(m_vProductPriceEdit) != typeid(float))//判断输入到proPriceLineEdit中的是否为float类型
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
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)          //回车键和小键盘的Enter键
	{
		confirmSlot();//按钮槽函数
	}
}