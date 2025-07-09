#include "CustomMenu.h"
#include <QApplication>

CustomMenu::CustomMenu(QWidget* parent) : QMenu(parent)
{
	setTitle("File");

	QAction* open = new QAction("Open");
	addAction(open);

	QAction* _new = new QAction("New");
	addAction(_new);

	addSeparator();

	QAction* close = new QAction("Close");
	addAction(close);

	QObject::connect(close, &QAction::triggered, this, &CustomMenu::onClose);
}

void CustomMenu::onClose()
{
	QApplication::exit();
}