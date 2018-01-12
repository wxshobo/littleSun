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

	void keyPressEvent(QKeyEvent*);          //�����¼�

signals:
	void addSuccess();
private slots:
	void closeButtonClicked();
	void finishButtonClicked();

private:
	QPoint offset;

	QVector<QVector<QString> > proInformation;//�������ݿ��ѯ������Ϣ

	QString m_vProductID;					  //��ƷID
	QString m_vProductNameEdit;				  //��Ʒ����
	QString m_vProductTypeEdit;				  //��Ʒ����
	float m_vProductPriceEdit;				  //��Ʒ����
	QString m_vProductMarkEdit;				  //��ע

	int allPage;							  //����ҳ��
	int currentPage;						  //��ǰҳ��
	Ui::addProduct ui;
	
};

#endif // ADDPRODUCT_H
