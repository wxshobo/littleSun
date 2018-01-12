#ifndef TABPRODUCTMANAGE_H
#define TABPRODUCTMANAGE_H

#include <QWidget>
#include "ui_tabproductmanage.h"
#include <qmessagebox.h>
#include "addproduct.h"
#include "deleteproduct.h"
#include "sqlOp.h"
#include "tipdialog.h"

class TabProductManage : public QWidget
{
	Q_OBJECT

public:
	TabProductManage(QWidget *parent = 0);
	~TabProductManage();
	 
	void proBtn(bool, bool, bool, bool);//设置按钮是否可点击
	void addDate(int, int);             //向表格中加入数据：（页面数，行数）
	int  selectCount();                 //返回被选中的位置
	void setContent(int);               //加单选框
	void findSql();

public slots:
	
	void firstPageClicked();            //点击第一页
	void previousPageClicked();         //点击上一页
	void nextPageClicked();             //点击下一页
	void lastPageClicked();             //点击最后一页
	void addPageClicked();              //增加页
	void delPageClicked();              //删除记录
	void updatePageClicked();           //修改记录
	void onCellClicked(int,int);        //点击某行

	void onRadioButtonClicked(int);

	void addfresh();                    //添加后刷新
	void deletefresh();					//删除后刷新
	void revisefresh();					//修改后刷新

private:
	Ui::TabProductManage ui;
	QVector<QVector <QString>> proInformation;//保存数据库查询到的信息
	int allPage;                              //所有页面
	int currentPage;                          //当前页面
	int selectedIndex;						  //被选中的行数
	int number;								  //光标所在的行

	QButtonGroup *buttons;                    //负责所有界面中单选按钮
	
	static QString proID;                     //用来存放用户在开始检测时选中的产品的ID号

};

#endif // TABPRODUCTMANAGE_H
