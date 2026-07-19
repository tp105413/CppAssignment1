#pragma once

#include <string>

enum class Suit {
	Spades, Hearts, Clubs, Diamonds
};

enum class Rank {
	Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

class Card {
private:
	Suit suit;
	Rank rank;

public:
	Card(Suit s, Rank r);
	Suit getSuit() const;
	Rank getRank() const;
	int getChips() const;
	std::string displayCard() const;
};