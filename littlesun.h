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
	void keyPressEvent(QKeyEvent*);          //按键事件
	void closeEvent();

private:
	Ui::LittleSunClass ui;
	QString m_vUserName;            //姓名变量
	QString m_vUserPWD;			    //密码变量

	private slots:
	void loginBtnSlot();
	void narrowBtnSlot();
	void closeBtnSlot();

	void opentest();
};

#endif // LITTLESUN_H
