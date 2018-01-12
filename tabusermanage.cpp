#pragma execution_character_set("utf-8")
#include "tabusermanage.h"
#include "getUUID.cpp"


//#include "TableToExcel.cpp"
TabUserManage::TabUserManage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	buttons = new QButtonGroup();                //管理复选框
    //buttons->setExclusive(false);                //可以同时选中
	ui.usertableWidget->setRowCount(7);            //设置7行
	ui.usertableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为，以行为单位
	ui.usertableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止编辑单元格编辑
	//ui.usertableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //设置选择模式，选择多行
	ui.usertableWidget->verticalHeader()->setVisible(false);                 //设置垂直头不可见
	ui.usertableWidget->horizontalHeader()->setSectionsClickable(false);       //设置表头不可点击
	ui.usertableWidget->setColumnWidth(0, 54);  //设置第一列的宽度
	ui.usertableWidget->setColumnWidth(1, 292);  //设置第二列的宽度
	ui.usertableWidget->setColumnWidth(2, 244);  //设置第三列的宽度
	ui.usertableWidget->setColumnWidth(3, 312);  //设置第四列的宽度
	ui.usertableWidget->horizontalHeader()->setFixedHeight(52);              //设置表头的高度
	for (int i = 0; i < 7; i++)
		ui.usertableWidget->setRowHeight(i, 52);   //设置单元格的高度

	ui.usertableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{ border: 1px solid gray; }"); //设置表头背景色 groove gray;      border-radius:10px; padding:2px 4px;
	//ui.usertableWidget->setStyleSheet("gridline:  1px solid black; ");

	connect(ui.userfirstBtn, SIGNAL(clicked()), this, SLOT(userfirstSlot()));
	connect(ui.userpreviousBtn, SIGNAL(clicked()), this, SLOT(userpreviousSlot()));
	connect(ui.usernextBtn, SIGNAL(clicked()), this, SLOT(usernextSlot()));
	connect(ui.userlastBtn, SIGNAL(clicked()), this, SLOT(userlastSlot()));
	connect(ui.useraddBtn, SIGNAL(clicked()), this, SLOT(useraddSlot()));
	connect(ui.userdeleteBtn, SIGNAL(clicked()), this, SLOT(userdeleteSlot()));
	connect(ui.userreviseBtn, SIGNAL(clicked()), this, SLOT(userreviseSlot()));
	connect(ui.usertableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(onCellClicked(int, int)));   //点击表中单元格，返回单元格坐标
	connect(buttons, SIGNAL(buttonClicked(int)), this, SLOT(onRadioButtonClicked(int)));



	query = "select UserID, UserName,UserType,UserPWD  from UserInfo ";     //将第一页数据插入到表中
	selectTemp = SqlOp::SelectQuery(query, 4);
	allPage = (selectTemp.size()-1) / 7;
	if (selectTemp.size() <=7)
	{
		userBtn(false, false, false, false);
		setContent(selectTemp.size());                     //设置单选按钮
		addData(0, selectTemp.size());                     //向表格中加入数据(0:第一页)
	}
	else
	{
		setContent(7);
		addData(0, 7);
	}


}

TabUserManage::~TabUserManage()
{

}



void TabUserManage::userfirstSlot()       //首页槽函数
{
	userBtn(false, false, true, true);
	currentPage = 0;
	setContent(7);
	addData(currentPage, 7);
}


void TabUserManage::userpreviousSlot()
{
	if (currentPage == 0)
	{
		userBtn(false, false, true, true);
	}
	else
	{
		setContent(7);
		currentPage--;
		addData(currentPage, 7);
		if (currentPage == 0)
		{
			userBtn(false, false, true, true);

		}
		else
		{
			userBtn(true, true, true, true);

		}
	}
}


void TabUserManage::usernextSlot()
{

	setContent(7);
	currentPage++;
	if (currentPage == allPage)
	{
		userBtn(true, true, false, false);
		ui.usertableWidget->clearContents();                    //清空之前的内容，重新写入新的内容
		int last = selectTemp.size() - (currentPage)* 7;
		setContent(last);
		addData(currentPage, last);
	}
	else
	{
		userBtn(true, true, true, true);
		addData(currentPage, 7);
	}
}


