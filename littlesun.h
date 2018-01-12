#ifndef LITTLESUN_H
#define LITTLESUN_H
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "ui_littlesun.h"
#include <QObject.h>
#include <QSqlQuery>
#include <qmessagebox.h>
#include "homepage.h"
#include <QDesktopWidget>
#include <qdatetime.h>
#include "tipdialog.h"

class LittleSun : public QWidget
{
	Q_OBJECT

public:
	LittleSun(QWidget *parent = 0);
	~LittleSun();
	void keyPressEvent(QKeyEvent*);          //�����¼�
	void closeEvent();

private:
	Ui::LittleSunClass ui;
	QString m_vUserName;            //��������
	QString m_vUserPWD;			    //�������

	private slots:
	void loginBtnSlot();
	void narrowBtnSlot();
	void closeBtnSlot();

	void opentest();
};

#endif // LITTLESUN_H
