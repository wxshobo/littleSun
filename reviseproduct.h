#ifndef REVISEPRODUCT_H
#define REVISEPRODUCT_H

#include <QWidget>
#include "sqlOp.h"
#include<qpoint.h>
#include<QMouseEvent>
#include <qmessagebox.h>
#include "tipdialog.h"
#include "ui_reviseproduct.h"

class reviseProduct : public QWidget
{
	Q_OBJECT

public:
	reviseProduct(QVector<QVector<QString>>,int,int,QWidget *parent = 0);
	~reviseProduct();
	QVector<QVector <QString>> sel;
	int result;
	int cur;
	int num;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent*);          //°´¼üÊÂ¼þ
	QPoint offset;

	QString m_vProductId;
	QString m_vProductNameEdit;
	float m_vProductPriceEdit;
	QString m_vProductTypeEdit;
	QString m_vProductMarkEdit;
	int allPage;
signals:
	void reviseSuccess();
private slots:
	void concleSlot();
	void confirmSlot();

private:
	Ui::reviseProduct ui;
};

#endif // REVISEPRODUCT_H
