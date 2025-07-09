#pragma once

#include <QCheckBox>

class CustomCheckBox : public QCheckBox {
	Q_OBJECT
public:
	CustomCheckBox(QWidget* parent = nullptr);
	CustomCheckBox(QString const& text, QWidget* parent = nullptr);
	~CustomCheckBox() = default;
};