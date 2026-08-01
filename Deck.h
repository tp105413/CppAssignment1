#pragma once

#include <vector>

#include "BaseCard.h"
#include "AbilityCard.h"

class Deck {
private:
	std::vector<BaseCard> cards;
	std::vector<AbilityCard> abilities;

public:
	Deck();
	void shuffle();
	BaseCard drawCard();
	size_t remainingCards();
	void deckReset();

	// ability card function
	void createAbilityDeck();
	AbilityCard drawAbilityCard();
};