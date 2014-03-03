
#include "Player.hpp"

#define DefaultStackValue 100

/* Constructor for the player object */
Player::Player()
{
	/* Set chosen name and default stack value */
	Stack = DefaultStackValue;
}

/* Return the player's stack value */
float Player::CountStack() const
{
	return Stack;
}

/* Reduce the stack by the bet value */
void Player::PlaceBet(const float NewBet)
{
	Stack -= NewBet;
	UpdateStack();
}

/* Add to the stack value */
void Player::AddToStack(const float Winnings)
{
	Stack += Winnings;
	UpdateStack();
}

void Player::UpdateStack()
{
	emit updateStack(QString::number(Stack));
}

