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
	void setContent(int);                               //���뵥ѡ��
	void userBtn(bool, bool, bool, bool);               //���ð�ť�Ƿ����
	void addData(int, int);                             //�����м�������(ҳ������������
	int  selectCount();                                 //���ر�ѡ�е�λ��
	

private:
	Ui::TabUserManage ui;

	QVector<QVector <QString>> selectTemp;              //�����ʱ��ѯ���
	QString query;                                      //��Ų�ѯ���
	QButtonGroup *buttons;                              //�����������ж�ѡ��ť
	int currentPage = 0;                                //��ǰҳ��ʼ��Ϊ0
	int allPage;                                        //��ҳ��
	int selectedIndex;                                  //ѡ�е�����

	private slots:
	void userfirstSlot();                               //�û������еİ�ť�ۺ���
	void userpreviousSlot();
	void usernextSlot();
	void userlastSlot();
	void useraddSlot();
	void userdeleteSlot();
	void userreviseSlot();
	void onCellClicked(int row, int col);               //�������һ�У����ظ��е�����
	void onRadioButtonClicked(int);                     //���ڽ��ܽ����¼�
	void addfreshen();                                  //�������ݺ�ˢ�£�����Ƶ��¼ӵ����ݣ����
	void deletefreshen();                               // ɾ�����ݺ�ˢ�£�����Ƶ���ҳ��һ������
	void  revisefreshen();                              // �޸����ݺ�ˢ�£�����Ƶ��޸�������
	//void tabletoexcel();
};

#endif // TABUSERMANAGE_H