void TabUserManage::userlastSlot()
{
	userBtn(true, true, false, false);
	ui.usertableWidget->clearContents();                    //清空之前的内容，重新写入新的内容
	currentPage = allPage;
	int last = selectTemp.size() - (currentPage)* 7;
	setContent(last);
	addData(currentPage, last);


}


void TabUserManage::useraddSlot()
{
	adduser *add = new adduser(this);      //初始化
	add->show();
	connect(add, SIGNAL(adduserfresh()), this, SLOT(addfreshen()));
}



void TabUserManage::userdeleteSlot()
{
	int num= selectCount();
	if (num>=0)
	{
		deleteuser *del = new deleteuser(selectTemp, currentPage, num,this);
		del->show();
		connect(del, SIGNAL(deleteuserfresh()), this, SLOT(deletefreshen()));
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请选择要删除的用户"));
		w->show();
	}

}




void TabUserManage::userreviseSlot()
{
	int num = selectCount();
	if (num >= 0)
	{
		reviseuser *revise = new reviseuser(selectTemp, currentPage, num,this);
		revise->show();
		connect(revise, SIGNAL(reviseuserfresh()), this, SLOT(revisefreshen()));
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请选择要修改的信息"));
		w->show();
	}
		//QMessageBox::warning(NULL, "警告", "请选择要修改的信息");
}





