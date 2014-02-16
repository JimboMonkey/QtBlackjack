
#include "Participant.hpp"

#include <sstream>

#define DefaultStackValue 100

/* List all cards of the current hand */
void Participant::ListHand()
{
	unsigned int i;
	
	emit ClearPlayersHand();

	for(i = 0; i < Hand.size(); i++)
	{
		//cout << "  " << Hand.at(i).GetName() << "(" << Hand.at(i).GetValue() << ")" << " of " << Hand.at(i).GetSuit() << endl;
		QString CardName = Hand.at(i).GetName();
		QString CardSuit = Hand.at(i).GetSuit();
		QString LoadCardName = "PlayerCards/" + CardName + CardSuit + ".png";
		emit updatePlayersHand(LoadCardName, i);	
	}
	cout << endl;
}

/* State the result of the current hand */
QString Participant::StatusResult() const
{
	QString strHandValue;	

	/* Current box is bust */
	if (HandValue > 21 and AcesHeld == 0)
	{
		//cout << "  Bust with ";
		//strHandValue = " Bust with ";
	}
	/* Current box is holding aces so has a soft hand */
	else if (AcesHeld > 0 and HandValue != 21)
	{
		//cout << "  Soft ";
		strHandValue = "S";
	}
	/* State the value of the current hand */
	else
	{
		//cout << "  ";
		strHandValue = "";
	}
	//cout << HandValue << endl << endl;
	strHandValue += QString::number(HandValue);
	return strHandValue;
}

/* Check the value of the current hand */
int Participant::CheckHand() const
{
	return HandValue;
}

/* Return the number of cards in the current hand */
int Participant::CountCards() const
{
	return Hand.size();
}

/* Check the name of a chosen card */
const string Participant::CheckCard(const int CardIndex) const
{
	return Hand.at(CardIndex).GetName();
}

/* Soften the value of an ace card */
void Participant::SoftenAce()
{
	HandValue -= 10;
	AcesHeld--;
}

/* Receive the card dealt to the box */
void Participant::TakeCard(const Card& DealtCard)
{
/*	const char* Suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	const int Values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
	const char* Names[] = {"Ace",
		       "Two",
		       "Three",
		       "Four",
		       "Five",
		       "Six",
		       "Seven",
		       "Eight",
		       "Nine",
		       "Ten",
		       "Jack",
		       "Queen",
		       "King"};

	string UserEntry;
	int CardVal;
	cout << "Card value?" << endl;
	getline(cin, UserEntry);
	stringstream StrToInt(UserEntry); 
	StrToInt >> CardVal;
	HandValue += CardVal+1;

	Card TestCard;

	TestCard.SetSuit(Suits[2]);
	TestCard.SetName(Names[CardVal]);
	TestCard.SetValue(Values[CardVal]);*/

	Hand.push_back(DealtCard);
//	Hand.push_back(TestCard);
	HandValue += DealtCard.GetValue();

	/* Keep a count of the number of aces held */
	string CompareString = DealtCard.GetName();
	if (CompareString.compare("Ace") == 0)
	{
		AcesHeld++;
	}
	/* Soften any aces if required */
	if(CheckHand() > 21)
	{
		if (AcesHeld > 0)
		{
			SoftenAce();
		}
	}
}

