
#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QIcon>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setApplicationName("Blackjack");
    MainWindow window;
	
  /*  QPixmap pixmap("Background4.png");
    QPalette p = window.palette();
    p.setBrush(QPalette::Base, pixmap);
    window.setPalette(p);
    window.resize(25, 15);
    window.resize(pixmap.size());*/

	QRect Screen = QApplication::desktop()->screenGeometry();
	qDebug() << "Screen width =" << Screen.width() << "\nScreen height =" << Screen.height();

	float XScalingFactor = Screen.width() / 1920.0;
	float YScalingFactor = Screen.height() / 1080.0;

	window.setGeometry(300*XScalingFactor, 100*YScalingFactor, 604*XScalingFactor, 812*YScalingFactor);
	window.setFixedSize(604*XScalingFactor, 812*YScalingFactor);

/*	if(Screen.width() >= 1920)
	{
		window.setGeometry(300, 100, 604, 812);
		window.setFixedSize(604, 812);
	}
	else
	{
		window.setGeometry(300, 100, 322, 577);
		window.setFixedSize(322, 577);
	}*/

    window.setWindowTitle("Blackjack");
    window.setWindowIcon(QIcon("Icon.png"));
    window.setStyleSheet("MainWindow {border-image: url(Background4.png)}");
    window.setCursor(Qt::OpenHandCursor);
    window.show();
	return app.exec();
}

