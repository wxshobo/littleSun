#pragma execution_character_set("utf-8")
#include "tabproductmanage.h"
#include <QTableWidgetItem>
#include<QHBoxLayout>
#include <QRadioButton>
#include "reviseproduct.h"

TabProductManage::TabProductManage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	currentPage = 1;//当前页数的初始值
	number = -1;
	allPage = 1;
	buttons = new QButtonGroup();
	//buttons->setExclusive(false);//可以同时选中

	ui.proTableWidget->setRowCount(7); 
	ui.proTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为，以行为单位x
//	ui.proTableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	ui.proTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑单元格编辑
	ui.proTableWidget->verticalHeader()->setVisible(false);                 //设置垂直头不可见
	ui.proTableWidget->horizontalHeader()->setSectionsClickable(false);       //设置表头不可点击
	  
	/*设置表格的宽度*/	
	ui.proTableWidget->setColumnWidth(0, 54);
	ui.proTableWidget->setColumnWidth(1, 292);
	ui.proTableWidget->setColumnWidth(2, 244);
	ui.proTableWidget->setColumnWidth(3, 312);
	ui.proTableWidget->horizontalHeader()->setFixedHeight(52);  //设置表头的高度
	for (int i = 0; i < 7; i++)
		ui.proTableWidget->setRowHeight(i, 52);   //设置单元格的高度  
	ui.proTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{ border: 1px solid gray; }"); //设置表头背景色 groove gray;      border-radius:10px; padding:2px 4px;
	//ui.proTableWidget->setStyleSheet("gridline:  1px solid black; ");

	/*各按钮信号与槽的连接*/
	connect(ui.proAddBtn, SIGNAL(clicked()), this, SLOT(addPageClicked()));
	connect(ui.proFirstBtn, SIGNAL(clicked()), this, SLOT(firstPageClicked()));
	connect(ui.proPreBtn, SIGNAL(clicked()), this, SLOT(previousPageClicked()));
	connect(ui.proNextBtn, SIGNAL(clicked()), this, SLOT(nextPageClicked()));
	connect(ui.proLastBtn, SIGNAL(clicked()), this, SLOT(lastPageClicked()));
	connect(ui.proDelBtn, SIGNAL(clicked()), this, SLOT(delPageClicked()));
	connect(ui.proUpdateBtn, SIGNAL(clicked()), this, SLOT(updatePageClicked()));

	connect(ui.proTableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(onCellClicked(int, int)));
	connect(buttons, SIGNAL(buttonClicked(int)), this, SLOT(onRadioButtonClicked(int)));
	
	QString tempQuery = "select ProductID,ProductName,ProductType,Price from ProductInfo";	//将第一页数据插入表中	
	proInformation = SqlOp::SelectQuery(tempQuery, 4);
//	setContent(proInformation.size());
//	setContent();
	if (proInformation.size() <= 7)
	{
		setContent(proInformation.size());
		addDate(1, proInformation.size());
		proBtn(false, false, false, false);
		if (proInformation.size() == 0)
		{
			ui.proDelBtn->setEnabled(false);
			ui.proUpdateBtn->setEnabled(false);
		}
	}
	else
	{
		setContent(7);
		addDate(1, 7);
		proBtn(false, true, false, true);
	}
}
TabProductManage::~TabProductManage()
{
}


