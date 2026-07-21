#pragma once

#include <vector>

#include "BaseCard.h"

class Hand {
private:
	std::vector<BaseCard> hand;
	std::vector<BaseCard> playedCards;

public:
	void addCard(BaseCard card);
	void sortHand();
	void displayHand();
	void playHand();
	std::vector<BaseCard> getPlayedCards() const;
	void handReset();
};