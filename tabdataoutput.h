#ifndef TABDATAOUTPUT_H
#define TABDATAOUTPUT_H

#include <QWidget>
#include "ui_tabdataoutput.h"
#include"tipdialog.h"
#include"sqlOp.h"
#include"tabdataoutput.h"
#include <QDesktopServices>
class TabDataOutput : public QWidget
{
	Q_OBJECT

public:
	TabDataOutput(QWidget *parent = 0);
	~TabDataOutput();
	void Update();    //更新

	private slots:
	void savedatSortComBoxinfo();      //获取产品类型
	void inquire();     //查询
	void previousPage();   //上一页
	void nextPage();    //下一页
	void firstPage();   //第一页
	void lastPage();    //最后一页
	void Output();    //导出

	
protected:
	void addData(int currentpage);    //将当前页的数据显示出来
	void ButtonPosition(bool first, bool pre, bool next, bool last);
	QString judgeType(QString sort);    //判断产品属于哪个产品类型
	QString judgeContact(QString IsContact);   //判断是否平接
	QString toHtmlStr();
private:
	QString Sort;   //记录产品的类别
	int page;   //记录页数
	int current;   //当前显示的页数
	int row;    //一共有多少行
	QVector<QVector<QString>> InquireResult;   //查询结果
	Ui::TabDataOutput ui;

};

#endif // TABDATAOUTPUT_H
