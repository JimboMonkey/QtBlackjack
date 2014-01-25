
#ifndef BOX_HPP
#define BOX_HPP

#include <vector>
#include <QtGui>

#include "Player.hpp"
#include "Card.hpp"
#include "Participant.hpp"

class Box: public Participant
{
	Q_OBJECT

	public:
		Box(Player* NewOwner, const bool Split = false);
		string GetOwner() const;
		Player* GetOwnerObj() const;
		void Status();
		void PlaceBet(const float NewBet);
		float CountBet() const;
		void RetrieveBet();
		void ReceiveWinnings();
		float CountStack() const;
		void PlaceInsurance();
		bool CheckInsurance() const;
		void ReceiveInsurance();
		void Surrender();
		bool CheckSurrended() const;
		const Card MoveSplitCard();
		bool CheckSplit() const;
		void ReturnCards();
		void ReturnToStack(int ReturnedChipValue);

	private:
		Player *Owner;
		float Bet;
		bool UsingInsurance;
		float Insurance;
		bool Surrended;
		bool SplitBox;

	signals:
		void updatePlayersHandValue(QString);
		void updateBet(QString);
		void updatePlayersName(QString);

	private slots:
		void IncreaseBet(const float BetIncrease);
		void DecreaseBet(const float BetDecrease);
		
};

#endif


