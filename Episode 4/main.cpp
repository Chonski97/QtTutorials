#include <QApplication>
#include <QMainWindow>
#include <QCheckBox>
#include <QMenuBar>
#include <QPushButton>
#include <QBoxLayout>
#include <QLabel>
#include <QIcon>
#include <QFont>

#include "window.h"
#include "CustomMenu.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	QMainWindow* mainWindow = new QMainWindow();

	/*QMenuBar bar;
	auto menu = new CustomMenu();
	bar.insertMenu(new QAction(), menu);
	mainWindow->setMenuBar(&bar);
	mainWindow->show();*/

	window* win = new window("QTable");
	win->show();


	app.exec();
}