#include "ui_calculator.h"
#include "calculator.h"

#include <QButtonGroup>

calculator::calculator(QWidget* parent) : QWidget(parent) 
{
	initializeCalculator();
}

void calculator::initializeCalculator()
{
	ui = new Ui::calculator();
	ui->setupUi(this);

	ui->outputLineEdit->setText("");

	setWindowTitle("Calculator");

	operand = "";

	QObject::connect(ui->numbersButtonGroup, &QButtonGroup::buttonClicked, this, &calculator::onNumberPressed);
	QObject::connect(ui->functionsButtonGroup, &QButtonGroup::buttonClicked, this, &calculator::onFunctionPressed);
}

void calculator::executeOperation()
{
	if (operand == "/" && constants.back() == 0) { // Cannot divide by zero
		return;
	}

	if (operand == "-") {
		result = constants.front() - constants.back();
	}
	else if (operand == "/") {
		result = constants.front() / constants.back();
	}
	else if (operand == "X") {
		result = constants.front() * constants.back();
	}
	else if (operand == "+") {
		result = constants.front() + constants.back();
	}

	ui->outputLineEdit->setText(QString::fromStdString(std::to_string(result)));
	constants.clear();
	operand.clear();
}

void calculator::onNumberPressed(QAbstractButton* button)
{
	auto value = std::stoi(button->text().toStdString());
	auto text = ui->outputLineEdit->text();

	if (text.isEmpty() && value == 0) {
		return;
	}

	text = text + QString::fromStdString(std::to_string(value));
	ui->outputLineEdit->setText(text);
}

void calculator::onFunctionPressed(QAbstractButton* button)
{
	if (button->text() == '=') { // equals executes the function
		if (constants.size() == 1) {
			auto text = ui->outputLineEdit->text();
			auto val = text.toStdString().substr(text.toStdString().find(operand) + 1);
			if (!val.empty()) {
				constants.push_back(std::stod(val));
				executeOperation();
			}
		}
	}
	else if (button->text() == 'C') { // clears the board and values
		operand.clear();
		constants.clear();
		ui->outputLineEdit->clear();
	}
	else if (operand.empty() && !ui->outputLineEdit->text().isEmpty()) { // Guarantees there is a value to operate on
		QString output = ui->outputLineEdit->text();
		if (button->text() == '-') {
			output = output + '-';
			operand = '-';
		}
		else if (button->text() == '/') {
			output = output + '/';
			operand = '/';
		}
		else if (button->text() == 'X') {
			output = output + 'X';
			operand = 'X';
		}
		else if (button->text() == '+') {
			output = output + '+';
			operand = '+';
		}
		constants.push_back(std::stod(output.toStdString()));
		ui->outputLineEdit->setText(output);
	}

}