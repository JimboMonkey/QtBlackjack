
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt includes
#include <QMainWindow>
#include <QGroupBox>
#include <QMessageBox>
#include <QThread>
#include <QLabel>

#include <QtGui>

#include "Table.hpp"
#include "Croupier.hpp"
#include "GameThread.hpp"

#include "ClickableLabel.hpp"
#include "ChipPile.hpp"

#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>

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
		float XScale;
		float YScale;
	
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
		ChipPile *FivePile;
		ChipPile *TenPile;
		ChipPile *TwentyFivePile;
		ChipPile *FiftyPile;
		ChipPile *HundredPile;
		ChipPile *BettingPile;

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

		QSignalMapper *AboutBoxMapper;
		QWidget *AboutBox;
	    QVBoxLayout *AboutLayout;
	    QHBoxLayout *TextLayout;
	    QHBoxLayout *ButtonLayout;
		QVBoxLayout *PicLayout;
		QLabel *labelAboutPicture;
		QLabel *labelAbout;
		QString AboutBoxText;
		QPushButton *OKButton;
		QPushButton *LicenceButton;
		QPushButton *CreditsButton;
		QPushButton *AboutButton;

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

		Phonon::MediaObject* SoundFX;

		QGroupBox* PlayersCards;
		QGroupBox* DealersCards;

	    QSignalMapper *ButtonMapping;

	private slots:
		void UpdateDealersHand(QString LoadCardName, int CardPosition);
		void UpdatePlayersHand(QString LoadCardName, int CardPosition);
		void UpdatePlayersHandValue(QString HandValue);
		void UpdateDealersHandValue(QString HandValue);
		void UpdateStackValue(QString StackValue);
		void UpdateBetValue(QString BetValue);
		void ClearPlayersHand();
		void ClearDealersHand();
		void UpdateGameStatus(QString Status);
		void HideButtons(bool HitVisible, bool StandVisible, bool SurrenderVisible, bool DoubleVisible, bool SplitVisible, bool YesVisible, bool NoVisible, bool DoneVisible);
		void ResultText(bool BustVisible, bool DealerBustVisible, bool BlackjackVisible, bool DealerBlackjackVisible);
		void HideHandValues();
		void UpdateResultsSummary(QString ResultsSummary);
		void EnableChips(bool ActiveState);
		void HandleEndGame();
		void PlayWinSound();
		void PlayLoseSound();
		void PlayChipSound();
		void DisplayAboutBox();
		void MakeConnections();
		void ChangeAboutBoxText(int TextSet);

	signals:
		void threadStop();	

};

#endif

