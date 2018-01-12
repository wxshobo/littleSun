#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QWidget>
#include "ui_deleteuser.h"
#include <qmessagebox.h>
#include <qbuttongroup.h>
#include <qdebug.h>
#include "sqlOp.h"
#include "tipdialog.h"
class deleteuser : public QWidget
{
	Q_OBJECT

public:
	deleteuser(QVector<QVector <QString>>, int, int, QWidget *parent = 0);
	~deleteuser();

signals:
	void deleteuserfresh();
private:
	Ui::deleteuser ui;
	QVector<QVector <QString>> deleteTemp;     //存放查询结果
	int allPage;                               //页面总数
	int cur;								   //当前页
	int num = 0;                               //删除页面中的第几个
	int flag = 0;                              // 页面中是否有记录被选中

	private slots:
	void confirmBtnSlot();
	void concleBtnSlot();


};

#endif // DELETEUSER_H
