#pragma execution_character_set("utf-8")
#include "tabusermanage.h"
#include "getUUID.cpp"


//#include "TableToExcel.cpp"
TabUserManage::TabUserManage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	buttons = new QButtonGroup();                //����ѡ��
    //buttons->setExclusive(false);                //����ͬʱѡ��
	ui.usertableWidget->setRowCount(7);            //����7��
	ui.usertableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ����Ϊ������Ϊ��λ
	ui.usertableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //��ֹ�༭��Ԫ��༭
	//ui.usertableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //����ѡ��ģʽ��ѡ�����
	ui.usertableWidget->verticalHeader()->setVisible(false);                 //���ô�ֱͷ���ɼ�
	ui.usertableWidget->horizontalHeader()->setSectionsClickable(false);       //���ñ�ͷ���ɵ��
	ui.usertableWidget->setColumnWidth(0, 54);  //���õ�һ�еĿ��
	ui.usertableWidget->setColumnWidth(1, 292);  //���õڶ��еĿ��
	ui.usertableWidget->setColumnWidth(2, 244);  //���õ����еĿ��
	ui.usertableWidget->setColumnWidth(3, 312);  //���õ����еĿ��
	ui.usertableWidget->horizontalHeader()->setFixedHeight(52);              //���ñ�ͷ�ĸ߶�
	for (int i = 0; i < 7; i++)
		ui.usertableWidget->setRowHeight(i, 52);   //���õ�Ԫ��ĸ߶�

	ui.usertableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{ border: 1px solid gray; }"); //���ñ�ͷ����ɫ groove gray;      border-radius:10px; padding:2px 4px;
	//ui.usertableWidget->setStyleSheet("gridline:  1px solid black; ");

	connect(ui.userfirstBtn, SIGNAL(clicked()), this, SLOT(userfirstSlot()));
	connect(ui.userpreviousBtn, SIGNAL(clicked()), this, SLOT(userpreviousSlot()));
	connect(ui.usernextBtn, SIGNAL(clicked()), this, SLOT(usernextSlot()));
	connect(ui.userlastBtn, SIGNAL(clicked()), this, SLOT(userlastSlot()));
	connect(ui.useraddBtn, SIGNAL(clicked()), this, SLOT(useraddSlot()));
	connect(ui.userdeleteBtn, SIGNAL(clicked()), this, SLOT(userdeleteSlot()));
	connect(ui.userreviseBtn, SIGNAL(clicked()), this, SLOT(userreviseSlot()));
	connect(ui.usertableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(onCellClicked(int, int)));   //������е�Ԫ�񣬷��ص�Ԫ������
	connect(buttons, SIGNAL(buttonClicked(int)), this, SLOT(onRadioButtonClicked(int)));



	query = "select UserID, UserName,UserType,UserPWD  from UserInfo ";     //����һҳ���ݲ��뵽����
	selectTemp = SqlOp::SelectQuery(query, 4);
	allPage = (selectTemp.size()-1) / 7;
	if (selectTemp.size() <=7)
	{
		userBtn(false, false, false, false);
		setContent(selectTemp.size());                     //���õ�ѡ��ť
		addData(0, selectTemp.size());                     //�����м�������(0:��һҳ)
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



void TabUserManage::userfirstSlot()       //��ҳ�ۺ���
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
		ui.usertableWidget->clearContents();                    //���֮ǰ�����ݣ�����д���µ�����
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
	ui.usertableWidget->clearContents();                    //���֮ǰ�����ݣ�����д���µ�����
	currentPage = allPage;
	int last = selectTemp.size() - (currentPage)* 7;
	setContent(last);
	addData(currentPage, last);


}


void TabUserManage::useraddSlot()
{
	adduser *add = new adduser(this);      //��ʼ��
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
		w->setContent(tr("��ѡ��Ҫɾ�����û�"));
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
		w->setContent(tr("��ѡ��Ҫ�޸ĵ���Ϣ"));
		w->show();
	}
		//QMessageBox::warning(NULL, "����", "��ѡ��Ҫ�޸ĵ���Ϣ");
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



