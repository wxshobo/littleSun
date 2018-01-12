#ifndef TABPRODUCTMANAGE_H
#define TABPRODUCTMANAGE_H

#include <QWidget>
#include "ui_tabproductmanage.h"
#include <qmessagebox.h>
#include "addproduct.h"
#include "deleteproduct.h"
#include "sqlOp.h"
#include "tipdialog.h"

class TabProductManage : public QWidget
{
	Q_OBJECT

public:
	TabProductManage(QWidget *parent = 0);
	~TabProductManage();
	 
	void proBtn(bool, bool, bool, bool);//���ð�ť�Ƿ�ɵ��
	void addDate(int, int);             //�����м������ݣ���ҳ������������
	int  selectCount();                 //���ر�ѡ�е�λ��
	void setContent(int);               //�ӵ�ѡ��
	void findSql();

public slots:
	
	void firstPageClicked();            //�����һҳ
	void previousPageClicked();         //�����һҳ
	void nextPageClicked();             //�����һҳ
	void lastPageClicked();             //������һҳ
	void addPageClicked();              //����ҳ
	void delPageClicked();              //ɾ����¼
	void updatePageClicked();           //�޸ļ�¼
	void onCellClicked(int,int);        //���ĳ��

	void onRadioButtonClicked(int);

	void addfresh();                    //��Ӻ�ˢ��
	void deletefresh();					//ɾ����ˢ��
	void revisefresh();					//�޸ĺ�ˢ��

private:
	Ui::TabProductManage ui;
	QVector<QVector <QString>> proInformation;//�������ݿ��ѯ������Ϣ
	int allPage;                              //����ҳ��
	int currentPage;                          //��ǰҳ��
	int selectedIndex;						  //��ѡ�е�����
	int number;								  //������ڵ���

	QButtonGroup *buttons;                    //�������н����е�ѡ��ť
	
	static QString proID;                     //��������û��ڿ�ʼ���ʱѡ�еĲ�Ʒ��ID��

};

#endif // TABPRODUCTMANAGE_H
