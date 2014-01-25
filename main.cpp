
#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QIcon>

int main(int argc, char *argv[])
{
	// Create the application and window and name it
	QApplication app(argc, argv);
    MainWindow window;
	
	// Find out the user's screen resolution
	QRect Screen = QApplication::desktop()->screenGeometry();
	qDebug() << "Screen width =" << Screen.width() << "\nScreen height =" << Screen.height();

	// Set the window geometry using the calculated scaling factors
	if(Screen.width() >= 1920)
	{
		window.setGeometry(300, 100, 604, 812);
		window.setFixedSize(604, 812);
	}
	// User using resolution lower than that used for development
	else
	{
		// Calculate the scaling factors from the resolution
		float XScalingFactor = Screen.width() / 1920.0;
		float YScalingFactor = Screen.height() / 1080.0;

		window.setGeometry(300*XScalingFactor, 100*YScalingFactor, 604*XScalingFactor, 812*YScalingFactor);
		window.setFixedSize(604*XScalingFactor, 812*YScalingFactor);
	}

	// Setup the window name, icon, cursor, and background
    window.setWindowTitle("Blackjack");
    window.setWindowIcon(QIcon("Icon.png"));
    window.setStyleSheet("MainWindow {border-image: url(Background4.png)}");
    window.setCursor(Qt::OpenHandCursor);
    window.show();
	return app.exec();
}