void TabUserManage::setContent(int number)            //�ڵ�Ԫ������뵥ѡ��
{
	for (int i = 0; i <number; i++)
	{
		QRadioButton *one = new QRadioButton;
		one->setStyleSheet("QRadioButton::indicator{ width: 54px; height: 52px; }"
			"QRadioButton::indicator:unchecked{ image: url(:/userManage/image/userManage/circle.png);}"
			"QRadioButton::indicator:checked{ image: url(:/userManage/image/userManage/circle_a.png); }");
		ui.usertableWidget->setCellWidget(i, 0, one);
		buttons->addButton(one, i);              //����check box

	}
}


void TabUserManage::addData(int current, int line)         //�ڱ���м�������
{
	for (int i = 0; i < line; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			if (j == 2)
			{
				if (selectTemp[current * 7 + i][2] == QString::number(1))
				{
					QTableWidgetItem *item = new QTableWidgetItem("��ͨ�û�");
					item->setTextAlignment(Qt::AlignCenter);         //���õ�Ԫ���ڵ����־�����ʾ
					ui.usertableWidget->setItem(i, 2, item);
				}
				else
				{
					QTableWidgetItem *item = new QTableWidgetItem("����Ա");
					item->setTextAlignment(Qt::AlignCenter);
					ui.usertableWidget->setItem(i, 2, item);
				}
			}
			else
			{
				QTableWidgetItem *item = new QTableWidgetItem(QString(selectTemp[current * 7 + i][j]));
				item->setTextAlignment(Qt::AlignCenter);            //���õ�Ԫ���ڵ����־�����ʾ
				ui.usertableWidget->setItem(i, j, item);
			}

		}
	}

}



void TabUserManage::addfreshen()                     //�������ݺ�ˢ�£�����Ƶ��¼ӵ����ݣ����
{
	ui.usertableWidget->clearContents();                    //���֮ǰ�����ݣ�����д���µ�����
	query = "select UserID, UserName,UserType,UserPWD  from UserInfo ";
	selectTemp = SqlOp::SelectQuery(query, 4);
	allPage = (selectTemp.size() - 1) / 7;           //�����ݸ���Ϊ7��ʱ��ֻ��Ҫ1ҳ���˴�-1���Ա���ڶ�ҳû������

	currentPage = allPage;
	setContent(selectTemp.size() - currentPage * 7);                     //���뵥ѡ��ť
	addData(currentPage, selectTemp.size() - currentPage * 7);                     //�����м�������
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


void TabUserManage::deletefreshen()                  // ɾ�����ݺ�ˢ�£�����Ƶ���ҳ��һ������
{
	ui.usertableWidget->clearContents();                    //���֮ǰ�����ݣ�����д���µ�����
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


void TabUserManage::revisefreshen()                   // �޸����ݺ�ˢ�£�����Ƶ��޸�������
{
	int number = selectCount();
	ui.usertableWidget->clearContents();                    //���֮ǰ�����ݣ�����д���µ�����
	query = "select UserID, UserName,UserType,UserPWD  from UserInfo ";
	selectTemp = SqlOp::SelectQuery(query, 4);
	if (currentPage == allPage)
	{
		setContent(selectTemp.size() - currentPage * 7);                     //���õ�ѡ��ť
		addData(currentPage, selectTemp.size() - currentPage * 7);                     //�����м�������
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




void TabUserManage::userBtn(bool a, bool b, bool c, bool d)           //���ð�ť�Ƿ����
{
	ui.userfirstBtn->setEnabled(a);
	ui.userpreviousBtn->setEnabled(b);
	ui.usernextBtn->setEnabled(c);
	ui.userlastBtn->setEnabled(d);
}


int TabUserManage::selectCount()                   //�����øú����󣬷��ر�ѡ�е����ڵڼ���
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




void TabUserManage::onRadioButtonClicked(int Index)            //�������ѡ��ʱ����ʾΪ���� �¼�
{
	selectedIndex = Index;
	ui.usertableWidget->selectRow(Index);
	ui.usertableWidget->setFocus(Qt::MouseFocusReason);
	onCellClicked(Index, 7);
}


//void TabUserManage::tabletoexcel()
//{
//	QString str = "<table border='1' cellpadding='1'>"
//		" <tr>   <td>���</td>   <td>�γ�����</td>   <td>�ɼ�</td>    <td>ѧ��</td>   <td>����</td> </tr> "
//		" <tr>   <td>������ҵ��ѧ </td>   <td>������</td>   <td> 3 </td>    <td> 4 </td>   <td> 5 </td> </tr> "
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