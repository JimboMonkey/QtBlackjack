
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
		QString CardName = Hand.at(i).GetName();
		QString CardSuit = Hand.at(i).GetSuit();
		QString LoadCardName = ":/PlayerCards/" + CardName + CardSuit + ".png";
		emit updatePlayersHand(LoadCardName, i);	
	}
}

/* State the result of the current hand */
QString Participant::HandValueString() const
{
	QString strHandValue;	

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
	Hand.push_back(DealtCard);
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

