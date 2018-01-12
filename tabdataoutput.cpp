#pragma execution_character_set("utf-8")
#include "tabdataoutput.h"
#include <QHeaderView>
#include"TableToExcel.cpp"
TabDataOutput::TabDataOutput(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.dataTabWid->verticalHeader()->setVisible(false);   //隐藏列表头  
	ui.dataTabWid->setEditTriggers(QAbstractItemView::NoEditTriggers);    //禁止编辑表格，表格只能读不能写
	ui.dataTabWid->horizontalHeader()->setSectionsClickable(false);   //设置表头不可点击
	ui.dataTabWid->horizontalHeader()->setFixedHeight(42); //设置表头的高度
	ui.dataTabWid->setColumnWidth(0, 95);
	for (int i = 1; i < 13; i++)
	{
		if (i==7)
			ui.dataTabWid->setColumnWidth(i, 53);
		else ui.dataTabWid->setColumnWidth(i, 74);    //列的宽度
	}
	for (int i = 0; i < 6; i++)
	{
		ui.dataTabWid->setRowHeight(i, 48);     //行的高度
	}
	ui.datSortComBox->addItem(tr("所有产品类别"));//初始化产品类型下拉框
	ui.datSortComBox->addItem(tr("小太阳砂带"));   
	ui.datSortComBox->addItem(tr("三菱砂带"));
	ui.datSortComBox->addItem(tr("金牛砂带"));
	ui.datSortComBox->addItem(tr("其他砂带"));
	ui.datSortComBox->addItem(tr("圆盘砂"));
	ui.datSortComBox->addItem(tr("其他产品"));
	for (int i = 0; i < 7; i++)
	{
		ui.datSortComBox->model()->setData(ui.datSortComBox->model()->index(i, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	QString inquireman = "select UserName from UserInfo";
	QVector<QVector<QString>>man;    //查询得到的所有报价员
	man = SqlOp::SelectQuery(inquireman, 1);
	ui.datmanComBox->addItem(tr("所有报价员"));
	ui.datmanComBox->model()->setData(ui.datmanComBox->model()->index(0, 0), QSize(25, 25), Qt::SizeHintRole);
	for (int i = 0; i < man.size(); i++)
	{
		ui.datmanComBox->addItem(man[i][0]);
		ui.datmanComBox->model()->setData(ui.datmanComBox->model()->index(i + 1, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	connect(ui.datSortComBox, SIGNAL(activated(QString)), this, SLOT(savedatSortComBoxinfo()));     //获取当前产品类型
	connect(ui.datinquireButton, SIGNAL(clicked()), this, SLOT(inquire()));     //查询
  	connect(ui.datnextpageButton, SIGNAL(clicked()), this, SLOT(nextPage()));    //下一页
	connect(ui.datfirstpageButton, SIGNAL(clicked()), this, SLOT(firstPage()));   //第一页
	connect(ui.datprepageButton, SIGNAL(clicked()), this, SLOT(previousPage()));   //上一页
	connect(ui.datlastpageButton, SIGNAL(clicked()), this, SLOT(lastPage()));    //最后一页
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
			w->setContent(tr("文件已经成功导出!"));
			w->show();
		}
}

void TabDataOutput::Update()
{
	ui.datcompanyComBox->clear();
	ui.datcompanyComBox->addItem(tr("所有公司"));
	ui.datcompanyComBox->model()->setData(ui.datcompanyComBox->model()->index(0, 0), QSize(25, 25), Qt::SizeHintRole);
	QString inquireCompany = "select CompanyName from CompanyInfo";
	QVector<QVector<QString> > result;  //用来存放结果
	result = SqlOp::SelectQuery(inquireCompany, 1);
	for (int i = 0; i < result.size(); i++)     //初始化选择公司下拉框
	{
		ui.datcompanyComBox->addItem(result[i][0]);
		ui.datcompanyComBox->model()->setData(ui.datcompanyComBox->model()->index(i + 1, 0), QSize(25, 25), Qt::SizeHintRole);
	}
	current = 0;   //开始页为第一页
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
		page = InquireResult.size() / 6;     //一共有多少页
		row = InquireResult.size() % 6;     //最后一页有多少行
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

void TabDataOutput::savedatSortComBoxinfo()      //选择完公司后再选择产品类型
{
	ui.datNameComBox->clear();
	QString ProductType = ui.datSortComBox->currentText();    //获取当前所选的产品类别
	if (ProductType.indexOf("小") == 0)
		Sort = "1";
	else if (ProductType.indexOf("三") == 0)
		Sort = "2";
	else if (ProductType.indexOf("金") == 0)
		Sort = "3";
	else if (ProductType.indexOf("其") == 0)
	{
		if (ProductType.indexOf("砂") == 2)
			Sort = "4";
		else Sort = "6";
	}
	else if (ProductType.indexOf("圆") == 0)
		Sort = "5";
	else Sort = "7";

	if (Sort == "7")
	{
		ui.datNameComBox->addItem(tr("所有产品"));
	}
	else
	{
		QString inquireProduct = "select ProductName from ProductInfo where ProductType=?";
		QVector<QVector<QString>>result;     //用来存放查询得到的产品名称
		QVector<QString>bindValue;
		bindValue.append(Sort);
		result = SqlOp::SelectQuery(inquireProduct, 1, bindValue);
		ui.datNameComBox->addItem(tr("所有产品"));
		for (int i = 0; i < result.size(); i++)
		{
			ui.datNameComBox->addItem(result[i][0]);
		}
	}
}

void TabDataOutput::inquire()
{
	ui.dataTabWid->clearContents();    //清除所有内容不包括表头
	QString startDate = ui.datstartDateEdit->date().toString("yyyy-MM-dd");   //开始日期
	QString endDate = ui.datendDateEdit->date().toString("yyyy-MM-dd") + "23:59:59";      //结束日期
	QString CompanyName = ui.datcompanyComBox->currentText();     //公司名称
	QString ProductType = ui.datSortComBox->currentText();    //产品类别
	QString ProductName = ui.datNameComBox->currentText();     // 产品名称
	QString Man = ui.datmanComBox->currentText();    //报价员
	current = 0;   //开始页为第一页
	if (ProductType.indexOf("小") == 0)
		Sort = "1";
	else if (ProductType.indexOf("三") == 0)
		Sort = "2";
	else if (ProductType.indexOf("金") == 0)
		Sort = "3";
	else if (ProductType.indexOf("其") == 0)
	{
		if (ProductType.indexOf("砂") == 2)
			Sort = "4";
		else Sort = "6";
	}
	else if (ProductType.indexOf("圆") == 0)
		Sort = "5";
	else Sort = "7";
	if (QString::compare(CompanyName, "所有公司") == 0)   //如果选择所有公司
	{
		if (Sort == "7")    //如果选择所有产品类别
		{
			if (QString::compare(Man, "所有报价员") == 0) //如果选择所有报价员
			{
				QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=?";
				QVector<QString> bindValue;
				bindValue.append(startDate);
				bindValue.append(endDate);
				InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
			}
			else     //如果选择某一位报价员
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
			if (QString::compare(ProductName,"所有产品")== 0)  //如果选择所有产品
			{
				if (QString::compare(Man, "所有报价员") == 0)   //如果选择所有报价员
				{
					QString inquire = "select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord LEFT OUTER JOIN ProductInfo on BJRecord.ProductID=ProductInfo.ProductID where BJTime>=? and BJTime<=? and ProductInfo.ProductType=?";
					QVector<QString>bindValue;
					bindValue.append(startDate);
					bindValue.append(endDate);
					bindValue.append(Sort);
					InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
				}
				else     //如果选择某一位报价员
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
				if (QString::compare(Man, "所有报价员") == 0)   //如果选择所有报价员
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
	else    //如果选择某一家公司
	{
		if (Sort == "7")    //如果选择所有产品类别
		{
			if (QString::compare(Man, "所有报价员") == 0)    //如果选择所有报价员
			{
				QString inquire = tr("select BJTime,ProductInfo.ProductName,ProductInfo.ProductType,Length,Width,BJRecord.Price,BasicPrice,IsContact,ContactPrice,ContactTotalPrice,BJCoefficient,TotalPrice,BJMan from BJRecord")
					+ " LEFT OUTER JOIN ProductInfo on BJRecord.ProductID = ProductInfo.ProductID LEFT OUTER JOIN CompanyInfo on BJRecord.CompanyID = CompanyInfo.CompanyID  where BJTime >= ? and BJTime <= ? and CompanyInfo.CompanyName = ? ";
				QVector<QString> bindValue;
				bindValue.append(startDate);
				bindValue.append(endDate);
				bindValue.append(CompanyName);
				InquireResult = SqlOp::SelectQuery(inquire, 13, bindValue);
			}
			else    //如果选择某一位报价员
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
		else    //如果选择某一种产品类别
		{
			if (QString::compare(ProductName, "所有产品") == 0)  //如果选择某一产品类型中的所有产品
			{
				if (QString::compare(Man, "所有报价员") == 0)    //如果选择所有报价员
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
				else     //如果选择某一位报价员
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
			else    //如果选择某一类产品中的某一种产品
			{
				if (QString::compare(Man, "所有报价员") == 0)    //如果选择所有报价员
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
				else   //如果选择某一位报价员
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
		w->setContent(tr("查询成功!"));
		w->show();
	}
}
QString TabDataOutput::toHtmlStr()
{
	QString str = tr("<table border='1' cellpadding='1'>") +
		" <tr>   <td>报价时间</td>   <td>产品名称</td>   <td>产品类别</td>    <td>长度</td>   <td>宽度</td>  <td>单价(元)</td>  <td>基础价格</td>  <td>是否平接</td>  <td>平接单价</td>  <td>平接价格</td>  <td>报价系数</td>  <td>终端报价</td>  <td>报价员</td> </tr> ";
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
void TabDataOutput::addData(int currentpage)    //将数据显示到表格中
{
	QString str;
	ui.dataTabWid->clearContents();    //清除所有内容不包括表头
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
void TabDataOutput::nextPage()     //下一页
{
	addData(current);
}

void TabDataOutput::previousPage()     //上一页
{
	current = current - 2;
	addData(current);
	
}
void TabDataOutput::firstPage()      //第一页
{
	current = 0;
	addData(current);
}
void TabDataOutput::lastPage()     //最后一页
{
	current = page;
	addData(current);
}
QString TabDataOutput::judgeType(QString sort)
{
	QString type;
	if (sort == "1")
		return type = "小太阳砂带";
	else if (sort == "2")
		return type = "三菱砂带";
	else if (sort == "3")
		return type = "金牛砂带";
	else if (sort == "4")
		return type = "其他砂带";
	else if (sort == "5")
		return type = "圆盘砂";
	else if (sort == "6")
		return type = "其他产品";
}
QString TabDataOutput::judgeContact(QString IsContact)
{
	QString Contact;
	if (IsContact == "0")
		return Contact = "否";
	else return Contact = "是";
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

