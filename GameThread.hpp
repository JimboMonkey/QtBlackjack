/*#ifndef THREAD_H
#define MYTHREAD_H*/

#include <QtGui>

#include "Table.hpp"
#include "Croupier.hpp"
#include "Box.hpp"

class GameThread: public QThread
{
	Q_OBJECT

	public:
		GameThread();
		~GameThread();
		void run(); // this is virtual method, we must implement it in our subclass of QThread
		void ClearScreen();
		const int CountPlayers();
		void SeatPlayers(Table& BlackJackTable, const int NumberOfPlayers);
		void CollectBets(Table& BlackJackTable);
		void InitialDeal(Table& BlackJackTable, Croupier& Dealer);
		void InsuranceOffers(Table& BlackJackTable, Croupier& Dealer);
		bool CheckForBlackJack(Table& BlackJackTable, Croupier& Dealer);
		void StateOptions(Box* CurrentBox, bool PlayersFirstGo);
		const bool PlayersPlay(Table& BlackJackTable, Croupier& Dealer);
		void DealerPlays(Croupier& Dealer);
		void RefreshPlayerList(Table& BlackJackTable);
		void SettleBets(Table& BlackJackTable, Croupier& Dealer);
		Box* NewBox(Player* pPlayer, bool Split);
		void SetChoice(int ButtonIndex);
		int CheckChoice();
		void SetBetValue(int Bet);
		int CheckBetValue();
		Table BlackJackTable;
		string NumberToString(float Number);

	private:
		int ButtonChoice;
		int myBetValue;

	private slots:
		void ChoiceMade(int ButtonIndex);
		void hello(QString LoadCardName, int CardPosition);
		void goodbye(QString LoadCardName, int CardPosition);
		void thUpdatePlayersHandValue(QString HandValue);
		void thUpdateDealersHandValue(QString HandValue);
		void thUpdateStack(QString StackValue);
		void thUpdateBet(float BetValue);
	//	void thUpdatePlayersName(QString pName);
		void RemoveFromStack(int);
		void ReturnBet(int);
		void BettingDone();
		void ClearBet();
	
	signals:
		void updateFromThread(QString);	
		void clearPlayersHand();
		void clearDealersHand();
		void updateDealersHand(QString, int);
		void updatePlayersHand(QString, int);
		void updateDealersHandValue(QString);
		void updatePlayersHandValue(QString);
		void updateStack(QString);
		void updateBet(QString);
		void IncreaseBet(float);
		void DecreaseBet(float);
	//	void updatePlayersName(QString);
		void updatePlayersStack(QString);
		void updateGameStatus(QString);
		void Choice();
		void BetDone();
		void updateStatus(QString);
		void Clearchips();
		void ButtonVisibility(bool, bool, bool, bool, bool, bool, bool, bool);
		void ResultTextVisibility(bool, bool, bool, bool);
		void HandValueSpotsVisibility();
		void updateResultsSummary(QString);
		void HideResultsSummary();
		void DisableChips(bool);
		void GameOver();
		void PlayWinSound();
		void PlayLoseSound();
};

//#endif
