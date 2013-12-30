
#include "Card.hpp"

/* Set the suit of the card object */
void Card::SetSuit(const char *NewSuit)
{
	Suit = NewSuit;
}

/* Set the name of the card object */
void Card::SetName(const char *NewName)
{
	Name = NewName;
}

/* Set the value of the card object */
void Card::SetValue(const int NewValue)
{
	Value = NewValue;
}

/* Get the suit of the card object */
const char *Card::GetSuit() const
{
	return Suit;
}

/* Get the name of the card object */
const char *Card::GetName() const
{
	return Name;
}

/* Get the value of the card object */
const int Card::GetValue() const
{
	return Value;
}
