/********************************************************************************************
* 类名称  ：ToExcel
* 基本功能：将TableWidget表格内容导出并保存为Excel
* 作    者：
* 完成日期：
*
* 更新历史：
* 1，更新时间：
*    更新内容：
*    作    者：
***********************************************************************************************/

#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <QFileDialog>                        //Qt中用于文件打开和保存的对话框
#include <QDesktopServices>                   //QDesktopServices类提供的函数用于访问常见的桌面服务
#include <QMessageBox>
#include <qtextstream>
#include "tipdialog.h"
#include <qobject.h>
class ToExcel
{
private:
	QString fn;
public:
	bool Table2Excel(QString str)
	{
		fn = QFileDialog::getSaveFileName(NULL, "Save as...", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "EXCEL files(*.xls *.xlsx)");
		if (fn.isEmpty())
			return false;
		else
		{
			QFile index(fn);
			if (index.open(QFile::WriteOnly | QIODevice::Text))
			{
				QTextStream out(&index);
				//out<< ui.textEdit->document()->toHtml();
				out << str;
				return true;
			}
		}
	}

	void message()
	{
		QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fn)));
	}
};


