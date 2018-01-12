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
	currentPage = 1;//��ǰҳ���ĳ�ʼֵ
	number = -1;
	allPage = 1;
	buttons = new QButtonGroup();
	//buttons->setExclusive(false);//����ͬʱѡ��

	ui.proTableWidget->setRowCount(7); 
	ui.proTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ����Ϊ������Ϊ��λx
//	ui.proTableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //����ѡ��ģʽ��ѡ����
	ui.proTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //��ֹ�༭��Ԫ��༭
	ui.proTableWidget->verticalHeader()->setVisible(false);                 //���ô�ֱͷ���ɼ�
	ui.proTableWidget->horizontalHeader()->setSectionsClickable(false);       //���ñ�ͷ���ɵ��
	  
	/*���ñ��Ŀ��*/	
	ui.proTableWidget->setColumnWidth(0, 54);
	ui.proTableWidget->setColumnWidth(1, 292);
	ui.proTableWidget->setColumnWidth(2, 244);
	ui.proTableWidget->setColumnWidth(3, 312);
	ui.proTableWidget->horizontalHeader()->setFixedHeight(52);  //���ñ�ͷ�ĸ߶�
	for (int i = 0; i < 7; i++)
		ui.proTableWidget->setRowHeight(i, 52);   //���õ�Ԫ��ĸ߶�  
	ui.proTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{ border: 1px solid gray; }"); //���ñ�ͷ����ɫ groove gray;      border-radius:10px; padding:2px 4px;
	//ui.proTableWidget->setStyleSheet("gridline:  1px solid black; ");

	/*����ť�ź���۵�����*/
	connect(ui.proAddBtn, SIGNAL(clicked()), this, SLOT(addPageClicked()));
	connect(ui.proFirstBtn, SIGNAL(clicked()), this, SLOT(firstPageClicked()));
	connect(ui.proPreBtn, SIGNAL(clicked()), this, SLOT(previousPageClicked()));
	connect(ui.proNextBtn, SIGNAL(clicked()), this, SLOT(nextPageClicked()));
	connect(ui.proLastBtn, SIGNAL(clicked()), this, SLOT(lastPageClicked()));
	connect(ui.proDelBtn, SIGNAL(clicked()), this, SLOT(delPageClicked()));
	connect(ui.proUpdateBtn, SIGNAL(clicked()), this, SLOT(updatePageClicked()));

	connect(ui.proTableWidget, SIGNAL(cellClicked(int, int)), this, SLOT(onCellClicked(int, int)));
	connect(buttons, SIGNAL(buttonClicked(int)), this, SLOT(onRadioButtonClicked(int)));
	
	QString tempQuery = "select ProductID,ProductName,ProductType,Price from ProductInfo";	//����һҳ���ݲ������	
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


