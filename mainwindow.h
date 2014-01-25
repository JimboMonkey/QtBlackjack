
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QThread>
#include <QLabel>

#include <QtGui>

#include "Table.hpp"
#include "Croupier.hpp"
#include "GameThread.hpp"

#include "ClickableLabel.hpp"
#include "dragwidget.h"

#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include <phonon/mediasource.h>
#include <phonon/videowidget.h>

namespace Ui 
{
    class MainWindow;
}

class MainWindow: public QMainWindow 
{
    Q_OBJECT

	public:
	    MainWindow(QWidget *parent = 0);
	    ~MainWindow();
		void InitialDeal();
		void InsuranceOffers();
		void ClearScreen();
		void CollectBets();
		GameThread *myThread;
		float XScalingFactor;
		float YScalingFactor;
	
	protected:
	//	void contextMenuEvent(QContextMenuEvent *event);

	private:
	    Ui::MainWindow *ui;
	//	Table BlackJackTable;
	//	Croupier Dealer;
		QLabel* array[11];
		QLabel* DealersHand[12];
		QLabel* PlayersHand[12];
		int PlayersCardsHeld;
		int DealersCardsHeld;
		int HandValue;
		QString Dealers2ndCard;
//		GameThread *myThread; // this is our thread
//		GameThread myThread;
		ClickableLabel *HitButton;
		ClickableLabel *StandButton;
		ClickableLabel *SplitButton;
		ClickableLabel *DoubleButton;
		ClickableLabel *SurrenderButton;
		ClickableLabel *YesButton; 
		ClickableLabel *NoButton; 
		ClickableLabel *DoneButton; 
		DragWidget *newSWd;
		DragWidget *newSWd2;
		DragWidget *newSWd3;
		DragWidget *newSWd4;
		DragWidget *newSWd5;
		DragWidget *myDragWidget;

		QLabel* labelBetValue;
		QLabel* labelStackValue;
		QLabel* labelGameStatus;
		QLabel* labelResultsSummary;
		QLabel* labelBetRing;
		QLabel* labelStackSpot;
		QLabel* labelBustText;
		QLabel* labelDealersBustText;
		QLabel* labelBlackjackText;
		QLabel* labelDealersBlackjackText;
		QLabel* labelPlayersHandValue;
		QLabel* labelDealersHandValue;
		QLabel* labelHandValueSpot;
		QLabel* labelDealersHandValueSpot;
		QLabel* labelResultsBubble;
		QLabel* labelStatusBubble;

		QAction *NewGame;
		QAction *ToggleSound;
		QAction *About;
		QAction *Quit;

		void createActions();
		void createMenus();
		
		QMenu *fileMenu;
		QActionGroup *alignmentGroup;
		QAction *NewGameAction;
		QAction *AboutAction;
		QAction *ToggleSoundAction;
		QAction *ExitAction;

		Phonon::MediaObject* media;

		QGroupBox* PlayersCards;
		QGroupBox* DealersCards;

	private slots:
		void updateDealersHand(QString LoadCardName, int CardPosition);
		void updatePlayersHand(QString LoadCardName, int CardPosition);
		void UpdatePlayersHandValue(QString HandValue);
		void UpdateDealersHandValue(QString HandValue);
		void updateStackValue(QString StackValue);
		void UpdateBetValue(QString BetValue);
	//	void updatePlayersName(QString PlayersName);
		void ClearPlayersHand();
		void ClearDealersHand();
		void updateGameStatus(QString Status);
		void HideButtons(bool HitVisible, bool StandVisible, bool SurrenderVisible, bool DoubleVisible, bool SplitVisible, bool YesVisible, bool NoVisible, bool DoneVisible);
		void ResultText(bool BustVisible, bool DealerBustVisible, bool BlackjackVisible, bool DealerBlackjackVisible);
		void HideHandValueSpots();
		void updateResultsSummary(QString ResultsSummary);
		void HideResultsSummary();
		void Restart();
		void DisableChips(bool ActiveState);
		void PositionYesNo();
		void PlayWinSound();
		void PlayLoseSound();
		void PlayChipSound();
		void DisplayAboutBox();
		void MakeConnections();

	signals:
		void threadStop();	

};



class Sleeper: public QThread
{
	public:
    	static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    	static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    	static void sleep(unsigned long secs){QThread::sleep(secs);}
};

#endif // MAINWINDOW_H

