/********************************************************************************************
* ������  ��ToExcel
* �������ܣ���TableWidget������ݵ���������ΪExcel
* ��    �ߣ�
* ������ڣ�
*
* ������ʷ��
* 1������ʱ�䣺
*    �������ݣ�
*    ��    �ߣ�
***********************************************************************************************/

#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <QFileDialog>                        //Qt�������ļ��򿪺ͱ���ĶԻ���
#include <QDesktopServices>                   //QDesktopServices���ṩ�ĺ������ڷ��ʳ������������
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


