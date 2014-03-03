
#include "Box.hpp"

/* Constructor for the Box object */
Box::Box(Player *NewOwner, const bool Split)
{
	Owner = NewOwner;
	Bet = 0;
	HandValue = 0;
	Insurance = 0;
	AcesHeld = 0;
	UsingInsurance = false;
	Surrended = false;
	SplitBox = Split;
}

/* Return a pointer to the owner of the box */
Player* Box::GetOwnerObj() const
{
	return Owner;
}

/* Return whether the box is used for split card play */
bool Box::CheckSplit() const
{
	return SplitBox;
}

/* Return the size of box owner's stack */
float Box::CountStack() const
{
	return Owner->CountStack();
}

/* Return the bet placed on the current box */
float Box::CountBet() const
{
	return Bet;
}

/* Place or increase a bet on the current box */
void Box::IncreaseBet(const float BetIncrease)
{
	// Remove from stack
	qDebug() << "Increasing bet by " << BetIncrease;
	Owner->PlaceBet(BetIncrease);
	Bet += BetIncrease;
	qDebug() << "Bet stands at " << Bet;
	emit updateBet(QString::number(Bet));
}

// Decrease a bet on the current box
void Box::DecreaseBet(const float BetDecrease)
{
	// Return to stack
	qDebug() << "Decreasing bet by " << BetDecrease;
	Owner->AddToStack(BetDecrease);
	Bet -= BetDecrease;
	qDebug() << "Bet stands at " << Bet;
	emit updateBet(QString::number(Bet));
}

/* Surrender the current hand */
void Box::Surrender()
{
	Surrended = true;
	Owner->AddToStack(Bet/2);
}

/* Check to see if the current box surrended */
bool Box::CheckSurrended() const
{
	return Surrended;
}

/* Check if the current box has taken insurance */
bool Box::CheckInsurance() const
{
	return UsingInsurance;
}

/* Place insurance on the current box */
void Box::PlaceInsurance()
{
	Owner->PlaceBet(Bet / 2);
	Insurance = (Bet / 2);
	UsingInsurance = true;
}

/* Receive an insurance bet pay out */
void Box::ReceiveInsurance()
{
	Owner->AddToStack(Bet + Insurance);
	Insurance = 0;
}

/* Retrieve original bet after a push */
void Box::RetrieveBet()
{
	Owner->AddToStack(Bet);
}

void Box::ReturnToStack(int ReturnedChipValue)
{
	Owner->AddToStack(ReturnedChipValue);
	Bet -= ReturnedChipValue;
	emit updateBet(QString::number(Bet));
	qDebug() << "Bet is now " << Bet;
	qDebug() << "  Chip of " << ReturnedChipValue << " returned to stack";
	qDebug() << "Box Bet stands at " << CountBet();
}

/* Receive winnings of a bet  - covers blackjack and 'normal' wins*/
void Box::ReceiveWinnings()
{
	/* A blackjack win */
	if(CheckHand() == 21 and Hand.size() == 2 and SplitBox == false)
	{
		Owner->AddToStack(Bet + Bet + (Bet/2));
	}
	/* A non-blackjack win */
	else
	{
		Owner->AddToStack(Bet + Bet);
	}
}

/* Return the split card to be moved and reduced the current hand value */
const Card Box::MoveSplitCard()
{
	Card TempCard;

	TempCard = Hand.at(1);
	qDebug() << "TempCard = " << TempCard.GetName() << " (" << TempCard.GetValue() << ") of " << TempCard.GetSuit();
	HandValue -= Hand.at(1).GetValue();
	Hand.pop_back();
	/* AcesHeld must be reassessed after a split */
	string CompareString = Hand.front().GetName();
	if (CompareString.compare("Ace") == 0)
	{
		AcesHeld = 1;
		HandValue = 11;
	}
	return TempCard;
}

/* Reset all flags of the current box */
void Box::ReturnCards()
{
	Hand.clear();
	HandValue = 0;
	AcesHeld = 0;
	Bet = 0;
	Insurance = 0;
	UsingInsurance = false;
	Surrended = false;
}

/* Declare the status of the current hand */
void Box::Status()
{
	ListHand();
	emit updatePlayersHandValue(HandValueString());
}

