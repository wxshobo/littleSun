#ifndef TABSTARTSELL_H
#define TABSTARTSELL_H
#include <QWidget>
#include "ui_tabstartsell.h"
#include "sqlOp.h"
#include"tipdialog.h"
#include <QDebug>
#include<QDatetime>
#include<QString>
#include"Parameter.h"
class TabStartSell : public QWidget
{
	Q_OBJECT

public:
	TabStartSell(QWidget *parent = 0);
	~TabStartSell();
	void Refresh();
protected:
	int isDigitStr(QString str);   //�ж��Ƿ�Ϊ��ȷ��С��
	int isDigital(QString str);       //�ж��Ƿ�Ϊ������

	private slots:
	void savestabuyEditinfo(); //���湺��λ����Ϣ
	void savestatelephoneEditinfo();  //������ϵ�绰����Ϣ
	//void savestamanEditinfo();  //������ϵ�˵���Ϣ
	void savestaphoneEditinfo();  //�����ֻ��ŵ���Ϣ
	void savestasortComBoxinfo(QString);  //��ȡ��ǰѡ��Ĳ�Ʒ���
	void savestalengthEditinfo();   //���泤��
	void savestawidthEditinfo();    //������
	void savestateChanged(int);   //�ж�ƽ��ѡ���״̬
	void savestaflatsingleEditinfo();  //��¼ƽ�ӵ�����Ϣ
	void savestamodulusEditinfo();   //��¼����ϵ��
	void savestaterminalEditinfo();   //��¼�ն˱���
	void savestanameComBoxinfo();   //��ȡ��ǰѡ��Ĳ�Ʒ����
	void ClearScreen();       //����
	void Finish();         //���
private:
	Ui::TabStartSell ui;
	QString Sort;  //Ҫ��ѯ�Ĳ�Ʒ����
	QString m_vProductId;    //��ƷID
	QString m_vtelephone;     //�绰��
	QString m_vphone;   //�ֻ���
	QString m_vContactPerson;   //��ϵ��
	QString m_vCompanyName;    //��˾����
	bool m_vFlag = 0;  //�жϹ���λ�����ݿ����Ƿ��Ѿ�����
	bool m_vTemp = 0;   //�ж��Ƿ�ƽ��
	float FlatPrice;    //ƽ�Ӽ۸�
};

#endif // TABSTARTSELL_H