void TabProductManage::addPageClicked()//新增页
{
	AddProduct * m_update = new AddProduct(this);
	connect(m_update, SIGNAL(addSuccess()), this, SLOT(addfresh()));
	m_update->show();
}
/**************************************************************************
只有在页数超过1的时候，第一页的按钮才是可点击的状态，点击第一页那么将上一页，和第一页设置成不可
点击的状态，下一页和最后一页可点击，当前页面设置为1
****************************************************************************/
void TabProductManage::firstPageClicked()//点击第一页
{
	QString Query = "select ProductID,ProductName,ProductType,Price from ProductInfo";//查询语句
	proInformation = SqlOp::SelectQuery(Query, 4);
	proBtn(false, true, false, true);
	currentPage = 1;
	setContent(7);
	addDate(currentPage, 7);
}
/**************************************************************
点击上一页需要将下一页与最后一页的按钮设置为可点击状态，当前页面减一，点击上一页后若当前页面为第一页
则设置上一页和第一页为不可点击状态
****************************************************************/
void TabProductManage::previousPageClicked()//点击上一页
{
	findSql();   //查询语句并计算页数
	setContent(7);
	currentPage--;
	addDate(currentPage, 7);
	if (currentPage == 1)
		proBtn(false, true, false, true);
	else
		proBtn(true, true, true, true);
}
/*****************************************************************************
点击下一页，那么第一页和上一页的按钮设置为可点击状态，当前页数加一，然后判断当前页数与总页数是否相等
若相等则下一页和最后一页按钮设置为不可点击状态，还要判断添加记录的条数
******************************************************************************/
void TabProductManage::nextPageClicked()//点击下一页
{
	findSql();                 
	currentPage++;
	if (currentPage == allPage)
	{
		proBtn(true, false, true, false);
		ui.proTableWidget->clearContents();                    //清空之前的内容，重新写入新的内容
		int last = proInformation.size() - (currentPage - 1)* 7;
		setContent(last);
		addDate(currentPage, last);
	}
	else
	{
		proBtn(true, true, true, true);
		setContent(7);
		addDate(currentPage, 7);
	}

}
/***********************************************************************************
最后一页可点击表明页数超过1，点击最后一页将下一页与最后一页设置为不可点击，第一页与上一页设置为可
点击，将当前页数置为总页数
************************************************************************************/
void TabProductManage::lastPageClicked()//点击最后一页
{
	findSql();
	proBtn(true, false, true, false);
	ui.proTableWidget->clearContents();                    //清空之前的内容，重新写入新的内容
	currentPage = allPage;
	int last = proInformation.size() - (currentPage - 1)* 7;
	setContent(last);
	addDate(currentPage, last);
}

/*******************************************************************************************
* 函数名称：onCellClicked(int row, int col)
* 函数介绍：若点击一行，则将该行选中
* 输入参数：行数row
* 输出参数：无
* 返回值  ：无
********************************************************************************************/

void TabProductManage::onCellClicked(int row, int col){
	qDebug() << "++++++++++++++++-------------" << row;
	if (proInformation.size() == 0)
		return;
	if (currentPage == allPage) 
	{
		if (row >= (proInformation.size() - (currentPage-1)*7))
			return;
		else
		{
			if (buttons->button(row)->isChecked())
				buttons->button(row)->setChecked(false);
			else
				buttons->button(row)->setChecked(true);
		}
	}
	else
	{
		if (buttons->button(row)->isChecked())
			buttons->button(row)->setChecked(false);
		else
			buttons->button(row)->setChecked(true);
	}
	selectedIndex = row;
	qDebug() << "selectedIndex1" << selectedIndex;
}

void TabProductManage::onRadioButtonClicked(int Index)    
{
	selectedIndex = Index;
	ui.proTableWidget->selectRow(Index);
	ui.proTableWidget->setFocus(Qt::MouseFocusReason);
}


