
#ifndef CARD_HPP
#define CARD_HPP

class Card
{
	public:
		const char *GetSuit() const;
		const char *GetName() const;
		const int GetValue() const;

		void SetSuit(const char *NewSuit);
		void SetName(const char *NewName);
		void SetValue(const int NewValue);

	private:
		const char *Suit;
		const char *Name;
		int Value;
};

#endif
