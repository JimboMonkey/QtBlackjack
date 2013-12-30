
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

/* Return the name of the owner of the box */
string Box::GetOwner() const
{
	return Owner->GetName();
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
const float Box::CountBet() const
{
	return Bet;
}

/* Place a bet on the current box */
void Box::PlaceBet(const float NewBet)
{
	Owner->PlaceBet(NewBet);
	Bet += NewBet;
	cout << "Bet is now " << Bet << endl;
	emit updateBet(QString::number(Bet));
}

void Box::IncreaseBet(const float BetIncrease)
{
	// Remove from stack
	cout << "Increasing bet by " << BetIncrease << endl;
	Owner->PlaceBet(BetIncrease);
	Bet += BetIncrease;
	cout << endl << endl << "Bet stands at " << Bet << endl << endl;
	emit updateBet(QString::number(Bet));
}

void Box::DecreaseBet(const float BetDecrease)
{
	// Return to stack
	cout << "Decreasing bet by " << BetDecrease << endl;
	Owner->AddToStack(BetDecrease);
	Bet -= BetDecrease;
	cout << endl << endl << "Bet stands at " << Bet << endl << endl;
	emit updateBet(QString::number(Bet));
}

/* Surrender the current hand */
void Box::Surrender()
{
	Surrended = true;
	Owner->AddToStack(Bet/2);
}

/* Check to see if the current box surrended */
const bool Box::CheckSurrended() const
{
	return Surrended;
}

/* Check if the current box has taken insurance */
const bool Box::CheckInsurance() const
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
	cout << "  Wins insurance bet and collects " << Insurance << " from the dealer" << endl;
	Insurance = 0;
}

/* Retrieve original bet after a push */
void Box::RetrieveBet()
{
	Owner->AddToStack(Bet);
	cout << "  Bet of " << Bet << " returned" << endl;
}

void Box::ReturnToStack(int ReturnedChipValue)
{
	Owner->AddToStack(ReturnedChipValue);
	Bet -= ReturnedChipValue;
	emit updateBet(QString::number(Bet));
	cout << "Bet is now " << Bet << endl;
	cout << "  Chip of " << ReturnedChipValue << " returned to stack" << endl;
	cout << "Box Bet stands at " << CountBet() << endl;
}

/* Receive winnings of a bet  - covers blackjack and 'normal' wins*/
void Box::ReceiveWinnings()
{
	/* A blackjack win */
	if(CheckHand() == 21 and Hand.size() == 2 and SplitBox == false)
	{
		Owner->AddToStack(Bet + Bet + (Bet/2));
		cout << "  Wins bet and collects " << (Bet + (Bet/2)) << " from the dealer" << endl;			
	}
	/* A non-blackjack win */
	else
	{
		Owner->AddToStack(Bet + Bet);
		cout << "  Wins bet and collects " << Bet << " from the dealer" << endl;
	}
}

/* Return the split card to be moved and reduced the current hand value */
const Card Box::MoveSplitCard()
{
	Card TempCard;

	TempCard = Hand.at(1);
	cout << "TempCard = " << TempCard.GetName() << " (" << TempCard.GetValue() << ")" << " of " << TempCard.GetSuit() << endl;
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
	cout << Owner->GetName();

	/* If the current box is the result of a split hand, display a different message */
	if(CheckSplit() == true)
	{
		cout << " (Split Hand)";
		QString SplitHandWords = QString::fromStdString(Owner->GetName()) + " (Split Hand)";
		emit updatePlayersName(SplitHandWords);
	}
	else
	{
		emit updatePlayersName(QString::fromStdString(Owner->GetName()));
	}
	cout << ": (" << Owner->CountStack() << " in your stack, " << Bet << " on the table) You are holding: " << endl << endl;	

	ListHand();
	emit updatePlayersHandValue(StatusResult());
}

