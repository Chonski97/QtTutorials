#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	QMainWindow* mainWindow = new QMainWindow();
	mainWindow->setMinimumSize(QSize(400, 400));

	mainWindow->setWindowTitle("First Application Window");

	QLabel* label = new QLabel();
	label->setText("Hello World!");
	label->setAlignment(Qt::AlignCenter);

	QPushButton* btn = new QPushButton();
	btn->setText("Push Me!");

	QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom);
	layout->addWidget(label);
	layout->addWidget(btn);
	layout->setEnabled(true);

	QWidget* widget = new QWidget();
	widget->setLayout(layout);


	// Lambda operators in Qt
	QObject::connect(btn, &QPushButton::pressed, [=]() {
		if (label->palette().color(QPalette::WindowText) == QColor(Qt::red)) {
			label->setStyleSheet("color: white; font-weight: normal; font-size: 12px;");
		}
		else {
			label->setStyleSheet("color: red; font-weight: bold; font-size: 50px;");
		}
		});

	mainWindow->setCentralWidget(widget);
	mainWindow->show();

	app.exec();
}