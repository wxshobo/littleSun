#pragma execution_character_set("utf-8")
#include "deleteuser.h"

deleteuser::deleteuser(QVector<QVector <QString>> del, int current, int number,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::SplashScreen);                    //没有菜单栏
	connect(ui.confirmBtn, SIGNAL(clicked()), this, SLOT(confirmBtnSlot()));     //确认按钮槽函数
	connect(ui.concleBtn, SIGNAL(clicked()), this, SLOT(concleBtnSlot()));
	deleteTemp = del;
	cur = current;
	num = number;
	allPage = deleteTemp.size() / 7;

}

deleteuser::~deleteuser()
{

}

void deleteuser::concleBtnSlot()
{
	this->close();
}



void deleteuser::confirmBtnSlot()
{
	if (deleteTemp.size() <= 1)
	{
		this->close();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("至少需要一个用户，删除失败"));
		w->show();
	}
	else
	{

		int i;
		QVector<QVariant> bindValue;
		bindValue.append(deleteTemp[cur * 7 + num][0]);                //num:页面中被选中的第几个，可以知道将要删除的用户ID
		QString del = "delete from UserInfo where UserId=?";
		int result = SqlOp::Delete_UpdateQuery(del, bindValue);
		if (result == 1)
		{
			this->close();
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("删除用户成功"));
			w->show();
			//	QMessageBox::information(NULL, "提示", "删除用户成功");

			emit deleteuserfresh();                                //如果删除成功，则刷新，并将光标移到首页第一个位置
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("删除用户失败"));
			w->show();
			//	QMessageBox::information(NULL, "提示", "删除用户失败");
		}
	}
}
