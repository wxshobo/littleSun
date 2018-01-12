#ifndef TABUSERMANAGE_H
#define TABUSERMANAGE_H
#include <QWidget>
#include "ui_tabusermanage.h"
#include "sqlOp.h"
#include <QStandardItemModel>
#include <QAbstractItemView>
#include <qmessagebox.h>
#include <qradiobutton.h>
#include <QTableWidgetItem>
#include <qbuttongroup.h>
#include "adduser.h"
#include "reviseuser.h"
#include "deleteuser.h"
#include "tipdialog.h"


class TabUserManage : public QWidget
{
	Q_OBJECT

public:
	TabUserManage(QWidget *parent = 0);
	~TabUserManage();
	void setContent(int);                               //加入单选框
	void userBtn(bool, bool, bool, bool);               //设置按钮是否可用
	void addData(int, int);                             //向表格中加入数据(页面数，行数）
	int  selectCount();                                 //返回被选中的位置
	

private:
	Ui::TabUserManage ui;

	QVector<QVector <QString>> selectTemp;              //存放临时查询结果
	QString query;                                      //存放查询语句
	QButtonGroup *buttons;                              //负责管理界面中多选按钮
	int currentPage = 0;                                //当前页初始化为0
	int allPage;                                        //总页数
	int selectedIndex;                                  //选中的行数

	private slots:
	void userfirstSlot();                               //用户管理中的按钮槽函数
	void userpreviousSlot();
	void usernextSlot();
	void userlastSlot();
	void useraddSlot();
	void userdeleteSlot();
	void userreviseSlot();
	void onCellClicked(int row, int col);               //点击任意一行，返回该行的行数
	void onRadioButtonClicked(int);                     //窗口接受焦点事件
	void addfreshen();                                  //增加数据后刷新，光标移到新加的数据（最后）
	void deletefreshen();                               // 删除数据后刷新，光标移到首页第一个数据
	void  revisefreshen();                              // 修改数据后刷新，光标移到修改数据上
	//void tabletoexcel();
};

#endif // TABUSERMANAGE_H
