#ifndef GAMETHREAD_H
#define GAMETHREAD_H

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
		void MySleep(int Seconds);
		void SeatPlayers(Table& BlackJackTable);
		void CollectBets();
		void InitialDeal(Table& BlackJackTable, Croupier& Dealer);
		void InsuranceOffers(Table& BlackJackTable, Croupier& Dealer);
		bool CheckForBlackJack(Table& BlackJackTable, Croupier& Dealer);
		void StateOptions(Box* CurrentBox, bool PlayersFirstGo);
		bool PlayersPlay(Table& BlackJackTable, Croupier& Dealer);
		void DealerPlays(Croupier& Dealer);
		void RefreshPlayerList(Table& BlackJackTable);
		void SettleBets(Table& BlackJackTable, Croupier& Dealer);
		Box* NewBox(Player* pPlayer, bool Split);
		int CheckChoice();
		void SetBetValue(int Bet);
		int CheckBetValue();
		Table BlackJackTable;
		string NumberToString(float Number);

	private:
		int ButtonChoice;

	private slots:
		void ChoiceMade(int ButtonIndex);
		void ReturnBet(int);
	
	signals:
		void ClearPlayersHand();
		void ClearDealersHand();
		void UpdateDealersHand(QString, int);
		void UpdatePlayersHand(QString, int);
		void UpdateDealersHandValue(QString);
		void UpdatePlayersHandValue(QString);
		void UpdateStackValue(QString);
		void UpdateBetValue(QString);
		void IncreaseBet(float);
		void DecreaseBet(float);
		void UpdateGameStatus(QString);
		void Choice();
		void BetDone();
		void ClearChips();
		void ButtonVisibility(bool, bool, bool, bool, bool, bool, bool, bool);
		void ResultTextVisibility(bool, bool, bool, bool);
		void UpdateResultsSummary(QString);
		void EnableChips(bool);
		void PlayWinSound();
		void PlayLoseSound();
};

#endif
