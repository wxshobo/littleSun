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
	QVector<QVector <QString>> sel;         //��Ų�ѯ���
	int cur;                                //��ǰҳ
	int num;                                //Ҫ�޸����ݵ�����
	int allPage;                            //��ҳ��

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
