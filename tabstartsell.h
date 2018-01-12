#ifndef TABSTARTSELL_H
#define TABSTARTSELL_H
#include <QWidget>
#include "ui_tabstartsell.h"
#include "sqlOp.h"
#include"tipdialog.h"
#include <QDebug>
#include<QDatetime>
#include<QString>
#include"Parameter.h"
class TabStartSell : public QWidget
{
	Q_OBJECT

public:
	TabStartSell(QWidget *parent = 0);
	~TabStartSell();
	void Refresh();
protected:
	int isDigitStr(QString str);   //判断是否为正确的小数
	int isDigital(QString str);       //判断是否为纯数字

	private slots:
	void savestabuyEditinfo(); //保存购买单位的信息
	void savestatelephoneEditinfo();  //保存联系电话的信息
	//void savestamanEditinfo();  //保存联系人的信息
	void savestaphoneEditinfo();  //保存手机号的信息
	void savestasortComBoxinfo(QString);  //获取当前选择的产品类别
	void savestalengthEditinfo();   //保存长度
	void savestawidthEditinfo();    //保存宽度
	void savestateChanged(int);   //判断平接选项的状态
	void savestaflatsingleEditinfo();  //记录平接单价信息
	void savestamodulusEditinfo();   //记录报价系数
	void savestaterminalEditinfo();   //记录终端报价
	void savestanameComBoxinfo();   //获取当前选择的产品名称
	void ClearScreen();       //清屏
	void Finish();         //完成
private:
	Ui::TabStartSell ui;
	QString Sort;  //要查询的产品类型
	QString m_vProductId;    //产品ID
	QString m_vtelephone;     //电话号
	QString m_vphone;   //手机号
	QString m_vContactPerson;   //联系人
	QString m_vCompanyName;    //公司名称
	bool m_vFlag = 0;  //判断购买单位在数据库中是否已经存在
	bool m_vTemp = 0;   //判断是否平接
	float FlatPrice;    //平接价格
};

#endif // TABSTARTSELL_H
