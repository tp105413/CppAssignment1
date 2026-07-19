#pragma once

#include <vector>

#include "Card.h"

class Deck {
private:
	std::vector<Card> cards;

public:
	Deck();
	void shuffle();
	Card drawCard();
	int remainingCards();
};