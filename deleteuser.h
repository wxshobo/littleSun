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
	QVector<QVector <QString>> deleteTemp;     //��Ų�ѯ���
	int allPage;                               //ҳ������
	int cur;								   //��ǰҳ
	int num = 0;                               //ɾ��ҳ���еĵڼ���
	int flag = 0;                              // ҳ�����Ƿ��м�¼��ѡ��

	private slots:
	void confirmBtnSlot();
	void concleBtnSlot();


};

#endif // DELETEUSER_H
