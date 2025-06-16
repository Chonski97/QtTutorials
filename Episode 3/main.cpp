#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>

#include "calculator.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	calculator* calc = new calculator();
	calc->show();

	app.exec();
}