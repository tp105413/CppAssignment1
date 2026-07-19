#pragma once

#include <string>

#include "Card.h"

enum class Suit {
	Spades, Hearts, Clubs, Diamonds
};

enum class Rank {
	Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

class BaseCard : public Card {
private:
	Suit suit;
	Rank rank;

public:
	BaseCard(Suit s, Rank r);
	Suit getSuit() const;
	Rank getRank() const;
	int getChips() const;
	std::string displayCard() const override;
	void play() override;
};