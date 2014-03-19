
#ifndef CROUPIER_HPP
#define CROUPIER_HPP

#include <iostream>
#include <stdlib.h>
#include <QDebug>

#include "Participant.hpp"
#include "Card.hpp"

/* Define the card constants */
#define NumberOfDecks 4
#define SuitsPerDeck 4
#define CardsPerSuit 13
#define CardsPerDeck (SuitsPerDeck * CardsPerSuit)
#define ShoeSize (NumberOfDecks * CardsPerDeck)

class Croupier: public Participant
{
	Q_OBJECT

	public:
		Croupier();
		void InitialStatus();
		void Status();
		const Card Deal();
		void ReturnCards();
		void ListHand();
		
	private:
		/* Shoe size increased by 1 to accomodate cut card */
		Card Shoe[ShoeSize + 1];
		int NextCard;
		void List();
		void Shuffle();

	signals:
		void updateDealersHand(QString, int);	
		void updateDealersHandValue(QString);	
};

#endif
