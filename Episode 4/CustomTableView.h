#pragma once

#include <QTableView>

class CustomTableView : public QTableView {
	Q_OBJECT
public:
	CustomTableView(QWidget* parent = nullptr);
	~CustomTableView() = default;
};