void TabProductManage::addPageClicked()//����ҳ
{
	AddProduct * m_update = new AddProduct(this);
	connect(m_update, SIGNAL(addSuccess()), this, SLOT(addfresh()));
	m_update->show();
}
/**************************************************************************
ֻ����ҳ������1��ʱ�򣬵�һҳ�İ�ť���ǿɵ����״̬�������һҳ��ô����һҳ���͵�һҳ���óɲ���
�����״̬����һҳ�����һҳ�ɵ������ǰҳ������Ϊ1
****************************************************************************/
void TabProductManage::firstPageClicked()//�����һҳ
{
	QString Query = "select ProductID,ProductName,ProductType,Price from ProductInfo";//��ѯ���
	proInformation = SqlOp::SelectQuery(Query, 4);
	proBtn(false, true, false, true);
	currentPage = 1;
	setContent(7);
	addDate(currentPage, 7);
}
/**************************************************************
�����һҳ��Ҫ����һҳ�����һҳ�İ�ť����Ϊ�ɵ��״̬����ǰҳ���һ�������һҳ������ǰҳ��Ϊ��һҳ
��������һҳ�͵�һҳΪ���ɵ��״̬
****************************************************************/
void TabProductManage::previousPageClicked()//�����һҳ
{
	findSql();   //��ѯ��䲢����ҳ��
	setContent(7);
	currentPage--;
	addDate(currentPage, 7);
	if (currentPage == 1)
		proBtn(false, true, false, true);
	else
		proBtn(true, true, true, true);
}
/*****************************************************************************
�����һҳ����ô��һҳ����һҳ�İ�ť����Ϊ�ɵ��״̬����ǰҳ����һ��Ȼ���жϵ�ǰҳ������ҳ���Ƿ����
���������һҳ�����һҳ��ť����Ϊ���ɵ��״̬����Ҫ�ж���Ӽ�¼������
******************************************************************************/
void TabProductManage::nextPageClicked()//�����һҳ
{
	findSql();                 
	currentPage++;
	if (currentPage == allPage)
	{
		proBtn(true, false, true, false);
		ui.proTableWidget->clearContents();                    //���֮ǰ�����ݣ�����д���µ�����
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
���һҳ�ɵ������ҳ������1��������һҳ����һҳ�����һҳ����Ϊ���ɵ������һҳ����һҳ����Ϊ��
���������ǰҳ����Ϊ��ҳ��
************************************************************************************/
void TabProductManage::lastPageClicked()//������һҳ
{
	findSql();
	proBtn(true, false, true, false);
	ui.proTableWidget->clearContents();                    //���֮ǰ�����ݣ�����д���µ�����
	currentPage = allPage;
	int last = proInformation.size() - (currentPage - 1)* 7;
	setContent(last);
	addDate(currentPage, last);
}

/*******************************************************************************************
* �������ƣ�onCellClicked(int row, int col)
* �������ܣ������һ�У��򽫸���ѡ��
* �������������row
* �����������
* ����ֵ  ����
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


void TabProductManage::updatePageClicked()//�޸ļ�¼
{
	QString tempQuery = "select ProductID,ProductName,ProductType,Price,Notes from ProductInfo";//��ѯ���
	proInformation = SqlOp::SelectQuery(tempQuery, 5);
	allPage = proInformation.size() / 7;
	if (proInformation.size() % 7 != 0)
		allPage++;
	number = selectCount();    //ѡ�еĵڼ���,number��ֵ��Ϊ-1
	if (number >= 0)
	{
		reviseProduct *revise = new reviseProduct(proInformation, currentPage, number,this);
		revise->show();
		connect(revise, SIGNAL(reviseSuccess()), this, SLOT(revisefresh()));
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("��ѡ��Ҫ�޸ĵ���Ϣ"));
		w->show();
	}
}
void TabProductManage::delPageClicked()//ɾ����¼
{
	QString tempQuery = "select ProductID,ProductName,ProductType,Price,Notes from ProductInfo";//��ѯ���
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
		w->setContent(tr("��ѡ��Ҫɾ���Ĳ�Ʒ"));
		w->show();
	}
}
void TabProductManage::findSql()     //Sql������䲢�����ҳ��
{
	QString Query = "select ProductID,ProductName,ProductType,Price from ProductInfo";//��ѯ���
	proInformation = SqlOp::SelectQuery(Query, 4);
	/*����������������ҳ��*/
	allPage = proInformation.size() / 7;
	if (proInformation.size() % 7 != 0)
		allPage++;
}
void TabProductManage::addfresh()               //������ݺ�ˢ�£�����Ƶ�������ݵ�λ�ã����
{
	ui.proTableWidget->clearContents();//���֮ǰ������
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
void TabProductManage::deletefresh()                // ɾ�����ݺ�ˢ�£�����Ƶ���ҳ��һ������
{
	ui.proTableWidget->clearContents();//���֮ǰ������
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
void TabProductManage::revisefresh()         //�޸����ݺ�ˢ�£�����ƶ����޸ĵ�������
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
void TabProductManage::proBtn(bool a, bool b, bool c, bool d)//���ð�ť��״̬
{
	ui.proFirstBtn->setEnabled(a);
	ui.proLastBtn->setEnabled(b);
	ui.proPreBtn->setEnabled(c);
	ui.proNextBtn->setEnabled(d);
}
void TabProductManage::setContent(int number)        //���������Ӱ�ť
{
	for (int i = 0; i < number; i++)
	{
		QRadioButton *one = new QRadioButton();
		//����ѡ���ڹ�ѡ��δ��ѡʱ��ӵ�ͼ
		one->setStyleSheet("QRadioButton::indicator{width: 54px; height: 52px;}  "
			"QRadioButton::indicator::unchecked{image:url(:/productManage/image/productManage/circle.png);}  "
			"QRadioButton::indicator::checked{image:url(:/productManage/image/productManage/circle_a.png);}");
		ui.proTableWidget->setCellWidget(i, 0, one);
		buttons->addButton(one, i);
	}
}
void TabProductManage::addDate(int current, int line)   //�����м�������
{
	QTableWidgetItem *item;
	for (int i = 0; i < line; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			if (j == 2)
			{
				if (proInformation[(current-1) * 7 + i][2] == QString::number(1))
					item = new QTableWidgetItem("С̫��ɰ��");
				else if (proInformation[(current - 1) * 7 + i][2] == QString::number(2))
					item = new QTableWidgetItem("����ɰ��");
				else if (proInformation[(current - 1) * 7 + i][2] == QString::number(3))
					item = new QTableWidgetItem("��ţɰ��");
				else if (proInformation[(current - 1) * 7 + i][2] == QString::number(4))
					item = new QTableWidgetItem("����ɰ��");
				else if (proInformation[(current - 1) * 7 + i][2] == QString::number(5))
					item = new QTableWidgetItem("԰��ɰ");
				else
					item = new QTableWidgetItem("������Ʒ");
			}
			else
			{
				item = new QTableWidgetItem(QString(proInformation[(current - 1) * 7 + i][j]));
			}
			item->setTextAlignment(Qt::AlignCenter);            //���õ�Ԫ���ڵ����־�����ʾ
			ui.proTableWidget->setItem(i, j, item);
		}
	}
}
int TabProductManage::selectCount()                   //�����øú����󣬷��ر�ѡ�е����ڵڼ���
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