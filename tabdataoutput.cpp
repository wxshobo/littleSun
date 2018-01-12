#pragma execution_character_set("utf-8")
#include "tabdataoutput.h"
#include <QHeaderView>
#include"TableToExcel.cpp"
TabDataOutput::TabDataOutput(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.dataTabWid->verticalHeader()->setVisible(false);   //�����б�ͷ  
	ui.dataTabWid->setEditTriggers(QAbstractItemView::NoEditTriggers);    //��ֹ�༭��񣬱��ֻ�ܶ�����д
	ui.dataTabWid->horizontalHeader()->setSectionsClickable(false);   //���ñ�ͷ���ɵ��
	ui.dataTabWid->horizontalHeader()->setFixedHeight(42); //���ñ�ͷ�ĸ߶�
	ui.dataTabWid->setColumnWidth(0, 95);
	for (int i = 1; i < 13; i++)
	{
		if (i==7)
			ui.dataTabWid->setColumnWidth(i, 53);
		else ui.dataTabWid->setColumnWidth(i, 74);    //�еĿ��
	}
	for (int i = 0; i < 6; i++)
	{
		ui.dataTabWid->setRowHeight(i, 48);     //�еĸ߶�
	}
	ui.datSortComBox->addItem(tr("���в�Ʒ���"));//��ʼ����Ʒ����������
	ui.datSortComBox->addItem(tr("С̫��ɰ��"));   
	ui.datSortComBox->addItem(tr("����ɰ��"));
	ui.datSortComBox->addItem(tr("��ţɰ��"));
	ui.datSortComBox->addItem(tr("����ɰ��"));
	ui.datSortComBox->addItem(tr("Բ��ɰ"));
	ui.datSortComBox->addItem(tr("������Ʒ"));
	for (int i = 0; i < 7; i++)
	{
		ui.datSortComBox->model()->setData(ui.datSortComBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	QString inquireman = "select UserName from UserInfo";
	QVector<QVector<QString>>man;    //��ѯ�õ������б���Ա
	man = SqlOp::SelectQuery(inquireman, 1);
	ui.datmanComBox->addItem(tr("���б���Ա"));
	ui.datmanComBox->model()->setData(ui.datmanComBox->model()->index(0, 0), QSize(25, 25), Qt::SizeHintRole);
	for (int i = 0; i < man.size(); i++)
	{
		ui.datmanComBox->addItem(man[i][0]);
		ui.datmanComBox->model()->setData(ui.datmanComBox->model()->index(i + 1, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	connect(ui.datSortComBox, SIGNAL(activated(QString)), this, SLOT(savedatSortComBoxinfo()));     //��ȡ��ǰ��Ʒ����
	connect(ui.datinquireButton, SIGNAL(clicked()), this, SLOT(inquire()));     //��ѯ
  	connect(ui.datnextpageButton, SIGNAL(clicked()), this, SLOT(nextPage()));    //��һҳ
	connect(ui.datfirstpageButton, SIGNAL(clicked()), this, SLOT(firstPage()));   //��һҳ
	connect(ui.datprepageButton, SIGNAL(clicked()), this, SLOT(previousPage()));   //��һҳ
	connect(ui.datlastpageButton, SIGNAL(clicked()), this, SLOT(lastPage()));    //���һҳ
	connect(ui.datexportButton, SIGNAL(clicked()), this, SLOT(Output()));
	ui.datstartDateEdit->setDisplayFormat("yyyy-MM-dd");
	ui.datendDateEdit->setDisplayFormat("yyyy-MM-dd");
	ui.datstartDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
	ui.datendDateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
	ui.dataTabWid->horizontalHeader()->setStyleSheet("QHeaderView::section{ border: 1px solid gray; }");
	ui.datstartDateEdit->setCalendarPopup(true);
	ui.datendDateEdit->setCalendarPopup(true);
}

void TabDataOutput::Output()
{
		ToExcel a;
		if (a.Table2Excel(toHtmlStr()))
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("�ļ��Ѿ��ɹ�����!"));
			w->show();
		}
}

void TabDataOutput::Update()
{
	ui.datcompanyComBox->clear();
	ui.datcompanyComBox->addItem(tr("���й�˾"));
	ui.datcompanyComBox->model()->setData(ui.datcompanyComBox->model()->index(0, 0), QSize(25, 25), Qt::SizeHintRole);
	QString inquireCompany = "select CompanyName from CompanyInfo";
	QVector<QVector<QString> > result;  //������Ž��
	result = SqlOp::SelectQuery(inquireCompany, 1);
	for (int i = 0; i < result.size(); i++)     //��ʼ��ѡ��˾������
	{
		ui.datcompanyComBox->addItem(result[i][0]);
		ui.datcompanyComBox->model()->setData(ui.datcompanyComBox->model()->index(i + 1, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	current = 0;   //��ʼҳΪ��һҳ
	ui.datendDateEdit->setDateTime(QDateTime::currentDateTime());
	ui.datstartDateEdit->setDateTime(QDateTime::currentDateTime().addDays(-ui.datendDateEdit->sectionText(QDateTimeEdit::DaySection).toInt() + 1));
	QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=?";
	QVector<QString> bindValue;
	bindValue.append(ui.datstartDateEdit->date().toString("yyyy-MM-dd"));
	bindValue.append(ui.datendDateEdit->date().toString("yyyy-MM-dd") + "23:59:59");
	InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
	if (InquireResult.size() == 0)
	{
		ButtonPosition(false, false, false, false);
	}
	else
	{
		page = InquireResult.size() / 6;     //һ���ж���ҳ
		row = InquireResult.size() % 6;     //���һҳ�ж�����
		addData(current);
		ui.datfirstpageButton->setEnabled(false);
		ui.datprepageButton->setEnabled(false);
		if (page == 0)
		{
			ui.datnextpageButton->setEnabled(false);
			ui.datlastpageButton->setEnabled(false);
		}
	}
}

void TabDataOutput::savedatSortComBoxinfo()      //ѡ���깫˾����ѡ���Ʒ����
{
	ui.datNameComBox->clear();
	QString ProductType = ui.datSortComBox->currentText();    //��ȡ��ǰ��ѡ�Ĳ�Ʒ���
	if (ProductType.indexOf("С") == 0)
		Sort = "1";
	else if (ProductType.indexOf("��") == 0)
		Sort = "2";
	else if (ProductType.indexOf("��") == 0)
		Sort = "3";
	else if (ProductType.indexOf("��") == 0)
	{
		if (ProductType.indexOf("ɰ") == 2)
			Sort = "4";
		else Sort = "6";
	}
	else if (ProductType.indexOf("Բ") == 0)
		Sort = "5";
	else Sort = "7";

	if (Sort == "7")
	{
		ui.datNameComBox->addItem(tr("���в�Ʒ"));
	}
	else
	{
		QString inquireProduct = "select ProductName from ProductInfo where ProductType=?";
		QVector<QVector<QString>>result;     //������Ų�ѯ�õ��Ĳ�Ʒ����
		QVector<QString>bindValue;
		bindValue.append(Sort);
		result = SqlOp::SelectQuery(inquireProduct, 1, bindValue);
		ui.datNameComBox->addItem(tr("���в�Ʒ"));
		for (int i = 0; i < result.size(); i++)
		{
			ui.datNameComBox->addItem(result[i][0]);
		}
	}
}

void TabDataOutput::inquire()
{
	ui.dataTabWid->clearContents();    //����������ݲ�������ͷ
	QString startDate = ui.datstartDateEdit->date().toString("yyyy-MM-dd");   //��ʼ����
	QString endDate = ui.datendDateEdit->date().toString("yyyy-MM-dd") + "23:59:59";      //��������
	QString CompanyName = ui.datcompanyComBox->currentText();     //��˾����
	QString ProductType = ui.datSortComBox->currentText();    //��Ʒ���
	QString ProductName = ui.datNameComBox->currentText();     // ��Ʒ����
	QString Man = ui.datmanComBox->currentText();    //����Ա
	current = 0;   //��ʼҳΪ��һҳ
	if (ProductType.indexOf("С") == 0)
		Sort = "1";
	else if (ProductType.indexOf("��") == 0)
		Sort = "2";
	else if (ProductType.indexOf("��") == 0)
		Sort = "3";
	else if (ProductType.indexOf("��") == 0)
	{
		if (ProductType.indexOf("ɰ") == 2)
			Sort = "4";
		else Sort = "6";
	}
	else if (ProductType.indexOf("Բ") == 0)
		Sort = "5";
	else Sort = "7";
	if (QString::compare(CompanyName, "���й�˾") == 0)   //���ѡ�����й�˾
	{
		if (Sort == "7")    //���ѡ�����в�Ʒ���
		{
			if (QString::compare(Man, "���б���Ա") == 0) //���ѡ�����б���Ա
			{
				QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=?";
				QVector<QString> bindValue;
				bindValue.append(startDate);
				bindValue.append(endDate);
				InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
			}
			else     //���ѡ��ĳһλ����Ա
			{
				QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=? and BJMan=?";
				QVector<QString> bindValue;
				bindValue.append(startDate);
				bindValue.append(endDate);
				bindValue.append(Man);
				InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
			}
		}
		else
		{
			if (QString::compare(ProductName,"���в�Ʒ")== 0)  //���ѡ�����в�Ʒ
			{
				if (QString::compare(Man, "���б���Ա") == 0)   //���ѡ�����б���Ա
				{
					QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=? and ProductInfo.ProductType=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(Sort);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
				else     //���ѡ��ĳһλ����Ա
				{
					QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=? and ProductInfo.ProductType=? and BJMan=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(Sort);
					bindValue.append(Man);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
			}
			else
			{
				if (QString::compare(Man, "���б���Ա") == 0)   //���ѡ�����б���Ա
				{
					QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=? and ProductInfo.ProductType=? and ProductInfo.ProductName=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(Sort);
					bindValue.append(ProductName);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
				else
				{
					QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=? and ProductInfo.ProductType=? and ProductInfo.ProductName=? and BJMan=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(Sort);
					bindValue.append(ProductName);
					bindValue.append(Man);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
			}
		}
	}
	else    //���ѡ��ĳһ�ҹ�˾
	{
		if (Sort == "7")    //���ѡ�����в�Ʒ���
		{
			if (QString::compare(Man, "���б���Ա") == 0)    //���ѡ�����б���Ա
			{
				QString inquire = tr("select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord")
					+ " LEFT OUTER JOIN ProductInfo on BJRecord.ProductID = ProductInfo.ProductID LEFT OUTER JOIN CompanyInfo on BJRecord.CompanyID = CompanyInfo.CompanyID  where BJTime >= ? and BJTime <= ? and CompanyInfo.CompanyName = ? ";
				QVector<QString> bindValue;
				bindValue.append(startDate);
				bindValue.append(endDate);
				bindValue.append(CompanyName);
				InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
			}
			else    //���ѡ��ĳһλ����Ա
			{
				QString inquire = tr("select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord")
					+ " LEFT OUTER JOIN ProductInfo on BJRecord.ProductID = ProductInfo.ProductID LEFT OUTER JOIN CompanyInfo on BJRecord.CompanyID = CompanyInfo.CompanyID  where BJTime >= ? and BJTime <= ? and CompanyInfo.CompanyName = ? and BJMan=?";
				QVector<QString> bindValue;
				bindValue.append(startDate);
				bindValue.append(endDate);
				bindValue.append(CompanyName);
				bindValue.append(Man);
				InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
			}
		}
		else    //���ѡ��ĳһ�ֲ�Ʒ���
		{
			if (QString::compare(ProductName, "���в�Ʒ") == 0)  //���ѡ��ĳһ��Ʒ�����е����в�Ʒ
			{
				if (QString::compare(Man, "���б���Ա") == 0)    //���ѡ�����б���Ա
				{
					QString inquire = tr("select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord")
						+ " LEFT OUTER JOIN ProductInfo on BJRecord.ProductID = ProductInfo.ProductID LEFT OUTER JOIN CompanyInfo on BJRecord.CompanyID = CompanyInfo.CompanyID  where BJTime >= ? and BJTime <= ? and CompanyInfo.CompanyName = ? and ProductInfo.ProductType=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(CompanyName);
					bindValue.append(Sort);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
				else     //���ѡ��ĳһλ����Ա
				{
					QString inquire = tr("select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord")
						+ " LEFT OUTER JOIN ProductInfo on BJRecord.ProductID = ProductInfo.ProductID LEFT OUTER JOIN CompanyInfo on BJRecord.CompanyID = CompanyInfo.CompanyID  where BJTime >= ? and BJTime <= ? and CompanyInfo.CompanyName = ? and ProductInfo.ProductType=? and BJMan=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(CompanyName);
					bindValue.append(Sort);
					bindValue.append(Man);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
			}
			else    //���ѡ��ĳһ���Ʒ�е�ĳһ�ֲ�Ʒ
			{
				if (QString::compare(Man, "���б���Ա") == 0)    //���ѡ�����б���Ա
				{
					QString inquire = tr("select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord")
						+ " LEFT OUTER JOIN ProductInfo on BJRecord.ProductID = ProductInfo.ProductID LEFT OUTER JOIN CompanyInfo on BJRecord.CompanyID = CompanyInfo.CompanyID  where BJTime >= ? and BJTime <= ? and CompanyInfo.CompanyName = ? and ProductInfo.ProductType=? and ProductInfo.ProductName=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(CompanyName);
					bindValue.append(Sort);
					bindValue.append(ProductName);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
				else   //���ѡ��ĳһλ����Ա
				{
					QString inquire = tr("select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord")
						+ " LEFT OUTER JOIN ProductInfo on BJRecord.ProductID = ProductInfo.ProductID LEFT OUTER JOIN CompanyInfo on BJRecord.CompanyID = CompanyInfo.CompanyID  where BJTime >= ? and BJTime <= ? and CompanyInfo.CompanyName = ? and ProductInfo.ProductType=? and ProductInfo.ProductName=? and BJMan=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(CompanyName);
					bindValue.append(Sort);
					bindValue.append(ProductName);
					bindValue.append(Man);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
			}
		}
	}
	if (InquireResult.size() == 0)
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("Not Found!"));
		w->show();
		ButtonPosition(false, false, false, false);
	}
	else
	{
		page = InquireResult.size() / 6;
		row = InquireResult.size() % 6;
		toHtmlStr();
		addData(current);
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("��ѯ�ɹ�!"));
		w->show();
	}
}
QString TabDataOutput::toHtmlStr()
{
	QString str = tr("<table border='1' cellpadding='1'>") +
		" <tr>   <td>����ʱ��</td>   <td>��Ʒ����</td>   <td>��Ʒ���</td>    <td>����</td>   <td>���</td>  <td>����(Ԫ)</td>  <td>�����۸�</td>  <td>�Ƿ�ƽ��</td>  <td>ƽ�ӵ���</td>  <td>ƽ�Ӽ۸�</td>  <td>����ϵ��</td>  <td>�ն˱���</td>  <td>����Ա</td> </tr> ";
	for (int i = 0; i < InquireResult.size(); i++)
	{
		str = str + "<tr>   " + "<td>" + InquireResult[i][0] + "</td>"
			+ "<td>" + InquireResult[i][1] + "</td>"
			+ "<td>" + judgeType(InquireResult[i][2]) + "</td>"
			+ "<td>" + QString::number(InquireResult[i][3].toFloat(), 'f', 2) + "</td>"
			+ "<td>" + QString::number(InquireResult[i][4].toFloat(), 'f', 2) + "</td>"
			+ "<td>" + QString::number(InquireResult[i][5].toFloat(), 'f', 2) + "</td>"
			+ "<td>" + QString::number(InquireResult[i][6].toFloat(), 'f', 2) + "</td>"
			+ "<td>" + judgeContact(InquireResult[i][7]) + "</td>"
			+ "<td>" + QString::number(InquireResult[i][8].toFloat(), 'f', 2) + "</td>"
			+ "<td>" + QString::number(InquireResult[i][9].toFloat(), 'f', 2) + "</td>"
			+ "<td>" + QString::number(InquireResult[i][10].toFloat(), 'f', 2) + "</td>"
			+ "<td>" + QString::number(InquireResult[i][11].toFloat(), 'f', 2) + "</td>"
			+ "<td>" + InquireResult[i][12] + "</td>"
			+ "</tr>";
	}
	str += "</table> ";
	//ui.textEdit->setText(str);
	return str;
	
}
void TabDataOutput::addData(int currentpage)    //��������ʾ�������
{
	QString str;
	ui.dataTabWid->clearContents();    //����������ݲ�������ͷ
	if (currentpage == page)
	{
		for (int j = 0; j < row; j++)
		{
			ui.dataTabWid->setItem(j, 0, new QTableWidgetItem(InquireResult[currentpage * 6 + j][0]));
			ui.dataTabWid->setItem(j, 1, new QTableWidgetItem(InquireResult[currentpage * 6 + j][1]));
			ui.dataTabWid->setItem(j, 2, new QTableWidgetItem(judgeType(InquireResult[currentpage * 6 + j][2])));
			ui.dataTabWid->setItem(j, 3, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][3].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 4, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][4].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 5, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][5].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 6, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][6].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 7, new QTableWidgetItem(judgeContact(InquireResult[currentpage * 6 + j][7])));
			ui.dataTabWid->setItem(j, 8, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][8].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 9, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][9].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 10, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][10].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 11, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][11].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 12, new QTableWidgetItem(InquireResult[currentpage * 6 + j][12]));
			ui.dataTabWid->item(j, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 5)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 6)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 7)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 8)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 9)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 10)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 11)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 12)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		}
		current=current+1;
	}
	else if (currentpage < page)
	{
		for (int j = 0; j < 6; j++)
		{
			ui.dataTabWid->setItem(j, 0, new QTableWidgetItem(InquireResult[currentpage * 6 + j][0]));
			ui.dataTabWid->setItem(j, 1, new QTableWidgetItem(InquireResult[currentpage * 6 + j][1]));
			ui.dataTabWid->setItem(j, 2, new QTableWidgetItem(judgeType(InquireResult[currentpage * 6 + j][2])));
			ui.dataTabWid->setItem(j, 3, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][3].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 4, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][4].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 5, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][5].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 6, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][6].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 7, new QTableWidgetItem(judgeContact(InquireResult[currentpage * 6 + j][7])));
			ui.dataTabWid->setItem(j, 8, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][8].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 9, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][9].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 10, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][10].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 11, new QTableWidgetItem(QString::number(InquireResult[currentpage * 6 + j][11].toFloat(), 'f', 2)));
			ui.dataTabWid->setItem(j, 12, new QTableWidgetItem(InquireResult[currentpage * 6 + j][12]));
			ui.dataTabWid->item(j, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 5)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 6)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 7)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 8)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 9)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 10)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 11)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			ui.dataTabWid->item(j, 12)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		}
		current=current+1;
	}
	if (current == 1&&page==0)
	{
		ButtonPosition(false, false, false, false);
	}
	else if (current == 1 && page > 0)
	{
		ButtonPosition(false, false, true, true);
	}
	else if (current > page)
	{
		ButtonPosition(true, true, false, false);
	}
	else
	{
		ButtonPosition(true, true, true, true);
	}
}
void TabDataOutput::nextPage()     //��һҳ
{
	addData(current);
}

