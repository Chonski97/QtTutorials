#include "window.h"

#include <QBoxLayout>
#include <iostream>

window::window(QString const& type, QWidget* parent)
{
	initialize(type);
}


void window::initialize(QString const& type)
{
	QVBoxLayout* verticalLayout = new QVBoxLayout();
	verticalLayout->setAlignment(Qt::AlignCenter);

	setLayout(verticalLayout);

	if (type == "QCheckBox") {
		checkBox = new CustomCheckBox("Enable/Disable");
		lineEdit = new QLineEdit();
		lineEdit->setEnabled(false);
		verticalLayout->addWidget(lineEdit);
		verticalLayout->addWidget(checkBox);
		auto isTristateCheckBox = new CustomCheckBox("Set Tristate");
		verticalLayout->addWidget(isTristateCheckBox);


		QObject::connect(checkBox, &QCheckBox::stateChanged, this, &window::onCheckBoxChanged);
		QObject::connect(isTristateCheckBox, &QCheckBox::stateChanged, this, &window::onTristateChanged);
	}
	else if (type == "QComboBox") {
		QStringList data = { "Red", "White", "Blue" };
		comboBox = new CustomComboBox(data);
		comboBox->repaint();
		verticalLayout->addWidget(comboBox);
	}
	else if (type == "QMenu") {
		menu = new CustomMenu();
		verticalLayout->setMenuBar(menu);
	}
	else if (type == "QTable") {
		tableView = new CustomTableView();
		horizontalHeader = new CustomHeaderView(Qt::Horizontal);
		tableView->setHorizontalHeader(horizontalHeader);
		verticalHeader = new CustomHeaderView(Qt::Vertical);
		tableView->setVerticalHeader(verticalHeader);
		tableModel = new CustomTableModel();
		tableView->setModel(tableModel);
		verticalLayout->addWidget(tableView);
	}
}

void window::onCheckBoxChanged(int checkState)
{
	switch (checkState) {
	case 0: {
		lineEdit->setEnabled(false);
		lineEdit->show();
		break;
	}
	case 1: {
		lineEdit->hide();
		break;
	}
	case 2: {
		lineEdit->setEnabled(true);
		lineEdit->show();
		break;
	}
	}
}


void window::onTristateChanged(int checkState)
{
	switch (checkState) {
	case 0: {
		checkBox->setText("Enable/Disable");
		checkBox->setTristate(false);
		break;
	}
	case 2: {
		checkBox->setText("Hide/Enable/Disable");
		checkBox->setTristate(true);		
		break;
	}
	}
}