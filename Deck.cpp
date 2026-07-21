#include <random>
#include <algorithm>

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