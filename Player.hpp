
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include <QObject>

using namespace std;

class Player: public QObject
{
	Q_OBJECT

	public:
		Player();
		void PlaceBet(const float NewBet);
		float CountStack() const;
		void AddToStack(const float Winnings);

	private:
		float Stack;
		void UpdateStack();

	signals:
		void updateStack(QString);
};

#endif
