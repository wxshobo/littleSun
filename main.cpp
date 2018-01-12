#include "littlesun.h"
#include <QtWidgets/QApplication>
#include "sqlOp.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SqlOp::CreateConnection("", "LittleSun.db", "", "");
	LittleSun w;
	w.show();
	//HomePage h;
	//h.show();
	return a.exec();
}
