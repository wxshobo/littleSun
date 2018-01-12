#ifndef TABDATAOUTPUT_H
#define TABDATAOUTPUT_H

#include <QWidget>
#include "ui_tabdataoutput.h"
#include"tipdialog.h"
#include"sqlOp.h"
#include"tabdataoutput.h"
#include <QDesktopServices>
class TabDataOutput : public QWidget
{
	Q_OBJECT

public:
	TabDataOutput(QWidget *parent = 0);
	~TabDataOutput();
	void Update();    //����

	private slots:
	void savedatSortComBoxinfo();      //��ȡ��Ʒ����
	void inquire();     //��ѯ
	void previousPage();   //��һҳ
	void nextPage();    //��һҳ
	void firstPage();   //��һҳ
	void lastPage();    //���һҳ
	void Output();    //����

	
protected:
	void addData(int currentpage);    //����ǰҳ��������ʾ����
	void ButtonPosition(bool first, bool pre, bool next, bool last);
	QString judgeType(QString sort);    //�жϲ�Ʒ�����ĸ���Ʒ����
	QString judgeContact(QString IsContact);   //�ж��Ƿ�ƽ��
	QString toHtmlStr();
private:
	QString Sort;   //��¼��Ʒ�����
	int page;   //��¼ҳ��
	int current;   //��ǰ��ʾ��ҳ��
	int row;    //һ���ж�����
	QVector<QVector<QString>> InquireResult;   //��ѯ���
	Ui::TabDataOutput ui;

};

#endif // TABDATAOUTPUT_H
