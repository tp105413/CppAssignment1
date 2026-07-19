#pragma once

#include <vector>

#include "BaseCard.h"

class Hand {
private:
	std::vector<BaseCard> hand;

public:
	void addCard(BaseCard card);
	void sortHand();
	void displayHand();
	void playHand();
};