
#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP

#include <iostream>
#include <vector>

#include <QObject>

#include "Card.hpp"

using namespace std;

class Participant: public QObject
{
	Q_OBJECT

	public:
		const int CheckHand() const;
		void TakeCard(const Card& DealtCard);
		QString StatusResult() const;
		void ListHand();
		const string CheckCard(const int CardIndex) const;
		const int CountCards() const;
		void SoftenAce();	

	protected:
		vector<Card> Hand;
		int HandValue;
		int AcesHeld;

	signals:
		void updatePlayersHand(QString, int);	
};

#endif
