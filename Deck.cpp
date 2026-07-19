#include <random>
#include <algorithm>

#include "Deck.h"

// create player's deck
Deck::Deck() {
	for (int s = 0; s < 4; s++) {
		for (int r = 1; r <= 13; r++) {
			cards.push_back(
				Card(static_cast<Suit>(s), static_cast<Rank>(r))
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

Card Deck::drawCard() {
	Card drawnCard = cards.back();
	cards.pop_back();
	return drawnCard;
}

int Deck::remainingCards() {
	return cards.size();
}