void TabProductManage::updatePageClicked()//修改记录
{
	QString tempQuery = "select ProductID,ProductName,ProductType,Price,Notes from ProductInfo";//查询语句
	proInformation = SqlOp::SelectQuery(tempQuery, 5);
	allPage = proInformation.size() / 7;
	if (proInformation.size() % 7 != 0)
		allPage++;
	number = selectCount();    //选中的第几行,number初值设为-1
	if (number >= 0)
	{
		reviseProduct *revise = new reviseProduct(proInformation, currentPage, number,this);
		revise->show();
		connect(revise, SIGNAL(reviseSuccess()), this, SLOT(revisefresh()));
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请选择要修改的信息"));
		w->show();
	}
}
void TabProductManage::delPageClicked()//删除记录
{
	QString tempQuery = "select ProductID,ProductName,ProductType,Price,Notes from ProductInfo";//查询语句
	proInformation = SqlOp::SelectQuery(tempQuery, 5);
	allPage = proInformation.size() / 7;
	if (proInformation.size() % 7 != 0)
		allPage++;
	int num = selectCount();
	if (num >= 0)
	{
		deleteproduct *del = new deleteproduct(proInformation, currentPage, num,this);
		del->show();
		connect(del, SIGNAL(deleteSuccess()), this, SLOT(deletefresh()));
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请选择要删除的产品"));
		w->show();
	}
}
void TabProductManage::findSql()     //Sql查找语句并计算出页数
{
	QString Query = "select ProductID,ProductName,ProductType,Price from ProductInfo";//查询语句
	proInformation = SqlOp::SelectQuery(Query, 4);
	/*根据数据数量计算页数*/
	allPage = proInformation.size() / 7;
	if (proInformation.size() % 7 != 0)
		allPage++;
}
void TabProductManage::addfresh()               //添加数据后刷新，光标移到添加数据的位置（最后）
{
	ui.proTableWidget->clearContents();//清空之前的内容
	ui.proDelBtn->setEnabled(true);
	ui.proUpdateBtn->setEnabled(true);
	findSql();
	currentPage = allPage;
	setContent(proInformation.size() - (currentPage - 1) * 7);
	addDate(currentPage, proInformation.size() - (currentPage - 1) * 7);
	ui.proTableWidget->selectRow(proInformation.size() - (currentPage - 1) * 7 - 1);
	ui.proTableWidget->setFocus(Qt::MouseFocusReason);
	proBtn(true,false,true,false);
	if (currentPage == 1)
	{
		ui.proFirstBtn->setEnabled(false);
		ui.proPreBtn->setEnabled(false);
	}
}
void TabProductManage::deletefresh()                // 删除数据后刷新，光标移到首页第一个数据
{
	ui.proTableWidget->clearContents();//清空之前的内容
	findSql();
	currentPage = 1;
	proBtn(false, true, false, true);
	if (proInformation.size() == 0)
	{
		ui.proDelBtn->setEnabled(false);
		ui.proUpdateBtn->setEnabled(false);
		proBtn(false, false, false, false);
	}
	else
	{
		if (proInformation.size() > 7)
		{
			setContent(7);
			addDate(1, 7);
		}
		else
		{
			setContent(proInformation.size());
			addDate(1, proInformation.size());
			ui.proNextBtn->setEnabled(false);
			ui.proLastBtn->setEnabled(false);
		}
	}
	ui.proTableWidget->selectRow(0);
	ui.proTableWidget->setFocus(Qt::MouseFocusReason);
}
void TabProductManage::revisefresh()         //修改数据后刷新，光标移动到修改的数据上
{
	ui.proTableWidget->clearContents();
	findSql();
	if (currentPage == allPage)
	{
		setContent(proInformation.size() - (currentPage - 1) * 7);
		addDate(currentPage, proInformation.size() - (currentPage - 1) * 7);
	}
	else
	{
		setContent(7);
		addDate(currentPage, 7);
	}
	ui.proTableWidget->selectRow(number);
	ui.proTableWidget->setFocus(Qt::MouseFocusReason);
}
void TabProductManage::proBtn(bool a, bool b, bool c, bool d)//设置按钮的状态
{
	ui.proFirstBtn->setEnabled(a);
	ui.proLastBtn->setEnabled(b);
	ui.proPreBtn->setEnabled(c);
	ui.proNextBtn->setEnabled(d);
}
void TabProductManage::setContent(int number)        //给表格中添加按钮
{
	for (int i = 0; i < number; i++)
	{
		QRadioButton *one = new QRadioButton();
		//给单选框在勾选和未勾选时添加底图
		one->setStyleSheet("QRadioButton::indicator{width: 54px; height: 52px;}  "
			"QRadioButton::indicator::unchecked{image:url(:/productManage/image/productManage/circle.png);}  "
			"QRadioButton::indicator::checked{image:url(:/productManage/image/productManage/circle_a.png);}");
		ui.proTableWidget->setCellWidget(i, 0, one);
		buttons->addButton(one, i);
	}
}
void TabProductManage::addDate(int current, int line)   //向表格中加入数据
{
	QTableWidgetItem *item;
	for (int i = 0; i < line; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			if (j == 2)
			{
				if (proInformation[(current-1) * 7 + i][2] == QString::number(1))
					item = new QTableWidgetItem("小太阳砂带");
				else if (proInformation[(current - 1) * 7 + i][2] == QString::number(2))
					item = new QTableWidgetItem("三菱砂带");
				else if (proInformation[(current - 1) * 7 + i][2] == QString::number(3))
					item = new QTableWidgetItem("金牛砂带");
				else if (proInformation[(current - 1) * 7 + i][2] == QString::number(4))
					item = new QTableWidgetItem("其他砂带");
				else if (proInformation[(current - 1) * 7 + i][2] == QString::number(5))
					item = new QTableWidgetItem("园盘砂");
				else
					item = new QTableWidgetItem("其它产品");
			}
			else
			{
				item = new QTableWidgetItem(QString(proInformation[(current - 1) * 7 + i][j]));
			}
			item->setTextAlignment(Qt::AlignCenter);            //设置单元格内的文字居中显示
			ui.proTableWidget->setItem(i, j, item);
		}
	}
}
int TabProductManage::selectCount()                   //当调用该函数后，返回被选中的数在第几行
{
	int i, number = -1;
	if (currentPage == allPage)
	{
		int last = proInformation.size() - (currentPage - 1)* 7;
		for (i = 0; i < last; i++)
		{
			if (buttons->button(i)->isChecked())
				number = i;
		}
	}
	else
	{
		for (i = 0; i <7; i++)
		{
			if (buttons->button(i)->isChecked())
				number = i;
		}
	}
	return number;
}