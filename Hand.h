#pragma once

#include <vector>

#include "Card.h"

class Hand {
private:
	std::vector<Card> hand;

public:
	void addCard(Card card);
	void sortHand();
	void displayHand();
};