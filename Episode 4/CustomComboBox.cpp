#include "CustomComboBox.h"

CustomComboBox::CustomComboBox(QStringList data, QWidget* parent) : QComboBox(parent)
{
	for (auto& item : data) {
		addItem(item);
	}
}

void CustomComboBox::paintEvent(QPaintEvent* event)
{
	QComboBox::paintEvent(event);

	if (currentText() == "Red") {
		setStyleSheet("color: red;");
	}
	else if (currentText() == "White") {
		setStyleSheet("color: white;");
	}
	else if (currentText() == "Blue") {
		setStyleSheet("color: blue;");
	}
}