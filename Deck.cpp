#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "Deck.h"

// create player's deck
Deck::Deck() {
	for (int s = 0; s < 4; s++) {
		for (int r = 1; r <= 13; r++) {
			cards.push_back(
				BaseCard(static_cast<Suit>(s), static_cast<Rank>(r))
			);
		}
	}

	// create ability library store all abilities
	createAbilityDeck();
}

// shuffle created deck in vector
void Deck::shuffle() {
	std::random_device randomNumber;
	std::mt19937 generator(randomNumber());
	std::shuffle(cards.begin(), cards.end(), generator);
}

BaseCard Deck::drawCard() {
	BaseCard drawnCard = cards.back();
	cards.pop_back();
	return drawnCard;
}

size_t Deck::remainingCards() {
	return cards.size();
}

void Deck::deckReset() {
	cards.clear();
	for (int s = 0; s < 4; s++) {
		for (int r = 1; r <= 13; r++) {
			cards.push_back(
				BaseCard(static_cast<Suit>(s), static_cast<Rank>(r))
			);
		}
	}
}

// add all abilities here
void Deck::createAbilityDeck() {
	abilities.push_back(AbilityCard("Big 3", "Any 3 cards count as Big Three"));
	abilities.push_back(AbilityCard("Power Chips", "Base Chips +20"));
	abilities.push_back(AbilityCard("Power Multiplier", "Base Multiplier +1"));
	abilities.push_back(AbilityCard("Shield Breaker", "Instantly break Joker's Shield"));
}

AbilityCard Deck::drawAbilityCard() {
	int random = rand() % 4 + 1;
	return abilities[random];
}