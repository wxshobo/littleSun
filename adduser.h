#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include "ui_adduser.h"
#include "sqlOp.h"
#include <qmessagebox.h>
#include <qcombobox.h>
#include <QKeyEvent>
#include <qdatetime.h>
#include "tipdialog.h"
class adduser : public QWidget
{
	Q_OBJECT

public:
	adduser(QWidget *parent = 0);
	~adduser();
	void keyPressEvent(QKeyEvent *);

signals:
	void adduserfresh();

private:
	Ui::adduser ui;

	QString m_vUserEdit;
	QString m_vUsernameEdit;
	QString m_vUserpasswordEdit;
	QString m_vUsertypeEdit;

	private slots:
	void confirmSlot();
	void concleSlot();

};

#endif // ADDUSER_H
