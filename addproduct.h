#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include <QWidget>
#include<QMouseEvent>
#include <qmessagebox.h>
#include<qpoint.h>
#include "ui_addproduct.h"
#include "tipdialog.h"
#include "ui_tabproductmanage.h"

class AddProduct : public QWidget
{
	Q_OBJECT

public:
	AddProduct(QWidget *parent = 0);
	~AddProduct();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	void keyPressEvent(QKeyEvent*);          //按键事件

signals:
	void addSuccess();
private slots:
	void closeButtonClicked();
	void finishButtonClicked();

private:
	QPoint offset;

	QVector<QVector<QString> > proInformation;//保存数据库查询到的信息

	QString m_vProductID;					  //产品ID
	QString m_vProductNameEdit;				  //产品名称
	QString m_vProductTypeEdit;				  //产品类型
	float m_vProductPriceEdit;				  //产品单价
	QString m_vProductMarkEdit;				  //备注

	int allPage;							  //所有页数
	int currentPage;						  //当前页面
	Ui::addProduct ui;
	
};

#endif // ADDPRODUCT_H
