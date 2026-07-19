#pragma once

#include <vector>

#include "BaseCard.h"

class Deck {
private:
	std::vector<BaseCard> cards;

public:
	Deck();
	void shuffle();
	BaseCard drawCard();
	size_t remainingCards();
};