void TabUserManage::onCellClicked(int row, int col){
	//qDebug() << "++++++++++++++++-------------" << row;
	if (selectTemp.size() == 0)
		return;
	if (currentPage == allPage)
	{
		if (row >= (selectTemp.size() - currentPage * 7))
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



void TabUserManage::setContent(int number)            //在单元格里加入单选框
{
	for (int i = 0; i <number; i++)
	{
		QRadioButton *one = new QRadioButton;
		one->setStyleSheet("QRadioButton::indicator{ width: 54px; height: 52px; }"
			"QRadioButton::indicator:unchecked{ image: url(:/userManage/image/userManage/circle.png);}"
			"QRadioButton::indicator:checked{ image: url(:/userManage/image/userManage/circle_a.png); }");
		ui.usertableWidget->setCellWidget(i, 0, one);
		buttons->addButton(one, i);              //管理check box

	}
}


void TabUserManage::addData(int current, int line)         //在表格中加入数据
{
	for (int i = 0; i < line; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			if (j == 2)
			{
				if (selectTemp[current * 7 + i][2] == QString::number(1))
				{
					QTableWidgetItem *item = new QTableWidgetItem("普通用户");
					item->setTextAlignment(Qt::AlignCenter);         //设置单元格内的文字居中显示
					ui.usertableWidget->setItem(i, 2, item);
				}
				else
				{
					QTableWidgetItem *item = new QTableWidgetItem("管理员");
					item->setTextAlignment(Qt::AlignCenter);
					ui.usertableWidget->setItem(i, 2, item);
				}
			}
			else
			{
				QTableWidgetItem *item = new QTableWidgetItem(QString(selectTemp[current * 7 + i][j]));
				item->setTextAlignment(Qt::AlignCenter);            //设置单元格内的文字居中显示
				ui.usertableWidget->setItem(i, j, item);
			}

		}
	}

}



void TabUserManage::addfreshen()                     //增加数据后刷新，光标移到新加的数据（最后）
{
	ui.usertableWidget->clearContents();                    //清空之前的内容，重新写入新的内容
	query = "select UserID, UserName,UserType,UserPWD  from UserInfo ";
	selectTemp = SqlOp::SelectQuery(query, 4);
	allPage = (selectTemp.size() - 1) / 7;           //当数据个数为7个时，只需要1页，此处-1可以避免第二页没有数据

	currentPage = allPage;
	setContent(selectTemp.size() - currentPage * 7);                     //加入单选按钮
	addData(currentPage, selectTemp.size() - currentPage * 7);                     //向表格中加入数据
	ui.usertableWidget->selectRow(selectTemp.size() - currentPage * 7 - 1);
	ui.usertableWidget->setFocus(Qt::MouseFocusReason);
	if (allPage == 0)
	{
		userBtn(false, false, false, false);
	}
	else
	{
		userBtn(true, true, false, false);
	}
}


void TabUserManage::deletefreshen()                  // 删除数据后刷新，光标移到首页第一个数据
{
	ui.usertableWidget->clearContents();                    //清空之前的内容，重新写入新的内容
	query = "select UserID, UserName,UserType,UserPWD  from UserInfo ";
	selectTemp = SqlOp::SelectQuery(query, 4);
	allPage = (selectTemp.size() - 1) / 7;
	if (allPage == 0)
	{
		currentPage = 0;
		setContent(selectTemp.size());
		addData(0, selectTemp.size());
		ui.usertableWidget->selectRow(0);
		ui.usertableWidget->setFocus(Qt::MouseFocusReason);
		userBtn(false, false, false, false);
		
	}
	else
	{
		currentPage = 0;
		setContent(7);
		addData(0, 7);
		ui.usertableWidget->selectRow(0);
		ui.usertableWidget->setFocus(Qt::MouseFocusReason);
		userBtn(false, false, true, true);
	}
}


void TabUserManage::revisefreshen()                   // 修改数据后刷新，光标移到修改数据上
{
	int number = selectCount();
	ui.usertableWidget->clearContents();                    //清空之前的内容，重新写入新的内容
	query = "select UserID, UserName,UserType,UserPWD  from UserInfo ";
	selectTemp = SqlOp::SelectQuery(query, 4);
	if (currentPage == allPage)
	{
		setContent(selectTemp.size() - currentPage * 7);                     //设置单选按钮
		addData(currentPage, selectTemp.size() - currentPage * 7);                     //向表格中加入数据
		ui.usertableWidget->selectRow(number);
		ui.usertableWidget->setFocus(Qt::MouseFocusReason);
	}
	else
	{
		setContent(7);
		addData(currentPage, 7);
		ui.usertableWidget->selectRow(number);
		ui.usertableWidget->setFocus(Qt::MouseFocusReason);

	}
}




void TabUserManage::userBtn(bool a, bool b, bool c, bool d)           //设置按钮是否可用
{
	ui.userfirstBtn->setEnabled(a);
	ui.userpreviousBtn->setEnabled(b);
	ui.usernextBtn->setEnabled(c);
	ui.userlastBtn->setEnabled(d);
}


int TabUserManage::selectCount()                   //当调用该函数后，返回被选中的数在第几行
{
	int i, number = -1;
	if (currentPage == allPage)
	{
		int last = selectTemp.size() - (currentPage)* 7;
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




void TabUserManage::onRadioButtonClicked(int Index)            //当点击单选框时，显示为焦点 事件
{
	selectedIndex = Index;
	ui.usertableWidget->selectRow(Index);
	ui.usertableWidget->setFocus(Qt::MouseFocusReason);
	onCellClicked(Index, 7);
}


//void TabUserManage::tabletoexcel()
//{
//	QString str = "<table border='1' cellpadding='1'>"
//		" <tr>   <td>编号</td>   <td>课程名称</td>   <td>成绩</td>    <td>学分</td>   <td>绩点</td> </tr> "
//		" <tr>   <td>湖北工业大学 </td>   <td>吴晓松</td>   <td> 3 </td>    <td> 4 </td>   <td> 5 </td> </tr> "
//		" <tr>   <td> 2 </td>   <td> 2 </td>   <td> 3 </td>    <td> 4 </td>   <td> 5 </td> </tr> "
//		" <tr>   <td> 3 </td>   <td> 2 </td>   <td> 3 </td>    <td> 4 </td>   <td> 5 </td> </tr> "
//		" <tr>   <td> 4 </td>   <td> 2 </td>   <td> 3 </td>    <td> 4 </td>   <td> 5 </td> </tr> "
//		" <tr>   <td> 5 </td>   <td> 2 </td>   <td> 3 </td>    <td> 4 </td>   <td> 5 </td> </tr> "
//		" <tr>   <td> 6 </td>   <td> 2 </td>   <td> 3 </td>    <td> 4 </td>   <td> 5 </td> </tr> "
//		" <tr>   <td> 7 </td>   <td> 2 </td>   <td> 3 </td>    <td> 4 </td>   <td> 5 </td> </tr> "
//		"</table> ";
//	ToExcel to;
//	to.Table2Excel(str);
//}