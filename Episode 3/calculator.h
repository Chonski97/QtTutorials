#pragma once

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
	class calculator;
}

class calculator : public QWidget {
	Q_OBJECT

public:
	calculator(QWidget* parent = nullptr);
	~calculator() = default;

	void initializeCalculator();
	void executeOperation();

public slots:
	void onNumberPressed(QAbstractButton*);
	void onFunctionPressed(QAbstractButton*);

protected:
	Ui::calculator* ui;
	double result;
	std::vector<double> constants;
	std::string operand;
};