void TabDataOutput::previousPage()     //��һҳ
{
	current = current - 2;
	addData(current);
	
}
void TabDataOutput::firstPage()      //��һҳ
{
	current = 0;
	addData(current);
}
void TabDataOutput::lastPage()     //���һҳ
{
	current = page;
	addData(current);
}
QString TabDataOutput::judgeType(QString sort)
{
	QString type;
	if (sort == "1")
		return type = "С̫��ɰ��";
	else if (sort == "2")
		return type = "����ɰ��";
	else if (sort == "3")
		return type = "��ţɰ��";
	else if (sort == "4")
		return type = "����ɰ��";
	else if (sort == "5")
		return type = "Բ��ɰ";
	else if (sort == "6")
		return type = "������Ʒ";
}
QString TabDataOutput::judgeContact(QString IsContact)
{
	QString Contact;
	if (IsContact == "0")
		return Contact = "��";
	else return Contact = "��";
}
void TabDataOutput::ButtonPosition(bool first, bool pre, bool next, bool last)
{
	ui.datfirstpageButton->setEnabled(first);
	ui.datprepageButton->setEnabled(pre);
	ui.datnextpageButton->setEnabled(next);
	ui.datlastpageButton->setEnabled(last);
}
TabDataOutput::~TabDataOutput()
{

}

