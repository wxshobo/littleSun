#ifndef DELETEPRODUCT_H
#define DELETEPRODUCT_H

#include <QWidget>
#include <qpoint.h>
#include "sqlOp.h"
#include<QMouseEvent>
#include <qmessagebox.h>
#include "tipdialog.h"
#include "ui_deleteproduct.h"

class deleteproduct : public QWidget
{
	Q_OBJECT

public:
	deleteproduct(QVector<QVector<QString>>,int ,int ,QWidget *parent = 0);
	~deleteproduct();

	QVector<QVector<QString>> tempInformation;
	QVector<QVector<QString>> proInformation;
	int currentPage;
	int currentIndex;
	int result;
	int allPage;
	
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	void keyPressEvent(QKeyEvent*);          //°´¼üÊÂ¼þ
signals:
	void deleteSuccess();
private slots:
	void deleteButtonClicked();
	void cancelButtonClicked();

private:
	Ui::deleteproduct ui;

	QPoint offset;

};

#endif // DELETEPRODUCT_H
