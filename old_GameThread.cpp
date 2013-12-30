
#include <iostream>
#include <vector>
#include <sstream>

#include "GameThread.hpp"

using namespace std;

#define MinimumBet 5

GameThread::GameThread()
{
}

GameThread::~GameThread()
{
}

/* Use ANSI escape codes to clear the screen */
void GameThread::ClearScreen()
{
	cout << "\033[2J\033[2;1H";
}

/* Return the number of players */
const int GameThread::CountPlayers()
{
	string UserEntry;
	int NumberOfPlayers;

	/* Ensure the user enters a valid number (loop question until they do) */
	do
	{
		ClearScreen();
		cout << "How many players? (1 - 7)" << endl;
		getline(cin, UserEntry);
		stringstream StrToInt(UserEntry); 
		StrToInt >> NumberOfPlayers;
		/* Number must be between 1 and 7 and only 1 character long */
	}while(!(NumberOfPlayers > 0 && NumberOfPlayers < 8 && UserEntry.size() == 1));
	
	return NumberOfPlayers;
}








void GameThread::xhumos(QString LoadCardName)
{
	cout << "hello!" << endl;
	emit monkeys(LoadCardName);
}






void GameThread::run()
{
	/* Create table object */
	Table BlackJackTable;



	/* Create a dealer object which generates a shoe of cards which are then shuffled */
	Croupier Dealer;

	connect(&Dealer, SIGNAL(updatePlayersHand(QString)), this, SLOT(xhumos(QString)));


	/*qDebug() << "Executing in new independant thread, GUI is NOT blocked";
		
	emit disCommand();

	for(int i = 0; i < 10; i++)
	{
		qDebug() << "Time: " << 10 - i;	

		int t = 1;

		//ui->labelStack->setText(QString::number(i));

		// some OS specific stuff
		// mingw (3.4.2) sleep on windows is called _sleep and uses microseconds
		//#ifdef Q_OS_WIN32
		//t = t * 1000;
		//_sleep(t);
		//#else

		//Emit a SIGNAL with a message
		emit updateFromThread(QString("Iteration Done: ")+QString::number(i)+QString("\n"));

		//sleep(t);
		//#endif
	}
	
	qDebug() << "Execution done";
	
	emit enaCommand();
	//exec();*/
}




