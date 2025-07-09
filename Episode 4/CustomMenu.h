#pragma once

#include <QMenu>

class CustomMenu : public QMenu {
	Q_OBJECT
public:
	CustomMenu(QWidget* parent = nullptr);
	~CustomMenu() = default;

public slots:
	void onClose();
};