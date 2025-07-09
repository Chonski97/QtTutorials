#pragma once

#include <QWidget>
#include <QObject>
#include <QString>
#include <QLineEdit>
#include <QComboBox>

#include "CustomCheckBox.h"
#include "CustomComboBox.h"
#include "CustomMenu.h"
#include "CustomTableView.h"
#include "CustomTableModel.h"
#include "CustomHeaderView.h"

class window : public QWidget {
	Q_OBJECT
public:
	window(QString const& type, QWidget* parent = nullptr);
	~window() = default;

	void initialize(QString const& type);


public slots:
	void onCheckBoxChanged(int checkState);
	void onTristateChanged(int checkState);

protected:
	QLineEdit* lineEdit = nullptr;
	CustomCheckBox* checkBox = nullptr;
	CustomComboBox* comboBox = nullptr;
	CustomMenu* menu = nullptr;
	CustomTableView* tableView = nullptr;
	CustomTableModel* tableModel = nullptr;
	CustomHeaderView* horizontalHeader = nullptr;
	CustomHeaderView* verticalHeader = nullptr;
};