#include <QApplication>
#include <QMainWindow>
#include <QLabel>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	QMainWindow* mainWindow = new QMainWindow();
	mainWindow->setMinimumSize(QSize(400, 400));

	mainWindow->setWindowTitle("First Application Window");

	QLabel* label = new QLabel();
	label->setText("Hello World!");
	label->setAlignment(Qt::AlignCenter);

	mainWindow->setCentralWidget(label);

	mainWindow->show();

	app.exec();
}