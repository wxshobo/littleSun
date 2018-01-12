#ifndef REVISEUSER_H
#define REVISEUSER_H
#include <QWidget>
#include "ui_reviseuser.h"
#include "sqlOp.h"
#include <qmessagebox.h>
#include "tipdialog.h"
class reviseuser : public QWidget
{
	Q_OBJECT

public:
	reviseuser(QVector<QVector <QString>>, int, int, QWidget *parent = 0);
	~reviseuser();
signals:
	void reviseuserfresh();

private:
	Ui::reviseuser ui;
	QVector<QVector <QString>> sel;         //存放查询结果
	int cur;                                //当前页
	int num;                                //要修改数据的行数
	int allPage;                            //总页数

	QString m_vUserId;
	QString m_vUsernameEdit;
	QString m_vUserpasswordEdit;
	QString m_vUsertypeEdit;
	QString m_vUserremarkEdit;

	QString m_vusername;             
	QString m_vuserpassword;

	private slots:
	void concleSlot();
	void confirmSlot();

};

#endif // REVISEUSER_H
