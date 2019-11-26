#include "TestCRSDll.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestCRSDll w;
	w.show();
	return a.exec();
}
