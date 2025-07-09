#pragma once

#include <QWidget>
#include <QComboBox>
#include <QPaintEvent>

class CustomComboBox : public QComboBox {
	Q_OBJECT
public:
	CustomComboBox(QStringList data = QStringList(), QWidget* parent = nullptr);
	~CustomComboBox() = default;

	void paintEvent(QPaintEvent* event) override;
};